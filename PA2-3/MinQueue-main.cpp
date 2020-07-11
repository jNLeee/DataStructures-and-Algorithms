// testing the templated class MinQueue

#include <iostream>
#include <cstdio>
#include "TemplatedDLList.h"
#include "MinQueue.h"

using namespace std;

int main()
{
  cout << "Create a new list" << endl;
  MinQueue<int> q;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i = 10; i <= 100; i += 10)
  {
    q.enqueue(i);
  }
  cout << q.size() << endl;

  cout << "Delete the first 5 nodes" << endl;
  for (int i = 0; i < 5; i++)
  {
    q.dequeue();
  }
  cout << q.size() << endl;
  cout << "Find min value in the list of nodes: ";
  cout << q.min() << " is the min value in the list of nodes";

  return 0;
}
