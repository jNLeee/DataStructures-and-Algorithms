#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//extend runtime_error from <stdexcept>
struct CycleFound : public std::runtime_error
{
    explicit CycleFound(char const *msg = nullptr) : runtime_error(msg) {}
};

struct Vertex {
  int label; // unique int for a vertex
  int indegree; // Part 2
  int top_num; // Part 2: topological sorting number
  Vertex(int l) : label(l) {}
  Vertex(int l, int ind) : label(l), indegree(ind) {} //Part 2
};

class Graph {
private:
  vector<int> sorted;
  vector<Vertex> node_list;
  vector<list<int>*> adj_list; 
public:
  //Graph() {};  // default constructor
  ~Graph();
  // build a graph
  void buildGraph(ifstream &input);
  // display the graph
  void displayGraph();
  // topological sort
  void topological_sort(); // Part 2
  // find indegree
  void compute_indegree(); // Part 2
  // print topological sort
  void print_top_sort();  // Part 2
};

#endif
