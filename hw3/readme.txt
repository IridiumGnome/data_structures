I used 3 vectors, friends, que and store. Vector que is used to 
store customers in the queue. Vector friends contain other vectors 
of chars and it's used for storing the groups of friends. In the
beginning when I input the first integer "n" friends size becomes "n".
After this, there is a for loops for reading the groups of friends.
After that inside while loop I check the first char of string "input". 

If it's 'E' then I call the function AddFriend. 
In this function inside for loop I call another function check to 
compare entered customer and every element of que vector and check 
if they are friends. If it so then return true from check function 
and insert the customer in front of que element. 
Otherwise, put it in the back. 

If it's 'D' I put the first element of que inside store vector 
and delete the first element of que and shift the vector.

If ctrl+z is entered then I print out the store vector.

  
   