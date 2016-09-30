#include "pm.h"
#include <minix/callnr.h>
#include <signal.h>
#include <sys/svrctl.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <minix/com.h>
#include <minix/config.h>
#include <minix/sysinfo.h>
#include <minix/type.h>
#include <minix/vm.h>
#include <string.h>
#include <machine/archtypes.h>
#include <lib.h>
#include <assert.h>
#include "mproc.h"
#include "param.h"

#include <minix/endpoint.h>
#include <unistd.h>


// Pyczek

int get_pids() {
    int n = 0, i = 0;
    pid_t stopped_procs[NR_PROCS];

    for (i = 0; i < NR_PROCS; ++i) {
        struct mproc *rmp = mproc + i;
        if(rmp->mp_flags & MY_SIGSTOP)
            stopped_procs[n++] = rmp->mp_pid;
    }

    if(sys_vircopy(SELF, (phys_bytes) stopped_procs, mp->mp_endpoint,
            (phys_bytes) m_in.m1_i1, (phys_bytes) (n * sizeof(pid_t))) != 0)
        return EINVAL;
    
    return n;
}


    

