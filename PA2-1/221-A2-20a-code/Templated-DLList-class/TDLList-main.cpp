// testing the templated class DLList

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "TemplatedDLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<string> dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_last(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_first(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // Checking for remove_after and remove_before
  cout << "Testing remove_before() and remove_after() on list2" << endl;
  DLListNode<string> *node2 = dll2.first_node()->next->next;
  cout << "Selected element: " << node2->obj << endl;
  string a = dll2.remove_after(*node2);
  string b = dll2.remove_before(*node2);
  cout << "list2: " << dll2 << endl;
  cout << "Removed elements: " << a << ", " << b << endl << endl;

  // Checking for insert_after and insert_before
  cout << "Testing insert_before() and insert_after() on list3" << endl;
  DLListNode<string> *node3 = dll3.first_node()->next->next->next;
  cout << "Selected element: " << node3->obj << endl;
  dll3.insert_before(*node3, "before");
  dll3.insert_after(*node3, "after");
  cout << "list3: " << dll3 << endl;
  
  return 0;
}
