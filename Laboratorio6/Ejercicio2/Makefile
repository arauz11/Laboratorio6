CC = gcc
CFLAGS = -Wall 
LDFLAGS = 
OBJFILES = ejercicio2.o
TARGET = output

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
	
# gcc -Wall -o output ejercicio2.o
