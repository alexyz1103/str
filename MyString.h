#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
private:
	char* str;
	int lenght;
public:
	MyString() {
		lenght = 0;
		str = nullptr;
	}
	MyString(const char* newstr) {
		//lenght = strlen(newstr);
		int count = 0;
		while (newstr[count] != '\0') {
			count++;
		}
		lenght = count;
		str = new char[lenght];
		for (int i = 0; i < lenght; i++)
		{
			str[i] = newstr[i];
		}
		str[lenght] = '\0'; //??????????????????????????????????????????
		//lenght++;
	}
	~MyString() {
		delete[] str;
	}

	void print();

	MyString operator + (const MyString& other) {
		MyString temp;
		temp.lenght = this->lenght + other.lenght;
		temp.str = new char[lenght];
		int count = 0;
		while (this->str[count] != '\0')
		{
			temp.str[count] = this->str[count];
			count++;
		}
		count = 0;
		while (other.str[count] != '\0')
		{
			temp.str[count + this->lenght] = other.str[count];
			count++;
		}
		temp.str[temp.lenght] = '\0';
		return temp;
	}

	MyString(const MyString& other) {
		this->lenght = other.lenght;
		this->str = new char[this->lenght];
		for (int i = 0; i < this->lenght; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[this->lenght] = '\0';
	}

	/*MyString(MyString& other) {
		this->lenght = other.lenght;
		this->str = other.str;
		other.str = nullptr;
	}*/

};
	

