#if !defined(GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO) || !GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO
#import "Lego.pbobjc.h"
#endif

#if !defined(GPB_GRPC_PROTOCOL_ONLY) || !GPB_GRPC_PROTOCOL_ONLY
#import <ProtoRPC/ProtoService.h>
#import <ProtoRPC/ProtoRPC.h>
#import <RxLibrary/GRXWriteable.h>
#import <RxLibrary/GRXWriter.h>
#endif

@class GetRequest;
@class LegoRecord;
@class LegoResponse;
@class Template;

#if !defined(GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO) || !GPB_GRPC_FORWARD_DECLARE_MESSAGE_PROTO
#endif

@class GRPCProtoCall;


NS_ASSUME_NONNULL_BEGIN

@protocol Lego <NSObject, GRPCProtoServiceInit>

#pragma mark SendRecord(LegoRecord) returns (LegoResponse)

- (void)sendRecordWithRequest:(LegoRecord *)request handler:(void(^)(LegoResponse *_Nullable response, NSError *_Nullable error))handler;

- (GRPCProtoCall *)RPCToSendRecordWithRequest:(LegoRecord *)request handler:(void(^)(LegoResponse *_Nullable response, NSError *_Nullable error))handler;


#pragma mark GetData(GetRequest) returns (Template)

- (void)getDataWithRequest:(GetRequest *)request handler:(void(^)(Template *_Nullable response, NSError *_Nullable error))handler;

- (GRPCProtoCall *)RPCToGetDataWithRequest:(GetRequest *)request handler:(void(^)(Template *_Nullable response, NSError *_Nullable error))handler;


@end


#if !defined(GPB_GRPC_PROTOCOL_ONLY) || !GPB_GRPC_PROTOCOL_ONLY
/**
 * Basic service implementation, over gRPC, that only does
 * marshalling and parsing.
 */
@interface Lego : GRPCProtoService<Lego>
- (instancetype)initWithHost:(NSString *)host NS_DESIGNATED_INITIALIZER;
+ (instancetype)serviceWithHost:(NSString *)host;
@end
#endif

NS_ASSUME_NONNULL_END

