
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "SortImpls.h"
// windows.h is specific for windows. For Linux please use

#include <windows.h>

using namespace std;

void PrinArray(const vector<int> &array, string name);
void InitArray(vector<int> &array, int randMax);
int elapsed(timeval &startTime, timeval &endTime);

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: Sorter SORT_TYPE ARRAY_SIZE";
		return -1;
	}

	string sort_name = string(argv[1]);
	int size = atoi(argv[2]);

	if (size <= 0)
	{
		cerr << "array size must be positive" << endl;
		return -1;
	}

	srand(1);
	vector<int> items(size);
	InitArray(items, size);

	cout << "Sort employed:  " << sort_name << endl;
	cout << "initial:" << endl;

	PrinArray(items, string("items"));
	// GetTickCount is windows specific.
	int begin = GetTickCount();
	// Place logic to determine and call function of interest here.
	// Do not call all of them
	//    MergeSort(items, 0, size - 1);
	//    IterativeMergeSort(items, 0, size - 1);
	//    QuickSort(items, 0, size - 1);
	//    BubbleSort(items, 0, size - 1);
	//    InsertSort(items, 0, size - 1);

	if (sort_name == "MergeSort")
	{
		MergeSort(items, 0, size - 1);
	}
	else if (sort_name == "IterativeMergeSort")
	{
		IterativeMergeSort(items, 0, size - 1);
	}
	else if (sort_name == "QuickSort")
	{
		QuickSort(items, 0, size - 1);
	}
	else if (sort_name == "BubbleSort")
	{
		BubbleSort(items, 0, size - 1);
	}
	else if (sort_name == "InsertSort")
	{
		InsertSort(items, 0, size - 1);
	}

	int end = GetTickCount();

	cout << "sorted:" << endl;
	PrinArray(items, string("item"));
	int elapsed_secs = end - begin;
	cout << "Time (ms): " << elapsed_secs << endl;
	return 0;
}

// array initialization with random numbers
void InitArray(vector<int> &array, int randMax)
{

	vector<int> pool(randMax);
	for (int i = 0; i < randMax; i++)
	{
		pool[i] = i;
	}

	int spot;

	for (int i = 0; i < randMax; i++)
	{
		spot = rand() % (pool.size());
		array[i] = pool[spot];
		pool.erase(pool.begin() + spot);
	}

}

// Function to Print Array
void PrinArray(const vector<int> &array, string name)
{
	int size = array.size();

	for (int i = 0; i < size; i++)
	{
		cout << name << "[" << i << "] = " << array[i] << endl;
	}
}

// Function to calculate elapsed time if using gettimeofday
//int elapsed(timeval &startTime, timeval &endTime)
//{
// return (endTime.tv_sec - startTime.tv_sec) * 1000000 
// + (endTime.tv_usec - startTime.tv_usec);
//}
