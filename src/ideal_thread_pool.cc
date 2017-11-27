#include "ideal_thread_pool.h"

IdealThreadPool::IdealThreadPool(): thread_num_(0) {
	thread_queue_ = new std::queue<IdealThreadBase *>();
	task_queue_ = new std::queue<IdealTaskBase *>();

	if (initialize() != IDEAL_OK)
		LOG(ERROR);
}

IdealThreadPool::~IdealThreadPool() {
	// before delete the task_queue,
	// be sure that the task_que
	while(!task_queue_.empty()) {
		break;
	}

	delete task_queue_;
	task_queue_ = NULL;

	// thread_queue's delete needs to 
	// study further.
	delete thread_queue_;
	thread_queue = NULL;
}

Ideal_ERR IdealThreadPool::initialize() {

	return IDEAL_OK;
}

void IdealThreadPool::finalize() {

}

void IdealThreadPool::setThreadNumber(const int num) {
	thread_num_ = num;	
}

int IdealThreadPool::getThreadNumber() const {
	return thread_num_;
}

Ideal_ERR IdealThreadPool::insertTask(IdealTaskBase *task) {

	return IDEAL_OK;
}

Ideal_ERR IdealThreadPool::dispatchTask(IdealTaskBase *task) {

	return IDEAL_OK;
}
