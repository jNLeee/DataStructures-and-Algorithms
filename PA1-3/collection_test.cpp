#include <iostream>
#include <cstdlib>
#include "Collection.h"
#include "Stress_ball.h"
#include "Jeans.h"

using namespace std;

using CollectionSB = Collection<Stress_ball, Stress_ball_sizes, Stress_ball_colors>;
using CollectionJN = Collection<Jeans, Jeans_sizes, Jeans_colors>;

istream &operator>>(istream &is, CollectionSB &c)
{
    string color;
    string size;
    Stress_ball_colors tmpColor;
    Stress_ball_sizes tmpSizes;

    is >> color >> size;

    if (color == "red")
    {
        tmpColor = Stress_ball_colors::red;
    }
    else if (color == "blue")
    {
        tmpColor = Stress_ball_colors::blue;
    }
    else if (color == "yellow")
    {
        tmpColor = Stress_ball_colors::yellow;
    }
    else
    {
        tmpColor = Stress_ball_colors::green;
    }

    if (size == "small")
    {
        tmpSizes = Stress_ball_sizes::small;
    }
    else if (size == "medium")
    {
        tmpSizes = Stress_ball_sizes::medium;
    }
    else
    {
        tmpSizes = Stress_ball_sizes::large;
    }

    c.insert_item(Stress_ball(tmpColor, tmpSizes));

    return is;
}

istream &operator>>(istream &is, CollectionJN &c)
{
    string color;
    string size;
    Jeans_colors tmpColor;
    Jeans_sizes tmpSizes;

    is >> color >> size;

    if (color == "white")
    {
        tmpColor = Jeans_colors::white;
    }
    else if (color == "blue")
    {
        tmpColor = Jeans_colors::blue;
    }
    else if (color == "brown")
    {
        tmpColor = Jeans_colors::brown;
    }
    else
    {
        tmpColor = Jeans_colors::black;
    }

    if (size == "small")
    {
        tmpSizes = Jeans_sizes::small;
    }
    else if (size == "medium")
    {
        tmpSizes = Jeans_sizes::medium;
    }
    else if (size == "large")
    {
        tmpSizes = Jeans_sizes::large;
    }
    else 
    {
        tmpSizes = Jeans_sizes::xlarge;
    }

    c.insert_item(Jeans(tmpColor, tmpSizes));

    return is;
}

void test_stress_balls() 
{
    CollectionSB c1;
    CollectionSB c2;

    ifstream fin;
    fin.open("stress_ball1.data");
    if (!fin) // error in opening file
    {
        cout << "Error in opening file";
    }
    while (!fin.eof()) // while not at the end
    {
        fin >> c1;
    }
    fin.close();

    fin.open("stress_ball2.data");
    if (!fin)
    {
        cout << "Error in opening file";
    }
    while (!fin.eof())
    {
        fin >> c2;
    }
    fin.close();

    sort_by_size(c1, Sort_choice::bubble_sort);
    cout << "Printing out c1's contents after bubble sorting: \n";
    c1.print_items();
    cout << endl;
    sort_by_size(c2, Sort_choice::bubble_sort);
    cout << "Printing out c2's contents after bubble sorting: \n";
    c2.print_items();
    cout << endl;
    cout << "Number of stress balls of a given color in c1:\n";
    cout << "Red: " << c1.total_items(Stress_ball_colors::red) << endl;
    cout << "Blue: " << c1.total_items(Stress_ball_colors::blue) << endl;
    cout << "Yellow: " << c1.total_items(Stress_ball_colors::yellow) << endl;
    cout << "Green: " << c1.total_items(Stress_ball_colors::green) << endl;
    cout << endl;
    cout << "Total amount of stress balls in c1: " << c1.total_items() << endl;
    cout << endl;
    cout << "Number of stress balls of a given color in c2:\n";
    cout << "Red: " << c2.total_items(Stress_ball_colors::red) << endl;
    cout << "Blue: " << c2.total_items(Stress_ball_colors::blue) << endl;
    cout << "Yellow: " << c2.total_items(Stress_ball_colors::yellow) << endl;
    cout << "Green: " << c2.total_items(Stress_ball_colors::green) << endl;
    cout << endl;
    cout << "Total amount of stress balls in c2: " << c2.total_items() << endl;
    cout << endl;

    CollectionSB c3;
    c3 = c1;
    c3 = make_union(c1, c2);
    cout << "Printing c3's elements:\n";
    c3.print_items();
    cout << endl;
    cout << "Number of stress balls of a given color in c3:\n";
    cout << "Red: " << c3.total_items(Stress_ball_colors::red) << endl;
    cout << "Blue: " << c3.total_items(Stress_ball_colors::blue) << endl;
    cout << "Yellow: " << c3.total_items(Stress_ball_colors::yellow) << endl;
    cout << "Green: " << c3.total_items(Stress_ball_colors::green) << endl;
    cout << endl;
    cout << "Number of stress balls of a given size in c3:\n";
    cout << "Small: " << c3.total_items(Stress_ball_sizes::small) << endl;
    cout << "Medium: " << c3.total_items(Stress_ball_sizes::medium) << endl;
    cout << "Large: " << c3.total_items(Stress_ball_sizes::large) << endl;
    cout << endl;
    cout << "Total number of stress balls in c3: " << c3.total_items() << endl;
    cout << endl;

    swap(c1, c2);
    cout << "Printing c1's elements to check correct swapping:\n";
    c1.print_items();\
    cout << endl;
    cout << "Printing c2's elements to check correct swapping:\n";
    c2.print_items();
    cout << endl;

    sort_by_size(c1, Sort_choice::insertion_sort);
    cout << "Printing c1's elements to check insertion sort:\n";
    c1.print_items();
    cout << endl;
    sort_by_size(c1, Sort_choice::selection_sort);
    cout << "Printing c1's elements to check selection sort:\n";
    c1.print_items();   
}

