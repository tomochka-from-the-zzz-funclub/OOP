#include "gtest/gtest.h"
#include "square.h"

using namespace std;
#define FAULT 1e-5

TEST(test_square, constructor_abcd) {
  EXPECT_NO_THROW(square(point(2, 1), point(2, 3), point(4, 3), point(4, 1)));
}

TEST(test_square, constructor_other) {
  square test (point(1, 1), point(1, 3), point(3, 1), point(3, 3));
  EXPECT_NO_THROW(square(test));
}

TEST(test_square, get) {
  square test(point(1, 1), point(1, 3), point(3, 1), point(3, 3));
  point centre = test.geometric_centre();
  EXPECT_TRUE(abs(centre.get_x() - 2) < FAULT);
  EXPECT_TRUE(abs(centre.get_y() - 2) < FAULT);
}

TEST(test_square, area) {
  square test(point(2, 1), point(2, 3), point(4, 3), point(4, 1));
  double area = static_cast<double>(test);
  EXPECT_TRUE(abs(area - 4) < FAULT);
}

TEST(test_square, eq) {
  square test1(point(1, 1), point(1, 3), point(3, 3), point(3, 1));
  square test2(point(1, 1), point(1, 3), point(3, 3), point(3, 1));

  EXPECT_TRUE(test1 == test2);
}

TEST(test_square, aneq) {
    square test1(point(1, 1), point(1, 3), point(3, 3), point(3, 1));
    square test2(point(0, 0), point(0, 1), point(1, 0), point(1, 1));

  EXPECT_FALSE(test1 == test2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}