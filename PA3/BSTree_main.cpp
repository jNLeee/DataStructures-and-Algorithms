#include <iostream>
#include <fstream>
#include <string>
#include "BSTree.h"

using namespace std;

BSTree read_file(string file_name)
{
  BSTree newTree;
  ifstream infile;
  int numberOfNodes = 0;
  int data;

  infile.open(file_name);
  if (!infile) //if invalid file
  {
    cout << "The input file " << file_name << " cannot be opened!" << endl;
  }
  while (infile >> data)
  {
    numberOfNodes++;
    newTree.insert(data);
  }
  infile.close();

  newTree.update_search_times();
  cout << "\nTotal number of nodes: " << numberOfNodes << endl;
  return newTree;
}

int main()
{
  // test the copy constructor
  cout << "\nCopy Constructor testing:" << endl;
  BSTree tree1;
  tree1.insert(4);
  tree1.insert(6);
  tree1.insert(7);
  tree1.insert(5);
  tree1.insert(2);
  tree1.insert(3);
  tree1.insert(1);
  tree1.update_search_times();

  BSTree tree2(tree1);
  cout << "Output of tree1 level by level:\n" << tree1 << endl;
  cout << "Output of tree2 level by level:\n" << tree2 << endl;
  
  // test the copy assignment
  cout << "Copy Assignment testing:" << endl;
  BSTree tree3;
  tree3 = tree2;
  cout << "Output of tree2 level by level:\n" << tree2 << endl;

  // test the move constructor
  cout << "\nMove Constructor testing:" << endl;
  cout << "Output of original tree2 level by level:\n" << tree2 << endl;
  BSTree tree4(move(tree2));
  cout << "Output of tree4 level by level after moving:\n" << tree4 << endl;
  cout << "Output of the moved tree2 level by level:\n" << tree2 << endl;
  
  // test the move assignment
  cout << "\nMove Assignment testing:" << endl;
  cout << "Output of original tree1 level by level:\n" << tree1 << endl;
  BSTree tree5 = move(tree1);
  cout << "Output of tree5 level by level after moving:\n" << tree5 << endl;
  cout << "Output of the moved tree1 level by level:\n" << tree1 << endl;
  
  ofstream outfile;
  for (int i = 1; i <= 12; i++)
  {
    string dir = "data-files/" + std::to_string(i);
    cout << endl << "---------------------------Testing of File " << i << "---------------------------";
    cout << endl << endl;

    //linear search files
    BSTree l = read_file(dir+"l");
    outfile.open(dir+"l.txt");
    outfile << "Inorder Traversal (Key[SearchCost]): ";
    l.inorder(outfile);
    cout << "Average linear search cost: " << l.get_average_search_time() << endl;
    if(l.get_size() < 17) 
    {
      outfile << endl << endl << "Tree level by level:" << endl << endl << l << endl;
      cout << "Inorder Traversal (Key[SearchCost]): ";
      l.inorder(cout); 
      cout << endl << "------------------------" << endl << "Tree level by level:" << endl << "------------------------" << endl << l << endl;
    }
    outfile.close();

    //perfect search files
    BSTree p = read_file(dir + "p");
    outfile.open(dir + "p.txt");
    outfile << "Inorder Traversal (Key[SearchCost]): ";
    p.inorder(outfile);
    cout << "Average perfect search cost: " << p.get_average_search_time() << endl;
    if(p.get_size() < 17) {
      outfile << endl << endl << "Tree level by level:" << endl << endl << p << endl;
      cout << "Inorder Traversal (Key[SearchCost]): ";
      p.inorder(cout);
      cout << endl << "------------------------" << endl << "Tree level by level:" << endl << "------------------------" << endl << p << endl;
    }
    outfile.close();

    //random search files
    BSTree r = read_file(dir + "r");
    outfile.open(dir + "r.txt");
    outfile << "Inorder Traversal (Key[SearchCost]): ";
    r.inorder(outfile);
    cout << "Average random search cost: " << r.get_average_search_time() << endl;
    if(r.get_size() < 17) 
    {
      outfile << endl << endl << "Tree level by level:" << endl << endl << r << endl;
      cout << "Inorder Traversal (Key[SearchCost]): ";
      r.inorder(cout);
      cout << endl << "------------------------" << endl << "Tree level by level:" << endl << "------------------------" << endl << r << endl;
    }
    outfile.close();

    if (i <= 4)
    {
      cout << "perfect tree " << i << endl;
    }

    cout << endl;
  }
}