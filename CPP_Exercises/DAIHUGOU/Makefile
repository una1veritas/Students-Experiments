CC	= cc
C++	= c++
CFLAGS = -Wall -g
C++FLAGS = -Wall -g

OBJS = Card.o CardSet.o Dealer.o Player.o LittleThinkPlayer.o ThinkTA1.o main.o
HEADERS = Card.h CardSet.h Player.h Dealer.h LittleThinkPlayer.h ThinkTA1.h

.SUFFIXES: .o .cc .cpp .c++ .c

.c.o: $(HEADERS)
	$(CC) -c $(CFLAGS) $<

.cc.o: $(HEADERS)
	$(C++) -c $(C++FLAGS) $<

.cpp.o: $(HEADERS)
	$(C++) -c $(C++FLAGS) $<

all: daihugou
	@echo "build finished."

daihugou: $(OBJS) $(HEADERS)
	$(C++) $(OBJS) -o daihugou


clean   :
	rm -f core *.o
