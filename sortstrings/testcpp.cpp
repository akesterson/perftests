#include "stringlist.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <sys/timeb.h>

int main(void)
{
    struct timeb end;
    struct timeb start;
    std::array<std::string, STRINGLISTSIZE> strings;
    int i = 0;

    for ( ; i < STRINGLISTSIZE ; i++ ) {
	strings[i].assign(stringlist[i]);
    }

    ftime(&start);
    std::sort(strings.begin(), strings.end());
    ftime(&end);
    std::cout << "Over "
	      << STRINGLISTSIZE
	      << " elements : "
	      << (((end.time * 1000) + end.millitm) - ((start.time * 1000) + start.millitm))
	      << " milliseconds"
	      << std::endl;
}
