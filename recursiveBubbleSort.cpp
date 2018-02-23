#include <iostream>

using namespace std;

// A Bubble Sort... sort of a warm up. DO NOT USE THIS IN REAL WORLD APPLICATIONS!


// so many solutions I find forget to use pointers. Pointers are your friend!
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
    return;
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    
    cout << endl;
}

void recursiveBubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1]) { 
            swap(arr[i], arr[i+1]);
        }
    }
    if(size - 1 > 1) { 
        recursiveBubbleSort(arr, size-1);
    }
}

int main()
{
    int arr[] = { 3, 1, 0, -2, 5, 12, 2, 8, 4, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    recursiveBubbleSort(arr, size);
    printArray(arr, size);
}
