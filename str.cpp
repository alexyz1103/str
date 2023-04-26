#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int main()
{
	MyString b = "Second";
	MyString a("First");
	string c = "text";
	a.append(b);
	a.print();
}