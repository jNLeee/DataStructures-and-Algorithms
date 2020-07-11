#include <iostream>
#include <cstdlib>
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

int main()
{
    Collection c1;
    Collection c2;

    ifstream fin;
    fin.open("stress_ball1.data");
    if (!fin) // error in opening file
    {
        return -1;
    }
    while (!fin.eof()) // while not at the end
    {
        fin >> c1;
    }
    fin.close();

    fin.open("stress_ball2.data");
    if (!fin)
    {
        return -1;
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

    Collection c3;
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
    return 0;
}