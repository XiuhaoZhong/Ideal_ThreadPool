#include "ideal_thread_base.h"

IdealThreadbase::IdealThreadBase()
							: thread_state_()
							,	currrent_task_(NULL)
							, thread_(0) {
	if (pthread_create(&thread, NULL, run, void *arg) != 0)
		LOG(ERROR);
}

IdealThreadBase::IdealThreadBase(const IdealThreadBase &thread) {
	if (this != &thread) {
		this.thread_state_ = thread.thread_state_;
		this.current_task_ = new IdealTaskBase();
		this.current_task_ = thread.current_task_;
		this.thread_ = thread.thread_;
	}

	return *this;
}

IdealThreadBase& operator=(const IdealThreadBase &thread) {
	if (this->current_task_ != NULL)
		delete current_task_;

	current_task_ = new IdealTaskBase();
	*current_task_ = *thread.current_task_;
	thread_state_ = thread.thread_state_;
	thread_ = thread.thread_;

	return *this;
}

IdealThreadBase::~IdealThreadBase() {
	if (current_task_) {
		delete current_task_;
		current_task_ = NULL;
	}
}

void IdealThreadBase::start() {

}

void IdealThreadBase::destory() {

}

void* IdealThread::run(void *arg) {
	
}
