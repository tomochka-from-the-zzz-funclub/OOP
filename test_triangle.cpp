#include "gtest/gtest.h"
#include "triangle.h"

using namespace std;
#define FAULT 1e-4

TEST(test_triangle, constructor_abc) {
  EXPECT_NO_THROW(triangle(point(2, 1), point(2, 3), point(4, 3)));
}

TEST(test_triangle, constructor_other) {
    triangle test (point(0, 0), point(3, 2), point(7, 5));
    EXPECT_NO_THROW(triangle(test));
}

TEST(test_triangle, get) {
    triangle test(point(0, 0), point(3, 2), point(7, 5));
    point centre = test.geometric_centre();
    EXPECT_TRUE(abs(centre.get_x() - 3.33333) < FAULT);
    EXPECT_TRUE(abs(centre.get_y() - 2.33333) < FAULT);
}

TEST(test_triangle, area) {
    triangle test(point(0, 0), point(3, 2), point(7, 5));
    double area = static_cast<double>(test);
    EXPECT_TRUE(abs(area - 0.5) < FAULT);
}

TEST(test_triangle, eq) {
    triangle test1(point(1, 1), point(1, 3), point(3, 3));
    triangle test2(point(1, 1), point(1, 3), point(3, 3));
    EXPECT_TRUE(test1 == test2);
}

TEST(test_triangle, aneq) {
    triangle test1(point(1, 1), point(1, 3), point(3, 3));
    triangle test2(point(1, 1), point(1, 3), point(3, 5));
    EXPECT_FALSE(test1 == test2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}