#ifndef _IDEAL_THREAD_BASE_H_
#define _IDEAL_THREAD_BASE_H

#include "common.h"
#include "ideal_thread.h"

class IdealTaskBase;

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
		IdealThreadBase(const IdealWorkThread &thread);
		IdealThreadBase& operator=(const IdealThreadBase &thread);
		~virtual IdealThreadBase();

		virtual void executeTask() {}
		virtual void pauseTask() {}
		virtual void continueTask() {}
		virtual void threadExit() {}

		virtual IdealThreadState getThreadState();
		
		Ideal_ERR void setCurrentTask(IdealTaskBase *task);

	private:
		IdealThreadState thread_state_;
		IdealTaskBase *current_task_;
		pthread_thread_t *thread_;
};


#endif // _IDEAL_THREAD_BASE_H_
