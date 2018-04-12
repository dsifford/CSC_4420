SHELL = /bin/sh
CC = gcc
GCC_VERSION := $(shell gcc -dumpversion | awk -F . '{ print $$1 }')
DEBUG = -g -Wall -Wextra -Wlogical-op -Wdouble-promotion -Wshadow -Wformat=2
CFLAGS = -std=gnu11 $(DEBUG)

# Add debug flags based on the machine's GCC version
ifeq ($(shell test $(GCC_VERSION) -gt 5; echo $$?), 0)
	DEBUG += -Wduplicated-cond -Wnull-dereference 
endif
ifeq ($(shell test $(GCC_VERSION) -gt 6; echo $$?), 0)
	DEBUG += -Wduplicated-branches 
endif

bindir = bin

.PHONY: all
all: installdirs clean main

.PHONY: installdirs
installdirs: 
	@ mkdir -p $(bindir)

.PHONY: clean
clean:
	@ rm -f $(bindir)/*

main:
	$(CC) $(CFLAGS) $? $@.c -o $(bindir)/$@

