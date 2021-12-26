/* Copyright (c) 2018 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License.
 */

#ifndef GRAPH_REQUESTCONTEXT_H_
#define GRAPH_REQUESTCONTEXT_H_

#include "common/base/Base.h"
#include "common/cpp/helpers.h"
#include "common/time/Duration.h"
#include "graph/session/ClientSession.h"
#include "graph/session/GraphSessionManager.h"
#include "interface/gen-cpp2/GraphService.h"
#include <opentracing/span.h>
/**
 * RequestContext holds context infos of a specific request from a client.
 * The typical use is:
 *  1. Create a RequestContext, with statement, session, etc.
 *  2. Obtain a Future from the context, which is to be returned back to the
 * Thrift framework.
 *  3. Prepare the Response when the request is complished.
 *  4. Call `finish' to send the response to the client.
 */

namespace nebula {
namespace graph {

template <typename Response>
class RequestContext final : public cpp::NonCopyable, public cpp::NonMovable {
 public:
  RequestContext() = default;
  ~RequestContext() {
    if (session_ != nullptr) {
      // keep the session active
      session_->charge();
    }
  }

  void setQuery(std::string query) { query_ = std::move(query); }

  const std::string& query() const { return query_; }

  Response& resp() { return resp_; }

  folly::Future<Response> future() { return promise_.getFuture(); }

  void setSession(std::shared_ptr<ClientSession> session) {
    session_ = std::move(session);
    if (session_ != nullptr) {
      // keep the session active
      session_->charge();
    }
  }

  ClientSession* session() const { return session_.get(); }

  folly::Executor* runner() const { return runner_; }

  void setRunner(folly::Executor* runner) { runner_ = runner; }

  const time::Duration& duration() const { return duration_; }

  void finish() { promise_.setValue(std::move(resp_)); }

  void setSessionMgr(GraphSessionManager* mgr) { sessionMgr_ = mgr; }

  GraphSessionManager* sessionMgr() const { return sessionMgr_; }

  void setSpan(std::unique_ptr<opentracing::Span> span) { span_ = std::move(span); }

  std::unique_ptr<opentracing::Span> span()  { return span_; }

  void setTracer(std::shared_ptr<opentracing::Tracer> tracer) { tracer_ = std::move(tracer ); }
  std::shared_ptr<opentracing::Tracer> tracer()  { return tracer_; }
  void setTraceOut(std::shared_ptr<std::ostringstream> traceOut) {traceOut_ = std::move(traceOut );}
   std::shared_ptr<std::ostringstream> traceOut() {return traceOut_;}

 private:
  time::Duration duration_;
  std::string query_;
  Response resp_;
  std::shared_ptr<opentracing::Tracer> tracer_;
  std::unique_ptr<opentracing::Span> span_;
  std::shared_ptr<std::ostringstream> traceOut_;

  folly::Promise<Response> promise_;
  std::shared_ptr<ClientSession> session_;
  folly::Executor* runner_{nullptr};
  GraphSessionManager* sessionMgr_{nullptr};
};

}  // namespace graph
}  // namespace nebula

#endif  // GRAPH_REQUESTCONTEXT_H_
