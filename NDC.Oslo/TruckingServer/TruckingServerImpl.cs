using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading.Tasks;
using Cassandra;
using Expero;
using Grpc.Core;

namespace TruckingServer
{
    public class TruckingServerImpl : Trucking.ITrucking
    {
        public async Task RecordLocation(IAsyncStreamReader<Point> requestStream, IServerStreamWriter<Response> responseStream, ServerCallContext context)
        {
            var cluster = Cluster.Builder().AddContactPoint("xxx.xxxx.com").Build();
            var session = cluster.Connect("ndc_oslo");

            var stopwatch = new Stopwatch();

            while (await requestStream.MoveNext())
            {
                stopwatch.Restart();
                var point = requestStream.Current;
                SavePointToCassandra(session, point);

                stopwatch.Stop();

                await responseStream.WriteAsync(new Response
                {
                    ResponseTime = (int)stopwatch.ElapsedMilliseconds
                });
            }
        }

        private void SavePointToCassandra(ISession session, Point point)
        {
            session.Execute(String.Format("insert into location_by_tripid (tripid, time, manufacturer, truckname, latitude, longitude)" + 
                " values ('{0}', {1}, '{2}', '{3}', {4}, {5})", point.TripId, CurrentUnixTimestamp(), point.TruckManufacturer, 
                point.TruckName, point.Latitude, point.Longitude));
        }

        private RowSet ReadPointToCassandra(ISession session, Point point)
        {
            var results = session.Execute(String.Format("select * location_by_tripid where truckname='{0}' and manufacturer='{1} and tripid='{2}'",
                point.TruckName, point.TruckManufacturer, point.TripId));

            return results;
        }

        protected static long CurrentUnixTimestamp()
        {
            return Convert.ToInt64((DateTime.UtcNow - new DateTime(1970, 1, 1)).TotalMilliseconds);
        }
    }
}
