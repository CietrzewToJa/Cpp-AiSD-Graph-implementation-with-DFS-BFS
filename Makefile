# Makefile
# Kompilator g++.
CC = g++
# Mozliwe dodatkowe zmienne
# LIBS = -ll -lm
LIBS =
CFLAGS = -Wall -std=c++11
# Pliki obiektowe.
OBJECTS = main.o graph.o
# Pliki naglowkowe.
HFILES = $(patsubst %.o,%.h,$(OBJECTS))
# Koncowy plik wykonywalny.
TARGET = main.out

# Definicja domyslnej reguly wzorcowej.
# $< oznacza nazwe pliku pierwszej zaleznosci reguly.
# $@ oznacza nazwe pliku celu w regule.
# Wszystkie pliki obiektowe zaleza od wszystkich plikow naglowkowych.
%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

# Okreslenie celow sztucznych.
.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core
