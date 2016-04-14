CC	= cc
C++	= c++
CFLAGS = -Wall -O0 -g3
C++FLAGS = -Wall -O0 -g3

HEADERS = Card.h CardSet.h Dealer.h Player.h GameState.h 
OBJS = Card.o CardSet.o Dealer.o Player.o
EXTRA_OBJS = GroupB.o GroupH.o

all: daifugou

daifugou: main.o $(OBJS) LittleThinkPlayer.o ThinkTA1.o
	$(C++) $(C++FLAGS) main.o $(OBJS) LittleThinkPlayer.o ThinkTA1.o -o daifugou

taikai: $(OBJS) $(EXTRA_OBJS) LittleThinkPlayer.o ThinkTA1.o taikai_main.o 
	$(C++) $(C++FLAGS) $(OBJS) $(EXTRA_OBJS) taikai_main.o LittleThinkPlayer.o ThinkTA1.o -o taikai


ThinkTA1.o: $(HEADERS) ./extras/ThinkTA1.h 
	$(C++) -c $(C++FLAGS) ./extras/ThinkTA1.cpp
GroupB.o: $(HEADERS) ./extras/GroupB.h
	$(C++) -c $(C++FLAGS) ./extras/GroupB.cpp
GroupH.o: $(HEADERS) ./extras/GroupH.h
	$(C++) -c $(C++FLAGS) ./extras/GroupH.cpp

Card.o: $(HEADERS)
CardSet.o: $(HEADERS)
Player.o: $(HEADERS)
Dealer.o: $(HEADERS)
main.o: $(HEADERS)
taikai_main.o: $(HEADERS)

help:  README.txt
	more README.txt

clean   :
	\rm -f core $(OBJS) $(EXTRA_OBJS) main.o taikai_main.o *~ #*#

allclean: clean
	\rm -f taikai
	\rm -f daihugou
