We have 2 functions. Inside the "main" function we read two variables 
and then check if they are in the range from 0 to 5 (inclusive). 
If so we send them into recursive function "Function". 
There we (according to the certain conditions of Ackerman function) 
return determined value (b+1; Function(a-1, 1); Function(a-1, Function(a, b-1))).