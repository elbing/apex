include $(APEX)/src/$(OS).inc

TARGET = pic
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

CFLAGS +=
YACC = yacc
LEX = lex

.PHONY: all clean

all: $(TARGET)

%.o: %.c
	# $(LEX) -t $(TARGET)l.lx > picl.c # needs AT&T lex, uncompatible with flex or Bflex
	# $(YACC) -y -d $(TARGET)y.y # needs AT&T yacc due to some uncompatibilities
	$(CC) $(CFLAGS) -c $(SRCS) y.tab.c picl.c

$(TARGET): $(OBJ) 
	$(LD) -static -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $(TARGET) $(APEXLIB)/crt0.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	# add y.tab.c y.tab.h picl.c when native build will be available
	rm -f $(OBJ) $(TARGET)
