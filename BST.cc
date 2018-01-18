#include <iostream>
#include "BST.h"

using namespace std;

typedef string KeyTy;
typedef int ValueTy;
typedef void (*TraversalFunction)(const KeyTy& key, ValueTy& value);

BinarySearchTree::BSTNode::BSTNode(const KeyTy& key, 
                                   const ValueTy& value, BSTNode* left, 
                                   BSTNode* right) {
  
  //initializes BSTNode
   Key = key;	
   Right = right;
   Value = value;
   Left = left;
}

void insertHelper(const KeyTy& key,const ValueTy& value, 
                  BinarySearchTree::BSTNode*& pointer) {
  
  //if pointer is NULL, create a new node and assign key and value
  if(pointer == NULL){
    pointer = new BinarySearchTree::BSTNode(key, value);
  }
  else {
    
    //if tree is not empty and key is greater or equal to the present node key
    //call helper function recursively and pass right pointer
    if(key >= pointer -> Key) {
      insertHelper(key, value, pointer -> Right);
    }
    else {
      
      //if tree is not empty and key is not greater or requal to the
      // than present node key, call helper function recursively and 
      //pass left pointer
      insertHelper(key, value, pointer -> Left);
    }
  } 
}


bool searchHelper(const KeyTy& key, ValueTy& value, 
                  BinarySearchTree::BSTNode* pointer) {
  
  //if pointer is NULL, return false as the required node is not
  //in this section of the tree 
  if(pointer == NULL) {
    return false;
  }
  else {
    
    //if current node has the required key, change the value of referenced
    //value to the value of the node and return true
    if(pointer -> Key == key) {
      value = pointer -> Value;
      return true;
    }
    else {
      
      //if current node has a key greater or equal to required key
      // call helper function recursively and pass the right pointer
      if(key >= pointer -> Key) {
        return searchHelper(key, value, pointer -> Right);
      }
      else {
        
        //if current node has a key that is not greater or equal to the
        //required key, call helper function recursively and pass the
        //left pointer
        return  searchHelper(key, value, pointer -> Left);
      }
    }
  }
}


bool removeHelper(BinarySearchTree::BSTNode*& pointer, const KeyTy key) {
  
  //if pointer isn't NULL
  if(pointer != NULL) {
      
    //if key is equal to current node key
    if(pointer -> Key ==  key) {
      
      //if the left and right pointers of current node are null delete
      // current node, set pointer to null and return true
      if(pointer -> Left == NULL && pointer -> Right == NULL) {
        delete pointer;
        pointer = NULL;
        return true;
      }
      else {
        
        //if the left pointer is null but the right is not delete node and
        // have pointer point at the node to the right of the deleted 
        //node and return true
        if(pointer -> Left == NULL && pointer -> Right != NULL) {
          BinarySearchTree::BSTNode* temporaryPointer = pointer;
          pointer = pointer -> Right;
          delete temporaryPointer;
          return true;
        }
        else {
          
          
          //if the right pointer is null but the left is not delete node and 
          //have pointer point at the node to the left of the deleted node 
          //and return true
          if(pointer -> Right == NULL && pointer -> Left != NULL) {
            BinarySearchTree::BSTNode* temporaryPointer = pointer;
            pointer = pointer -> Left;
            delete temporaryPointer;
            return true;
          }
          else {
            
            //in the case that both pointers are not NULL
            if(pointer -> Right != NULL and pointer -> Left != NULL) {
              BinarySearchTree::BSTNode* temporaryMainPointer;
              BinarySearchTree::BSTNode* temporaryFollowingPointer;
              
              //traverse the tree below current node by moving right 
              //once and then move left until the new node's left 
              //pointer is null
              temporaryMainPointer = pointer -> Right;
              temporaryFollowingPointer = pointer;
              
              //The actual process of traversal with 2 pointers
              while(temporaryMainPointer -> Left != NULL) {
                temporaryFollowingPointer = temporaryMainPointer;
                temporaryMainPointer = temporaryMainPointer -> Left;
              }
              
              //Swap the key and value of the new node with the 
              //original node
              pointer -> Key = temporaryMainPointer -> Key;
              pointer -> Value = temporaryMainPointer -> Value;
              
              //If there are nodes to the right of new node attach 
              //them to the left pointer of the node before for the
              // case where taversal took place
              if( temporaryMainPointer -> Right != NULL && pointer !=
                  temporaryFollowingPointer)
                temporaryFollowingPointer -> Left = temporaryMainPointer 
                  -> Right;
              
              //If there are nodes to the right of new node attach
              // them to the left pointer of the node before for 
              //the case where traversal did not take place
              if(temporaryFollowingPointer == pointer)
                pointer -> Right = temporaryMainPointer -> Right;
              
              //delete the new node and return true
              delete temporaryMainPointer;
              return true;
            }
          }
        }
      }
    } 
    else {
      
      //if key is greater or equal to the current node key
      // value call helper function recursively and 
      //pass the right pointer
      if(key >=  pointer -> Key)
        return removeHelper(pointer -> Right, key);
      else
        
        //else call the helper function recursively and pass the left pointer
        return removeHelper(pointer -> Left, key);
    }
  }
  
  //if the pointer is NULL, return false
  return false;
}

