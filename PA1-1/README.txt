Justin Lee, 727000824, Sec 501, jlee232435, jlee232435@tamu.edu
Aggie Honor statement:

I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.

Your Name: Justin Lee           Date: 1/21/20

There were no other outside resources used for this assignment as well as no known problems.

A collection was created by writing a Stress_ball class. The Stress_ball.h had the enum classes for the four colors (red, blue, yellow, green) and three sizes 
(small, medium, large) placed outside the public class of Stress_ball. Inside the public were the declarations of the default constructor and the parameterized constructor, 
the two member functions for get_color() and get_size(), and lastly the == operator. In the private class of Stress_ball, the variable color from the Stress_ball_colors 
enum class and the variable size from the Stress_ball_size enum class were declared here. Outside Stress_ball class was the overloading of the extraction operator, which 
is defined in the Stress_ball.cpp.

In the Stress_ball.cpp, it had the constructor initialization list assign color with one of four randomized colors and size with one of three randomized sizes. The member function get_color() was 
defined to return color and get_size() to return size. The == operator was overloaded to check for any comparisons matched. If both the color and size 
were to match with one of the test sets then it would return true, otherwise it would return false. Then the extraction operator used one set of switch case statements to print out the color form "(color," and 
another set was used for the size form " size)". 

No exceptions were used for error handling for this assignment because there was no need for them as there weren't any input errors to be handled in this program. 
The program was also tested for correctness by using the given Stress_ball_test.cpp file, which had premade comparison tests. 