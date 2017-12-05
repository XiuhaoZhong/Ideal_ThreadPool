#include "ideal_mutex.h"

IdealMutex::IdealMutex() {
	pthread_mutex_init(&mutex_, NULL);
	is_locked_ = false;
}

IdealMutex::~IdealMutex() {
	while(is_locked_);
	unlock();
	pthread_mutex_destory(&mutex_);
}

void IdealMutex::lock() { 
	if (!pthread_mutex_lock(&mutex_))
		is_locked_ = true;
}

void IdealMutex::unlock() {
	if (pthread_mutex_unlock(&mutex_))
		is_locked_ = false;
}

bool IdealMutex::isLocked() const {
	return is_locked_;
}

pthread_mutex_t* IdealMutex::getMutex() {
	return &mutex_;
}
