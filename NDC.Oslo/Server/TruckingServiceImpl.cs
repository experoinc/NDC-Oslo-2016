using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Expero;
using Grpc.Core;

namespace TruckingServer
{
    class TruckingServiceImpl : Expero.Trucking.ITrucking
    {
        public Task RecordLocation(IAsyncStreamReader<Point> requestStream, IServerStreamWriter<Response> responseStream, ServerCallContext context)
        {
            throw new NotImplementedException();
        }
    }
}
