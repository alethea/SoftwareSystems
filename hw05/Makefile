CC=gcc
PKGS=glib-2.0
CFLAGS=
PKG_CONFIG!=pkg-config --cflags --libs $(PKGS)

hello: hello.c
	$(CC) hello.c -o hello $(CFLAGS) $(PKG_CONFIG)
