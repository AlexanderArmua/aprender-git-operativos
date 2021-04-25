# ORQUESTADOR DE MAKES

SRC_ROUTE := src
TEST_ROUTE := $(SRC_ROUTE)/tests/unit-tests

all: 
	-cd $(SRC_ROUTE) && $(MAKE) all
	-cd $(TEST_ROUTE) && $(MAKE) all
	-echo FIN

#clean:
#	-cd $(SRC_ROUTE) && $(MAKE) clean
#	-cd $(TEST_ROUTE) && $(MAKE) clean

#debug:
#	-cd $(SRC_ROUTE) && $(MAKE) debug
#	-cd $(TEST_ROUTE) && $(MAKE) debug

test:
	-cd $(TEST_ROUTE) && $(MAKE) test

#install: test
#	-cd $(SRC_ROUTE) && $(MAKE) install

#uninstall:
#	-cd $(SRC_ROUTE) && $(MAKE) uninstall

valgrind: all
	-cd $(TEST_ROUTE) && $(MAKE) valgrind
