#include "ArrayList.h"
#include "gtest/gtest.h"
#include <limits>

TEST(ArrayListConstruction, ParmeterSetting) {
    ArrayList<int> array_list{};
    EXPECT_EQ(array_list.get_size(), 0);
    EXPECT_EQ(array_list.get_current_capacity(), array_list.INITIAL_CAPACITY);
}

TEST(ArrayListAddAtIndex, BasicAddAtIndex) {
    ArrayList<int> array_list{};
    array_list.add_at_index(0, 2);
    array_list.add_at_index(0, 1);
    array_list.add_at_index(2, 4);
    array_list.add_at_index(2, 3);
    array_list.add_at_index(0, 0);

    EXPECT_EQ(array_list.get_size(), 5);
    EXPECT_EQ(array_list.get_current_capacity(), array_list.INITIAL_CAPACITY);
    int expected[]{0, 1, 2, 3, 4};
    for (int i{}; i < 5; ++i) {
        int actual{array_list.get(i)};
        EXPECT_EQ(actual, expected[i]) << "Arrays differed at " << i;
    }
}

TEST(SantizerTest, MemoryLeak) {
    ArrayList<int> *array_list{new ArrayList<int>()};
    ASSERT_TRUE(array_list != nullptr);
}

TEST(SanitizerTest, AddressLeak) {
    ArrayList<int> *array_list{new ArrayList<int>()};
    ASSERT_TRUE(array_list != nullptr);
    delete array_list;
    std::cout << array_list->get_current_capacity();
}

TEST(SanitizerTest, UndefinedBehavior) {
    int k = std::numeric_limits<int>::max();
    int overflow = k + 1;
    std::cout << "Overflow int is " << overflow;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ArrayList<int> array_list;
    return RUN_ALL_TESTS();
}