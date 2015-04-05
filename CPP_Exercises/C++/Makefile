CC	= cc
C++	= c++
CFLAGS = -Wall -g
C++FLAGS = -Wall -g
VEC2EX1COBJS = vector2c.o vec2ex1c.o
VEC2EX1POBJS = vector2p.o vec2ex1p.o
MAT22EX1OBJS = matrix22.o mat22ex1.o
CARDSETEX1OBJS = cardset.o cardsetex1.o
CARDSETEXOBJS = cardset.o cardset_example.o
BABANUKI1OBJS = cardset.o babastate.o babanuki1.o

.SUFFIXES: .o .cc .c++ .c

.c.o:
	$(CC) -c $(CFLAGS) $<

.cc.o:
	$(C++) -c $(C++FLAGS) $<

all     :
	@echo '使用法: make xxx の形で演習を指定すること'

vec2ex1c	: $(VEC2EX1COBJS)
	$(CC) $(VEC2EX1COBJS) -o vec2ex1c

vec2ex1p	: $(VEC2EX1POBJS)
	$(C++) $(VEC2EX1POBJS) -o vec2ex1p

mat22ex1	: $(MAT22EX1OBJS)
	$(C++) $(MAT22EX1OBJS) -o mat22ex1

cardsetex1	: $(CARDSETEX1OBJS)
	$(C++) $(CARDSETEX1OBJS) -o cardsetex1

babanuki1	: $(BABANUKI1OBJS)
	$(C++) $(BABANUKI1OBJS) -o babanuki1

cardset_example: $(CARDSETEXOBJS)
	$(C++) $(CARDSETEXOBJS) -o cardset_example

vector2c.o	: vector2c.h
vec2ex1c.o	: vector2c.h
vector2p.o	: vector2p.h
vec2ex1p.o	: vector2p.h
matrix22.o	: matrix22.h
mat22ex1.o	: matrix22.h
cardset.o	: cardset.h
cardsetex1.o	: cardset.h
babastate.o	: babastate.h cardset.h
babanuki1.o	: babastate.h cardset.h

clean   :
	rm -f core *.o