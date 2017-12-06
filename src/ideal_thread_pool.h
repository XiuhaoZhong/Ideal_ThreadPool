#ifndef _IDEAL_THREAD_POOL_H_
#define _IDEAL_THREAD_POOL_H_

#include "common.h"

#include <vector>

class IdealTaskBase;
class IdealThreadBase;
class IdealMutex;
class IdealCond;

/**
 * IdealThreadPool holds a thread queue,
 *
 * and is reponsible for dispatching tasks
 *
 * to appropriate thread.
 *
 * Thread pool is a singleton.
 *
 */
class IdealThreadPool {
public:
	IdealThreadPool();
	IdealThreadPool(int thread_num, int max_thread_num);
	~IdealThreadPool();

	// thread number in normal.
	void setThreadNumber(const int num);
	int getThreadNumber() const;

	// max thread number in busy.
	void setMaxNumber(const int max);
	int getMaxNumber() const;

	// insert task into task_queue_ when there 
	// is not idle thread and thread num is max.
	Ideal_ERR insertTask(IdealTaskBase* task);

	void Run();

protected:
	Ideal_ERR initialize();
	Ideal_ERR finalize();

	void createThreads();

private:
	int thread_num_;
	int max_thread_num_;
	IdealMutex *mutex_;
	IdealCond *cond_;
	std::vector<IdealThreadBase *> *thread_queue_;
	std::vector<IdealTaskBase *> *task_queue_;

	DISALLOW_COPY_AND_ASSIGN(IdealThreadPool);
};

#endif // _IDEAL_THREAD_POOL_H_
