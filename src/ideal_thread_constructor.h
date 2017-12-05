#ifndef _IDEAL_THREAD_CONSTRUCTOR_H
#define _IDEAL_THREAD_CONSTRUCTOR_H

#include <pthread>

/**
 *
 * The header defines the functions to construct 
 *
 * thread with different parameters.
 *
 */

/**
 * Create a default thread.
 *
 */
pthread_t create_ideal_thread();

/**
 * Create a thread with attributeion attr.
 *
 */
pthread_t create_ideal_thread(pthread_attr_t attr);

/**
 * destory a thread.
 *
 */
void destory_ideal_thread(pthread_t thread);

#endif // _IDEAL_THREAD_CONSTRUCTOR_H_
