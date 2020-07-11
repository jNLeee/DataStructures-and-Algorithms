#ifndef MINQUEUE_H
#define MINQUEUE_H
#include <iostream>
#include <stdexcept>
#include "TemplatedDLList.h"

template <typename T>
class MinQueue
{
private:
    DLList<T> q;
    int count;

public:
    MinQueue() : count(0){}
    void enqueue(T x);
    T dequeue();
    int size() { return count; }
    bool is_empty() const { return q.is_empty(); }
    T min();
};

template <typename T>
void MinQueue<T>::enqueue(T x)
{
    count++;
    q.insert_last(x);
}

template <typename T>
T MinQueue<T>::dequeue()
{
    if (is_empty())
    {
        throw EmptyDLList("Access to an empty queue");
    }
    count--;
    return q.remove_first();
}

template <typename T>
T MinQueue<T>::min()
{
    T min_val = q.first();
    DLListNode<T> *temp = q.first_node();
    while (temp != q.after_last_node())
    {
        if (temp->obj < min_val)
        {
            min_val = temp->obj;
        } 
        temp = temp->next;
    }
    return min_val;
}
#endif