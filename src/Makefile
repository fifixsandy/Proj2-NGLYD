CC=g++
TEAM=my_sme_tim
CMAKE = cmake
BUILD_DIR = build
GTEST_URL := https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
GTEST_ZIP := googletest.zip
GTEST_DIR := googletest


.PHONY: profile test pack clean

all: profile



profile:
	@echo "Building profiling..."
	@cd PROFILING && $(CC) -g -o  stddev *.cpp ../LIBS/*.cpp >/dev/null 2>&1
	@echo "Profiling compilation completed."


test:
	@cd TESTS && mkdir -p build && cd build && cmake .. && make -s && make -s test

clean:
	@rm -rf ./TESTS/build/ ./PROFILING/stddev


pack:
	tar -czvf ../NGLYD.gz Makefile CMakeLists.txt TESTS PROFILING LIBS GUI 
	

#cmake:
#	@if [ ! -d $(BUILD_DIR) ]; then \
#		mkdir -p $(BUILD_DIR); \
#		cd $(BUILD_DIR) && $(CMAKE) .. && make -s; \
#	else \
#		echo "Build directory exists. Entering $(BUILD_DIR)"; \
#		cd $(BUILD_DIR) && $(CMAKE) .. && make -s; \
#	fi


#som to chcel robit tak ze by nebolo treba cmake ale no problem ze cmake stahuje tu kniznicu gtest tak ono sa to 
#da aj takto ze bez cmaku ale treba asi stiahnut kniznicu do dir

#profile:
#	cd build/PROFILING && make -s profile

#test:
#	cd build/TESTS && make -s test 




#GTEST_DIR = ./googletest-main/build
#test: $(GTEST_DIR)
    # Compile and run your tests here

#$(GTEST_DIR):
#	@echo "Downloading Google Test..."
#	@cd TESTS && \
#	wget $(GTEST_URL) -O $(GTEST_ZIP) && \
#	unzip $(GTEST_ZIP) && \
#	mv googletest-* $(GTEST_DIR) && \
#	rm $(GTEST_ZIP) && \
#	$(CC) -o test *.cpp -I/../LIBS/*.cpp



#getlibs:
#	sudo apt-get install pkg-config && sudo apt-get install libgtk-3-dev


#test:
#	@echo "Building tests..."
#	@$(CC) -o test $(wildcard TESTS/*.cpp) $(wildcard LIBS/*.cpp) -I./googltest-main/googletest/include -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread
#	@echo "Tests completed."