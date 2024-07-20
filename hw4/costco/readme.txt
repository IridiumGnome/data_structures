First I fill the groups of friends using the vector of vectors with chars.
To store queue I use a doubly linked list.
After that inside while loop, I check the first char of string "input". 

If it's 'E' then write in a customer. If the linked list is empty
just add a customer in the queue. If it's not I check (using function "check")
if at least one element of linked list in the same group of 
friends with the entry customer. If so I call function "insert_in" to insert
a new node in front of another node. If they are not in the same group 
just put the customer at the end of the queue (function "add").

If it's 'D' I print out the first element of the linked list and 
after that remove it. Next element points to NULL by the previous 
pointer and becomes the first element in the queue.

Differences:

The main difference is that in previous homework I used a vector 
to store a queue. 
Also, I print out the customers who left after ctrl+z. In this homework I
print out the customer who left after each DEQUEUE.