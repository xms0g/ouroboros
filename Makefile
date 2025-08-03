CC = gcc
TARGET = ouroboros

all: $(TARGET)

$(TARGET): ouroboros.c
	$(CC) -o $(TARGET) -O0 -no-pie -fno-stack-protector ouroboros.c