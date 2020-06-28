# Możliwe polecenia: make, make run, make clean, make tar
#
# Nazwa katalogu biezacego: wykorzystanie polecenia basename
KATBIEZ=$(shell basename "$(PWD)")
# Nazwy rdzeniowe plikow
GLOWNY = program_figury
ODCINEK = program_odcinek
TROJKAT = program_trojkat
PROSTOKAT = program_prostokat
OKRAG = program_okrag
# Po prawej stronie można użyć nazw zmiennych make’a
BIBKOM = $(ODCINEK).o $(TROJKAT).o $(PROSTOKAT).o $(OKRAG).o 
AR = ar         # archiwizer
AROP = rsv	# Opcje archiwizera
# Tworzenie biblioteki statycznej:
# $@ oznacza nazwę celu, $? –zmodyfikowany prerekwizyt
$(BIBSTAT): $(BIBKOM)
	$(AR) $(AROP) $@ $?
# Linkowanie: $^ oznacza wszystkie prerekwizyty
$(GLOWYK): $(GLOKOM) $(BIBSTAT)
	$(LINKER) -o $@ $(LINOP) $^


# Plik źródłowy
GLOZRO = $(GLOWNY).cpp
ZODCINEK = $(ODCINEK).cpp
ZTROJKAT = $(TROJKAT).cpp
ZPROSTOKAT = $(PROSTOKAT).cpp
ZOKRAG = $(OKRAG).cpp
# Pliki skompilowane
GLOKOM = $(GLOWNY).o
OODCINEK = $(ODCINEK).o
OTROJKAT = $(TROJKAT).o
OPROSTOKAT = $(PROSTOKAT).o
OOKRAG = $(OKRAG).o
BIBSTAT = libFigury.a 
# Plik wykonawczy
GLOWYK = $(GLOWNY).x
# Kompilator
KOMP = g++
# Opcje kompilatora
KOMOP = -c -Wall
# Linker 
LINKER = $(KOMP)
# Opcje linkera
LINOP = -Wall -pedantic
# Regula all - bedzie uruchamiana po wykonaniu make bez argumentow.
# Tu oznacza utworzenie pliku wykonawczego.
all: $(GLOWYK)
# Reguly dla kompilacji:
# 1. Plik z funkcjami
$(OODCINEK): $(ZODCINEK) 
	$(KOMP) $(KOMOP) $(ZODCINEK)
$(OTROJKAT): $(ZTROJKAT) 
	$(KOMP) $(KOMOP) $(ZTROJKAT)
$(OPROSTOKAT): $(ZPROSTOKAT) 
	$(KOMP) $(KOMOP) $(ZPROSTOKAT)
$(OOKRAG): $(ZOKRAG) 
	$(KOMP) $(KOMOP) $(ZOKRAG)
$(GLOKOM): $(GLOZRO) 
	$(KOMP) $(KOMOP) $(GLOZRO)
# Po prawej stronie można użyć nazw zmiennych make’a
BIBKOM = $(OODCINEK) $(OTROJKAT) $(OPROSTOKAT) $(OOKRAG)
AR = ar         # archiwizer
AROP = rsv	# Opcje archiwizera
# Tworzenie biblioteki statycznej:
# $@ oznacza nazwę celu, $? –zmodyfikowany prerekwizyt
$(BIBSTAT): $(BIBKOM)
	$(AR) $(AROP) $@ $?
# Linkowanie: $^ oznacza wszystkie prerekwizyty
$(GLOWYK): $(GLOKOM) $(BIBSTAT)
	$(LINKER) -o $@ $(LINOP) $^

# Regula dla wykonania 
run: $(GLOWYK) 
	./$(GLOWYK)
# Regula do czyszczenia katalogu 
clean:
	rm -f a.out *~ *.o *.x *.a
# Regula do archiwizacji i kompresji: 
# 1. Przejsciedo katalogu macierzystego (jeden poziom wstecz).
# 2. Archiwizacja z kompresja przy uzyciutar.
# 3. Wyswietleniezawartoscikatalogu macierzystego.
# Zewnetrzne nawiasy ( ) sprawiaja wykonanie powyzszych operacji 
# w tymczasowo uruchomionej powloce, po czym nastepuje powrot
# do pierwotnej powloki.
tar: clean
	(cd ..; tar cvzf $(KATBIEZ).tar.gz $(KATBIEZ); ls -altr)
