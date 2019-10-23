CXX = g++
FLAGS = -g -Wall --std=c++11
OBJS = ex12
.PHONY: all, clean

all: ex12

ex12: ex12.cc SkipList.h SkipList.cc
	$(CXX) $(FLAGS) -o $@ $<

clean:
	rm -rf ex12
