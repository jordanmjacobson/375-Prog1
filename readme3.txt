In order to compile the source code, just type in the
 following command: make run3
  You can update filex and filey, as this command takes in filex and filey
  as args
  Alternatively, you can do:
  ./program3 filex.txt filey.txt output.txt

This program is similar to the second one, but is optimized.
It has a 2D table like the first one.
Initially, all values are set to -1.
Once the recursive solution for lcs has been computed, the table at
that index is updated to the value.
If the recursive function finds that the value is no -1, it will not bother
calculating the lcs length, as this value already exist in the table,
thus optimizing the run time. 

NOTE: you must remove the output.txt file before running any program,
if the output.txt exists. This can be done with a "make clean",
or the old fashioned way
