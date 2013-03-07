#include <Judy.h>
#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>

#include "stringlist.h"

int main()
{
  struct timeb start;
  struct timeb end;

  void *map = NULL;

  ftime(&start);
  size_t i = 0;
  for (; i < STRINGLISTSIZE; i++) {
    size_t *value = NULL;

    JSLI(value, map, stringlist[i]);
    if (value != NULL) {
      *value = *value + 1;
    }
    else {
      *value = 0;
    }
  }
  ftime(&end);

  printf("Over %d elements : %d milliseconds\n",
      STRINGLISTSIZE,
      (int)(((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm)));

  return 0;
}
