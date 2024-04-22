CC=g++
TEAM=my_sme_tim
CMAKE = cmake
BUILD_DIR = build
GTEST_URL := https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
GTEST_ZIP := googletest.zip
GTEST_DIR := googletest


.PHONY: profile test pack clean run doc

all: profile calc

calc:
	@cd GUI && mkdir -p build && cd build && cmake .. && make -s 


profile:
	@echo "Building profiling..."
	@cd PROFILING && $(CC) -g -o  stddev *.cpp ../LIBS/*.cpp >/dev/null 2>&1
	@echo "Profiling compilation completed."


test:
	@cd TESTS && mkdir -p build && cd build && cmake .. && make -s && ./mathTest

clean:
	@rm -rf ./TESTS/build/ ./PROFILING/stddev ./GUI/build/ ./doc/
 
	
doc:
	doxygen Doxyfile && rm -f doxygenWarning.txt

run:
	@cd GUI && mkdir -p build && cd build && cmake .. && make -s && ./Calculator

pack: clean
	tar -czvf ../xnovakf00_xskovaj00_xmalegt00_xfignam00.gz ../../Proj2-NGLYD
