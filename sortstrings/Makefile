TESTSIZE=20000
STRSIZE=2

OPTIMIZE_C=-O2
OPTIMIZE_CPP=-O2

clean:
	rm -f intlist* testcpp testc

stringlist.h:
	bash mkints.sh $(TESTSIZE) $(STRSIZE)
stringlist.sh:
	bash mkints.sh $(TESTSIZE) $(STRSIZE)
stringlist.py:
	bash mkints.sh $(TESTSIZE) $(STRSIZE)

testc: stringlist.h
	gcc $(OPTIMIZE_C) -o testc testc.c

testcpp: testcpp.cpp stringlist.h
	g++ $(OPTIMIZE_CPP) --std=c++11 -o testcpp testcpp.cpp

test: testc testcpp stringlist.py stringlist.sh stringlist.js
	@echo "C $(OPTIMIZE_C)                    : " $$(wc -l testc.c) : " " $$(./testc)
	@echo "C++ $(OPTIMIZE_CPP)                  : " $$(wc -l testcpp.cpp) : " " $$(./testcpp)
	@echo "Python                   : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "JavaScript (Node)        : " $$(wc -l testjs.js) : $$(js ./testjs.js)
	@echo "Bash                     : " $$(wc -l testsh.sh) : $$(bash ./testsh.sh)
