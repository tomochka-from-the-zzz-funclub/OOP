#include "gtest/gtest.h"
#include "point.h"
using namespace std;

TEST(test_point, point_constructor_xy){
    point <int> test{1, 1};
    ASSERT_NO_THROW(test);
}

TEST(test_point, point_constructor_other){
    ASSERT_NO_THROW(point(point (2, 2)));
}

TEST(test_point, get){
    point test (0, 5);
    ASSERT_EQ(test.get_x(), 0);
    ASSERT_EQ(test.get_y(), 5);
}

TEST(test_point, dist_){
    point<int> a (-1, 3);
    point<int> b (2, 7);
    
    ASSERT_EQ(dist(a, b), 5);
}

TEST(test_point, equal){
    point a (1, 3);
    point b (1, 3);
    ASSERT_TRUE(a == b);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}