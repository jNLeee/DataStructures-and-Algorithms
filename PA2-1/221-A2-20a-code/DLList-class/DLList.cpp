// implementation of the DLList class

#include <stdexcept>
#include "DLList.h"

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error
{
  explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList &dll)
{
  // Initializing
  header.next = &trailer;
  trailer.prev = &header;

  DLListNode *Node = &header;
  DLListNode *newNode = dll.header.next;

  while (newNode != &dll.trailer)
  {
    Node->next = new DLListNode(newNode->obj, Node, &trailer); 
    trailer.prev = Node->next;
    Node = Node->next; 
    newNode = newNode->next; 
  }
}
// move constructor
DLList::DLList(DLList &&dll)
{
  header.next = &trailer;
  trailer.prev = &header;

  if (!dll.is_empty())
  {
    header.next = dll.header.next;
    header.next->prev = &header;

    trailer.prev = dll.trailer.prev;
    trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  }
}

// copy assignment operator
DLList &DLList::operator=(const DLList &dll)
{
  if (this == &dll)
  {
    return *this;
  } 

  DLListNode *Node = header.next;

  // deleting
  while (Node != &trailer)
  {
    Node = Node->next;
    delete Node->prev;
  }

  // Initializing
  header.next = &trailer;
  trailer.prev = &header;

  Node = &header; 
  DLListNode *newNode = dll.header.next;

  while (newNode != &dll.trailer)
  {
    Node->next = new DLListNode(newNode->obj, Node, &trailer); 
    trailer.prev = Node->next;                                   
    Node = Node->next;                                      
    newNode = newNode->next;                               
  }

  return *this;
}

// move assignment operator
DLList &DLList::operator=(DLList &&dll)
{
  if (this == &dll)
  {
    return *this;
  } 

  DLListNode *Node = header.next;

  // deleting 
  while (Node != &trailer)
  {
    Node = Node->next;
    delete Node->prev;
  }

  // Initializing
  header.next = &trailer;
  trailer.prev = &header;

  if (!dll.is_empty())
  {
    header.next = dll.header.next;
    header.next->prev = &header;

    trailer.prev = dll.trailer.prev;
    trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  }

  return *this;
}

// destructor
DLList::~DLList()
{
  if (header.next != &trailer)
  {
    DLListNode *Node = header.next;
    while (Node != &trailer)
    {
      Node = Node->next;
      delete Node->prev;
    }
    header.next = &trailer;
    trailer.prev = &header;
  }
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{
  DLListNode *newNode = new DLListNode(obj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
  DLListNode *newNode = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first node from the list
int DLList::remove_first()
{
  if (is_empty())
  {
    throw EmptyDLList();
  }

  DLListNode *node = header.next;
  int first = node->obj;
  header.next = header.next->next;
  header.next->prev = &header;
  delete node;

  return first;
}

// remove the last node from the list
int DLList::remove_last()
{
  if (is_empty())
  {
    throw EmptyDLList();
  }

  DLListNode *node = trailer.prev;
  int last = node->obj;
  trailer.prev = trailer.prev->prev;
  trailer.prev->next = &trailer;
  delete node;

  return last;
}

// return the first object (do not remove)
int DLList::first() const
{
  if (is_empty())
  {
    throw EmptyDLList();
  }

  return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const
{
  if (is_empty())
  {
    throw EmptyDLList();
  }

  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  if (&p == &trailer)
  {
    throw EmptyDLList();
  } 

  p.next = new DLListNode(obj, &p, p.next);
  p.next->next->prev = p.next;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  if (&p == &header)
  {
    throw EmptyDLList();
  } 

  p.prev = new DLListNode(obj, p.prev, &p);
  p.prev->prev->next = p.prev;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
  if (is_empty())
  {
    throw EmptyDLList();
  }

  DLListNode *node = p.next;
  int value = node->obj;
  p.next = node->next;
  node->next->prev = &p;
  delete node;

  return value;
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  if (is_empty())
  {
    throw EmptyDLList();
  }

  DLListNode *node = p.prev;
  int value = node->obj;
  p.prev = node->prev;
  node->prev->next = &p;
  delete node;

  return value;
}

// output operator
ostream &operator<<(ostream &out, const DLList &dll)
{
  DLListNode *node = dll.first_node();

  while (node != dll.after_last_node())
  {
    if (node == dll.after_last_node()->prev)
    {
      out << node->obj << endl;
    }
    else
    {
      out << node->obj << ",";
    }
    node = node->next;
  }
  return out;
}
