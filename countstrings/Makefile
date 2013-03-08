TESTSIZE=19999
STRINGSIZE=2

GLIB_CFLAGS=$(shell pkg-config --cflags glib-2.0)
GLIB_LDFLAGS=$(shell pkg-config --libs glib-2.0)
OPTIMIZE_C=-O0
OPTIMIZE_CPP=-O0
clean:
	rm -f stringlist* testcpp testcpp_stdstring

stringlist.h:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)
stringlist.sh:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)
stringlist.py:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)

testc_glib: stringlist.h
	gcc $(OPTIMIZE_C) -o testc_glib testc_glib.c $(GLIB_LDFLAGS) $(GLIB_CFLAGS)

testc_judy: stringlist.h testc_judy.c
	gcc $(OPTIMIZE_C) -o testc_judy testc_judy.c -lJudy

testcpp_hashmap: testcpp_hashmap.cpp stringlist.h
	g++ $(OPTIMIZE_CPP) -std=c++11 -o testcpp_hashmap testcpp_hashmap.cpp

testcpp_stdstring: testcpp_stdstring.cpp stringlist.h
	g++ $(OPTIMIZE_CPP) -o testcpp_stdstring testcpp.cpp

testcpp: testcpp.cpp stringlist.h
	g++ $(OPTIMIZE_CPP) -o testcpp testcpp.cpp

test: testc_glib testc_judy testcpp testcpp_hashmap testcpp_stdstring stringlist.py stringlist.sh
	@echo "C (glib, char *) $(OPTIMIZE_C)     : " $$(wc -l testc_glib.c) : " " $$(./testc_glib)
	@echo "C (Judy, char *) $(OPTIMIZE_C)     : " $$(wc -l testc_judy.c) : " " $$(./testc_judy)
	@echo "C++ (std string) $(OPTIMIZE_CPP)     : " $$(wc -l testcpp_stdstring.cpp) : " " $$(./testcpp_stdstring)
	@echo "C++ (std hash_map) $(OPTIMIZE_CPP)  : " $$(wc -l testcpp_hashmap.cpp) : " " $$(./testcpp_stdstring)
	@echo "C++ (const char *) $(OPTIMIZE_CPP)  : " $$(wc -l testcpp.cpp) : " " $$(./testcpp)
	@echo "Python              : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "JavaScript (Node)   : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "Bash             : " $$(wc -l testsh.sh) : $$(bash ./testsh.sh)
