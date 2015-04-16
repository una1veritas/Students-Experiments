CC	= cc
C++	= c++
CFLAGS = -Wall -g
C++FLAGS = -Wall -g
EX1OBJS = vector2c.o vec2ex1c.o
EX2OBJS = vector2.o vec2ex2.o
EX4OBJS = matrix22.o mat22ex4.o
EX6OBJS = card.o cardset.o cardsetex6.o
EX6AOBJS = card.o cardset.o cardset_remove.o cardsetex6a.o
EX7OBJS = card.o cardset.o cardset_remove.o babastate.o babastate_move.o babanuki.o

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
	$(C++) $(EX3OBJS) -o ex4

ex6	: $(EX6OBJS)
	$(C++) $(EX6OBJS) -o cardsetex6

ex6a : $(EX6AOBJS)
	$(C++) $(EX6AOBJS) -o ex6a

ex7 : $(EX7OBJS)
	$(C++) $(EX7OBJS) -o ex7

vector2c.o	: vector2c.h
vec2ex1c.o	: vector2c.h
vector2.o	: vector2.h
vec2ex2.o	: vector2.h
matrix22.o	: matrix22.h
mat22ex4.o	: matrix22.h
card.o	: card.h
cardset.o	: card.h cardset.h
cardsetex6.o : card.h cardset.h
cardset_remove.o: card.h cardset.h
cardsetex6a.o : card.h cardset.h
babastate.o	: babastate.h cardset.h
babastate_move.o	: babastate.h cardset.h
babanuki.o	: babastate.h cardset.h

clean   :
	rm -f core *.o *~
