CC = gcc
PKGS = glib-2.0
CFLAGS = -Wall -Wpedantic
INCLUDES != pkg-config --cflags $(PKGS)
LFLAGS != pkg-config --libs $(PKGS)

SRCS = main.c histogram.c parser.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: hello wordfreq

wordfreq: $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDES) $(LFLAGS)

hello: hello.c
	$(CC) $< -o $@ $(CFLAGS) $(INCLUDES) $(LFLAGS)

-include $(DEPS)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)
	$(CC) -MM $< $(CFLAGS) $(INCLUDES) -o $*.d

.PHONY: clean 

clean:
	rm -f hello wordfreq *.o *.d
