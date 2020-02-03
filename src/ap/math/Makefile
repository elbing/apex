include $(APEX)/src/$(OS).inc

TARGET = libap.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I../internal -Wno-unused-but-set-variable

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	ar rcs ${APEXLIB}/$@ $^
	cd x86_64; $(MAKE) $(MFLAGS)

clean:
	rm -f $(OBJ)
