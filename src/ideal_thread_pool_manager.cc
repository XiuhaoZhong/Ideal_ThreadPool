#include "ideal_thread_pool_manager.h"

IdealThreadPoolManager::instance_ = NULL;

IdealTHreadPoolManager::getInstance() {
	if (!instance_)
		instance_ = new IdealThreadPoolManager();

	return instance_;
}

IdealThreadPoolManager::IdealThreadPoolManager():thread_pool_(NULL) {
	initialize();
}

IdealThreadPoolManager::IdealThreadPoolManager(IdealThreadPool* thread_pool):
	thread_pool_(thread_pool) {
	initialize();	
}

IdealThreadPoolManager::~IdealThreadPoolManager() {
	finalize();
}

Ideal_ERR IdealThreadPoolManager::initialize() {
	Ideal_ERR ret = IDEAL_OK;

	if (!thread_pool_) 
		thread_pool_ = new IdealThreadPool();

	return ret;
}

void IdealThreadPoolManager::finalize() {
	if (threaf_pool_) {
		delete thread_pool_;
		thread_pool = NULL;
	}
}

IdealThreadPool* IdealThreadPoolManager::getIdealThreadPool() const {
	return thread_pool_;
}

Ideal_ERR IdealThreadPoolManager::insertTaskIntoThreadPool(const IdealTaskBase *task) {
	if (!thread_pool_)
		return IDEAL_GENNERIC_ERROR;

	thread_pool_->insertTask(task);

	return IDEAL_OK;
}
