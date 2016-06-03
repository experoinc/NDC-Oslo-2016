using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Cassandra;
using Expero;
using Grpc.Core;

namespace TruckingServer
{
    public class TruckingServerImpl : Trucking.ITrucking
    {
        public ISession Session { get; set; }
        public TruckingServerImpl()
        {
            var cluster = Cluster.Builder().AddContactPoint("dse5.palladiumconsulting.com").Build();
            Session= cluster.Connect("ndc_oslo");
        }
        public async Task RecordLocation(IAsyncStreamReader<Point> requestStream, IServerStreamWriter<Response> responseStream, ServerCallContext context)
        {

            var stopwatch = new Stopwatch();

            while (await requestStream.MoveNext())
            {
                stopwatch.Restart();
                var point = requestStream.Current;
                SavePointToCassandra(point);

                stopwatch.Stop();

                await responseStream.WriteAsync(new Response
                {
                    ResponseTime = (int)stopwatch.ElapsedMilliseconds
                });
            }
        }

        private void SavePointToCassandra(Point point)
        {
            Session.Execute(String.Format("INSERT INTO location_by_tripid (tripid, time, manufacturer, truckname, latitude, longitude)" + 
                " VALUES ('{0}', {1}, '{2}', '{3}', {4}, {5})", point.Trip.TripId, CurrentUnixTimestamp(), point.Trip.TruckManufacturer, 
                point.Trip.TruckName, point.Latitude, point.Longitude));
        }

         protected static long CurrentUnixTimestamp()
        {
            return Convert.ToInt64((DateTime.UtcNow - new DateTime(1970, 1, 1)).TotalMilliseconds);
        }

        public Task<Point> ReadLastLocation(Trip request, ServerCallContext context)
        {
            Row results = Session.Execute(String.Format("SELECT * FROM location_by_tripid WHERE truckname='{0}' AND manufacturer='{1}' AND tripid='{2}' LIMIT 1",
                request.TruckName, request.TruckManufacturer, request.TripId)).First();

            var point = new Point
            {
                Trip = new Trip
                {
                    TripId = results["tripid"].ToString(),
                    TruckManufacturer = results["manufacturer"].ToString(),
                    TruckName = results["truckname"].ToString()
                },
                Latitude = (float)results["latitude"],
                Longitude = (float)results["longitude"]
            };

            return Task.FromResult(point);
        }
    }
}
