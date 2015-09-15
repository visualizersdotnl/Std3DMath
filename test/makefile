
TARGET = test
SOURCES = test.cpp ../Vector3.cpp ../Matrix44.cpp ../Quaternion.cpp

CC = g++
CFLAGS = -std=c++11 -g -Wall

OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all default clean

default: $(TARGET)
all: default

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm $(TARGET)
