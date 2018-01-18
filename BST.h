#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BinarySearchTree {

 public:
  typedef string KeyTy;
  typedef int ValueTy;
  typedef void (*TraversalFunction)(const KeyTy& key, ValueTy& value);
  
  class BSTNode{
  public:
    
    // Purpose: Constructor
    //
    // Pre: None.
    // Post: A Node is created.
    BSTNode(const KeyTy& key, const ValueTy& value, 
            BSTNode* left = NULL,  BSTNode* right = NULL);
    
    KeyTy Key;
    BSTNode* Right;
    ValueTy Value;
    BSTNode* Left;
  };
  
  // Purpose: Constructor
  //
  // Pre: None.
  // Post: An empty tree is created.
  BinarySearchTree();
  
  // Purpose: Destructor
  //
  // Pre: None.
  // Post: All memory associated with the tree has been freed.
  ~BinarySearchTree();
  
  // Purpose: Inserts the key and associated value into the tree.
  //
  // Pre: None.
  // Post: The key and value have been successfully placed in the tree.
  void insert(const KeyTy& key, const ValueTy& value);
  
  // Purpose: Finds a value in the tree using the key
  //
  // Pre: None.
  // Post: Searches for key in the tree. If found, value will be set to the
  // value associated with the key in the tree. If the value is returned through
  // the parameter, the True is returned. Otherwise, False is returned.
  bool search(const KeyTy& key, ValueTy& value) const;
  
  // Purpose: Removes a key and value from the tree
  //
  // Pre: The key exists in the tree.
  // Post: The key and associated value are removed from the tree.
  void remove(const KeyTy& key);
  
  // Purpose: Determines if a tree is empty
  //
  // Pre: None
  // Post: Returns True if the tree contains no key/value pairs, False otherwise
  bool empty() const;
  
  // Purpose: Returns number of key/value pairs in the tree
  //
  // Pre: None.
  // Post: Returns the number of keys stored in the tree.
  size_t size() const;
  
  // Purpose: Determine the height of the tree
  //
  // Pre: None.
  // Post: Returns the height of the highest leaf in the tree.
  // An empty tree has height 0, a tree with 1 key has height 1
  size_t height() const;
  
  // Purpose: Visits each node in order (in key order)
  //
  // Pre: None.
  // Post: Each node in the tree is "visited" by calling func with each
  // key and value, in "in-order" order
  void inorder(TraversalFunction func) const;
  
  // Purpose: Visits each node in postorder (children first, then root)
  //
  // Pre: None
  // Post: Each node in the tree is "visited" by calling func with each
  // key and value, in "post-order" order.
  void postorder(TraversalFunction func) const;
  
  // Purpose: Visits each node in preorder (root first, then children)
  //
  // Pre: None.
  // Post: Each node in the tree is "visited" by calling func with each
  // key and value, in "pre-order" order.
  void preorder(TraversalFunction func) const;
  
  // Purpose: Displays the tree's representation in a useful way
  //
  // Pre: None.
  // Post: The tree is output in such a way that its structure can be gleaned
  void print() const;
  
 private:
  
  size_t Size;
  BSTNode* Root;
  
};


#endif
