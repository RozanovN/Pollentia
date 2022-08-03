#include "gtest/gtest.h"

/**
 * Runs all the tests.
 * Always include "gtest/gtest.h" to the children tests.
 *
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}