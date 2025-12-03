
CC = gcc

CFLAGS = -Wall -g

SRCS = fun.c main.c board.c

OBJS = $(SRCS:.c=.o)

TARGET = Twixt

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
