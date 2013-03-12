TESTSIZE=20000
INTSIZE=2

OPTIMIZE_C=-O0
OPTIMIZE_CPP=-O0

clean:
	rm -f intlist* testcpp testc

intlist.h:
	bash mkints.sh $(TESTSIZE) $(INTSIZE)
intlist.sh:
	bash mkints.sh $(TESTSIZE) $(INTSIZE)
intlist.py:
	bash mkints.sh $(TESTSIZE) $(INTSIZE)

testc: intlist.h
	gcc $(OPTIMIZE_C) -o testc testc.c

testcpp: testcpp.cpp intlist.h
	g++ $(OPTIMIZE_CPP) -o testcpp testcpp.cpp

test: testc testcpp intlist.py intlist.sh intlist.js
	@echo "C $(OPTIMIZE_C)                    : " $$(wc -l testc.c) : " " $$(./testc)
	@echo "C++ $(OPTIMIZE_CPP)                  : " $$(wc -l testcpp.cpp) : " " $$(./testcpp)
	@echo "Python                   : " $$(wc -l testpy.py) : $$(python ./testpy.py)
	@echo "JavaScript (Node)        : " $$(wc -l testjs.js) : $$(js ./testjs.js)
	@echo "Bash                     : " $$(wc -l testsh.sh) : $$(bash ./testsh.sh)
