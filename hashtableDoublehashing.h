#include<iostream>
#include"Node.h"


//Hash Tables Open Addressing and Double Hashing
template<typename T>
class hashtable_dh {
private:
	T* data;
	int m;
	int n;
	const int EMPTY = -1;
	const int DEL = -2;

public:
	hashtable_dh(int s)
	{
		n = 0;
		m = s;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = EMPTY;
		}
	}
	~hashtable_dh() {
		delete[]data;

	}
	int hash_div(int k, int m)
	{
		return k % m;

	}
	void insert(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 7);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idx2 = idx + i * (1 + h2) % m;
				if (data[idx2] == EMPTY || data[idx2] == DEL)
				{
					data[idx2] = val;
					n++;
					return;
				}
			}
		}


	}
	bool find(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 7);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idx2 = idx + i * (1 + h2) % m;
				if (data[idx2] == val)
				{

					return true;
				}
			}
		}

		return false;
	}
	bool erase(const T& val)
	{
		int idx = hash_div(val, m);
		int h2 = hash_div(val, 7);
		if (idx >= 0 && idx < m)
		{
			for (int i = 0; i < m; i++)
			{
				int idx2 = idx + i * (1 + h2) % m;
				if (data[idx2] == val)
				{
					data[idx2] = DEL;
					n--;
					return true;
				}
			}
		}

		return false;
	}

};