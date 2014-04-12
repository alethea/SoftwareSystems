CC = gcc
PKGS = glib-2.0
CFLAGS = -Wall -Wpedantic
CPPFLAGS = -D WORDFREQ_EBOOK=\"$(EBOOK)\"
INCLUDES != pkg-config --cflags $(PKGS)
LFLAGS != pkg-config --libs $(PKGS)

SRCS = main.c histogram.c parser.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

EBOOK = shakespeare.txt
EBOOK_ID = 100

all: hello wordfreq

wordfreq: $(OBJS) $(EBOOK)
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(INCLUDES) $(LFLAGS)

$(EBOOK):
	wget http://www.gutenberg.org/ebooks/$(EBOOK_ID).txt.utf-8 -O $@

hello: hello.c
	$(CC) $< -o $@ $(CFLAGS) $(INCLUDES) $(LFLAGS)

-include $(DEPS)

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES) $(CPPFLAGS)
	$(CC) -MM $< $(CFLAGS) $(INCLUDES) -o $*.d

.PHONY: clean 

clean:
	rm -f hello wordfreq $(EBOOK) *.o *.d
