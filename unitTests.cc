#include <gtest/gtest.h>
#include "funkcijos.h"

// Include the necessary headers for the classes and functions being tested

// Define your test case
TEST(CompareTest, SameSurnameDifferentFirstName)
{
    // Create two student objects with the same surname but different first names
    studentas s1("John", "Doe");
    studentas s2("Alice", "Doe");

    // Call the compare function and assert the expected result
    ASSERT_NE(compare(s1, s2), false); 
    EXPECT_EQ(compare(s2, s1), true);
}
// Add more test cases as needed to cover different scenarios
// Demonstrate some basic assertions.
// TEST(HelloTest, BasicAssertions) {
//   // Expect two strings not to be equal.
//   EXPECT_STREQ("hello", "world");
//   // Expect equality.
//   EXPECT_EQ(7 * 6, 42);
// }

TEST(CountVidTest, AverageCalculation)
{
    // Create a vector of integers
    std::vector<int> nd_vec = { 5, 6, 7, 8, 9 };

    // Call the count_vid function and get the expected average
    float expected_average = 7.0f;

    // Call the count_vid function and get the actual average
    float actual_average = count_vid(nd_vec);

    // Check if the actual average matches the expected average
    EXPECT_EQ(actual_average, expected_average);
}

TEST(countvid, testcountvid)
{
    // Create two student objects with the same surname but different first names
    studentas s1("John", "Doe");
    studentas s2("Alice", "Doe");
    std::vector<int> nd_vec = { 5, 6, 7, 8, 9 };
    // s1.count_vid(nd_vec);
    s1.setGalutinis(nd_vec, 10);
    std::cout << s1.getGalutinis() << std::endl;

    ASSERT_EQ(s1.getGalutinis(), 8.8f); 
    // EXPECT_EQ(compare(s2, s1), true);
}
// Run the tests
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
