#include <gtest/gtest.h>
#include "string.hpp"

TEST(String, Construct){
    BMTSU::string str;
    EXPECT_EQ(str.Size(), 0);
    EXPECT_EQ(str.data(), nullptr);

    BMTSU::string str2("hello");
    EXPECT_EQ(str2.Size(), 5);
    EXPECT_EQ(*(str2.data() + 1), 'e');

    BMTSU::string str3(str2);
    EXPECT_EQ(str3.Size(), 5);
    EXPECT_EQ(*(str3.data() + 1), 'e');
}

TEST(String, operator_plus){
    BMTSU::string str1("hello ");
    BMTSU::string str2("world");
    BMTSU::string str3 = str1 + str2;
    EXPECT_EQ(str3.Size(), 11);
    EXPECT_EQ(*(str3.data() + 5), ' ');
    EXPECT_EQ(*(str3.data() + 6), 'w');
}