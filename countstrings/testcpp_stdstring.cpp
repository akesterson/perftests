#include <map>
#include <sys/timeb.h>
#include <iostream>
#include <string>
#include "stringlist.h"

int main(void)
{
    std::map<std::string, int> stringcounts;
    std::map<std::string, int>::iterator iter;
    std::string stdstrings[STRINGLISTSIZE];
    const char *cur;
    timeb end;
    timeb start;

    for ( int i = 0; i < STRINGLISTSIZE ; i++ ) {
	cur = stringlist[i];
	stdstrings[i].assign(cur);
    }

    ftime(&start);
    for ( int i = 0; i < STRINGLISTSIZE ; i++ ) {
	cur = stdstrings[i];
	iter = stringcounts.find(cur);
	if ( iter == stringcounts.end() ) {
	    stringcounts[cur] = 1;
	} else {
	    stringcounts[cur] = stringcounts[cur] + 1;
	}
    }
    ftime(&end);
    std::cout << "Over "
	      << STRINGLISTSIZE
	      << " elements :"
	      << (((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm))
	      << " milliseconds "
	      << std::endl;
}
