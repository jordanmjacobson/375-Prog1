In order to compile the source code, just type in the
 following command: make run1
  You can update filex and filey, as this command takes in filex and filey
  as args. Alternatively, you can do:
  ./program2 filex.txt filey.txt output.txt


In this program, I created a separate object class called Entry, which stores
an integer value, a direction, and a character for printing out the lcs. program1.cpp contains a two dimensional array
of Entries (called matrix). This 2D array is a representation of the dynamic
programming table mentioned in lectures 15-16. Descriptions of functions can
be found in Entry.h

NOTE: For some reason, at least on my machine, it outputs the table weirdly.
I have also made it print to stdout, just so you can see that my code actually
constructs the table properly. It will still also write to the output file as well. 

NOTE: you must remove the output.txt file before running any program,
if the output.txt exists. This can be done with a "make clean",
or the old fashioned way.
