#include "pch.h"
#include <gtest/gtest.h>
#include "Set.h"

//Iryna Nazarchuk
TEST(SetTest, AddAndContains) {
    Set<int> set;
    set.add(1);
    set.add(2);
    set.add(3);

    EXPECT_TRUE(set.contains(1));
    EXPECT_TRUE(set.contains(2));
    EXPECT_TRUE(set.contains(3));
    EXPECT_FALSE(set.contains(4));
}

//Halyna Danylchyk
TEST(SetTest, Remove) {
    Set<int> set = { 1, 2, 3 };
    set.remove(2);

    EXPECT_TRUE(set.contains(1));
    EXPECT_FALSE(set.contains(2));
    EXPECT_TRUE(set.contains(3));
}

//Halyna Danylchyk
TEST(SetTest, Union) {
    Set<int> set1 = { 1, 2, 3 };
    Set<int> set2 = { 3, 4, 5 };
    Set<int> expected = { 1, 2, 3, 4, 5 };

    Set<int> unionSet = set1.unionWith(set2);
    EXPECT_EQ(unionSet, expected);
}

//Iryna Nazarchuk
TEST(SetTest, Intersection) {
    Set<int> set1 = { 1, 2, 3 };
    Set<int> set2 = { 3, 4, 5 };
    Set<int> expected = { 3 };

    Set<int> intersectionSet = set1.intersectionWith(set2);
    EXPECT_EQ(intersectionSet, expected);
}

//Halyna Danylchyk
TEST(SetTest, Difference) {
    Set<int> set1 = { 1, 2, 3 };
    Set<int> set2 = { 3, 4, 5 };
    Set<int> expected = { 1, 2 };

    Set<int> differenceSet = set1.differenceWith(set2);
    EXPECT_EQ(differenceSet, expected);
}

//Iryna Nazarchuk
TEST(SetTest, AddSet) {
    Set<int> set1 = { 1, 2, 3 };
    Set<int> set2 = { 4, 5, 6 };
    Set<int> expected = { 1, 2, 3, 4, 5, 6 };

    set1.add(set2);
    EXPECT_EQ(set1, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

