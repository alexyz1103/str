#include "MyString.h"
//#include <iostream>
using namespace std;

void MyString::print()
{
	for (int i = 0; i < lenght; i++) 
	{ 
		cout << str[i]; 
	}
	cout << endl;
}

int MyString::size()
{
	return this->lenght;
}

void MyString::resize(int n, char c)
{
	if (n < this->lenght && n >= 0) {
		MyString temp(*this);
		delete[] this->str;
		this->str = new char[n+1];
		for (int i = 0; i < n; i++)
		{
			this->str[i] = temp.str[i];
		}
		this->str[n] = '\0';
		this->lenght = n;
	}
	if (n > this->lenght) {
		MyString temp(*this);
		delete[] this->str;
		this->str = new char[n+1];
		for (int i = 0; i < this->lenght; i++)
		{
			this->str[i] = temp.str[i];
		}
		for (int i = this->lenght; i < n; i++)
		{
			this->str[i] = c;
		}
		this->str[n] = '\0';
		this->lenght = n;
	}
}


void MyString::clear()
{
	if (!empty()) {
		delete[] this->str;
		this->lenght = 0;
		this->str = nullptr;
	}
}

bool MyString::empty()
{
	if (lenght == 0 && this->str == nullptr) return true;
	else return false;
}

void MyString::push_back(char c)
{
	resize(lenght+1, c);
}

void MyString::append(int n, char c)
{
	resize(lenght + n, c);
}

void MyString::append(string T)
{
	int size = this->lenght + T.length();
	MyString temp(*this);
	delete[] this->str;
	this->str = new char[size + 1];
	int i = 0;
	for (; i < temp.lenght; i++)
		this->str[i] = temp.str[i];
	for (int j = 0; j < T.length(); j++, i++)
		this->str[i] = T[j];
	this->str[size] = '\0';
	this->lenght = size;
}

void MyString::append(MyString other)
{

}



