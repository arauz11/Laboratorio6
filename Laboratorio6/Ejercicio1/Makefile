CC = gcc
CFLAGS = -Wall -Werror
LDFLAGS = 
OBJFILES = ejercicio1.o
TARGET = output

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
	
# gcc -Wall -Werror -o output ejercicio1.o
