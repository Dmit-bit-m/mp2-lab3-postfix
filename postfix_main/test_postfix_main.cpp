
#include "stack.h"
#include "postfix.h"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	TStack<int> s(100);
	cout << endl << "Тест постфикса" << endl;

	TPostfix pos;
	try 
	{
		cout << pos.SetInfix("((5+6+8*8)/7/5)*5-(1+3)") << endl;
		cout << pos.ToPostfix() << endl;
		cout << pos.Calculate() << endl;
	}
	catch (const char* e) 
	{
		cout << e << endl;
	}
	return 1;
}