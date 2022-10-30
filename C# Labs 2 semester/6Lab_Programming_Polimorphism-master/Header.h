#include <string>
#include <iostream>
using namespace std;

class Lines
{
public:
	virtual int Length() = 0;
	virtual void Decrement() = 0;
};

class Symbols : Lines
{
private:
	string str;
public:
	Symbols(string _str);
	virtual int Length();
	virtual void Decrement();
	string GetData();
};

class Numbers : Lines
{
private:
	string str;
public:
	Numbers(string _str);
	virtual int Length();
	virtual void Decrement();
	string GetData();
};