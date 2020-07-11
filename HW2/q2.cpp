#include <iostream>
using namespace std;

struct Listnode  
{  
    int data;  
    Listnode* next;  
};  

int count (Listnode* node) 
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + count(node->next);
}

int main()
{
    Listnode* head = NULL; 
    Listnode* second = NULL; 
    Listnode* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = new Listnode(); 
    second = new Listnode(); 
    third = new Listnode(); 
  
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with second 
  
    second->data = 2; // assign data to second node 
    second->next = third; 
  
    third->data = 3; // assign data to third node 
    third->next = NULL; 

    cout << "The number of nodes in this singly linked list is " << count(head) << endl;
    return 0;
}