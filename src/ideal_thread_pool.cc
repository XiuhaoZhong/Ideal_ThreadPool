#include "ideal_thread_pool.h"
#include "ideal_mutex.h"
#include "ideal_cond.h"

IdealThreadPool::IdealThreadPool(): thread_num_(0)
																	, max_thread_num_(0) {
	if (initialize() != IDEAL_OK)
		LOG(ERROR);
}

IdealThreadPool::IdealThreadPool(int thread_num, int max_thread_num)
															: thread_num_(thread_num)
															, max_thread_num_(max_thread_num) {

	if (initialize() != IDEAL_OK)
		LOG(ERROR);
}
																

IdealThreadPool::~IdealThreadPool() {
	if (finalize() != IDEAL_OK)
		LOG(ERROR);
}

Ideal_ERR IdealThreadPool::initialize() {
	thread_queue_ = new std::vector<IdealThreadBase *>();
	task_queue_ = new std::vector<IdealTaskBase *>();

	mutex_ = new IdealMutex();
	cond_ = new IdealCond();

	return IDEAL_OK;
}

Ideal_ERR IdealThreadPool::finalize() {
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

	return IDEAL_OK;
}

void IdealThreadPool::setThreadNumber(const int num) {
	thread_num_ = num;	
}

int IdealThreadPool::getThreadNumber() const {
	return thread_num_;
}

void IdealThreadPool::setMaxNumber(int max) {
	max_thread_num_ = max;
}

int IdealThreadPool::getMaxNumber() const {
	return max_thread_num_;
}

Ideal_ERR IdealThreadPool::insertTask(IdealTaskBase *task) {

	return IDEAL_OK;
}

Ideal_ERR IdealThreadPool::dispatchTask(IdealTaskBase *task) {

	return IDEAL_OK;
}

IdealThreadBase* IdealThreadPool::getIdleThread() const {

	return IdealThreadBase();
}
