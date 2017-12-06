#ifndef _IDEAL_TASK_H_
#define _IDEAL_TASK_H_

class IdealTask {
public:
	IdealTask(void (*func_ptr)(void*), void *arg));
	~IdealTask();

	void operator()();
	void run();
private:
	void (*func_ptr_(void*));
	void *arg_;
};

#endif // _IDEAL_TASK_H_
