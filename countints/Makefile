TESTSIZE=20000
INTSIZE=2

GLIB_CFLAGS=$(shell pkg-config --cflags glib-2.0)
GLIB_LDFLAGS=$(shell pkg-config --libs glib-2.0)
OPTIMIZE_C=-O3
OPTIMIZE_CPP=-O3

clean:
	rm -f intlist* testcpp testcpp_stdstring testcpp_hashmap testc_glib

intlist.h:
	bash mkints.sh $(TESTSIZE) $(INTSIZE)
intlist.sh:
	bash mkints.sh $(TESTSIZE) $(INTSIZE)
intlist.py:
	bash mkints.sh $(TESTSIZE) $(INTSIZE)

testc_glib: intlist.h
	gcc $(OPTIMIZE_C) -o testc_glib testc_glib.c $(GLIB_LDFLAGS) $(GLIB_CFLAGS)

testcpp_hashmap: testcpp_hashmap.cpp intlist.h
	g++ $(OPTIMIZE_CPP) -std=c++11 -o testcpp_hashmap testcpp_hashmap.cpp

testcpp: testcpp.cpp intlist.h
	g++ $(OPTIMIZE_CPP) -o testcpp testcpp.cpp

test: testc_glib testcpp testcpp_hashmap intlist.py intlist.sh intlist.js
	@echo "C (glib) $(OPTIMIZE_C)             : " $$(wc -l testc_glib.c) : " " $$(./testc_glib)
	@echo "C++ (std hash_map) $(OPTIMIZE_CPP)   : " $$(wc -l testcpp_hashmap.cpp) : " " $$(./testcpp_hashmap)
	@echo "C++ (std map) $(OPTIMIZE_CPP)        : " $$(wc -l testcpp.cpp) : " " $$(./testcpp)
	@echo "Python                   : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "JavaScript (Node)        : " $$(wc -l testjs.js) : $$(js ./testjs.js)
	@echo "Bash                     : " $$(wc -l testsh.sh) : $$(bash ./testsh.sh)
