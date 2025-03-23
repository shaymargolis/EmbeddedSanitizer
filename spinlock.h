#ifndef EMBEDDED_SANITIZER_SPINLOCK_H
#define EMBEDDED_SANITIZER_SPINLOCK_H

#include <pthread.h>
#include <stdio.h>

typedef struct {
    pthread_mutex_t lock;
} spinlock_t;

#define DEFINE_SPINLOCK(name) spinlock_t name = { PTHREAD_MUTEX_INITIALIZER }

typedef unsigned long irq_flags_t;  // Dummy flag type for UML

#define spin_lock_irqsave(lock_, flags) \
    do { \
        pthread_mutex_lock(lock_.lock); \
        flags = 0;  \
    } while(0)

static inline void spin_unlock_irqrestore(spinlock_t *lock, long flags)
{
    pthread_mutex_unlock(&lock->lock);
    (void)flags;  // No real interrupts to restore
}

#endif // EMBEDDED_SANITIZER_SPINLOCK_H
