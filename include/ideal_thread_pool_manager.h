#ifndef _IDEAL_THREAD_POOL_MANAGER_H_
#define _IDEAL_THREAD_POOL_MANAGER_H_

#include "common.h"

class IdealThread;

class IdealThreadPoolManager {
	public:
		IdealThreadPoolManager* getInstance();
		~IdealThreadPoolManager();

		bool initialize();
		bool finalize();

		void addThread(IdealThread *thread);
		IdealThread* getThread() const;


	protected:

	private:
		IdealThreadPoolManager();

		static IdealThreadPoolManager *instance_;

		IdealThread *current_thread_;
		Queue<IdealThread *> thread_queue_;
};

#endif // _IDEAL_THREAD_POOL_MANAGER_H_
