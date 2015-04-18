CXX := g++
CC := $(CXX)
CXXFLAGS := -g -Wall --std=c++11
CFLAGS := $(CXXFLAGS)

all: test-all

test-all: test test-half test-subsequence

test: edit-distance.out
	./$< anagram agnar
	./$< polynomial exponential

test-half: edit-halved-distance.out
	./$< anagram agnar
	./$< polynomial exponential

test-subsequence: subsequence.out
	./$< anagram agnar
	@# ./$< polynomial exponential
	@# ./$< hieroglyphology michaelangelo

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.out

.PHONY: clean test all test-half test-all test-subsequence
