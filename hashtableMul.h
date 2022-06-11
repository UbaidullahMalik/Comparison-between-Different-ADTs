#include<iostream>
#include"Node.h"
#include<list>
using namespace std;



//Hash Tables Chaining and Multiplication

template<typename T>
class hashtable_m
{
private:
	list<T>* data;
	int m;
public:
	hashtable_m(int s)
	{
		m = s;
		data = new list<T>[m];
	}
	~hashtable_m() {
		delete[] data;

	}
	int hash_mul(T k, int m, float a)
	{
		return m * ((k * a) - int(k * a));
	}
	void insert(const T& val)
	{
		int idx = hash_mul(val, m, 0.3);
		data[idx].push_back(val);
	}
	bool find(const T& val)
	{
		typename list<T>::iterator it;
		int idx = hash_mul(val, m, 0.3);
		if (idx >= 0 && idx < m)
		{
			for (it = data[idx].begin(); it != data[idx].end(); it++)
			{
				if (*it == val)
				{
					return true;
				}

			}
		}
		return false;
	}

	bool erase(const T& val)
	{

		typename list<T>::iterator it;
		int idx = hash_mul(val, m, 0.3);
		if (idx >= 0 && idx < m)
		{
			for (it = data[idx].begin(); it != data[idx].end(); it++)
			{
				if (*it == val)
				{
					data[idx].erase(it);
					return true;
				}

			}
		}

		return false;
	}
};