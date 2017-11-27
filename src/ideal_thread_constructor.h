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
pthread_thread_t create_ideal_thread();

/**
 * Create a thread with attributeion attr.
 *
 */
pthread_thread_t create_ideal_thread(pthread_attr_t attr);

#endif // _IDEAL_THREAD_CONSTRUCTOR_H_
