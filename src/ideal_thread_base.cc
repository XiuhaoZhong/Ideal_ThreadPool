#include "ideal_thread_base.h"

IdealThreadbase::IdealThreadBase(threadFunc func)
							: thread_state_()
							, thread_(0)
							, is_joined_(false) {
	if (pthread_create(&thread, NULL, func, void *arg) != 0)
		LOG(ERROR);
}

IdealThreadBase::IdealThreadBase(threadFunc func, pthread_attr_t p_attr)
							: thread_state()
							, thread_(0)
							, is_joined_(false) {
	if (pthread_create(&thread, &p_attr, func, void *arg) != 0)
		LOG(ERROR);
}

IdealThreadBase::IdealThreadBase(const IdealThreadBase &thread) {
	if (this != &thread) {
		this.thread_state_ = thread.thread_state_;
		this.thread_ = thread.thread_;
	}

	return *this;
}

IdealThreadBase& operator=(const IdealThreadBase &thread) {
	thread_state_ = thread.thread_state_;
	thread_ = thread.thread_;

	return *this;
}

IdealThreadBase::~IdealThreadBase() {
	join();
}

void IdealThreadBase::join() {
	if (!is_joined_) {
		void *result;
		pthread_join(thread_, &result);
		is_joined_ = true;
	}
}