void test_jeans() 
{
    CollectionJN c1;
    CollectionJN c2;

    ifstream fin;
    fin.open("jean1.data");
    if (!fin) // error in opening file
    {
        cout << "Error in opening file";
    }
    while (!fin.eof()) // while not at the end
    {
        fin >> c1;
    }
    fin.close();

    fin.open("jean2.data");
    if (!fin)
    {
        cout << "Error in opening file";
    }
    while (!fin.eof())
    {
        fin >> c2;
    }
    fin.close();

    sort_by_size(c1, Sort_choice::bubble_sort);
    cout << "Printing out c1's contents after bubble sorting: \n";
    c1.print_items();
    cout << endl;
    sort_by_size(c2, Sort_choice::bubble_sort);
    cout << "Printing out c2's contents after bubble sorting: \n";
    c2.print_items();
    cout << endl;
    cout << "Number of jeans of a given color in c1:\n";
    cout << "White: " << c1.total_items(Jeans_colors::white) << endl;
    cout << "Blue: " << c1.total_items(Jeans_colors::blue) << endl;
    cout << "Brown: " << c1.total_items(Jeans_colors::brown) << endl;
    cout << "Black: " << c1.total_items(Jeans_colors::black) << endl;
    cout << endl;
    cout << "Total amount of jeans in c1: " << c1.total_items() << endl;
    cout << endl;
    cout << "Number of jeans of a given color in c2:\n";
    cout << "White: " << c2.total_items(Jeans_colors::white) << endl;
    cout << "Blue: " << c2.total_items(Jeans_colors::blue) << endl;
    cout << "Brown: " << c2.total_items(Jeans_colors::brown) << endl;
    cout << "Black: " << c2.total_items(Jeans_colors::black) << endl;
    cout << endl;
    cout << "Total amount of jeans in c2: " << c2.total_items() << endl;
    cout << endl;

    CollectionJN c3;
    c3 = c1;
    c3 = make_union(c1, c2);
    cout << "Printing c3's elements:\n";
    c3.print_items();
    cout << endl;
    cout << "Number of jeans of a given color in c3:\n";
    cout << "White: " << c3.total_items(Jeans_colors::white) << endl;
    cout << "Blue: " << c3.total_items(Jeans_colors::blue) << endl;
    cout << "Brown: " << c3.total_items(Jeans_colors::brown) << endl;
    cout << "Black: " << c3.total_items(Jeans_colors::black) << endl;
    cout << endl;
    cout << "Number of jeans of a given size in c3:\n";
    cout << "Small: " << c3.total_items(Jeans_sizes::small) << endl;
    cout << "Medium: " << c3.total_items(Jeans_sizes::medium) << endl;
    cout << "Large: " << c3.total_items(Jeans_sizes::large) << endl;
    cout << "Xlarge: " << c3.total_items(Jeans_sizes::xlarge) << endl;
    cout << endl;
    cout << "Total number of stress balls in c3: " << c3.total_items() << endl;
    cout << endl;

    swap(c1, c2);
    cout << "Printing c1's elements to check correct swapping:\n";
    c1.print_items();\
    cout << endl;
    cout << "Printing c2's elements to check correct swapping:\n";
    c2.print_items();
    cout << endl;

    sort_by_size(c1, Sort_choice::insertion_sort);
    cout << "Printing c1's elements to check insertion sort:\n";
    c1.print_items();
    cout << endl;
    sort_by_size(c1, Sort_choice::selection_sort);
    cout << "Printing c1's elements to check selection sort:\n";
    c1.print_items();    
}

int main()
{
    int answer; 
    cout << "What version to test: stress_ball (=0) or jeans (=1): "; 
    cin >> answer; 
    if (answer == 0) 
    {
        test_stress_balls(); 
    }
    else if (answer == 1) 
    {
        test_jeans();
    }
    else 
    {
        cout << "Wrong value: " << answer << endl; 
    }
    return 0;
}