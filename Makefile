FLAGS = -Wall -Wextra -DDebug -g -std=c++14

all: program1 program1 program3

Entry.o: Entry.cpp
	g++ $(FLAGS) -c Entry.cpp -o Entry.o

program1.o: program1.cpp
	g++ $(FLAGS) -c program1.cpp -o program1.o

program1: program1.o Entry.o
	g++ $(FLAGS) program1.o Entry.o -o program1

program2.o: program2.cpp
	g++ $(FLAGS) -c program2.cpp -o program2.o

program2: program2.o
	g++ $(FLAGS) program2.o -o program2

program3.o: program3.cpp
	g++ $(FLAGS) -c program3.cpp -o program3.o

program3: program3.o
	g++ $(FLAGS) program3.o -o program3

clean:
	rm -rf program1 program2 program3
	rm -rf *.o
	rm -rf output.txt
run1: program1
	./program1 filex.txt filey.txt output.txt

run2: program2
	./program2 filex.txt filey.txt output.txt

run3: program3
	./program3 filex.txt filey.txt output.txt
