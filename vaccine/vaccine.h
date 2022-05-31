#pragma once
template <class t>
class vaccine
{
	t* arr;
	int elements;
	int capacity;
public:
	vaccine(int);
	void update(int, t);
	int length();
	void Append(t);
	void Display();
	void insertat(int, t);
	void deleteat(int);
	~vaccine(void);
	void AT(int);
};