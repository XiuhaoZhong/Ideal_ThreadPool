#include "ideal_task.h"

IdealTask::IdealTask(void (*fun_ptr)(void*), void *arg))
										: func_ptr_(fun_ptr)
										, arg_(arg) {


}

void IdealTask::operator()() {
	if (func_ptr_)
		func_ptr_(arg_);

	if (arg) {
		delete arg;
		arg = NULL;
	}
}

void IdealTask::run() {
	if (func_ptr_)
		(func_ptr_)(arg_);
}