void inorderHelper(BinarySearchTree::BSTNode* pointer,
                   TraversalFunction func) {
  
  //traverse tree by calling helper function
  //recursively and  passing left pointer
  if(pointer -> Left != NULL)
    inorderHelper(pointer -> Left, func);
  
  //call the function passed via paramters
  func(pointer -> Key, pointer -> Value);
  
  //traverse tree by calling helper function
  //recursively and passing right pointer 
  if(pointer -> Right != NULL)
    inorderHelper(pointer -> Right, func);
}

void preorderHelper(BinarySearchTree::BSTNode* pointer,
                    TraversalFunction func) {
  
  //call the function passed via parameters
  func(pointer -> Key, pointer -> Value);
  
  //traverse tree by calling helper function
  //recursively and passing left pointer
  if(pointer -> Left != NULL)
    preorderHelper(pointer -> Left, func);
  
  //traverse tree by calling helper function
  //recursively and passing right pointer
  if(pointer -> Right != NULL)
    preorderHelper(pointer -> Right, func);
}

void postorderHelper(BinarySearchTree::BSTNode* pointer,
                     TraversalFunction func) {
  
  //traverse tree by calling helper function
  //recursively and passing left pointer
  if(pointer -> Left != NULL)
    postorderHelper(pointer -> Left, func);
  
  //traverse tree by calling helper function
  //recursively and passing right pointer
  if(pointer -> Right != NULL)
    postorderHelper(pointer -> Right, func);
  
  //call the function passed via parameters
  func(pointer -> Key, pointer -> Value);
}  

void printHelper(BinarySearchTree::BSTNode* pointer) {
  
  //print out a tree, depicting which nodes are 
  //empty and which are not
  if(pointer == NULL) {
    cout << " empty";
  }
  else {
  cout  <<  "key "<< pointer -> Key;
  cout << " value " << pointer-> Value ;
  cout << " ( ";
  printHelper(pointer -> Left);
    cout << " )";
  cout<< ", ";
  cout << "( ";
  printHelper(pointer -> Right);
  cout << " )";
  }
}

size_t sizeHelper(BinarySearchTree::BSTNode* pointer, size_t number) {
  
  size_t nullT = 0;
  size_t addLeft = 0;
  size_t addRight = 0;
  
  //if pointer is not null call function
  //recursively for both right and left
  //pointers and add up their values
  if(pointer != NULL) {
    addLeft = (sizeHelper(pointer -> Left, number));
    addRight = (sizeHelper(pointer -> Right, number));
    number = number + addLeft + addRight;
    number ++;
    return number;
  }
  
  //if pointer is null return 0
  return nullT;
}

size_t heightHelper(BinarySearchTree::BSTNode* pointer) {
  
  size_t nullT = 0;
  size_t rightBranchHeight;
  size_t leftBranchHeight;
  
  //if pointer is not null call function
  //recursively and select the larger of
  //the returned values between right
  //and left branches
  if(pointer != NULL) {
    rightBranchHeight = heightHelper(pointer -> Right);
    leftBranchHeight = heightHelper(pointer -> Left);
    
    //add 1 to the height of longer branch
    // and return
    if(rightBranchHeight > leftBranchHeight) {
      rightBranchHeight ++;
      return rightBranchHeight;
    }
    else {
      leftBranchHeight ++;
      return leftBranchHeight;
    }
  }
  
  //return 0 if the pointer is NULL
  return nullT;
}

void deleteHelper(BinarySearchTree::BSTNode* pointer) {
  
  //if either pointer is not NULL
  //call the function recursively
  //and pass that pointer
  if(pointer -> Left != NULL)
    deleteHelper(pointer -> Left);
  if(pointer -> Right != NULL)
    deleteHelper(pointer -> Right);
  
  //if pointer is not null
  //delete the current node
  if(pointer != NULL)
    delete pointer;
}

BinarySearchTree:: BinarySearchTree() {
  
  //initializes BinarySearchTree
  Root = NULL;
  Size = 0;
}

BinarySearchTree:: ~BinarySearchTree() {
  
  //deletes BinarySearchTree
  deleteHelper(Root);
}

void BinarySearchTree:: insert(const KeyTy& key, const ValueTy& value) {
  
  //inserts a node into BST
  //increments size
  insertHelper(key, value, Root);
  Size ++;
}

bool BinarySearchTree::search(const KeyTy& key, ValueTy& value) const { 
  
  //searches for key and 
  //changes value to 
  //the value of that node if
  //found
  return searchHelper(key, value, Root);
}

void BinarySearchTree::remove(const KeyTy& key) {
  
  //if key is found and node is removed
  //removehelper returns true
  //size is decreased
  if(removeHelper(Root, key))
    Size --;
}

bool BinarySearchTree::empty() const {
  
  //if tree is empty, return true
  if(Root == NULL)
    return true;
  else
    
    //else return false
    return false;
}

size_t BinarySearchTree::size() const {
  
  //returns number of nodes
  //in tree
  return Size;
}

size_t BinarySearchTree::height() const {
  
  //returns length of the longest
  //branch in the tree
  return heightHelper(Root);
}

void BinarySearchTree::inorder(TraversalFunction func) const {
  
  //traverses tree and calls
  //functions in order
  inorderHelper(Root, func);
}

void BinarySearchTree::postorder(TraversalFunction func) const {
  
  //traverses tree first
  //then calls function
  postorderHelper(Root, func);
}

void BinarySearchTree::preorder(TraversalFunction func) const {
  
  //calls function first
  //then traverses tree
  preorderHelper(Root, func);
}

void BinarySearchTree::print() const {
  
  //print keys and values
  //of the nodes in the tree
  printHelper(Root);
}

