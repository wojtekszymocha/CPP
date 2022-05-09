#include <gtest/gtest.h>
#include "Unique_ptr.hpp"

constexpr int testedValue = 5;
constexpr int expectedValue = 5;

class MoveTest : public testing::Test {
public:
    auto moveTest() {
        Unique_ptr<int> ptr{new int{testedValue}};
        return ptr;
    }
};

TEST(Unique_ptrTest, DereferenceOperatorShouldReturnTestedValue) {
    Unique_ptr<int> unique{new int(testedValue)};
    ASSERT_EQ(expectedValue, *unique);
}

TEST(Unique_ptrTest, GetFunctionShouldReturnValueOfPointer) {
    Unique_ptr<int> ptr{new int{testedValue}};
    auto ptrNew = ptr.get();
    ASSERT_EQ(expectedValue, *ptrNew);
}

TEST(Unique_ptrTest, AfterReleaseUnique_ptrShouldHaveNullPtrInside) {
    Unique_ptr<int> ptr{new int{testedValue}};
    auto newPtr = ptr.release();
    delete newPtr;
    ASSERT_EQ(nullptr, ptr.get());
}

TEST_F(MoveTest, MoveConstructorTest) {
    Unique_ptr<int> ptr{new int{testedValue}};
    Unique_ptr<int> secondPtr(std::move(ptr));

    ASSERT_EQ(ptr.get(), nullptr);
    ASSERT_EQ(expectedValue, *secondPtr.get());
}

TEST(Unique_ptrTest, IfUnique_ptrDereferenceNullPtrExceptionShouldBeThrown) {
    Unique_ptr<int> ptr{nullptr};
    ASSERT_THROW(*ptr, NullPtrDereferenceException);
}

TEST(Unique_ptrTest, IfResetIsUsedUnique_ptrShouldContainNewValue) {
    constexpr int newValue =  5;
    Unique_ptr<int> ptr{new int{testedValue}};
    ptr.reset(new int{newValue});
    ASSERT_EQ(expectedValue, *ptr);
}

TEST_F(MoveTest, MoveAssignmentTest) {
    constexpr int firstValue = 12;
    Unique_ptr<int> ptr{new int{firstValue}};
    ptr = moveTest();
    ASSERT_EQ(expectedValue, *ptr);
}

