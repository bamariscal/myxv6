#include "types.h"
#include "riscv.h"
#include "param.h"
#include "defs.h"
#include "spinlock.h"

struct semtab semtable;

void
seminit(void)
{
   initlock(&semtable.lock, "semtable");
   for (int i = 0; i < NSEM; i++)
     initlock(&semtable.sem[i].lock, "sem");
}

int 
semalloc(void)
{  
  for (int i = 0; i < NSEM; i++){
    acquire(&semtable.lock);
    if(semtable.sem[i].valid ==0){
      release(&semtable.lock);
      return i;
    }
  }
    release(&semtable.lock);
    return -1;
}

int 
semdealloc(int index)
{
  acquire(&semtable.lock);
  semtable.sem[index].valid = 0;
  release(&semtable.lock);
  return 0;

}
