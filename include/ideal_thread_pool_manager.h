#ifndef _IDEAL_THREAD_POOL_MANAGER_H_
#define _IDEAL_THREAD_POOL_MANAGER_H_

#include "common.h"

class IdealThreadPool;

class IdealThreadPoolManager {
	public:
		IdealThreadPoolManager* getInstance();
		~IdealThreadPoolManager();

		bool initialize();
		bool finalize();

		

	private:
		IdealThreadPoolManager();
		IdealThreadPoolManager(IdealThreadPool* thread_pool);

		static IdealThreadPoolManager *instance_;
		IdealThreadPool thread_pool_;



		DISALLOW_COPY_AND_ASSIGN(IdealThreadPoolManager);
};

#endif // _IDEAL_THREAD_POOL_MANAGER_H_
