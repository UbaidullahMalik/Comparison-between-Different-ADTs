#include<iostream>
#include"Node.h"



//Hash Tables Chaining and Division
template<typename T>
class hashtable_d {
private:
	list<T>* data;
	int m;
public:
	hashtable_d(int s)
	{
		m = s;
		data = new list<T>[m];
	}
	~hashtable_d() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		data[idx].push_back(val);
	}
	bool find(const T& val)
	{
		typename list<T>::iterator it;
		int idx = hash_div(val, m);
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
		int idx = hash_div(val, m);
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