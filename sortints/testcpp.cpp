#include "intlist.h"
#include <iostream>
#include <cstdlib>
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
    std::cout << "Over "
	      << INTLISTSIZE
	      << " elements : "
	      << (((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm))
	      << " milliseconds"
	      << std::endl;
}
