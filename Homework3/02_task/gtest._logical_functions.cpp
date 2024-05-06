#include <gtest/gtest.h> // Google Test header
#include "logical_functions.h" // Header with the above functions


TEST(LogicalFunctionsTest, SynthesizeByOnes) {
    EXPECT_EQ(synthesizeByOnes(0, 0, 0), 1);
    EXPECT_EQ(synthesizeByOnes(0, 0, 1), 0);
    EXPECT_EQ(synthesizeByOnes(0, 1, 0), 1);
    EXPECT_EQ(synthesizeByOnes(0, 1, 1), 1);
    EXPECT_EQ(synthesizeByOnes(1, 0, 0), 0);
    EXPECT_EQ(synthesizeByOnes(1, 0, 1), 0);
    EXPECT_EQ(synthesizeByOnes(1, 1, 0), 0);
    EXPECT_EQ(synthesizeByOnes(1, 1, 1), 1);
}


TEST(LogicalFunctionsTest, SynthesizeByZeros) {
    EXPECT_EQ(synthesizeByZeros(0, 0, 0), 1);
    EXPECT_EQ(synthesizeByZeros(0, 0, 1), 0);
    EXPECT_EQ(synthesizeByZeros(0, 1, 0), 1);
    EXPECT_EQ(synthesizeByZeros(0, 1, 1), 1);
    EXPECT_EQ(synthesizeByZeros(1, 0, 0), 0);
    EXPECT_EQ(synthesizeByZeros(1, 0, 1), 0);
    EXPECT_EQ(synthesizeByZeros(1, 1, 0), 0);
    EXPECT_EQ(synthesizeByZeros(1, 1, 1), 1);
}


TEST(LogicalFunctionsTest, MinimizedExpression) {
    EXPECT_EQ(minimizedExpression(0, 0, 0), 1);
    EXPECT_EQ(minimizedExpression(0, 0, 1), 0);
    EXPECT_EQ(minimizedExpression(0, 1, 0), 1);
    EXPECT_EQ(minimizedExpression(0, 1, 1), 1);
    EXPECT_EQ(minimizedExpression(1, 0, 0), 0);
    EXPECT_EQ(minimizedExpression(1, 0, 1), 0);
    EXPECT_EQ(minimizedExpression(1, 1, 0), 0);
    EXPECT_EQ(minimizedExpression(1, 1, 1), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
