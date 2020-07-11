Justin Lee, 727000824, Sec 501, jlee232435, jlee232435@tamu.edu
Aggie Honor statement:

I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.

Your Name: Justin Lee           Date: 2/5/20

Resources:
Some resources used for implementing the sorts were https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/ and Dr.Leyk's lecture notes called Introduction to Analysis of Algorithms.

Issues:
There are no problems with the assignment as it compiles without any errors and outputs correctly. 

Short Code Description:
This assigment was separated into two parts where the first part consisted of creating the Collection class. The Collection class included the Rule of 5: destructor, copy constructor, copy assignment, move constructor, and move assignment.
Some other necessary functions for inserting, removing, resizing, empty flags, total counting, printing, and overloading the [] operator were implemented to be eventually used for the part 2 functions. For part 2, we were just implementing some bigger 
functions to read from a file, overload the << operator, combine 2 class objects into 1, swap the contents of 2 class objects, and to sort the contents of a class by size using bubble sort, insertion sort, or selection sort. 
In addition, the sorting function was done by using a switch statement option for the user to decide which sorting method they wanted to use to organize the stress ball data. Lastly, a collection_test.cpp was made to test and output the functions
from part 2 of the assignment. For example, the istream overloaded operator was used to fill the collection objects with stress balls from separate data files and then were sorted by size using bubble sort. Afterwards, they were printed out using the print_item
function. In addition, the make_union function was tested to make sure all the contents of c1 and c2 combined into c3 and the swap function was used to see that c1's contents could be switched into c2 and vice versa. All three sorts were also tested to make 
sure they all worked properly. 

Testing:
The program for this assignment was tested for correctness using the collection_test.cpp that we had to create on our own to implement several functions, such as sort_by_size(), print_items(), total_items(), and make_union().
They were outputted using a lot of cout statements to make sure that they functioned how they were suppose to. Although no uses of exceptions are shown in the final submitted collection_test.cpp, try and catch statements were used for testing the part 1 remove function
as shown below.

Ex. cout << "Testing remove_any_item():\n";
    try {
        array2.remove_any_item();
        array2.print_items();
        array2.print_s_c();
    } catch(const char *e) {
        cout << "Caught exception: " << e << endl;
    }

