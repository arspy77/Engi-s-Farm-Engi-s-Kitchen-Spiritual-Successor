#include "Point.h"
#include <gtest/gtest.h>

TEST(PointTest, ChangeComponent) {
    Point a;
    a.x = 5;
    EXPECT_EQ(5, a.x);
    a.x = 6;
    EXPECT_EQ(6, a.x);
    a.y = 5;
    EXPECT_EQ(5, a.y);
    a.y = 6;
    EXPECT_EQ(6, a.y);    
}
