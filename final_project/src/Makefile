SHELL = /bin/sh
CC = g++ -lssl -lcrypto
GCC_VERSION := $(shell gcc -dumpversion | awk -F . '{ print $$1 }')
DEBUG = -g -Wall -Wextra -Wlogical-op -Wdouble-promotion -Wshadow -Wformat=2
CFLAGS = -std=c++11 $(DEBUG)

# Add debug flags based on the machine's GCC version
ifeq ($(shell test $(GCC_VERSION) -gt 5; echo $$?), 0)
	DEBUG += -Wduplicated-cond -Wnull-dereference 
endif
ifeq ($(shell test $(GCC_VERSION) -gt 6; echo $$?), 0)
	DEBUG += -Wduplicated-branches 
endif

libdir = lib
bindir = bin

targets = $(filter-out main,$(patsubst %.cpp, %, $(wildcard *.cpp)))
headers = $(wildcard *.h)

.PHONY: all
all: installdirs main

.PHONY: installdirs
installdirs: 
	@ mkdir -p $(bindir) $(libdir)

main: $(libdir)/$(targets:=.o) $(headers)
	$(CC) $(CFLAGS) $? $@.cpp -o $(bindir)/$@

$(libdir)/%.o: %.cpp $(headers)
	$(CC) -c $(CFLAGS) $< -o $@

