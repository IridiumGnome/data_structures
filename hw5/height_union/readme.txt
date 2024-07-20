In this homework I use 2 vectors "p" and "h" for storing nodes and heights respectively.
For node p[i] I store a parent of i; h[i] is the height of a tree with root i.

First I assign values of both vectors.

Then read a command UNION, FIND or STOP.

If input is STOP terminate a program;
If the first element of input is 'U' call function heightUnion;
If the first element of input is 'F' call function collapsingFind.

Inside function heightUnion I compare the heights of both trees.
If the height of tree with root 'a' is greater than height of tree with root 'b'
then 'a' becomes a parent of 'b'. Otherwise 'b' becomes a parent of 'a'. 

Inside function collapsingFind first call another function find_vert to find a root of the
number we want to find. In the find_vert also count the number of steps from node to root.
If the parent of 'a' is root then the answer is 1 and we dont have to make any changes. 
Otherwise root becomes a parent of all nodes on the path from desired node. And add 1 as the reset link.

ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);

This two rows above just simply mean that all output will be printed after execution of program.

 