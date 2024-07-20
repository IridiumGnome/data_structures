Inside main function, I create an array of length M (# of rows) and fill it with integers.
After that I call function CreateHeap with array arr and M as parameters.
Inside this function, I choose an index of the parent node and call MaxHeap to create 
a max heap.

How MaxHeap works: 
For example, we have an array of integers 1 7 2 3 5 (1 has the first index)
7 is a parent and child index is 4 (hence 3 is on child position)
check if the element on the right side of the child node is greater. 
3 is less than 5 so child index becomes child + 1
check if the parent is greater than the child node
if so break
otherwise, child is on parents position and child index becomes 2 * child
outside the while loop declare that value with index child / 2 is equal to the parent value 

Returning to the main function after calling the CreateHeap function I'm looking for
the maximum value in an array. Add the largest value to the price and subtract 1
from the largest. Call the CreateHeap function again. Print out the total price
and clear arr.
