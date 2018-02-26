SHELL = /bin/sh
CC = gcc
DEBUG = -g -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wlogical-op \
		 -Wnull-dereference -Wdouble-promotion -Wshadow -Wformat=2
CFLAGS = -std=gnu11 $(DEBUG)

libdir = lib
bindir = bin

.PHONY: all clean installdirs run

all: installdirs clean main

main:
	$(CC) $(CFLAGS) $@.c -o $(bindir)/$@

run:
	@ ./bin/main

installdirs: 
	@ mkdir -p $(bindir) $(libdir)

clean:
	@ rm -rf $(bindir)/* $(libdir)/*
