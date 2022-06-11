#include<iostream>
#include"Node.h"

//Hash Tables Open Addressing and Linear Probing
template<typename T>
class hashtable_lp {
private:
	T* data;
	int m;
	int n;
	const int EMPTY = -1;
	const int DEL = -2;

public:
	hashtable_lp(int s)
	{
		m = s;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = EMPTY;
		}
	}
	~hashtable_lp() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + i) % m;
			if (data[idx2] == EMPTY || data[idx2] == DEL)
			{
				data[idx2] = val;
				n++;
				return;
			}
		}

	}
	bool find(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + i) % m;
			if (data[idx2] == val)
			{

				return true;
			}
		}
		return false;
	}
	bool erase(const T& val)
	{
		int idx = hash_div(val, m);
		for (int i = 0; i < m; i++)
		{
			int idx2 = (idx + i) % m;
			if (data[idx2] == val)
			{
				data[idx2] = DEL;
				n--;
				return true;
			}
		}
		return false;
	}



};