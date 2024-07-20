I implemented this program using Yen's algorithm. Hence no loops.

All program can be divided into several parts:

1) initialization of the network (I used vector of vectors "graph" to store 
network).
2) calling the "Dijkstra" function the first time to find the minimal distance from
the source vertex to destination. This function gets deleted edge and "p" vector
which stores parents as arguments. Because this is the first time of calling this 
function so removed edge is {-1, -1}. 
"Dijkstra" function returns the distance from the start vertex to end vertex or
-1 in case if there is no path that exists.
3) then in the main function check if returning value is not -1. If so then restore
a path using the "p" vector and push it into the "path" vector. After that push
distance value we get and "path" vector into a vector "ans" and mark the path
as already found. If the returning value is -1 then print out "there is no path".
4) After that, there is yan's algorithm. We call "Dijkstra" again but every time
remove one of the edges. If the returning value is not -1 then push a new path
into the "path" vector. And then check if this path already exists or not.
If not then push new answers into vector "ans" and mark the path as already found.
5) sort the "ans" vector in increasing order.
6) Print out k paths using "print_path" function.