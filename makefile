CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11 -g
LDFLAGS=-g

SRCS=Main.cpp Huffman.cpp HuffmanTree.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS)

Main.o: Main.cpp Huffman.h

Huffman.o: Huffman.cpp Huffman.h HuffmanTree.h

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) main
