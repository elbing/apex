include $(APEX)/src/$(OS).inc

TARGET = libap.a
SRCS = $(wildcard *.c)
SRC =\
	x86_64/fenv.s \

OBJ = ${SRCS:.c=.o}
OBJS = ${SRC:.s=.o}
CFLAGS += -I../internal

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRC) || exit 1
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ) $(OBJS)
	ar rcs ${APEXLIB}/$@ $^

clean:
	rm -f $(OBJ) $(OBJS)
