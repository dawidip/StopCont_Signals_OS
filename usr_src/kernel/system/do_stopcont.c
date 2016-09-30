#include "kernel/system.h"
#include <minix/endpoint.h>
#include <unistd.h>

/*=================================*
 *
 *				do_stopcont
 *
 *				Pyczek
 *
 *	=================================*/


int do_stopcont(struct proc *caller_ptr, message *m_ptr)
{
    proc_nr_t proc_nr, proc_nr_e;
    register struct proc * rp;

    proc_nr_e= (proc_nr_t) m_ptr->m1_i1;        
    if (!isokendpt(proc_nr_e, &proc_nr)) return(EINVAL);
    if (iskerneln(proc_nr)) return(EPERM);
    rp = proc_addr(proc_nr);
    
    if(m_ptr->m1_i2 == 0) 
        RTS_SET( rp , RTS_P_STOP);
    else if(m_ptr->m1_i2 == 1)
        RTS_UNSET( rp , RTS_P_STOP);

    return (OK);
}
