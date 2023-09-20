#include <gtest/gtest.h>
#include "lab_1_separation.h"
#include <string>

TEST(Test_separation, empty_string){
  // Arrange
  string string_with_letters_and_numbers = "";
  string answer_number;
  
  // Act
  answer_number = filter_numbers(string_with_letters_and_numbers);

  // Assert
  ASSERT_EQ(answer_number, "");
}

TEST(Test_separation, only_numbers){
  string string_with_letters_and_numbers = "6786940";
  string answer_number;
  
  answer_number=filter_numbers(string_with_letters_and_numbers);

  ASSERT_EQ(answer_number, "6786940");
}

TEST(Test_separation, only_letters){
  string string_with_letters_and_numbers = "gjdbvhk";
  string answer_number;

  answer_number=filter_numbers(string_with_letters_and_numbers);

  ASSERT_EQ(answer_number, "");
}

TEST(Test_separation, first_number){
  string string_with_letters_and_numbers = "6f78h23hf000ytn9";
  string answer_number;

  answer_number = filter_numbers(string_with_letters_and_numbers);

  ASSERT_EQ(answer_number, "6 78 23 000 9");
}

TEST(Test_separation, first_letter){
  string string_with_letters_and_numbers = "hgb34nj8hj0000bh234hu16758";
  string answer_number;

  answer_number = filter_numbers(string_with_letters_and_numbers);

  ASSERT_EQ(answer_number, "34 8 0000 234 16758");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}