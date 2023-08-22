# 42KL-21-CPP09

This module is designed to help you understand the containers in CPP.

**Ex00- Bitcoin Exchange**
- use map to store data.csv - use to convert data contained in input.txt

**Ex01- Reverse Polish Notation**
A+B   :		infix notation
+A B  :  	prefix notation
A B + :		postfix notation/Reverse Polish Notation

1. unambigious and doesn't need brackets
2. use stacks

2 4 * 6 +
- store values into stack first, when it's an operation, 
	  perform the operation on the two numbers before it
- stack: 2 4 
- 2 * 4 = 8 then delete 2 and 4 from stack
- store 8 into stack  
- stack: 8
- 8 * 6 = 48
- Answer: 48 

2 3 4 - *
- 3 - 4 = -1
- 2 * -1 
- Answer: -2

**Ex02- Ford-Johnson algorithm/merge insertion sort**
1. 	Split the collection in n/2 pairs of 2 elements and order these elements pairwise
	If the number of elements is odd, the last element of the collection isn't paired with any element
2.	Recursively sort the pairs by their highest value.
	If the number of elements is odd, the last element is not considered a highest value
	and is left at the end of the collection
	Consider that the highest values form a sorted list that we will call the main chain
	while the rest of the elements will be known as pend elements
3.	
