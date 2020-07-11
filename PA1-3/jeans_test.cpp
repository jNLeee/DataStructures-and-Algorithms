#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jeans.h"
#include "Collection.h"

using namespace std;

int main(){
  srand(time(NULL));
  
  cout << "Default constructor test:\n";
  Jeans arr_test[5];
  for(int i = 0; i < 5; i++){
    arr_test[i] = Jeans();
    cout << i << ": " << arr_test[i] << endl;
  }

  cout << "\nTwo arg constructor test:\n";
  Jeans test2(Jeans_colors::white, Jeans_sizes::small);
  cout << test2 << endl;

  Jeans test3(Jeans_colors::black, Jeans_sizes::large);
  cout << test3 << endl;

  cout << "\nCompare stress balls:\n";
  for (int i = 0; i < 5; i++) {
    if (arr_test[i] == test2) {
      cout << "arr_test[" << i << "] equal test2\n";
    } else if (arr_test[i] == test3) {
      cout << "arr_test[" << i << "] equal test3\n";
    } else {
      cout << "arr_test[" << i << "] not equal test2 nor test3\n";
    }
  }  
}