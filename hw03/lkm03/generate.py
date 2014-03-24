#!/usr/bin/env python3

import random
import psycopg2


def connect(dsn_file):
    with open(dsn_file) as dsn:
        return psycopg2.connect(dsn.read())

def test_data(movies, actors, avg_size):
    actor_list = list(range(actors))
    movie_list = []
    random.shuffle(actor_list)
    max_size = avg_size * 2

    for _ in range(movies):
        movie_list.append(set())
        
    # Make sure every actor is in at least one movie
    while actor_list:
        for movie in movie_list:
            movie.add(actor_list.pop())
            if not actor_list:
                break

    # Fill in the rest of each roster
    for movie in movie_list:
        size = len(movie)
        if size < max_size:
            movie.update(
                random.sample(range(actors),
                    random.randint(0, max_size - size)))

    return movie_list
