using System;
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

            
            for (int i = 0; i < 5; i++)
            {
                Task.Factory.StartNew(() => StartTruckRecording(channel));
            }
            Console.ReadLine();
            channel.ShutdownAsync().Wait();
        }

        private static async Task StartTruckRecording(Channel channel)
        {
            var client = new Trucking.TruckingClient(channel);
            var truckName = "Truck " + DateTime.UtcNow.Millisecond;
            var manufacturer = Manufacturers[DateTime.UtcNow.Millisecond % 5];
            using (var call = client.RecordLocation())
            {

                var responseReaderTask = Task.Run(async () =>
                {
                    while (await call.ResponseStream.MoveNext())
                    {
                        var note = call.ResponseStream.Current;
                        Console.WriteLine("Truck Name:"+ truckName + " - Processing Time " + note.Status);
                    }
                });

                var rnd = new Random();
                var tripid = Guid.NewGuid();
                while (true)
                {
                    var point = new Point
                    {
                        TruckName = truckName,
                        TruckManufacturer = manufacturer,
                        TripId = tripid.ToString(),
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
