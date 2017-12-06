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

void *start_thread(void *arg) {
	IdealThreadPool *itp = (IdealThreadPool *) arg;
	if (itp) {
		ipt->Run();
	}
}

void Run() {
	for (;;) {
		int s;
		mutex_.lock();
		
		if (s != 0)
			LOG(ERROR);

		while (thread_queue.empty()) {
			cond_.wait(mutex_.getMutex());	
		}

		IdealTaskBase *task = task_queue_->front();
		task_queue_->erase(task_queue_->begin());
		mutex_.unlock();

		task->run();
	}
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

	createThreads();

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
	int s;
	s = mutex_->lock();
	if (s != 0)
		LOG(ERROR);

	task_queue_.push_back(task);
	s = cond_->cond_signal();
	if (s != 0)
		LOG(ERROR);

	s = mutex_->unlock();
	if (s != 0)
		LOG(ERROR);

	return IDEAL_OK;
}

void IdealThreadPool::createThreads() {
	if (thread_num_ <= 0) 
		return ;

	for (int i = 0; i < thread_num_; i++) {
		IdealThreadBase ideal_thread = new IdealThreadBase(start_thread);
		thread_queue_->push_back(ideal_thread);
	}
}

