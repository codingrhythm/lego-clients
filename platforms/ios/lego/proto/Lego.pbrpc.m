#if !defined(GPB_GRPC_PROTOCOL_ONLY) || !GPB_GRPC_PROTOCOL_ONLY
#import "Lego.pbrpc.h"
#import "Lego.pbobjc.h"
#import <ProtoRPC/ProtoRPC.h>
#import <RxLibrary/GRXWriter+Immediate.h>


@implementation Lego

// Designated initializer
- (instancetype)initWithHost:(NSString *)host {
  self = [super initWithHost:host
                 packageName:@"lego"
                 serviceName:@"Lego"];
  return self;
}

// Override superclass initializer to disallow different package and service names.
- (instancetype)initWithHost:(NSString *)host
                 packageName:(NSString *)packageName
                 serviceName:(NSString *)serviceName {
  return [self initWithHost:host];
}

#pragma mark - Class Methods

+ (instancetype)serviceWithHost:(NSString *)host {
  return [[self alloc] initWithHost:host];
}

#pragma mark - Method Implementations

#pragma mark SendRecord(LegoRecord) returns (LegoResponse)

- (void)sendRecordWithRequest:(LegoRecord *)request handler:(void(^)(LegoResponse *_Nullable response, NSError *_Nullable error))handler{
  [[self RPCToSendRecordWithRequest:request handler:handler] start];
}
// Returns a not-yet-started RPC object.
- (GRPCProtoCall *)RPCToSendRecordWithRequest:(LegoRecord *)request handler:(void(^)(LegoResponse *_Nullable response, NSError *_Nullable error))handler{
  return [self RPCToMethod:@"SendRecord"
            requestsWriter:[GRXWriter writerWithValue:request]
             responseClass:[LegoResponse class]
        responsesWriteable:[GRXWriteable writeableWithSingleHandler:handler]];
}
#pragma mark GetData(GetRequest) returns (Template)

- (void)getDataWithRequest:(GetRequest *)request handler:(void(^)(Template *_Nullable response, NSError *_Nullable error))handler{
  [[self RPCToGetDataWithRequest:request handler:handler] start];
}
// Returns a not-yet-started RPC object.
- (GRPCProtoCall *)RPCToGetDataWithRequest:(GetRequest *)request handler:(void(^)(Template *_Nullable response, NSError *_Nullable error))handler{
  return [self RPCToMethod:@"GetData"
            requestsWriter:[GRXWriter writerWithValue:request]
             responseClass:[Template class]
        responsesWriteable:[GRXWriteable writeableWithSingleHandler:handler]];
}
@end
#endif
