#ifndef _IDEAL_THREAD_H_
#define _IDEAL_THREAD_H_

#include "common.h"

/**
 * IdealThread define all the interfaces 
 *
 * to thread operations.
 *
 */
class IdealThread {
	public:
		IdealThread();
		virtual ~IdealThread();

		virtual void executeTask() = 0;
		virtual void pauseTask() = 0;
		virtual void continueTask() = 0;
		virtual void threadExit() = 0;
		
		virtual IdealThreadState getThreadState() const = 0;
};

#endif // _IDEAL_THREAD_H_
