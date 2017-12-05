#include "ideal_thread_constructor.h"

void *(*start)(void *arg);

pthread_t create_ideal_thread() {
	pthread_t thread;
	if (pthread_create(&thread, NULL, start, NULL) == 0)
		return thread;
	return -1;
}

pthread_t create_ideal_thread(pthread_attr_t attr) {
	pthread_t thread;
	if (pthread_create(&thread, &attr, start, NULL) == 0) 
		return thread;
	return -1;
}

void destory_ideal_thread(pthread_t thread) {
	
}
