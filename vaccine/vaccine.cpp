#include "vaccine.h"
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
template <class t>
vaccine<t>::vaccine(int maxsize)
{
	arr = new t[maxsize];
	elements = 0;
	capacity = maxsize;
}
template <class t>
int vaccine<t>::length()
{
	return elements;
}
template <class t>
void vaccine <t>::update(int p, t newrecord)
{
	arr[p] = newrecord;
}
template <class t>
void vaccine<t>::Display()
{
	for (int i = 0; i < elements; i++)
	{
		cout << arr[i] << endl;
	}
}
template <class t>
void vaccine <t>::Append(t newrecord)
{
	arr[elements] = newrecord;
	elements++;
}
template <class t>
void vaccine <t> ::insertat(int index, t val)
{
	for (int i = elements; i > index; i--)
		arr[i] = arr[i - 1];
	arr[index] = val;
	elements++;
}
template <class t>
void vaccine <t> ::deleteat(int position)
{
	for (int i = position; i < elements - 1; i++)
		arr[i] = arr[i + 1];
	elements--;
}
template <class t>
void vaccine<t> ::AT(int pos)
{
	cout << arr[pos];
}
template <class t>
vaccine <t> ::~vaccine()
{
	delete[] arr;
}