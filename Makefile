CC=clang++-12
LLVM=$(shell llvm-config-12 --cxxflags --ldflags --system-libs --libs core)
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS: .cpp=.o)

ned: 	$(OBJS)
	$(CC) -o ned $(OBJS) $(LDFLAGS) $(LLVM)

$(OBJS): ned.h
