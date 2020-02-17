#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
using namespace std;

class MaxHeap {
public:
    MaxHeap();//Default Constructor

    int GetParentIndex(int i);  //GT
    int GetLeftIndex(int i);  //GT
    int GetRightIndex(int i);  //GT
    int GetLargestChildIndex(int i);  //GT

    int GetLeft(int i);
    int GetRight(int i);
    int GetParent(int i);

    int top(); //GT
    void push(int v); //GT
    void pop();  //GT
    void TrickleUp(int i);
    void TrickleDown(int i);

private:
    vector<int> data_;
};

#endif