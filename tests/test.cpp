#include "../console.h"
#include "../functions.h"
#include "../functions.cpp"
#include "../libraries.h"
#include <gtest/gtest.h>

TEST(Exam, Function) {
    stud S;
    ASSERT_EQ(0, S.getExam());
    ASSERT_EQ(4, S.getExam());
}
TEST(Answer, Function) {

    ASSERT_EQ(1, string_is_valid("Vardas"));
    ASSERT_EQ(0, string_is_valid("Vardas11"));
    ASSERT_EQ(1, string_is_valid("Vardas11"));
}
TEST(Name, Function) {
    stud S;
    S.setFirstName("Vardas");
    ASSERT_EQ("Vardas", S.getFirstName());
    ASSERT_EQ("Vardas1", S.getFirstName());
}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
