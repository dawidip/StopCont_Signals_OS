#include "syslib.h"
//  Pyczek
int sys_stopcont(int pid, int flag)
{
	message m;
    m.m1_i1 = pid;
    m.m1_i2 = flag;
	return (_kernel_call(SYS_STOPCONT, &m));
}
