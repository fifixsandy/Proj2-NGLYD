CC=g++
TEAM=my_sme_tim
CMAKE = cmake
BUILD_DIR = build
GTEST_URL := https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
GTEST_ZIP := googletest.zip
GTEST_DIR := googletest
TEAM_PACK_NAME = xnovakf00_xskovaj00_xmalegt00_xfignam00

.PHONY: profile test pack clean run doc

all: profile calc test_compile


calc:
	@cd GUI && mkdir -p build && cd build && cmake .. && make -s 

run: calc
	@cd GUI/build/ && ./Calculator


profile:
	@echo "Building profiling..."
	@cd PROFILING && $(CC) -g -o  stddev *.cpp ../LIBS/*.cpp >/dev/null 2>&1
	@echo "Profiling compilation completed."


test: test_compile
	cd TESTS/build && ./mathTest 

test_compile:
	@cd TESTS && mkdir -p build && cd build && cmake .. && make -s 

	
doc:
	doxygen Doxyfile 


clean:
	@rm -rf ./TESTS/build/ ./PROFILING/stddev ./GUI/build/ ./doc/ ./doxygenWarning.txt


pack: clean
	mkdir ../../$(TEAM_PACK_NAME)
	mkdir -p ../../$(TEAM_PACK_NAME)/repo
	cd .. && cp -a . ../$(TEAM_PACK_NAME)/repo
	

	mkdir -p ../../$(TEAM_PACK_NAME)/install
	cp -a ../packages/. ../../$(TEAM_PACK_NAME)/install

	doxygen Doxyfile
	mkdir ../../$(TEAM_PACK_NAME)/doc
	cp -a doc/. ../../$(TEAM_PACK_NAME)/doc

	cd ../.. && zip -qr $(TEAM_PACK_NAME).zip  $(TEAM_PACK_NAME)
	rm -rf ./doc/
	rm -f doxygenWarning.txt
	rm -rf ../../$(TEAM_PACK_NAME)

#tar -czvf ../../$(TEAM_PACK_NAME).gz $(TEAM_PACK_NAME)