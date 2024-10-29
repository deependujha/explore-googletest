#include <gtest/gtest.h>

class MyFixture : public ::testing::Test
{
protected:
    int *x, *y;
    MyFixture()
    {
        // This code will be called before each test (once per test)
    }

    ~MyFixture()
    {
        // This code will be called after each test (once per test)
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
        x = new int(21);
        y = new int(17);
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
        free(x);
        free(y);
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
};

TEST_F(MyFixture, Test1)
{
    int val = 4;
    EXPECT_EQ(*x-*y, val);
}
