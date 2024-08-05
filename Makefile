CC=g++
CFLAGS=-std=c++20 -I./lib/includes/ -I./include -g
LDFLAGS= -L./lib -ltemple

SRCDIR=src
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
EXECUTABLE=Portfolio

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f $(EXECUTABLE)

run: all
	./$(EXECUTABLE)
