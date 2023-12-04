#include "gtest/gtest.h"
#include "Eleven.h"
using namespace std;

TEST(test_Eleven, Eleven_constructor_empty){
    ASSERT_NO_THROW(Eleven());
}

TEST(test_Eleven, Eleven_constructor_value){
    ASSERT_NO_THROW(Eleven(5, '1'));
}

TEST(test_Eleven, Eleven_constructor_initializer_list){
    ASSERT_NO_THROW(Eleven({'1', '5', '5'}));
}

TEST(test_Eleven, Eleven_constructor_string){
    ASSERT_NO_THROW(Eleven("17A"));
}

TEST(test_Eleven, Eleven_constructor_other){
    Eleven other_el(5,'1');
    ASSERT_NO_THROW(Eleven(other_el));
}

TEST(test_Eleven, Eleven_get_size){
    Eleven el(5,'1');
    ASSERT_EQ(el.get_size(), 5);
}

TEST(test_Eleven, Eleven_get_numbers){
    Eleven el(5,'1');
    ASSERT_EQ(*(el.get_numbers()), '1');
}

TEST(test_Eleven, char_to_int_A){
    ASSERT_EQ(char_to_int('A'), 10);
}

TEST(test_Eleven, char_to_int_num){
    ASSERT_EQ(char_to_int('7'), 7);
}

TEST(test_Eleven, Eleven_equel_t){
    Eleven l(5,'1');
    Eleven r("11111");
    EXPECT_TRUE(l == r);
}

TEST(test_Eleven, Eleven_equel_f){
    Eleven l(5,'1');
    Eleven r("11113");
    EXPECT_FALSE(l == r);
}

TEST(test_Eleven, Eleven_more_t){
    Eleven l(5,'3');
    Eleven r("11113");
    EXPECT_TRUE(l > r);
}

TEST(test_Eleven, Eleven_more_f){
    Eleven l(5,'1');
    Eleven r("11113");
    EXPECT_FALSE(l > r);
}

TEST(test_Eleven, Eleven_less_t){
    Eleven l("112");
    Eleven r("11113");
    EXPECT_TRUE(l < r);
}

TEST(test_Eleven, Eleven_less_f){
    Eleven l(5,'1');
    Eleven r("11000");
    EXPECT_FALSE(l < r);
}

TEST(test_Eleven, Eleven_anequel_t){
    Eleven l("112");
    Eleven r("11113");
    EXPECT_TRUE(l != r);
}

TEST(test_Eleven, Eleven_anequel_f){
    Eleven l(2,'1');
    Eleven r("11");
    EXPECT_FALSE(l != r);
}

TEST(test_Eleven, Eleven_plus1){
    Eleven l(4,'1');
    Eleven r("12A");
    Eleven result;
    Eleven right ("1240");
    result = l + r;
    ASSERT_EQ(result, right);
}

TEST(test_Eleven, Eleven_plus2){
    Eleven l(3,'1');
    Eleven r("119");
    Eleven result;
    result = l + r;
    string res = "";
    for(size_t i = 0; i < result.get_size(); i++){
        res.push_back(result.get_numbers()[i]);
    }
    ASSERT_EQ(res, "22A");
}

TEST(test_Eleven, Eleven_plus3){
    Eleven l(5,'1');
    Eleven r("11999A");
    Eleven result;
    result = l + r;
    string res = "";
    for(size_t i = 0; i < result.get_size(); i++){
        res.push_back(result.get_numbers()[i]);
    }
    ASSERT_EQ(res, "130000");
}

TEST(test_Eleven, Eleven_minus1){
    Eleven l(5,'1');
    Eleven r("11A");
    Eleven result;
    result = l - r;
    string res = "";
    for(size_t i = 0; i < result.get_size(); i++){
        res.push_back(result.get_numbers()[i]);
    }
    ASSERT_EQ(res, "10AA2");
}

TEST(test_Eleven, Eleven_minus2){
    Eleven l("A");
    Eleven r(1,'1');
    Eleven result;
    result = l - r;
    string res = "";
    for(size_t i = 0; i < result.get_size(); i++){
        res.push_back(result.get_numbers()[i]);
    }
    ASSERT_EQ(res, "9");
}

TEST(test_Eleven, Eleven_minus3){
    Eleven l("AA");
    Eleven r(1,'0');
    Eleven result;
    result = l - r;
    string res = "";
    for(size_t i = 0; i < result.get_size(); i++){
        res.push_back(result.get_numbers()[i]);
    }
    ASSERT_EQ(res, "AA");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}