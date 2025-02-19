nebula_add_library(
    storage_common_obj OBJECT
    StorageFlags.cpp
    CommonUtils.cpp
)

nebula_add_library(
    storage_admin_service_handler OBJECT
    StorageAdminServiceHandler.cpp
    admin/CreateCheckpointProcessor.cpp
    admin/DropCheckpointProcessor.cpp
    admin/SendBlockSignProcessor.cpp
    admin/AdminTaskProcessor.cpp
    admin/StopAdminTaskProcessor.cpp
    admin/AdminTaskManager.cpp
    admin/AdminTask.cpp
    admin/CompactTask.cpp
    admin/FlushTask.cpp
    admin/RebuildIndexTask.cpp
    admin/RebuildTagIndexTask.cpp
    admin/RebuildEdgeIndexTask.cpp
    admin/RebuildFTIndexTask.cpp
    admin/StatsTask.cpp
    admin/ListClusterInfoProcessor.cpp
)

nebula_add_library(
    graph_storage_service_handler OBJECT
    GraphStorageServiceHandler.cpp
    ExprVisitorBase.cpp
    context/StorageExpressionContext.cpp
    mutate/AddVerticesProcessor.cpp
    mutate/DeleteVerticesProcessor.cpp
    mutate/DeleteTagsProcessor.cpp
    mutate/AddEdgesProcessor.cpp
    mutate/DeleteEdgesProcessor.cpp
    mutate/UpdateVertexProcessor.cpp
    mutate/UpdateEdgeProcessor.cpp
    query/GetNeighborsProcessor.cpp
    query/GetPropProcessor.cpp
    query/ScanVertexProcessor.cpp
    query/ScanEdgeProcessor.cpp
    index/LookupProcessor.cpp
    exec/IndexNode.cpp
    exec/IndexDedupNode.cpp
    exec/IndexEdgeScanNode.cpp
    exec/IndexLimitNode.cpp
    exec/IndexProjectionNode.cpp
    exec/IndexScanNode.cpp
    exec/IndexSelectionNode.cpp
    exec/IndexVertexScanNode.cpp
    kv/PutProcessor.cpp
    kv/GetProcessor.cpp
    kv/RemoveProcessor.cpp
)

nebula_add_library(
    internal_storage_service_handler OBJECT
    InternalStorageServiceHandler.cpp
)

nebula_add_library(
    storage_http_handler OBJECT
    http/StorageHttpIngestHandler.cpp
    http/StorageHttpDownloadHandler.cpp
    http/StorageHttpAdminHandler.cpp
    http/StorageHttpStatsHandler.cpp
    http/StorageHttpPropertyHandler.cpp
)

nebula_add_library(
    storage_transaction_executor OBJECT
    transaction/TransactionManager.cpp
    transaction/ConsistUtil.cpp
    transaction/ChainUpdateEdgeProcessorLocal.cpp
    transaction/ChainUpdateEdgeProcessorRemote.cpp
    transaction/ChainResumeProcessor.cpp
    transaction/ChainAddEdgesGroupProcessor.cpp
    transaction/ChainAddEdgesProcessorLocal.cpp
    transaction/ChainAddEdgesProcessorRemote.cpp
    transaction/ResumeAddEdgeProcessor.cpp
    transaction/ResumeAddEdgeRemoteProcessor.cpp
    transaction/ResumeUpdateProcessor.cpp
    transaction/ResumeUpdateRemoteProcessor.cpp
    transaction/ChainProcessorFactory.cpp
)

nebula_add_library(
    storage_server OBJECT
    StorageServer.cpp
)

nebula_add_subdirectory(test)
