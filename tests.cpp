#include "gtest/gtest.h"
#include "calculator.h" // Our functions to test

// Test the square root function
TEST(SquareRootTest, HandlesPositiveNumbers) {
    ASSERT_EQ(squareRoot(4.0), 2.0);
    ASSERT_EQ(squareRoot(9.0), 3.0);
}

// Test the factorial function
TEST(FactorialTest, HandlesBaseCases) {
    ASSERT_EQ(factorial(0), 1);
    ASSERT_EQ(factorial(1), 1);
    ASSERT_EQ(factorial(5), 120);
}

// Test the natural log function
TEST(NaturalLogTest, HandlesPositiveNumbers) {
    // Use ASSERT_NEAR for floating point comparisons
    ASSERT_NEAR(naturalLog(1.0), 0.0, 0.001);
}

// Test the power function
TEST(PowerTest, HandlesPositiveBases) {
    ASSERT_EQ(power(2.0, 3.0), 8.0);
    ASSERT_EQ(power(5.0, 2.0), 25.0);
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}