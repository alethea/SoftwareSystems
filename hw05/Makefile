CC = gcc
PKGS = glib-2.0
CFLAGS = -Wall -Wpedantic
INCLUDES != pkg-config --cflags $(PKGS)
LFLAGS != pkg-config --libs $(PKGS)

all: hello

hello: hello.c
	$(CC) $< -o $@ $(CFLAGS) $(INCLUDES) $(LFLAGS)

.PHONY: clean

clean:
	rm -f hello *.o
