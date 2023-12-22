#ifndef _POSTFIX_ 
#define _POSTFIX_ 
#include "stack.h"
#include <string>
#include <math.h>

using namespace std;

class TPostfix 
{
	string infix;
	string postfix;
	TStack<char> st;
	TStack<double> st2;
	int Priority(char elem) 
	{
		switch (elem) 
		{
		case '(': 
			return 0;
			break;
		case ')': 
			return 0;
			break;
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*': 
			return 2;
			break;
		case '/': 
			return 2;
			break;
		}
		return -1;
	}


public:
	TPostfix() : st(100), st2(100) 
	{
		infix = "";
		postfix = "";
	}

	string GetExpression() 
	{
		return infix;
	}
	string GetPostfix() 
	{
		return postfix;
	}
	string ToPostfix()
	{
		unsigned int i = 0;
		postfix = "";
		st.Clear();
		string src = "(" + infix + ")";
		for (i = 0; i < src.size(); i++) {
			if ((src[i] >= '0') && (src[i] <= '9') || (src[i] == '.')) 
			{
				postfix += src[i];
			}
			else if (src[i] == '(') 
			{
				st.Push('(');
			}

			else if (src[i] == ')') 
			{
				while (st.TopView() != '(')
					postfix += st.GetTop();
				st.GetTop();
			}
			else if ((src[i] == '+') || (src[i] == '-') || (src[i] == '*') || (src[i] == '/') ) 
			{
				postfix += ' ';
				if (Priority(st.TopView()) < Priority(src[i]))
					st.Push(src[i]);
				else {
					while (Priority(st.TopView()) >= Priority(src[i]))
						postfix += st.GetTop();
					st.Push(src[i]);
				}
			}
		}
		return postfix;

	}
	bool Brackets(string strc) 
	{
		int Flag = 0;
		for (size_t i = 0; i < strc.size(); i++) 
		{
			if (strc[i] == '(') 
			{
				Flag++;
			}
			if (strc[i] == ')')
			{
				Flag--;
				if (Flag < 0) return false;
			}
		}
		if (Flag == 0)
			return true;
		else
			return false;
	}
	double Calculate() 
	{
		st2.Clear();
		double a, b, res;
		if (!Brackets(postfix)) 
		{
			throw "Неверные скобки";
		}
		for (size_t i = 0; i < postfix.size(); i++) 
		{
			if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' ) 
			{
		
				if (st2.IsEmpty()) 
				{
					throw "Стек пуст";
				}
				b = st2.GetTop();
				if (st2.IsEmpty()) 
				{
					throw "Стек пуст";
				}
				a = st2.GetTop();
				switch (postfix[i]) 
				{
				case '+':
					res = a + b;
					break;
				case '-':
					res = a - b;
					break;
				case '*':
					res = a * b; 
					break;
				case '/':
					res = a / b;
					break;
				}
				st2.Push(res);
			}
			else if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.')
			{
				char* tmp;
				res = strtod(&postfix[i], &tmp);
				st2.Push(res);
				size_t g = static_cast<size_t>(tmp - &postfix[i]);
				i += g - 1;
			}
		}
		if (st2.IsEmpty())
		{
			throw "Стек пуст";
		}
		else
		{
			res = st2.GetTop();
		}
		if (!st2.IsEmpty()) 
		{
			throw "Стек не пуст";
		}

		return res;
	}
	string SetInfix(const string str)
	{
		infix = "";
		if (!Brackets(str)) 
		{
			throw "Неверные скобки";
		}

		for (size_t i = 0; i < str.size(); i++) 
		{
			if (str[i] != ' ') 
			{
				infix += str[i];
			}
		}

		return infix;
	}
};


#endif