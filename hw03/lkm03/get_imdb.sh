#!/bin/sh

mkdir -p imdb
cd imdb
wget -rc -np -nd -l1 -A.list.gz ftp://ftp.sunet.se/pub/tv+movies/imdb/
gzip -vdn *.gz
cd ..
