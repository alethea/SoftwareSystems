#!/bin/sh

mkdir -p imdb
cd imdb
for i in actors actresses movies
do
  wget -c -np ftp://ftp.sunet.se/pub/tv+movies/imdb/$i.list.gz
done
gzip -vdn *.gz
cd ..
