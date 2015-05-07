CC	= cc
C++	= c++
CFLAGS = -Wall -O0 -g3 
C++FLAGS = -Wall -O0 -g3 

OBJS = Card.o CardSet.o Dealer.o Player.o LittleThinkPlayer.o
HEADERS = main.h Card.h CardSet.h Dealer.h GameStatus.h Player.h main.h LittleThinkPlayer.h ./extras/ThinkTA1.h
EXTRA_OBJS = GroupB.o GroupC.o GroupH.o 
EXTRA_HEADERS = ./extras/GroupB.h ./extras/GroupC.h ./extras/GroupH.h 

.SUFFIXES: .o .cc .cpp .c++ .c


.c.o: $(HEADERS) $(EXTRA_HEADERS)
	$(CC) -c $(CFLAGS) $< 

.cc.o: $(HEADERS) $(EXTRA_HEADERS)
	$(C++) -c $(C++FLAGS) $< 

.cpp.o: $(HEADERS) $(EXTRA_HEADERS)
	$(C++) -c $(C++FLAGS) $< 

all: daifugou
	@echo "build finished."

daifugou: main.o ThinkTA1.o $(OBJS) $(HEADERS)
	$(C++) $(C++FLAGS) main.o $(OBJS) ThinkTA1.o -o daifugou

taikai: $(OBJS) $(EXTRA_OBJS) taikai_main.o ThinkTA1.o $(HEADERS) $(EXTRA_HEADERS)
	$(C++) $(C++FLAGS) $(OBJS) ThinkTA1.o $(EXTRA_OBJS) taikai_main.o -o taikai

ThinkTA1.o: $(HEADERS) $(EXTRA_HEADERS)
	$(C++) -c $(C++FLAGS) extras/ThinkTA1.cpp
GroupB.o: $(HEADERS) $(EXTRA_HEADERS)
	$(C++) -c $(C++FLAGS) extras/GroupB.cpp
GroupC.o: $(HEADERS) $(EXTRA_HEADERS)
	$(C++) -c $(C++FLAGS) extras/GroupC.cpp
GroupH.o: $(HEADERS) $(EXTRA_HEADERS)
	$(C++) -c $(C++FLAGS) extras/GroupH.cpp


help:  README.txt
	more README.txt

clean   :
	\rm -f core $(OBJS) $(EXTRA_OBJS) main.o taikai_main.o *~ #*#

cleanall: clean
	\rm -f ThinkTA1.o
	\rm -f taikai
	\rm -f daihugou
