#include <iostream>

#include "gtest/gtest.h"

#include "lib/edge.h"

using namespace std;


#define TOLERANCE 0.0000001

TEST(EdgeTest, distSingle){
  Edge<int> e1(1, 1, 2, 2);
  EXPECT_LT( abs(e1.dist() - sqrt(2)), TOLERANCE );
}

TEST(EdgeTest, distToAnother){
  Edge<int> e1(1, 1, 2, 2);
  Edge<int> e2(0, 0, 2, -2);
  EXPECT_LT( abs(e1.dist(e2) - sqrt(2)), TOLERANCE );
  //EXPECT_LT( abs(e1.dist() - sqrt(2)), TOLERANCE);

  // Point to line special case
  /// 1 1 1 1 1 1 2 1
  
  e1 = Edge<int>(1, 1, 1, 1);
  e2 = Edge<int>(1, 1, 2, 1);

  EXPECT_LT( abs(e1.dist(e2) - 0), TOLERANCE);
  
  // Point to point special case
  /// 1 1 1 1 2 1 2 1
  e1 = Edge<int>(1, 1, 1, 1);
  e2 = Edge<int>(2, 1, 2, 1);

  EXPECT_LT( abs(e1.dist(e2) - 1), TOLERANCE);
}

TEST(EdgeTest, extend){
  Edge<int> e(1, 1, 2, 2);
  
  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
