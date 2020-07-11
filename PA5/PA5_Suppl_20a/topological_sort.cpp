// topological sort

#include <iostream>
#include "graph.h"

void Graph::compute_indegree()
{
  for (int i = 0; i < node_list.size(); i++) //initializing all indegrees to zero
  {
    node_list[i].indegree = 0;
  }
  for (int i = 0; i < node_list.size(); i++) //filling indegrees of the nodes
  {
    for (list<int>::iterator it = (*adj_list[i]).begin(); it != (*adj_list[i]).end(); it++)
    {
      ++node_list[*it-1].indegree; 
    }
  }
}

void Graph::topological_sort()
{
  compute_indegree(); //calling helper function compute_indegree here
  queue<int> q; //creating the queue
  int count = 0; //initializing the counter for the visited vertices

  while (!q.empty()) //emptying the queue
  {
    q.pop();
  }

  for (int i = 0; i < node_list.size(); i++) //enqueuing all the vertices with indegree 0
  {
    if (node_list[i].indegree == 0)
    {
      q.push(node_list[i].label);
    }
  }

    sorted.clear();

  while (!q.empty())
  {
    //dequeue and then add to sorted vector
    int v = q.front();
    q.pop();
    sorted.push_back(v);
    for (list<int>::iterator it = (*adj_list[v-1]).begin(); it != (*adj_list[v-1]).end(); it++) //go through adjacent nodes of dequeued node v and reduce the indegree by 1
    {
      if (--node_list[*it-1].indegree == 0)
      {
        q.push(*it);
      }
    } 
    count++;
  }

  if (count != node_list.size()) //check for cycles
  {
    throw CycleFound();
    return;
  }
}

void Graph::print_top_sort() //printing the topological sorting vector by printing the labels of vertices
{
  cout << "\nPrinting the topological sort ordering vector: ";
  for (int i = 0; i < sorted.size(); i++)
  {
    cout << sorted[i] << " "; 
  }
  cout << endl;
}
