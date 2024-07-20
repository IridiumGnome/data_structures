There are functions shuffle and change to mix array. Srand(time(NULL)) prevent 
sequence repetition between runs. After that I create arr2~arr14 and the length
of each array is less by one. I call function deleteElement with different parameters
(array to check, max number of elements in that array, card to draw out and new array
which length is num). Every time the max number of elements in array (count) is less 
by one. In fuction deleteElement() I use while loop to check if the first element of array 
is not equal to card we have draw out. If it doesn't I shift array to left and print it out.
In case the first element is equal to card I copy each element of array starting from the
second to a new one. After that I print new array out and return max number of element - 1
(count-=1).  