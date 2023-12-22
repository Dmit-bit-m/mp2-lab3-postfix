#include <gtest.h>
#include "stack.h"
#include "postfix.h"

TEST(TPostfix, can_create_posrfix)
{
	ASSERT_NO_THROW(TPostfix c);
}

TEST(TPostfix, can_SetInfix_with_non_equal_count_brakets)
{
	TPostfix pos;
	ASSERT_ANY_THROW(pos.SetInfix("(5+4*7/(4+3)("));
}

TEST(TPostfix, can_SetInfix_with_equal_count_brakets)
{
	TPostfix pos;
	ASSERT_NO_THROW(pos.SetInfix("(5+4*7/(4+3))"));
}

TEST(TPostfix, can_SetInfix_void_TCalculator)
{
	TPostfix pos;
	ASSERT_NO_THROW(pos.SetInfix(""));
}

TEST(TPostfix, right_postfix_SetInfix)
{
	TPostfix pos;
	pos.SetInfix("1+2");
	pos.ToPostfix();
	string tmp;
	tmp = ("1 2+");
	ASSERT_EQ(pos.GetPostfix(), tmp);
}

TEST(TPostfix, can_ToPostfix_empty_string)
{
	TPostfix pos;
	pos.SetInfix("");
	ASSERT_NO_THROW(pos.ToPostfix());
}

TEST(TPostfix, can_ToPostfix_string_with_equal_brackets)
{
	TPostfix pos;
	pos.SetInfix("(5+4*7/(4+3))");
	ASSERT_NO_THROW(pos.ToPostfix());
}

TEST(TPostfix, right_Calculation)
{
	TPostfix pos;
	pos.SetInfix("3+2");
	pos.ToPostfix();
	ASSERT_EQ(pos.Calculate(), 5);
}