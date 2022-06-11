#include<iostream>
#include<cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>
#include<fstream>
#include <array>  
#include <random>
#include"unsortedList.h"
#include"sortedList.h"
#include"BST.h"
#include<map>
#include<unordered_map>
#include"hashtableMul.h"
#include"hashtableDiv.h"
#include"hashtableLin.h"
#include"hashtableQuad.h"
#include"hashtableDoublehashing.h"
using  namespace std;

int main()
{
	using namespace std::chrono;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	ofstream file_1;
	ofstream file_2;
	string F_observations = "Observations.csv";
	string F_report = "Final_report.csv";
	
	//Change the value of the variable OPS to change the number of observations the ADTs are tested against
	int const ARRAYSIZE = 11;
	int const OPS = 5000;
	array<int, OPS> Data{ 0 };

	int const hashtablesize = OPS / 5;
	double const hashtablesize2 = OPS * 1.3;
	UList<int> unorderedlist;
	SList<int> sortedlist;
	list<int> l;
	Tree<int> T;
	map<int, int> BstT;
	unordered_map<int, int> HashT;
	hashtable_m<int> hashmul(hashtablesize);
	hashtable_d<int> hashdiv(hashtablesize);
	hashtable_lp<int> hashlin(hashtablesize2);
	hashtable_qp<int> hashquad(hashtablesize2);
	hashtable_dh<int> hashdoub(hashtablesize2);

	string ADT[ARRAYSIZE] = { "Unordered List","Sorted List","STL List","BST Tree","MAP","Unordered MAP","HashTable_Multiplication","HashTable_Division" ,"HashTable_LinearProbing" ,"HashTable_QuadraticProbing" ,"HashTable_Doublehashing" };
	duration<double> INSERT[ARRAYSIZE];
	duration<double> FINDP[ARRAYSIZE];
	duration<double> FINDN[ARRAYSIZE];
	duration<double> DELETE[ARRAYSIZE];

	duration<double> FINSERT[ARRAYSIZE];
	duration<double> FFINDP[ARRAYSIZE];
	duration<double> FFINDN[ARRAYSIZE];
	duration<double> FDELETE[ARRAYSIZE];

	for (short o = 0; o < ARRAYSIZE; o++)
	{
		INSERT[o] = duration<double>(0);
		FINDP[o] = duration<double>(0);
		FINDN[o] = duration<double>(0);
		DELETE[o] = duration<double>(0);

		FINSERT[o] = duration<double>(0);
		FFINDP[o] = duration<double>(0);
		FFINDN[o] = duration<double>(0);
		FDELETE[o] = duration<double>(0);
	}

	cout << "The program is not stuck, it may take 20-25 minutes" << endl;

	file_1.open(F_observations, ios::out);

	for (short i = 0; i < 10; i++)
	{

		cout << "PROGRESS: " << (i + 1) * 10 << "%" << endl;
		for (short o = 0; o < ARRAYSIZE; o++)
		{
			INSERT[o] = duration<double>(0);
			FINDP[o] = duration<double>(0);
			FINDN[o] = duration<double>(0);
			DELETE[o] = duration<double>(0);
		}

		srand(time(NULL));
		for (int i = 0; i < OPS; i++)
		{
			Data[i] = rand() % OPS;
		}

		duration<double> inserttime_0;
		for (int j = 0; j < OPS; j++)
		{
			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.insert(Data[j]);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			INSERT[0] = INSERT[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			INSERT[1] = INSERT[1] + time_1;

			t1 = steady_clock::now();
			l.push_front(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			INSERT[2] = INSERT[2] + time_2;

			t1 = steady_clock::now();
			T.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			INSERT[3] = INSERT[3] + time_3;

			t1 = steady_clock::now();
			BstT.insert(pair<int, int>(j, Data[j]));
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			INSERT[4] = INSERT[4] + time_4;

			t1 = steady_clock::now();
			HashT.insert(pair<int, int>(j, Data[j]));
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			INSERT[5] = INSERT[5] + time_5;

			t1 = steady_clock::now();
			hashmul.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			INSERT[6] = INSERT[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			INSERT[7] = INSERT[7] + time_7;

			t1 = steady_clock::now();
			hashlin.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			INSERT[8] = INSERT[8] + time_8;

			t1 = steady_clock::now();
			hashquad.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			INSERT[9] = INSERT[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.insert(Data[j]);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			INSERT[10] = INSERT[10] + time_10;

		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FINSERT[a] = FINSERT[a] + INSERT[a];
		}

		shuffle(Data.begin(), Data.end(), default_random_engine(seed));
		for (int k = 0; k < OPS; k++)
		{
			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.find(Data[k]);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			FINDP[0] = FINDP[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			FINDP[1] = FINDP[1] + time_1;

			t1 = steady_clock::now();
			find(l.begin(), l.end(), Data[k]);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			FINDP[2] = FINDP[2] + time_2;

			t1 = steady_clock::now();
			T.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			FINDP[3] = FINDP[3] + time_3;

			t1 = steady_clock::now();
			BstT.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			FINDP[4] = FINDP[4] + time_4;

			t1 = steady_clock::now();
			HashT.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			FINDP[5] = FINDP[5] + time_5;

			t1 = steady_clock::now();
			hashmul.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			FINDP[6] = FINDP[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			FINDP[7] = FINDP[7] + time_7;

			t1 = steady_clock::now();
			hashlin.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			FINDP[8] = FINDP[8] + time_8;

			t1 = steady_clock::now();
			hashquad.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			FINDP[9] = FINDP[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.find(Data[k]);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			FINDP[10] = FINDP[10] + time_10;
		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FFINDP[a] = FFINDP[a] + FINDP[a];
		}

		shuffle(Data.begin(), Data.end(), default_random_engine(seed));
		for (int q = 0; q < OPS; q++)
		{
			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.find(-1);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			FINDN[0] = FINDN[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.find(-1);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			FINDN[1] = FINDN[1] + time_1;

			t1 = steady_clock::now();
			find(l.begin(), l.end(), -1);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			FINDN[2] = FINDN[2] + time_2;

			t1 = steady_clock::now();
			T.find(-1);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			FINDN[3] = FINDN[3] + time_3;

			t1 = steady_clock::now();
			BstT.find(-1);
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			FINDN[4] = FINDN[4] + time_4;

			t1 = steady_clock::now();
			HashT.find(-1);
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			FINDN[5] = FINDN[5] + time_5;

			t1 = steady_clock::now();
			hashmul.find(-1);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			FINDN[6] = FINDN[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.find(-1);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			FINDN[7] = FINDN[7] + time_7;

			t1 = steady_clock::now();
			hashlin.find(-1);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			FINDN[8] = FINDN[8] + time_8;

			t1 = steady_clock::now();
			hashquad.find(-1);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			FINDN[9] = FINDN[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.find(-1);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			FINDN[10] = FINDN[10] + time_10;

		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FFINDN[a] = FFINDN[a] + FINDN[a];
		}

		shuffle(Data.begin(), Data.end(), default_random_engine(seed));
		for (int m = 0; m < OPS; m++)
		{


			steady_clock::time_point t1 = steady_clock::now();
			unorderedlist.remove(Data[m]);
			steady_clock::time_point t2 = steady_clock::now();
			duration<double> time_0 = duration_cast<duration<double>>(t2 - t1);
			DELETE[0] = DELETE[0] + time_0;

			t1 = steady_clock::now();
			sortedlist.remove(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_1 = duration_cast<duration<double>>(t2 - t1);
			DELETE[1] = DELETE[1] + time_1;

			t1 = steady_clock::now();
			l.remove(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_2 = duration_cast<duration<double>>(t2 - t1);
			DELETE[2] = DELETE[2] + time_2;

			t1 = steady_clock::now();
			T.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_3 = duration_cast<duration<double>>(t2 - t1);
			DELETE[3] = DELETE[3] + time_3;

			t1 = steady_clock::now();
			BstT.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_4 = duration_cast<duration<double>>(t2 - t1);
			DELETE[4] = DELETE[4] + time_4;

			t1 = steady_clock::now();
			HashT.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_5 = duration_cast<duration<double>>(t2 - t1);
			DELETE[5] = DELETE[5] + time_5;

			t1 = steady_clock::now();
			hashmul.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_6 = duration_cast<duration<double>>(t2 - t1);
			DELETE[6] = DELETE[6] + time_6;

			t1 = steady_clock::now();
			hashdiv.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_7 = duration_cast<duration<double>>(t2 - t1);
			DELETE[7] = DELETE[7] + time_7;

			t1 = steady_clock::now();
			hashlin.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_8 = duration_cast<duration<double>>(t2 - t1);
			DELETE[8] = DELETE[8] + time_8;

			t1 = steady_clock::now();
			hashquad.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_9 = duration_cast<duration<double>>(t2 - t1);
			DELETE[9] = DELETE[9] + time_9;

			t1 = steady_clock::now();
			hashdoub.erase(Data[m]);
			t2 = steady_clock::now();
			duration<double> time_10 = duration_cast<duration<double>>(t2 - t1);
			DELETE[10] = DELETE[10] + time_10;

		}

		for (int a = 0; a < ARRAYSIZE; a++)
		{
			FDELETE[a] = FDELETE[a] + DELETE[a];
		}

		
		file_1 << "Obseravtion# " << i+1 << ",Insert" << ",Search(Present)" << ",Search(Not Present): " << ",Delete" << "\n";
		for (int a = 0; a < ARRAYSIZE; a++)
		{
			file_1 << ADT[a] << "," << INSERT[a].count() << "," << FINDP[a].count() << "," << FINDN[a].count() << "," << DELETE[a].count() << "\n";
		}
		file_1 << "\n";
		
	}
	file_1.close();

	cout << "Calculating Averages" << endl;
	file_2.open(F_report, ios::out);
	file_2 << "FINAL AVERAGES: " << ",Insert" << ",Search(Present)" << ",Search(Not Present): " << ",Delete" << "\n";
	for (int a = 0; a < ARRAYSIZE; a++)
	{
		file_2 << ADT[a] << "," << (FINSERT[a].count()) / ARRAYSIZE << "," << (FFINDP[a].count()) / ARRAYSIZE << "," << (FFINDN[a].count()) / ARRAYSIZE << "," << (FDELETE[a].count()) / ARRAYSIZE << "\n";
	}
	file_2.close();
	cout << "Completed!" << endl;

	return 0;
}