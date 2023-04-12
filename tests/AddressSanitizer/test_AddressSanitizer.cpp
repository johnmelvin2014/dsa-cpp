#include <vector>
#include "gtest/gtest.h"
#include <limits>

TEST(SanitizerTest, DISABLED_MemoryLeak) {
    int *array{new int};
    ASSERT_TRUE(array != nullptr);
}

TEST(SanitizerTest, DISABLED_AddressLeak) {
    std::vector<int> *vect_ptr{new std::vector<int>()};
    ASSERT_TRUE(vect_ptr != nullptr);
    delete vect_ptr;
    int size = vect_ptr->size();
    (void) size;
}

TEST(SanitizerTest, DISABLED_UndefinedBehavior) {
    int k = std::numeric_limits<int>::max();
    int overflow = k + 1;
    (void) overflow;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}