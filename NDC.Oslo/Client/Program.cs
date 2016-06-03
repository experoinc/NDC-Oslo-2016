using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Grpc.Core;
using Expero;
using System.Threading;

namespace Client
{
    class Program
    {
        private static List<string> Manufacturers = new List<string> { "Mack", "Volvo", "Freightliner", "Kenworth", "Saab" };


        static void Main(string[] args)
        {
            Channel channel = new Channel("127.0.0.1:50051", ChannelCredentials.Insecure);

            Task.Factory.StartNew(() => StartTruckRecording(channel));

            Console.ReadLine();
            channel.ShutdownAsync().Wait();
        }

        private static async Task StartTruckRecording(Channel channel)
        {
            var client = new Trucking.TruckingClient(channel);
            var truckName = "Truck " + DateTime.UtcNow.Millisecond;
            var manufacturer = Manufacturers[DateTime.UtcNow.Millisecond % 5];
            var tripid = Guid.NewGuid();
            using (var call = client.RecordLocation())
            {

                var responseReaderTask = Task.Run(async () =>
                {
                    var i = 0;
                    var avg = new int[5];
                    while (await call.ResponseStream.MoveNext())
                    {
                        i++;
                        var note = call.ResponseStream.Current;
                        avg[i % 5] = note.ResponseTime;
                        //Show the running average for every 5th time as well as the last Location
                        if (i % 5 == 0)
                        {
                            var sw = new Stopwatch();
                            sw.Start();
                            client.ReadLastLocation(new Trip { TripId = tripid.ToString(), TruckName = truckName, TruckManufacturer = manufacturer });
                            sw.Stop();
                            Console.WriteLine("Name:" + truckName + "\r\nManufacturer:" + manufacturer + "\r\nTripId:" + tripid + "\r\nAvg Last 5 Writes Time (ms):" + avg.Average().ToString() + "\r\nLast Location Read Time(ms):" + sw.ElapsedMilliseconds);
                        }
                    }
                });

                var rnd = new Random();

                while (true)
                {
                    var point = new Point
                    {
                        Trip = new Trip
                        {
                            TruckName = truckName,
                            TruckManufacturer = manufacturer,
                            TripId = tripid.ToString()
                        },
                        Latitude = (float)(rnd.NextDouble() * 75),
                        Longitude = (float)(rnd.NextDouble() * 90)
                    };
                    await call.RequestStream.WriteAsync(point);
                    Thread.Sleep(1000);

                }

                await call.RequestStream.CompleteAsync();
            }
        }
    }
}
