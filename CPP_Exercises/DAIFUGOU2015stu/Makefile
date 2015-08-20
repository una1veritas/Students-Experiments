CC	= cc
C++	= c++
CFLAGS = -Wall -O0 -g3
C++FLAGS = -Wall -O0 -g3

HEADERS = Card.h CardSet.h Dealer.h Player.h GameState.h 
OBJS = Card.o CardSet.o Dealer.o Player.o LittleThinkPlayer.o
GROUPS_OBJS = Group1.o Group3.o Group4.o Group5.o Group6.o Group7.o \
			Group2.o 
GROUPS_HEADERS = Group1.h Group2.h Group3.h Group4.h Group5.h Group6.h Group7.h

all: taikai

daifugou: main.o $(OBJS) ThinkTA1.o
	$(C++) $(C++FLAGS) main.o $(OBJS) ThinkTA1.o -o daifugou

taikai: $(OBJS) $(GROUPS_OBJS) ThinkTA1.o taikai_main.o 
	$(C++) $(C++FLAGS) $(OBJS) $(GROUPS_OBJS) taikai_main.o ThinkTA1.o -o taikai


ThinkTA1.o: $(HEADERS) ./extras/ThinkTA1.h 
	$(C++) -c $(C++FLAGS) ./extras/ThinkTA1.cpp

Group1.o: $(HEADERS) Group1.h
Group2.o: $(HEADERS) Group2.h
Group3.o: $(HEADERS) Group3.h
Group4.o: $(HEADERS) Group4.h
Group5.o: $(HEADERS) Group5.h
Group6.o: $(HEADERS) Group6.h
Group7.o: $(HEADERS) Group7.h

Card.o: $(HEADERS)
CardSet.o: $(HEADERS)
Player.o: $(HEADERS)
Dealer.o: $(HEADERS)
main.o: $(HEADERS)
taikai_main.o: $(HEADERS)

help:  README.txt
	more README.txt

clean   :
	\rm -f core $(OBJS) $(GROUPS_OBJS) main.o taikai_main.o *~ #*#

allclean: clean
	\rm -f taikai
	\rm -f daihugou
