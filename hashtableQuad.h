#include<iostream>
#include"Node.h"


//Hash Tables Open Addressing and Quadratic Probing
template<typename T>
class hashtable_qp {
private:
	T* data;
	int m;
	int n;
	int C1;
	int C2;
	const int EMPTY = -1;
	const int DEL = -2;

public:
	hashtable_qp(int s)
	{
		C1 = 3;
		C2 = 2;
		n = 0;
		m = s;
		data = new T[m];
		for (int i = 0; i < m; i++)
		{
			data[i] = EMPTY;
		}
	}
	~hashtable_qp() {
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
			int idx2 = (idx + C1 * i + C2 * i * i) % m;
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
			int idx2 = (idx + C1 * i + C2 * i * i) % m;
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
			int idx2 = (idx + C1 * i + C2 * i * i) % m;
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