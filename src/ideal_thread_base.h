#ifndef _IDEAL_THREAD_BASE_H_
#define _IDEAL_THREAD_BASE_H

#include "common.h"
#include "ideal_thread.h"

class IdealTaskBase;

/**
 * thread's running function
 *
 * thread runs the function, in this function,
 * 
 * thread get task from thread pool's task 
 *
 * queue, and run it.
 *
 */
void* (* threadFunc)(void *arg);

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
		IdealThreadBase();
		IdealThreadBase(pthread_attr_t);
		IdealThreadBase(const IdealWorkThread &thread);
		IdealThreadBase& operator=(const IdealThreadBase &thread);
		~virtual IdealThreadBase();

		virtual void start();
		virtual void destory();

		virtual IdealThreadState getThreadState();
		
		Ideal_ERR void setCurrentTask(IdealTaskBase *task);

		// thread exxcutes the function once be created.
		void* run(void *arg);

	private:
		IdealThreadState thread_state_;
		IdealTaskBase *current_task_;
		pthread_thread_t thread_;
};


#endif // _IDEAL_THREAD_BASE_H_
