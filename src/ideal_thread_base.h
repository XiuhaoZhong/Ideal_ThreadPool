#ifndef _IDEAL_THREAD_BASE_H_
#define _IDEAL_THREAD_BASE_H

#include "common.h"
#include "ideal_thread.h"

/**
 * IdealThreadBase is all the threads' base,
 *
 * provides the default implementation for
 *
 * all the interfaces defined by IdealThread,
 *
 * Keeps a task is going to be executed and 
 *
 * a posix thread to execute the task.
 *
 */
class IdealThreadBase : public IdealThread {
	public:
		IdealThreadBase(threadFunc func);
		IdealThreadBase(threadFunc func, pthread_attr_t);
		IdealThreadBase(const IdealWorkThread &thread);
		IdealThreadBase& operator=(const IdealThreadBase &thread);
		~virtual IdealThreadBase();
		
		void join();

		virtual IdealThreadState getThreadState();
		
	private:
		IdealThreadState thread_state_;
		pthread_thread_t thread_;
		bool is_joined_;
};


#endif // _IDEAL_THREAD_BASE_H_
