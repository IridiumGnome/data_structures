We have 2 functions, the main function which doesn't return value and a recursive function "Function". 
So we initialize variable "input" to read out a string and also initialize vector "ourVector" 
to store elements of subset. Inside for loop, we read elements in sequence until we meet an empty
space or the last element of the string. If we meet empty space we push values of string we 
just read into the vector. Then we call the recursive function. 
First, it prints out an empty subspace {}. After that inside for loop, we create a new 
recursion branch where we send the element that has not been used yet.

for example input is "a b c":

				j=-1; subspace=""
	/				|			\
j=0; subspace="a"		j=1; subspace="b"	j=2; subspace="c"
	/	     \			   |
j=1; subspace="a b"  j=2;subs="a c"	j=2;subs="b c"
	|
j=2; subspace="a b c"