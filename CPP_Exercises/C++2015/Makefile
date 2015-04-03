CC	= cc
C++	= c++
CFLAGS = -Wall -g
C++FLAGS = -Wall -g
EX1OBJS = vector2c.o vec2ex1c.o
EX2OBJS = vector2.o vec2ex2.o
EX4OBJS = matrix22.o mat22ex4.o
EX6OBJS = cardset.o cardsetex6.o
EX7OBJS = cardset.o cardset_example.o
EX8OBJS = cardset.o babastate.o babanuki1.o

.SUFFIXES: .o .cc .c++ .c

.c.o:
	$(CC) -c $(CFLAGS) $<

.cc.o:
	$(C++) -c $(C++FLAGS) $<

.cpp.o:
	$(C++) -c $(C++FLAGS) $<

all     :
	@echo '使用法: make xxx の形で演習を指定すること'

ex1	: $(EX1OBJS)
	$(CC) $(EX1OBJS) -o ex1

ex2	: $(EX2OBJS)
	$(C++) $(EX2OBJS) -o ex2

ex4	: $(EX4OBJS)
	$(C++) $(EX3OBJS) -o ex3

ex6	: $(EX6OBJS)
	$(C++) $(EX6OBJS) -o cardsetex6

babanuki1	: $(BABANUKI1OBJS)
	$(C++) $(BABANUKI1OBJS) -o babanuki1

cardset_example: $(CARDSETEXOBJS)
	$(C++) $(CARDSETEXOBJS) -o cardset_example

vector2c.o	: vector2c.h
vec2ex1c.o	: vector2c.h
vector2.o	: vector2.h
vec2ex2.o	: vector2.h
matrix22.o	: matrix22.h
mat22ex4.o	: matrix22.h
cardset.o	: cardset.h
cardsetex6.o : cardset.h
babastate.o	: babastate.h cardset.h
babanuki1.o	: babastate.h cardset.h

clean   :
	rm -f core *.o *~
