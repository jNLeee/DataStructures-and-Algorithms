Justin Lee, 727000824, Sec 501, jlee232435, jlee232435@tamu.edu
Aggie Honor statement:

I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.

Your Name: Justin Lee           Date: 2/16/20

Resources:
Some resources used for implementing the sorts were https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/ and Dr.Leyk's lecture notes called Introduction to Analysis of Algorithms.

Issues:
There are no problems with the assignment as it compiles without any errors and outputs correctly. 

Short Code Description:
This assignment focused on templating the Collection class using the template parameters Obj, F1, and F2 for ease of use with multiple classes like Stress_ball and Jeans. The operator >> was also templated using a specific alias such as
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> inside the collection_test.cpp instead of the Stress_ball_test.cpp as well as the jeans_test.cpp for simplification of test files. 
Another Jeans class was made very similar to the Stress_ball class except by using a different enum color class with white, blue, brown, and black and a enum size class with small, medium, large, and xlarge. Lastly, the collection_test.cpp
was modified from the part 2 assignment by now offering the user to test between either the Stress_ball class with an input of 0 or the Jeans class with an input of 1.  


Testing:
The program for this assignment was tested for correctness using the Stress_ball_test.cpp, jeans_test.cpp, and the collection_test.cpp. that we had to create on our own to implement several functions, such as sort_by_size(), print_items(), total_items(), and make_union().
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

Generic Programming Written Portion:

Generic programming is used to improve the efficiency of code by allowing type to be a parameter to functions, classes, and interfaces. 
This is implemented using templates: templating provides a way for functions and classes to perform with generic types, thus allowing them to operate on various data types without
having issues of being rewritten every time. They are also especially useful when doing inheritance or operator overloading. Templating particularly 
relates to this assignment as it required the use of two of the three types of templates: function templates and class templates. More specifically, 
the assignment required the templating of the Collection class using the parameters Obj (for Stress_ball and Jeans class), F1 (for Stress_ball_colors and Jeans_colors), and F2 
(for Stress_ball_sizes and Jean_sizes) so that it could be used with the Stress_ball class and Jeans class for testing of certain outputs and functions. For example, 
the input operator>> for Stress_ball was templated using a specific version istream& operator>>(istream& is, CollectionSB& c), while also including an alias to shorten the long class names with 
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> instead. This shows how generic programming can be used to prevent unneccesary 
repetition of code especially when having to template with multiple classes, which can lead to having long class names. 