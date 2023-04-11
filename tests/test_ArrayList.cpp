#include "ArrayList.h"
#include "gtest/gtest.h"

TEST(ArrayListConstruction, ParmeterSetting) {
    ArrayList<int> array_list{};
    EXPECT_EQ(array_list.get_size(), 0);
    EXPECT_EQ(array_list.get_current_capacity(), array_list.INITIAL_CAPACITY);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ArrayList<int> array_list;
    return RUN_ALL_TESTS();
}