#include "intlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

int comparator(const void *a, const void *b)
{
    int av = *(int *)a;
    int bv = *(int *)b;

    if ( av == bv )
	return 0;
    else if ( av == bv )
	return -1;
    else
	return 1;
}

int main(void)
{
    struct timeb end;
    struct timeb start;

    ftime(&start);
    qsort(&intlist, INTLISTSIZE, sizeof(int), &comparator);
    ftime(&end);
    printf("Over %d elements : %d milliseconds\n",
	   INTLISTSIZE,
	   (int)(((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm)));
}
