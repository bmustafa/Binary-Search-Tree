/******************************************************************************
 *
 * Name:	
 *
 * Date:	
 *
 * Assignment:	
 *
 * Purpose:	
 *
 *****************************************************************************/
#include <iostream>
#include "BST.h"

using namespace std;
typedef string KeyTy;
typedef int ValueTy;
typedef void (*TraversalFunction)(const KeyTy& key, ValueTy& value);

void printer(const KeyTy& key,ValueTy& value){
  cout << "Key  " << key << " and Value  " << value << endl;
}

int main() {
  BinarySearchTree treeOne;
  KeyTy keyA = "a";
  KeyTy keyB = "b";
  KeyTy keyC = "c";
  KeyTy keyD = "d";
  KeyTy keyE = "e";
  KeyTy keyF = "f";
  KeyTy keyG = "g";
  //KeyTy keyH = "h";

  ValueTy value1 = 1;
  ValueTy value2 = 2;
  ValueTy value3 = 3;
  ValueTy value4 = 4;
  ValueTy value5 = 5;
  ValueTy value6 = 6;
  ValueTy value7 = 7;
  //ValueTy value8 = 8;
  //cout << treeOne.empty() << endl;
  treeOne.insert(keyD, value4);
  treeOne.insert(keyB, value2);
  treeOne.insert(keyA, value1);
  treeOne.insert(keyC, value3);
  treeOne.insert(keyF, value6);
  treeOne.insert(keyE, value5);
  treeOne.insert(keyG, value7);
  cout << treeOne.size() << "size" <<endl;
  cout << treeOne.height() << "height" << endl;
  treeOne.postorder(printer);
  //cout << "all inserted" << endl;
  //treeOne.print();
  //cout << treeOne.empty() << endl;
  //treeOne.remove(keyD);
  //treeOne.print();
}
