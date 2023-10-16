/*
Collision is when two different keys are mapped to the same index in the hash-table. 
This is a problem because you may ending up losing data by inserting a new one. You do not want that.
One idea to solve the problem is to use a linked-list for the entries. 
if several entries are mapped to the same index , they are chained. Then to retrieve the value, you compute the index and do a classic lookup of your linked list
*/

