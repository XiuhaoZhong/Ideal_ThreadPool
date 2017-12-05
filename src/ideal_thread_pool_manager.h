#ifndef _IDEAL_THREAD_POOL_MANAGER_H_
#define _IDEAL_THREAD_POOL_MANAGER_H_

#include "common.h"

class IdealThreadPool;
class IdealTaskBase;

class IdealThreadPoolManager {
	public:
		IdealThreadPoolManager* getInstance();
		~IdealThreadPoolManager();

		Ideal_ERR insertTaskIntoThreadPool(IdealTaskBase* task);
		
	protected:
		IdealThreadPool* getIdealThreadPool() const;
		Ideal_ERR initialize();
		Ideal_ERR finalize();

	private:
		IdealThreadPoolManager();
		IdealThreadPoolManager(IdealThreadPool* thread_pool);

		static IdealThreadPoolManager *instance_;
		IdealThreadPool thread_pool_;
};

#endif // _IDEAL_THREAD_POOL_MANAGER_H_
