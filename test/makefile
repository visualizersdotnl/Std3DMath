
SOURCES = test.cpp ../Vector3.cpp ../Matrix44.cpp ../Quaternion.cpp
TARGET = test

CC = g++
CFLAGS = -std=c++11 -g -Wall

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@
