In this program, I have several vectors such as 'aoe' to store matrix representation of network 
and 'le', 'ee', 'l', 'e', 'slack', 'status' to store output values.

Initially, the size of aoe is 101 and it's filled with zeroes; Sizes of ee and le are the number of 
events, sizes of l and e are the number of activities;

Start to initialize network matrix and its values are equal to duration.

Call additional functions:  
1) 'eeFunction' to count ee values; when I call this function I give the number of events in the network 
as a parameter.
2) 'leFunction', which is getting the number of events as a parameter, to count le values. 
3) 'elFunction', which is getting the number of activities as a parameter, to count e and l values
4) 'path', which is getting the number of activities as a parameter, to count a critical path (indexes of
activities);

Then print out the results table.

To know 'slack' and 'status' values I count l[i]-e[i] and check l[i] and e[i]
are the same.