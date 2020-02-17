#include "src/lib/bst.h"
#include "gtest/gtest.h"
#include <vector>

TEST(BstTest, BstTest) {
  BST bst;
  bst.push(1);
  EXPECT_EQ(true, bst.find(1));
  EXPECT_EQ(false, bst.find(2));
  bst.push(2);
  EXPECT_EQ(true, bst.find(1));
  EXPECT_EQ(true, bst.find(2));
 EXPECT_EQ(false, bst.find(3));
  bst.push(3);
  EXPECT_EQ(true, bst.find(1));
  EXPECT_EQ(true, bst.find(2));
  EXPECT_EQ(true, bst.find(3));
  EXPECT_EQ(false, bst.find(4));

  bool res = bst.erase(4);
  EXPECT_EQ(false, res);
  EXPECT_EQ(true, bst.find(1));
  EXPECT_EQ(true, bst.find(2));
  EXPECT_EQ(true, bst.find(3));

  res = bst.erase(2);
  EXPECT_EQ(true, bst.find(1));
  EXPECT_EQ(false, bst.find(2));
  EXPECT_EQ(true, bst.find(3));

  res = bst.erase(3);
  EXPECT_EQ(true, bst.find(1));
  EXPECT_EQ(false, bst.find(2));
  EXPECT_EQ(false, bst.find(3));

  res = bst.erase(1);
  EXPECT_EQ(false, bst.find(1));
  EXPECT_EQ(false, bst.find(2));
  EXPECT_EQ(false, bst.find(3));  
}

TEST(BstLevelTraversalTest, BstLevelTraversalTest) {
    vector<int> vec = {3,1,5,2,4};
    BST bst(vec);
    // BST bst;
    // bst.push(3);
    // bst.push(1);
    // bst.push(5);
    // bst.push(2);
    // bst.push(4);
    vector<int> res = bst.levelTraversal();
    vector<int> expectedRes = {3,1,5,2,4};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(res[i], expectedRes[i]);
    }
}