#include "pch.h"
#include "header.h"
TEST(SumDivTest, PrimeNumbers) {
    EXPECT_EQ(sum_div(7), 1);  
    EXPECT_EQ(sum_div(13), 1);  
    EXPECT_EQ(sum_div(2), 1);
}


TEST(SumDivTest, PerfectNumbers) {
    EXPECT_EQ(sum_div(6), 6); 
    EXPECT_EQ(sum_div(28), 28); 
}


TEST(SumDivTest, CompositeNumbers) {
    EXPECT_EQ(sum_div(12), 16); 
    EXPECT_EQ(sum_div(9), 4);   
    EXPECT_EQ(sum_div(15), 9); 
}


TEST(SumDivTest, BoundaryAndEdgeCases) {
    EXPECT_EQ(sum_div(1), 0);  
    EXPECT_EQ(sum_div(0), 0); 
    EXPECT_EQ(sum_div(-5), 0); 
}