#include "BSTree.h"

// input / output operators
ostream &operator<<(ostream &out, BSTree &tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream &operator<<(ostream &out, Node node)
{
  return out << "( " << node.value << ", " << node.search_time << " )";
}

istream &operator>>(istream &in, BSTree &tree)
{
  int next;
  while (in >> next)
  {
    tree.insert(next);
  }
  return in;
}

// copy constructor
BSTree::BSTree(const BSTree &other)
{
  if (other.root == nullptr) 
  {
    root = nullptr;
    size = 0;
    return;
  }
  root = new Node(other.root->value);
  root->search_time = other.root->search_time; 
  copy_helper(root, other.root);
  this->update_search_times();
}

// move constructor
BSTree::BSTree(BSTree &&other)
{
  root = other.root;
  size = other.size;
  other.root = nullptr;
  other.size = 0;
}

//copy assignment
BSTree &BSTree::operator=(const BSTree &other)
{
  if (this == &other) 
  { 
    return *this; 
  } 

  delete_helper(root);

  if (other.root == nullptr) 
  {
    root = nullptr;
    size = 0;
    return *this;
  }

  root = new Node(other.root->value);
  root->search_time = other.root->search_time;
  copy_helper(root, other.root);
  return *this;
}

// move assignment
BSTree &BSTree::operator=(BSTree &&other)
{
  delete_helper(root);
  root = other.root;
  size = other.size;
  other.root = nullptr;
  other.size = 0;
  return *this;
}

// destructor
BSTree::~BSTree()
{
  delete_helper(root);
  root = nullptr;
}

void BSTree::delete_helper(Node *root)
{
  if (root == nullptr)
  {
    return; // nothing to delete
  }
  if (root->left != nullptr)
  {
    delete_helper(root->left);
  }
  if (root->right != nullptr)
  {
    delete_helper(root->right);
  }
  delete root;
}

// recursive
void BSTree::copy_helper(Node *copy_to,
                         const Node *copy_from) const
{
  if (copy_from == nullptr)
    return;

  if (copy_from->left != nullptr)
  {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  }
  else
  {
    copy_to->left = nullptr;
  }

  if (copy_from->right != nullptr)
  {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  }
  else
  {
    copy_to->right = nullptr;
  }
}

Node *BSTree::insert(int obj)
{
  size++;
  root = insert_helper(obj, root);
  return nullptr;
}

Node *BSTree::insert_helper(int obj, Node *node)
{
  if (node == nullptr)
  {
    node = new Node(obj);
  }
  else if (obj < node->value)
  {
    node->left = insert_helper(obj, node->left);
  }
  else if (obj > node->value)
  {
    node->right = insert_helper(obj, node->right);
  }
  else
  {
    throw "Access to a duplicate item";
  }
  return node;
}

Node *BSTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    if you dont find anything return null
  */
  return search_helper(obj, root);
}

Node *BSTree::search_helper(int obj, Node *node)
{
  if (node == nullptr)
  {
    return nullptr;
  }
  else if (obj == node->value)
  {
    return node;
  }
  else if (obj < node->value)
  {
    search_helper(obj, node->left);
  }
  else if (obj > node->value)
  {
    search_helper(obj, node->right);
  }
}

void BSTree::update_search_times()
{
  /*
    do a BFS or DFS of your tree and update the searchtimes of all nodes
  */
  int depth = 0;
  vector <Node*> current_level;
  vector <Node*> next_level;
  current_level.push_back(root);
  while (!current_level.empty())
  {
    depth++;
    for (auto node : current_level)
    {
      if (node != nullptr)
      {
        node->search_time = depth;
        if (node->left != nullptr)
        {
          next_level.push_back(node->left);
        }
        if (node->right != nullptr)
        {
          next_level.push_back(node->right);
        }
      }
    }
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }
}

ostream &BSTree::inorder(ostream &out)
{
  /*
    print your nodes in infix order
    if our tree looks like 

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
  return inorder_helper(root, out);
}

ostream &BSTree::inorder_helper(Node *node, ostream &out)
{
  if (node == nullptr)
  {
    return out;
  }
  inorder_helper(node->left, out);
  pretty_print_node(out, node);
  inorder_helper(node->right, out);
  return out;
}

// implemented
void BSTree::pretty_print_node(ostream &out, Node *node)
{
  out << node->value << "[" << node->search_time << "] ";
}

// implemented
ostream &BSTree::print_level_by_level(ostream &out)
{
  /*
    print the tree using a BFS 
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */

  if (root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node *> current_level;
  vector<Node *> next_level;
  current_level.push_back(root);
  while (hasNodes)
  {
    hasNodes = false;
    for (auto node : current_level)
    {
      if (node != nullptr)
      {
        pretty_print_node(out, node);
        if (node->left != nullptr)
          hasNodes = true;
        if (node->right != nullptr)
          hasNodes = true;

        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
      else
      {
        out << "X ";
        next_level.push_back(nullptr);
        next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
}

// implemented
int BSTree::get_total_search_time(Node *node)
{
  if (node == nullptr)
    return 0;

  return get_total_search_time(node->left) + get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if (total_search_time == 0)
    return -1;

  return ((float)total_search_time) / size;
}
