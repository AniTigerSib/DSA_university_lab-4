CPP=g++
CFLAGS:=-Wall -Werror -Wextra -g -c
FOLDER=../build/
OBJS=$(addprefix $(FOLDER),main.o search.o generate_text.o)

all:

rebuild: clean build

build: main.o search.o generate_text.o
	$(CPP) $(OBJS) -o $(FOLDER)Search
	$(MAKE) clean_objs

main.o: main.cpp search.h
	$(CPP) $(CFLAGS) $< -o $(FOLDER)$@

search.o: search.cpp search.h
	$(CPP) $(CFLAGS) $< -o $(FOLDER)$@

generate_text.o: generate_text.cpp generate_text.h
	$(CPP) $(CFLAGS) $< -o $(FOLDER)$@

clean_objs:
	rm -rf $(OBJS)

clean: clean_objs
	rm -rf $(FOLDER)*