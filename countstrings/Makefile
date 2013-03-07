TESTSIZE=10000
STRINGSIZE=2

clean:
	rm -f stringlist* testcpp testcpp_stdstring

stringlist.h:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)
stringlist.sh:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)
stringlist.py:
	bash mkstrings.sh $(TESTSIZE) $(STRINGSIZE)

testcpp_stdstring: testcpp_stdstring.cpp stringlist.h
	g++ -o testcpp_stdstring testcpp.cpp

testcpp: testcpp.cpp stringlist.h
	g++ -o testcpp testcpp.cpp

test: testcpp testcpp_stdstring stringlist.py stringlist.sh
	@echo "C++ (std string)   : " $$(wc -l testcpp_stdstring.cpp) : " " $$(./testcpp_stdstring)
	@echo "C++ (const char *) : " $$(wc -l testcpp.cpp) : " " $$(./testcpp)
	@echo "Python             : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "Bash               : " $$(wc -l testsh.sh) : $$(bash ./testsh.sh)