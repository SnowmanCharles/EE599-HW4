#include "src/lib/maxHeap.h"
#include "gtest/gtest.h"
#include <vector>

TEST(MaxHeapTest, MaxHeapTest) {
  MaxHeap maxHeap;
  
  maxHeap.push(5);
  EXPECT_EQ(5, maxHeap.top());
  maxHeap.push(4);
  EXPECT_EQ(5, maxHeap.top());
  maxHeap.push(3);
  EXPECT_EQ(5, maxHeap.top());

  EXPECT_EQ(-1, maxHeap.GetParentIndex(0));
  EXPECT_EQ(0, maxHeap.GetParentIndex(1));
  EXPECT_EQ(1, maxHeap.GetLeftIndex(0));
  EXPECT_EQ(2, maxHeap.GetRightIndex(0));
  EXPECT_EQ(-1, maxHeap.GetLeftIndex(1));
  EXPECT_EQ(-1, maxHeap.GetRightIndex(2));

  EXPECT_EQ(1, maxHeap.GetLargestChildIndex(0));
  EXPECT_EQ(-1, maxHeap.GetLargestChildIndex(1));
  maxHeap.pop();
  EXPECT_EQ(4, maxHeap.top());
  maxHeap.pop();
  EXPECT_EQ(3, maxHeap.top());
  maxHeap.pop();
  EXPECT_EQ(INT_MIN, maxHeap.top());
}





