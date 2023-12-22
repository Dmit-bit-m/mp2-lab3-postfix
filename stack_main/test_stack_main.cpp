#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	TStack<int> a(10);
	a.Push(5);
	a.Push(4);
	a.Push(7);
	a.Push(9);
	cout << "Вывод заполненого стека" << endl;
	while (!a.IsEmpty())
	{
		cout << a.GetTop() << endl;
	}
}