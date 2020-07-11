Justin Lee, 727000824, Sec 501, jlee232435, jlee232435@tamu.edu
Aggie Honor statement:

I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.

Your Name: Justin Lee           Date: 3/4/20

Resources:
The only resource used in this assigment was Dr. Leyk's Queue Linked List Based lecture notes.

Issues:
There are no problems with the assignment as it compiles without any errors and outputs correctly. 

Short Code Description:
This assignment implemented a MinQueue from the TemplatedDLList.h. The MinQueue used the functions enqueue(), dequeue(), size(), is_empty(), and a min(). The enqueue simply inserted a node at the end and
and the dequeue removed the first node in the list. Both functions took a constant number of operations making it O(1). The size function returned the count of number of items in the list as a counter was 
incremented after every enqueue and decremented after every dequeue. In addition, the is_empty function just returned whether or not the list was empty, which was made in the TemplatedDLList.h and simply 
reimplemented in the Minqueue.h. Thus, both the size and is_empty function had a constant number of operations also making it O(1). Lastly, the min function traversed through the whole list in order to make
a comparison to check for the smallest value in the list, which is then assigned to a min_value variable and then returned. Thus, the min function requires O(n) as it needed to go through the entire list to 
find the minimum value.  

Testing:
The program for this assignment was tested for correctness using the MinQueue-main.cpp that we had to create on our own to implement several functions, such as size(), enqueue(), dequeue(), and min().
They were outputted using cout statements to make sure that they functioned how they were suppose to. An exception was used in the dequeue function to throw EmptyDLList("Access to an empty queue") if 
it was trying to dequeue in an empty list. 