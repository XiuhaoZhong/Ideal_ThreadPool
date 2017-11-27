/*
 * This file function:
 *
 * 1. includes common headers for all the files;
 * 2. define base structs in the projects.
 * 3. macros' definition.
 *
 * */

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&) {} \
	void operator=(const TypeName&){};

#define LOG(ERROR) (printf("%s: [%d, %s] failed", __FILE__, __LINE__, __FUNCTION__)) 

enum IdealThreadState {
	IDLE = 0,
	RUNNING,
	PAUSE,
	EXCEPTION
}

enum Ideal_ERR {
	IDEAL_OK = 0,
	IDEAL_GENERIC_ERROR,
	IDEAL_INITIALIZE_ERROR;
	IDEAL_FINALIZE_ERROR;
	IDEAL_NO_THREAD_USE
}

#endif // _COMMON_h_
