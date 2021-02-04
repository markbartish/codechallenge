#include <iostream>

#include "gtest/gtest.h"

#include "lib/inc/point.h"

using namespace std;

#define PI 3.141592653589793
#define TOLERANCE 0.0000001


TEST(PointTest, addition){
  Point<int> p1(1,1);
  Point<int> p2(1,1);
  EXPECT_EQ(p1 + p2, Point<int>(2,2));

  p1 += p2;
  EXPECT_EQ(p1, Point<int>(2,2));
}

TEST(PointTest, subtraction){
  Point<int> p1(1,1);
  Point<int> p2(1,1);
  EXPECT_EQ(p1 - p2, Point<int>(0,0));
  
  p1 -= p2;
  EXPECT_EQ(p1, Point<int>(0,0));
}

TEST(PointTest, ScalarMultiplication){
  Point<int> p1(1,1);
  int s = 4;
  double sd = 5.0;
  EXPECT_EQ(p1 * s, Point<int>(4,4));
  EXPECT_EQ(p1 * sd, Point<int>(5, 5));

  Point<double> p2(1,1);
  EXPECT_EQ(p2 * 2.0, Point<double>(2, 2));
  
  EXPECT_EQ(p1 *= 2, Point<int>(2, 2));
  EXPECT_EQ(p1, Point<int>(2, 2));
  
  EXPECT_EQ(p2 *= 2, Point<double>(2, 2));
  EXPECT_EQ(p2, Point<double>(2, 2));

  Point<int> p3(4, 4);
  EXPECT_EQ( 1.5 * p3, Point<int>(6, 6));
}

TEST(PointTest, ScalarDivision){
  Point<int> p1(1,1);
  int s = 4;
  double sd = 5.0;
  EXPECT_EQ(p1 / s,  Point<int>(0, 0));
  EXPECT_EQ(p1 / sd, Point<int>(0, 0));

  Point<double> p2(1,1);
  EXPECT_EQ(p2 / 2.0, Point<double>(0.5, 0.5));

  EXPECT_EQ(p1 /= 1, Point<int>(1, 1));
  EXPECT_EQ(p1, Point<int>(1, 1));
  
  EXPECT_EQ(p1 /= 2, Point<int>(0, 0));
  EXPECT_EQ(p1, Point<int>(0, 0));

  EXPECT_EQ(p2 /= 2, Point<double>(0.5, 0.5));
  EXPECT_EQ(p2, Point<double>(0.5, 0.5));
}

TEST(PointTest, ScalarProduct){
  Point<int> p1(1, 1);
  Point<int> p2(3, 3);
  EXPECT_EQ(p1 * p2, 6);

  Point<double> p3(1.5, 1.5);
  Point<double> p4(8, 8);
  EXPECT_EQ(p3 * p4, 24);
}

TEST(PointTest, CrossProduct){
  Point<int> p1(1, 1);
  Point<int> p2(3, 3);
  EXPECT_EQ(p1 ^ p2, 0);
  
  Point<double> p3(1.5, 1.5);
  Point<double> p4(8, 8);
  EXPECT_EQ(p3 ^ p4, 0);
}

TEST(PointTest, dist){
  Point<int> p1(1, 1);
  Point<int> p2(3, 1);
  EXPECT_EQ(p1.dist(p2), 2);
}

TEST(PointTest, norm){
  Point<int> p1(1, 1);
  Point<int> p2(3, 1);
  EXPECT_LT( abs( p1.norm() - sqrt(2) ), TOLERANCE);
  EXPECT_LT( abs( p2.norm() - sqrt(10) ), TOLERANCE);
  EXPECT_LT( abs( (p2-p1).norm() - 2 ), TOLERANCE);

  Point<int> p3(-1, 1);
  Point<int> p4(1, -1);
  EXPECT_LT( abs( p3.norm() - sqrt(2) ), TOLERANCE);
  EXPECT_LT( abs( p4.norm() - sqrt(2) ), TOLERANCE);
  EXPECT_LT( abs( (p4 - p3).norm() - (2 * sqrt(2)) ), TOLERANCE);
}

TEST(PointTest, angle){
  Point<int> p1(1, 0);
  Point<int> p2(-1, 0);
  EXPECT_LT( abs(p1.angle(p2) - PI), 0.000001);

  p1 = Point<int>(1, 1);
  p2 = Point<int>(-1, 1);
  EXPECT_LT( abs(p1.angle(p2) - (PI/2)  ), 0.000001);

  p1 = Point<int>(1, 1);
  p2 = Point<int>(1, -1);

  // Expect angle = -PI/2
  EXPECT_LT( abs(p1.angle(p2) - (-PI/2)), 0.000001);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
