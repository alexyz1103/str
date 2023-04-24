#include "MyString.h"
//#include <iostream>
using namespace std;

void MyString::print()
{
	int count = 0;
	while (this->str[count] != '\0') {
		cout << str[count];
		count++;
	}
	/*for (int i = 0; i < lenght; i++) 
	{ 
		cout << str[i]; 
	}*/
	cout << endl;
}
