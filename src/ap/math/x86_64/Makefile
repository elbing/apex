include $(APEX)/src/$(OS).inc

TARGET = libap.a
SRCS = $(wildcard *.s)
OBJ = ${SRCS:.s=.o}
CFLAGS += -I../../internal

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${APEXLIB}/$@ $^

clean:
	rm -f $(OBJ)
