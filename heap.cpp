// heap.cpp
// Andy Gonzalez
#include "heap.h"
#include <iostream>
#include <vector>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int v = vdata.size()-1;
  int p = (v-1)/2;
  if (v==0) {return;}
  while (value < vdata.at(p)) {
    swap(v,p);
    v = p;
    p = (v-1)/2;
    if (p < 0) {return;}
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  swap(0, vdata.size()-1);
  vdata.pop_back();
  int size(vdata.size()), i(0);
  int leftchild = 1;
  while (leftchild < size) {
      int minvalue(vdata.at(i)),  min_index(-1), index(0);
      while (index<2 && (index+leftchild) < size) {
         if (vdata.at(index+leftchild) < minvalue) {
            minvalue = vdata.at(index+leftchild);
            min_index = index+leftchild;
         }
         index++;
      }
      if (minvalue == vdata.at(i)){
         return;
      }
      else {
         swap(i, min_index);
         i = min_index;
         leftchild = (2*i)+1;
      }
   }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty()){return 0;}
  else{return vdata.at(0);}
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}

void Heap::swap(int i, int i2) {
  if (i >= vdata.size() || i2 >= vdata.size()) {
    std::cerr << "Out of Bounds!" << std::endl;
  }
  int temp = vdata.at(i);
  vdata.at(i) = vdata.at(i2);
  vdata.at(i2) = temp;
}
    