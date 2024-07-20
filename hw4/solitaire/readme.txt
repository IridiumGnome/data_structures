First I create an array with cards and shuffle it randomly.
After that, I insert every element of an array into a singly linked list.
Print out every element of the linked list using function "display".
Then I call function "searchElement" several times with card I want to
draw up. Inside that function, I check if the data of the current node
is the same with the element I want to remove. While it's not the same 
I shift the linked list to left. So the first node points to last and becomes
the last node. If it's the same I remove the first node and the next node
becomes the first.

Differences:

The main difference is that for previous homework I create a new
array which length was (length of the previous array - 1) every time 
when I call the function that removes the card. 
