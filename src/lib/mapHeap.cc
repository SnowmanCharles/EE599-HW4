#include "maxHeap.h"
#include <vector>

MaxHeap::MaxHeap() {

}

int MaxHeap::GetParentIndex(int i) {  //O(1)
    return i == 0 ? -1 : (i - 1) / 2;
}

int MaxHeap::GetLeftIndex(int i) {  //O(1)
    return (2 * i + 1) >= data_.size() ? -1 : 2 * i + 1;
}

int MaxHeap::GetRightIndex(int i) {  //O(1)
    return (2 * i + 2) >= data_.size() ? -1 : 2 * i + 2;
}

int MaxHeap::GetLargestChildIndex(int i) {  //O(1)
    int res = -1, val = INT_MIN, l = 2 * i + 1, r = 2 * i + 2;
    if (l < data_.size() && data_[l] >= val) {
        res = l;
        val = data_[l];
    }
    if (r < data_.size() && data_[r] >= val) {
        res = r;
        val = data_[r];
    }
    return res;
}

int MaxHeap::GetLeft(int i) {  //O(1)
    return 2 * i + 1 >= data_.size() ? INT_MIN : data_[2 * i + 1];
}

int MaxHeap::GetRight(int i) {  //O(1)
    return 2 * i + 2 >= data_.size() ? INT_MIN : data_[2 * i + 2];
}

int MaxHeap::GetParent(int i) {  //O(1)
    return i == 0 ? INT_MIN : data_[(i - 1) / 2];
}

int MaxHeap::top() {  //O(1)
    return data_.size() == 0 ? INT_MIN : data_[0];
}

void MaxHeap::push(int v) {  //O(log(n))
    data_.push_back(v);
    TrickleUp(data_.size() - 1);
}

void MaxHeap::pop() {  //O(log(n))
    if (data_.size() == 0) return;
    data_[0] = data_[data_.size() - 1];
    TrickleDown(0);
    data_.pop_back();
}

void MaxHeap::TrickleUp(int i) {  //O(log(n))
    while (i != 0 && GetParent(i) < data_[i]) {
        swap(data_[i], data_[GetParentIndex(i)]);
        i = GetParentIndex(i);
    }
}

void MaxHeap::TrickleDown(int i) {  //O(log(n))
    int largetChildIdx = GetLargestChildIndex(i);
    while (largetChildIdx != -1 && data_[i] < data_[largetChildIdx]) {
        swap(data_[i], data_[largetChildIdx]);
        i = largetChildIdx;
        largetChildIdx = GetLargestChildIndex(i);
    }
}