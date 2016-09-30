#define __USE_MISC
#define _SYSTEM	1
#define _MINIX 1

#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"

#include <lib.h>
#include <minix/rs.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

// Pyczek


int get_stopped_procs(pid_t * buf){
    message m;
    m.m1_i1 = buf;

    return _syscall(PM_PROC_NR, 105, &m);
}


