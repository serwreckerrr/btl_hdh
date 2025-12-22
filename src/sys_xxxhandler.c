// From src/sys_xxxhandler.c
#include "common.h"
#include "syscall.h"
#include "stdio.h"

int __sys_xxxhandler(struct krnl_t *caller,
                     arg_t a1, arg_t a2, arg_t a3,
                     arg_t a4, arg_t a5, arg_t a6)
{
    /* Reconstruct sc_regs locally so old-style code can use regs->a1 etc. */
    struct sc_regs regs_local;

    regs_local.a1 = a1;
    regs_local.a2 = a2;
    regs_local.a3 = a3;
    regs_local.a4 = a4;
    regs_local.a5 = a5;
    regs_local.a6 = a6;

    /* orig_ax and flags are not passed by the dispatcher currently.
       Initialize to sensible defaults. */
    regs_local.orig_ax = 0;
    regs_local.flags = 0;

    /* Example: print the first syscall parameter using project's macro */
    printf("The first system call parameter " FORMAT_ARG "\n", regs_local.a1);

    /* Implement your syscall handling logic here, using regs_local.* or a1..a6 */

    return 0;
}







// // From src/sys_xxxhandler.c
// #include "common.h"
// #include "syscall.h"
// #include "stdio.h"

// int __sys_xxxhandler(struct pcb_t *caller, struct sc_regs* regs)
// {
//     /* TODO: implement syscall job */
//     printf("The first system call parameter %d\n", regs->a1);
//     return 0;
// }



// #include "common.h"
// #include "syscall.h"
// #include "stdio.h"

// int __sys_xxxhandler(struct pcb_t *caller, struct sc_regs* reg)
// {
//     /* TODO: implement syscall job */
//     printf("The first system call parameter %d\n", regs->a1);
//     return 0;
// }
