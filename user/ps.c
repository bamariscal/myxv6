/*
 * Skeleton code for ps.c
 */
#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"


int
main(int argc, char **argv)
{

  struct uproc uproc[NPROC];
  struct uproc *up;
  int nprocs;
  
  static char *states[] = {
  [UNUSED]    "unused",
  [SLEEPING]  "sleep ",
  [RUNNABLE]  "runble",
  [RUNNING]   "run   ",
  [ZOMBIE]    "zombie",
   };

  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);

  printf("Pid\tState\tSize\tParent\tName\n");
  for(up = uproc; up < &uproc[nprocs]; up++){
   printf("%d\t%s\t%d\t%d\t%s\n",up->pid,states[up->state], up->size, up->ppid,up->name);
}


  exit(0);
}

