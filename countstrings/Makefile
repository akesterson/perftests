TESTSIZE=19999
STRINGSIZE=2

GLIB_CFLAGS=$(shell pkg-config --cflags glib-2.0)
GLIB_LDFLAGS=$(shell pkg-config --libs glib-2.0)

clean:
	rm -f stringlist* testcpp testcpp_stdstring

stringlist.h:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)
stringlist.sh:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)
stringlist.py:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)

testc_glib: stringlist.h
	gcc -o testc_glib testc_glib.c $(GLIB_LDFLAGS) $(GLIB_CFLAGS)

testcpp_stdstring: testcpp_stdstring.cpp stringlist.h
	g++ -o testcpp_stdstring testcpp.cpp

testcpp: testcpp.cpp stringlist.h
	g++ -o testcpp testcpp.cpp

test: testcpp testcpp_stdstring stringlist.py stringlist.sh
	@echo "C (glib, char *)   : " $$(wc -l testc_glib.c) : " " $$(./testc_glib)
	@echo "C++ (std string)   : " $$(wc -l testcpp_stdstring.cpp) : " " $$(./testcpp_stdstring)
	@echo "C++ (const char *) : " $$(wc -l testcpp.cpp) : " " $$(./testcpp)
	@echo "Python             : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "Bash               : " $$(wc -l testsh.sh) : $$(bash ./testsh.sh)