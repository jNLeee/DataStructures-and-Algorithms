// header file for the templated DLList
#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error
{
    explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

// doubly linked list node
template <typename T>
struct DLListNode
{
    T obj;
    DLListNode<T> *prev, *next;
    // constructor
    DLListNode(T obj = T(), DLListNode<T> *p = nullptr, DLListNode<T> *n = nullptr)
        : obj(obj), prev(p), next(n) {}
};

// doubly linked list class
template <typename T>
class DLList
{
private:
    DLListNode<T> header, trailer;

public:
    DLList() : header(T()), trailer(T()) // default constructor
    {
        header.next = &trailer;
        trailer.prev = &header;
    }
    DLList(const DLList<T> &dll);               // copy constructor
    DLList(DLList<T> &&dll);                    // move constructor
    ~DLList();                                  // destructor
    DLList<T> &operator=(const DLList<T> &dll); // copy assignment operator
    DLList<T> &operator=(DLList<T> &&dll);      // move assignment operator
    // return the pointer to the first node
    DLListNode<T> *first_node() const { return header.next; }
    // return the pointer to the trailer
    const DLListNode<T> *after_last_node() const { return &trailer; }
    // return if the list is empty
    bool is_empty() const { return header.next == &trailer; }
    T first() const;          // return the first object
    T last() const;           // return the last object
    void insert_first(T obj); // insert to the first node
    T remove_first();         // remove the first node
    void insert_last(T obj);  // insert to the last node
    T remove_last();          // remove the last node
    void insert_after(DLListNode<T> &p, T obj);
    void insert_before(DLListNode<T> &p, T obj);
    T remove_after(DLListNode<T> &p);
    T remove_before(DLListNode<T> &p);
};

// copy constructor
template <typename T>
DLList<T>::DLList(const DLList<T> &dll)
{
    // Initializing
    header.next = &trailer;
    trailer.prev = &header;

    DLListNode<T> *Node = &header;
    DLListNode<T> *newNode = dll.header.next;

    while (newNode != &dll.trailer)
    {
        Node->next = new DLListNode<T>(newNode->obj, Node, &trailer); 
        trailer.prev = Node->next;
        Node = Node->next; 
        newNode = newNode->next; 
    }
}

// move constructor
template <typename T>
DLList<T>::DLList(DLList<T> &&dll)
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
template <typename T>
DLList<T> &DLList<T>::operator=(const DLList<T> &dll)
{
    if (this == &dll)
    {
        return *this;
    } 

    DLListNode<T> *Node = header.next;

    // deleting
    while (Node != &trailer)
    {
        Node = Node->next;
        delete Node->prev;
    }

    // initializing 
    header.next = &trailer;
    trailer.prev = &header;

    Node = &header; 
    DLListNode<T> *newNode = dll.header.next;

    while (newNode != &dll.trailer)
    {
        Node->next = new DLListNode<T>(newNode->obj, Node, &trailer); 
        trailer.prev = Node->next;                                  
        Node = Node->next;                                   
        newNode = newNode->next;                                          
    }

    return *this;
}

// move assignment operator
template <typename T>
DLList<T> &DLList<T>::operator=(DLList<T> &&dll)
{
    if (this == &dll)
    {
        return *this;
    }

    DLListNode<T> *Node = header.next;

    // deleting 
    while (Node != &trailer)
    {
        Node = Node->next;
        delete Node->prev;
    }

    // initializing
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
template <typename T>
DLList<T>::~DLList()
{
    if (header.next != &trailer)
    {
        DLListNode<T> *Node = header.next;
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
template <typename T>
void DLList<T>::insert_first(T obj)
{
    DLListNode<T> *node = new DLListNode<T>(obj, &header, header.next);
    header.next->prev = node;
    header.next = node;
}

// insert a new object as the last one
template <typename T>
void DLList<T>::insert_last(T obj)
{
    DLListNode<T> *node = new DLListNode<T>(obj, trailer.prev, &trailer);
    trailer.prev->next = node;
    trailer.prev = node;
}

// remove the first node from the list
template <typename T>
T DLList<T>::remove_first()
{
    if (is_empty())
    {
        throw EmptyDLList();
    }

    DLListNode<T> *node = header.next;
    T first = node->obj;
    header.next = header.next->next;
    header.next->prev = &header;
    delete node;

    return first;
}

// remove the last node from the list
template <typename T>
T DLList<T>::remove_last()
{
    if (is_empty())
    {
        throw EmptyDLList();
    }

    DLListNode<T> *node = trailer.prev;
    T last = node->obj;
    trailer.prev = trailer.prev->prev;
    trailer.prev->next = &trailer;
    delete node;

    return last;
}

// return the first object (do not remove)
template <typename T>
T DLList<T>::first() const
{
    if (is_empty())
    {
        throw EmptyDLList();
    }

    return header.next->obj;
}

// return the last object (do not remove)
template <typename T>
T DLList<T>::last() const
{
    if (is_empty())
    {
        throw EmptyDLList();
    }

    return trailer.prev->obj;
}

// insert a new node after the node p
template <typename T>
void DLList<T>::insert_after(DLListNode<T> &p, T obj)
{
    if (&p == &trailer)
    {
        throw EmptyDLList();
    } 

    p.next = new DLListNode<T>(obj, &p, p.next);
    p.next->next->prev = p.next;
}

// insert a new node before the node p
template <typename T>
void DLList<T>::insert_before(DLListNode<T> &p, T obj)
{
    if (&p == &header)
    {
        throw EmptyDLList();
    } 

    p.prev = new DLListNode<T>(obj, p.prev, &p);
    p.prev->prev->next = p.prev;
}

// remove the node after the node p
template <typename T>
T DLList<T>::remove_after(DLListNode<T> &p)
{
    if (is_empty())
    {
        throw EmptyDLList();
    }

    DLListNode<T> *node = p.next;
    T value = node->obj;
    p.next = node->next;
    node->next->prev = &p;
    delete node;

    return value;
}

// remove the node before the node p
template <typename T>
T DLList<T>::remove_before(DLListNode<T> &p)
{
    if (is_empty())
    {
        throw EmptyDLList();
    }

    DLListNode<T> *node = p.prev;
    T value = node->obj;
    p.prev = node->prev;
    node->prev->next = &p;
    delete node;

    return value;
}

// output operator
template <typename T>
ostream &operator<<(ostream &out, const DLList<T> &dll)
{
    DLListNode<T> *node = dll.first_node();
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

#endif