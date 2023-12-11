#include "gtest/gtest.h"
#include "rectangle.h"

using namespace std;
#define FAULT 1e-5

TEST(test_rectangle, constructor_abcd) {
  EXPECT_NO_THROW(rectangle(point(1, 1), point(1, 3), point(3, 3), point(3, 1)));
}

TEST(test_rectangle, constructor_other) {
  rectangle test (point(1, 1), point(1, 3), point(8, 3), point(8, 1));
  EXPECT_NO_THROW(rectangle(test));
}

TEST(test_rectangle, get) {
  rectangle test(point(1, 1), point(1, 3), point(5, 3), point(5, 1));
  point centre = test.geometric_centre();
  EXPECT_TRUE(abs(centre.get_x() - 3) < FAULT);
  EXPECT_TRUE(abs(centre.get_y() - 2) < FAULT);
}

TEST(test_rectangle, area) {
  rectangle test(point(1, 1), point(1, 3), point(5, 3), point(5, 1));
  double area = static_cast<double>(test);
  EXPECT_TRUE(abs(area - 8) < FAULT);
}

TEST(test_rectangle, eq) {
  rectangle test1(point(1, 1), point(1, 3), point(5, 3), point(5, 1));
  rectangle test2(point(1, 1), point(1, 3), point(5, 3), point(5, 1));

  EXPECT_TRUE(test1 == test2);
}

TEST(test_rectangle, aneq) {
    rectangle test1(point(1, 1), point(1, 3), point(5, 3), point(5, 1));
    rectangle test2(point(0, 0), point(0, 3), point(5, 3), point(5, 0));

  EXPECT_FALSE(test1 == test2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}