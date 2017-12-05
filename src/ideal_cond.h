#ifndef _IDEAL_COND_H_
#define _IDEAL_COND_H_

class IdealCond {
public:
	IdealCond();
	~IdealCond();

	void cond_signal();
	void cond_broadcast();
	void cond_wait();

private:
	pthread_cond_t cond_;

	DISALLOW_COPY_AND_ASSGIN(IdealCond);
};

#endif // _IDEAL_COND_H_
