include $(APEX)/src/$(OS).inc

TARGET = eqn
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

CFLAGS +=
YACC = yacc

.PHONY: all clean

all: $(TARGET)

%.o: %.c
	$(YACC) -d $(TARGET).y
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ) 
	$(LD) -static -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $(TARGET) $(APEXLIB)/crt0.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ) $(TARGET) y.tab.c y.tab.h
