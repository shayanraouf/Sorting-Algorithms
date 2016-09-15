#ifndef SORTIMPLS_H
#define SORTIMPLS_H
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void BubbleSort(vector<int>& vector, int first, int last); 
void InsertSort(vector<int>& vector, int first, int last); 
void MergeSort(vector<int>& vec, int first, int last); 
void Merge(vector<int>& result, int first, int middle, int last);
void IterativeMergeSort(vector<int>& vector, int left, int right); 
void IterativeMerge(vector<int>& vec, vector<int>& tempArray, int left, int mid, int right);
void QuickSort(vector<int>& vec, int first, int last); 
int min(int x, int y) 
{ 
	return (x < y) ? x : y; 
} 


void QuickSort(vector<int>& vec, int first, int last) {

	int i = first; 
	int j = last;
	int pivot = vec[(first + last) / 2];

	
	while (i <= j) {          // partitions the array around the pivot 
		while (vec[i] < pivot)
		{
			i++;
		}

		while (vec[j] > pivot)
		{
			j--;
		}

		if (i <= j) 
		{
			
			swap(vec[i], vec[j]);
			i++;
			j--;
		}
	}

	
	if (first < j)   
	{
		QuickSort(vec, first, j);  
	}
	if (i < last)
	{

		QuickSort(vec, i, last);
	}
}

void IterativeMergeSort(vector<int>& vec, int left, int right)
{
	int size = right - left + 1;
	vector<int> tempArray(size);

	for (int i = 1; i < size; i = 2 * i)
	{
		for (int j = left; j < size - i; j += 2 * i)
		{
			int mid = j + i - 1;

			int rightEnd = min(j + 2 * i - 1, vec.size() - 1);

			IterativeMerge(vec, tempArray, j, mid, rightEnd);

		}
	}

}

void IterativeMerge(vector<int>& vec, vector<int>& tempArray, int left, int mid, int right)
{

	for (int i = left; i <= right; i++)
	{
		tempArray[i] = vec[i];
	}

	int leftIndex = left;
	int current = left;
	int high = mid + 1;

	while (current <= right)
	{
		if (high <= right && (tempArray[leftIndex] > tempArray[high] || leftIndex > mid))
		{
			vec[current] = tempArray[high];
			current++;
			high++;
		}
		else
		{
			vec[current] = tempArray[leftIndex];
			current++;
			leftIndex++;
		}
	}

}


void MergeSort(vector<int>& vec, int first, int last)
{

	if (first < last)
	{

		int middle = first + (last - first) / 2;
		MergeSort(vec, first, middle);
		MergeSort(vec, middle + 1, last);
		Merge(vec, first, middle, last);
	}

}
void Merge(vector<int>& vec, int first, int middle, int last)
{
	int size = last - first + 1;
	vector<int> tempArray(size);
	int first1 = first;
	int last1 = middle;
	int first2 = middle + 1;
	int last2 = last;
	int index = 0;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (vec[first1] < vec[first2])
		{
			tempArray[index] = vec[first1];
			first1++;
		}
		else
		{
			tempArray[index] = vec[first2];
			first2++;
		}

		index++;
	}

	while (first1 <= last1)
	{
		tempArray[index] = vec[first1];
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		tempArray[index] = vec[first2];
		first2++;
		index++;
	}
	for (index = 0; index < size; index++)
	{
		vec[first] = tempArray[index];
		first++;
	}


}


void BubbleSort(vector<int>& vector, int first, int last)
{
	int size = last - first + 1;
	for (int i = first; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (vector[j] > vector[j + 1])
			{
				swap(vector[j], vector[j + 1]);


			}
		}
	}

}


void InsertSort(vector<int>& vector, int first, int last)
{
	int size = last - first + 1;
	for (int i = 1; i < size; i++)
	{
		int k = i;
		int temp = vector[i];

		while (k > 0 && vector[k - 1] > temp)
		{
			vector[k] = vector[k - 1];
			k--;
		}

		vector[k] = temp;
	}
}

#endif 