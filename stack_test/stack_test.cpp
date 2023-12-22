#include <gtest.h>
#include "stack.h"


TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s1(10));
}

TEST(TStack, can_not_create_zero_size)
{
	ASSERT_ANY_THROW(TStack<int> s1(0));
}

TEST(TStack, can_get_stack_size)
{
	TStack<int> s1(3);
	ASSERT_EQ(3, s1.GetSize());
}

TEST(TStack, can_get_stack_top)
{
	TStack<int> s1(3);
	s1.Push(0);
	ASSERT_EQ(0, s1.GetTop());
}

TEST(TStack, can_push_stack_element)
{
	TStack<int> s1(3);
	ASSERT_NO_THROW(s1.Push(10));
}

TEST(TStack, can_not_push_stack_element_when_is_full)
{
	TStack<int> s1(1);
	s1.Push(10);
	ASSERT_ANY_THROW(s1.Push(10));
}

TEST(TStack, can_get_top_stack_element)
{
	TStack<int> s1(3);
	s1.Push(10);
	ASSERT_EQ(10, s1.TopView());
}

TEST(TStack, can_not_get_top_stack_element_when_is_empty)
{
	TStack<int> s1(3);
	ASSERT_ANY_THROW(s1.TopView());
}

TEST(TStack, can_check_if_stack_empty)
{
	TStack<int> s1(3);
	ASSERT_EQ(true, s1.IsEmpty());
	s1.Push(1);
	ASSERT_EQ(false, s1.IsEmpty());
}

TEST(TStack, can_check_if_stack_full)
{
	TStack<int> s1(1);
	ASSERT_EQ(false, s1.IsFull());
	s1.Push(1);
	ASSERT_EQ(true, s1.IsFull());
}

TEST(TStack, can_use_copy_constructor)
{
	TStack<int> s1(3);
	s1.Push(3);
	TStack<int> s2(s1);
	ASSERT_EQ(s1.GetTop(), s2.GetTop());
}


