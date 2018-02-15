CC = gcc
DEBUG = -g -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wlogical-op \
		 -Wnull-dereference -Wdouble-promotion -Wshadow -Wformat=2
CFLAGS = -std=gnu11 $(DEBUG)

BIN_PATH = bin
BUILD_PATH = build

DEPS = shell

HEADERS = $(addsuffix .h, $(DEPS))
OBJECTS = $(addsuffix .o, $(DEPS))

.PHONY: all run bootstrap clean

all: bootstrap clean main

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_PATH)/$@

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(addprefix build/, $(OBJECTS)) $@.c -o $(BIN_PATH)/$@

run:
	@ ./bin/main

bootstrap:
	@ mkdir -p ./{bin,build}

clean:
	@ rm -rf bin/* build/* output.txt 
