// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: p2psentinel/sentinel.proto

#include "p2psentinel/sentinel.pb.h"
#include "p2psentinel/sentinel.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace sentinel {

static const char* Sentinel_method_names[] = {
  "/sentinel.Sentinel/SubscribeGossip",
  "/sentinel.Sentinel/SendRequest",
  "/sentinel.Sentinel/SetStatus",
  "/sentinel.Sentinel/GetPeers",
};

std::unique_ptr< Sentinel::Stub> Sentinel::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Sentinel::Stub> stub(new Sentinel::Stub(channel, options));
  return stub;
}

Sentinel::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SubscribeGossip_(Sentinel_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_SendRequest_(Sentinel_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SetStatus_(Sentinel_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetPeers_(Sentinel_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientReader< ::sentinel::GossipData>* Sentinel::Stub::SubscribeGossipRaw(::grpc::ClientContext* context, const ::sentinel::EmptyMessage& request) {
  return ::grpc::internal::ClientReaderFactory< ::sentinel::GossipData>::Create(channel_.get(), rpcmethod_SubscribeGossip_, context, request);
}

void Sentinel::Stub::async::SubscribeGossip(::grpc::ClientContext* context, const ::sentinel::EmptyMessage* request, ::grpc::ClientReadReactor< ::sentinel::GossipData>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::sentinel::GossipData>::Create(stub_->channel_.get(), stub_->rpcmethod_SubscribeGossip_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::sentinel::GossipData>* Sentinel::Stub::AsyncSubscribeGossipRaw(::grpc::ClientContext* context, const ::sentinel::EmptyMessage& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::sentinel::GossipData>::Create(channel_.get(), cq, rpcmethod_SubscribeGossip_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::sentinel::GossipData>* Sentinel::Stub::PrepareAsyncSubscribeGossipRaw(::grpc::ClientContext* context, const ::sentinel::EmptyMessage& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::sentinel::GossipData>::Create(channel_.get(), cq, rpcmethod_SubscribeGossip_, context, request, false, nullptr);
}

::grpc::Status Sentinel::Stub::SendRequest(::grpc::ClientContext* context, const ::sentinel::RequestData& request, ::sentinel::ResponseData* response) {
  return ::grpc::internal::BlockingUnaryCall< ::sentinel::RequestData, ::sentinel::ResponseData, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendRequest_, context, request, response);
}

void Sentinel::Stub::async::SendRequest(::grpc::ClientContext* context, const ::sentinel::RequestData* request, ::sentinel::ResponseData* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::sentinel::RequestData, ::sentinel::ResponseData, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendRequest_, context, request, response, std::move(f));
}

void Sentinel::Stub::async::SendRequest(::grpc::ClientContext* context, const ::sentinel::RequestData* request, ::sentinel::ResponseData* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendRequest_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::sentinel::ResponseData>* Sentinel::Stub::PrepareAsyncSendRequestRaw(::grpc::ClientContext* context, const ::sentinel::RequestData& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::sentinel::ResponseData, ::sentinel::RequestData, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendRequest_, context, request);
}

::grpc::ClientAsyncResponseReader< ::sentinel::ResponseData>* Sentinel::Stub::AsyncSendRequestRaw(::grpc::ClientContext* context, const ::sentinel::RequestData& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendRequestRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Sentinel::Stub::SetStatus(::grpc::ClientContext* context, const ::sentinel::Status& request, ::sentinel::EmptyMessage* response) {
  return ::grpc::internal::BlockingUnaryCall< ::sentinel::Status, ::sentinel::EmptyMessage, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SetStatus_, context, request, response);
}

void Sentinel::Stub::async::SetStatus(::grpc::ClientContext* context, const ::sentinel::Status* request, ::sentinel::EmptyMessage* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::sentinel::Status, ::sentinel::EmptyMessage, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetStatus_, context, request, response, std::move(f));
}

void Sentinel::Stub::async::SetStatus(::grpc::ClientContext* context, const ::sentinel::Status* request, ::sentinel::EmptyMessage* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SetStatus_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::sentinel::EmptyMessage>* Sentinel::Stub::PrepareAsyncSetStatusRaw(::grpc::ClientContext* context, const ::sentinel::Status& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::sentinel::EmptyMessage, ::sentinel::Status, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SetStatus_, context, request);
}

::grpc::ClientAsyncResponseReader< ::sentinel::EmptyMessage>* Sentinel::Stub::AsyncSetStatusRaw(::grpc::ClientContext* context, const ::sentinel::Status& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSetStatusRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Sentinel::Stub::GetPeers(::grpc::ClientContext* context, const ::sentinel::EmptyMessage& request, ::sentinel::PeerCount* response) {
  return ::grpc::internal::BlockingUnaryCall< ::sentinel::EmptyMessage, ::sentinel::PeerCount, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetPeers_, context, request, response);
}

void Sentinel::Stub::async::GetPeers(::grpc::ClientContext* context, const ::sentinel::EmptyMessage* request, ::sentinel::PeerCount* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::sentinel::EmptyMessage, ::sentinel::PeerCount, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPeers_, context, request, response, std::move(f));
}

void Sentinel::Stub::async::GetPeers(::grpc::ClientContext* context, const ::sentinel::EmptyMessage* request, ::sentinel::PeerCount* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPeers_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::sentinel::PeerCount>* Sentinel::Stub::PrepareAsyncGetPeersRaw(::grpc::ClientContext* context, const ::sentinel::EmptyMessage& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::sentinel::PeerCount, ::sentinel::EmptyMessage, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetPeers_, context, request);
}

::grpc::ClientAsyncResponseReader< ::sentinel::PeerCount>* Sentinel::Stub::AsyncGetPeersRaw(::grpc::ClientContext* context, const ::sentinel::EmptyMessage& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetPeersRaw(context, request, cq);
  result->StartCall();
  return result;
}

Sentinel::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Sentinel_method_names[0],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< Sentinel::Service, ::sentinel::EmptyMessage, ::sentinel::GossipData>(
          [](Sentinel::Service* service,
             ::grpc::ServerContext* ctx,
             const ::sentinel::EmptyMessage* req,
             ::grpc::ServerWriter<::sentinel::GossipData>* writer) {
               return service->SubscribeGossip(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Sentinel_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Sentinel::Service, ::sentinel::RequestData, ::sentinel::ResponseData, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Sentinel::Service* service,
             ::grpc::ServerContext* ctx,
             const ::sentinel::RequestData* req,
             ::sentinel::ResponseData* resp) {
               return service->SendRequest(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Sentinel_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Sentinel::Service, ::sentinel::Status, ::sentinel::EmptyMessage, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Sentinel::Service* service,
             ::grpc::ServerContext* ctx,
             const ::sentinel::Status* req,
             ::sentinel::EmptyMessage* resp) {
               return service->SetStatus(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Sentinel_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Sentinel::Service, ::sentinel::EmptyMessage, ::sentinel::PeerCount, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Sentinel::Service* service,
             ::grpc::ServerContext* ctx,
             const ::sentinel::EmptyMessage* req,
             ::sentinel::PeerCount* resp) {
               return service->GetPeers(ctx, req, resp);
             }, this)));
}

Sentinel::Service::~Service() {
}

::grpc::Status Sentinel::Service::SubscribeGossip(::grpc::ServerContext* context, const ::sentinel::EmptyMessage* request, ::grpc::ServerWriter< ::sentinel::GossipData>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Sentinel::Service::SendRequest(::grpc::ServerContext* context, const ::sentinel::RequestData* request, ::sentinel::ResponseData* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Sentinel::Service::SetStatus(::grpc::ServerContext* context, const ::sentinel::Status* request, ::sentinel::EmptyMessage* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Sentinel::Service::GetPeers(::grpc::ServerContext* context, const ::sentinel::EmptyMessage* request, ::sentinel::PeerCount* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace sentinel
