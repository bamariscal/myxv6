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
  int nprocs;

  /********************************
   * Add any additional variables or data structures you will need
   ********************************/



  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);

  // You can remove the following print statement
  printf("%d processes\n", nprocs);

  /*********************************
   * Add your code here to output information returned by getprocs()
   * Hint: see procdump() code in kernel/console.c, except that here
   * you will be outputting the first nprocs elements of the uproc array
   * and all will have active states.
   *********************************/ 





  exit(0);
}

