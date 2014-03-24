#!/usr/bin/env python3

import psycopg2


def connect(dsn_file):
    with open(dsn_file) as dsn:
        return psycopg2.connect(dsn.read())
