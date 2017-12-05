#include "ideal_cond.h"
#include "ideal_mutex.h"

IdealCond::IdealCond() {
	pthread_cond_init(&cond_, NULL);
}

IdealCond::~IdealCond() {
	pthread_cond_destory(&cond_);
}

void IdealCond::cond_signal() {
	pthread_cond_signal(&cond_);
}

void IdealCond::cond_broadcast() {
	pthread_cond_broadcast(&cond_);
}

void IdealCond::wait(pthread_mutex_t *mutex) {
	pthread_cond_wait(&cond, mutex);
}
