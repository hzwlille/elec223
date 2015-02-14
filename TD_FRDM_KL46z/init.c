extern long  _bend, _bstart;
#include<stdio.h>
void init_bss()
{
  long*  dst;
  static int a;
  static int b; 
  for(dst= &_bstart; dst< &_bend; dst=dst+4)
    *dst=0;
}
