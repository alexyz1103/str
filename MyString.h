#pragma once
//#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
private:
	char* str;
	int lenght;
public:
	//����������� �� ���������
	//MyString a;
	MyString() {
		lenght = 0;
		str = nullptr;
	}
	
	//����������� � � ���������� ������� ��������
	//MyString a("����� �� �����");
	MyString(const char* newstr) {
		lenght = strlen(newstr);
		this->str = new char[lenght+1];
		for (int i = 0; i < lenght; i++)
		{
			this->str[i] = newstr[i];
		}
		this->str[lenght] = '\0';
	}
	//���������� ��� �������� ����� ������
	~MyString() {
		delete[] str;
	}

	//����� � ������� ������
	void print();

	//����������(������ ��������) � = 
	//a = "����� �� ������";
	MyString operator = (const char* newstr) {
		MyString temp(newstr);
		return temp;
	}

	MyString& operator = (const MyString& other) {
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->lenght = other.lenght;
		this->str = new char[lenght + 1];
		for (int i = 0; i < lenght; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[lenght] = '\0';
		return *this;
	}

	MyString operator + (const MyString& other) {
		MyString temp;
		temp.lenght = this->lenght + other.lenght;
		temp.str = new char[temp.lenght+1];
		int i = 0;
		for (; i < this->lenght; i++)
		{
			temp.str[i] = this->str[i];
		}
		for (int j = 0; j < other.lenght; j++,i++)
		{
			temp.str[i] = other.str[j];
		}
		temp.str[temp.lenght] = '\0';
		return temp;
	}

	MyString(const MyString& other) {
		this->lenght = other.lenght;
		this->str = new char[this->lenght+1];
		for (int i = 0; i < this->lenght; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[this->lenght] = '\0';
	}

	MyString(MyString& other) {
		this->lenght = other.lenght;
		this->str = other.str;
		other.str = nullptr;
	}

	char& operator [](int index) {
		return this->str[index];
	}
	
	int size();
	void resize(int n, char c = ' ');
	void clear();
	bool empty();
	void push_back(char c);
	void append(int n, char c);
	void append(string T);
	void append(MyString other);
};