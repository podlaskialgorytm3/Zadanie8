# Nazwa pliku wykonywalnego
TARGET = test_stack

# Pliki źródłowe
SRC = main.c fun_stack.c

# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Domyślny cel
all: $(TARGET)

# Reguła do tworzenia pliku wykonywalnego
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Reguła czyszczenia
clean:
	rm -f $(TARGET)
