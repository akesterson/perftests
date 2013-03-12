#include "stringlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

int comparator(const void *a, const void *b)
{
    char const *aa = (char const *)a;
    char const *bb = (char const *)b;

    return strcmp(aa, bb);
}

int main(void)
{
    struct timeb end;
    struct timeb start;

    ftime(&start);
    qsort(&stringlist, STRINGLISTSIZE, sizeof(char *), &comparator);
    ftime(&end);
    printf("Over %d elements : %d milliseconds\n",
	   STRINGLISTSIZE,
	   (int)(((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm)));
}
