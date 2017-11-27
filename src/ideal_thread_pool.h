#ifndef _IDEAL_THREAD_POOL_H_
#define _IDEAL_THREAD_POOL_H_

#include "common.h"

#include <queue>

class IdealTaskBase;
class IdealThreadBase;

/**
 * IdealThreadPool holds a thread queue,
 *
 * and is reponsible for dispatching tasks
 *
 * to appropriate thread.
 *
 */
class IdealThreadPool {

	public:
		IdealThreadPool();
		~IdealThreadPool();

		void setThreadNumber(const int num);
		int getThreadNumber() const;

		Ideal_ERR insertTask(IdealTaskBase* task);
		Ideal_ERR disptachTask(IdealTaskBase *task);

	protected:
		Ideal_ERR initialize();
		void finalize();
		
		// find a reasonable thread from thread queue to 
		// dispatch a task.
		IdealThreadBase* findReasonableThread() const;

	private:

		int thread_num_;
		std::queue<IdealThreadBase *> *thread_queue_;
		std::queue<IdealTaskBase *> *task_queue_;
	
		DISALLOW_COPY_AND_ASSIGN(IdealThreadPool);
};

#endif // _IDEAL_THREAD_POOL_H_
