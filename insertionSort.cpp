#include <bits/stdc++.h>

using namespace std;

void rcInsertionSort(int a[], int i, int s)
{
	int v = a[i];
	int j = i;

	while (j > 0 && a[j-1] > v)
	{
		a[j] = a[j-1];
		j--;
	}

	a[j] = v;

	if(i + 1 <= s) { 
		rcInsertionSort(a, i+1, s);
	}
}

void insertionSort(int a[], int s)
{
	for(int i = 1; i < s; i++)
	{
		int v = a[i];
		int j = i;

		while(j > 0 && a[j-1] > v)
		{
			a[j] = a[j - 1];
			j--;
		}

		a[j] = v;

	}
}

void printArray(int a[], int s)
{
	for(int i=0; i < s; i++)
	{
		cout << a[i] << " ";
	}
}


int main()
{
	
	int a[] = { 3, 9, 1, 4, 6, 5, 8, 7, 2, 10 };
	int s = sizeof(a)/sizeof(a[0]);

	insertionSort(a, s);
	printArray(a, s);

	cout << endl << endl;

	int rcA[] = { 3, 9, 1, 4, 6, 5, 8, 7, 2, 10 };
	int rcS = sizeof(a)/sizeof(a[0]);
	rcInsertionSort(rcA, 1, rcS - 1);
	printArray(rcA, rcS);

	return 0;
}
