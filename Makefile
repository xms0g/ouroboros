CC = gcc
CFLAGS = -O0 -no-pie -fno-stack-protector
TARGET = ouroboros

all: $(TARGET)

$(TARGET): ouroboros.c
	$(CC) $(CFLAGS) -o $(TARGET) ouroboros.c

.PHONY: all clean
clean:
	rm -f $(TARGET)
