FLAGS = -Wall -Wextra -DDebug -g -std=c++14

prog1: program1

Entry.o: Entry.cpp
	g++ $(FLAGS) -c Entry.cpp -o Entry.o

program1.o: program1.cpp
	g++ $(FLAGS) -c program1.cpp -o program1.o

program1: program1.o Entry.o
	g++ $(FLAGS) program1.o Entry.o -o program1

clean:
	rm -rf program1
	rm -rf *.o

run1: prog1
	./program1 filex.txt filey.txt
