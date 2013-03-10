#include <map>
#include <sys/timeb.h>
#include <iostream>
#include "intlist.h"

int main(void)
{
    std::map<int, int> intcounts;
    std::map<int, int>::iterator iter;
    int cur;
    timeb end;
    timeb start;

    ftime(&start);
    for ( int i = 0; i < INTLISTSIZE ; i++ ) {
	cur = intlist[i];
	iter = intcounts.find(cur);
	if ( iter == intcounts.end() ) {
	    intcounts[cur] = 1;
	} else {
	    intcounts[cur] = intcounts[cur] + 1;
	}
    }
    ftime(&end);
    std::cout << "Over "
	      << INTLISTSIZE
	      << " elements : "
	      << (((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm))
	      << " milliseconds"
	      << std::endl;
}
