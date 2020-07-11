#include "graph.h"

// Graph::Graph(){} //don't need

Graph::~Graph()
{
    if (adj_list.size() != 0 && node_list.size() != 0) {
        for (int i = 0; i < adj_list.size(); i++)
        {
            delete adj_list[i];
        }
    }
}

void Graph::buildGraph(ifstream &input)
{
    int vert1, vert2;

    while (input >> vert1)
    {
        Vertex v(vert1); //create vertex for current label
        node_list.push_back(v);

        list<int>* adj = new list<int>(); //pointer to an array containing adj lists
        input >> vert2;
        while (vert2 != -1)
        {
            (*adj).push_back(vert2);
            input >> vert2;
        }
        adj_list.push_back(adj);
    }
}

void Graph::displayGraph()
{
    cout << "\nPrinting the DAG: " << endl;
    for (int i = 0; i < node_list.size(); i++)
    {
        cout << node_list[i].label << " : ";
        for (list<int>::iterator it = (*adj_list[i]).begin(); it != (*adj_list[i]).end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

