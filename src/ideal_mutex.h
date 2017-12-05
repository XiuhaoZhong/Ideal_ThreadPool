#ifndef _IDEAL_MUTEX_H_
#define _IDEAL_MUTEX_H_

#include "common.h"

class IdealMutex {
public:
	IdealMutex();
	~IdealMutex();

	void lock();
	void unlock();
	bool isLocked() const;
	pthread_mutex_t* getMutex();

private:
	pthread_mutex_t mutex_;
	bool is_locked_;

	DISALLOW_COPY_AND_ASSGIN(IdealMutex);
};

#endif // _IDEAL_MUTEX_H_
