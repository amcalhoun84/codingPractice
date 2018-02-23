
#include <iostream>
#include <unordered_set>
using namespace std;

// You can use arrays or vectors for this... just depends on what you want to do.
bool zeroSumArray(int arr[], int size)
{

	// originally, I thought of using a hashmap, but I realized for this purpose, a set is probably better to 
	// store the elements. arr[0...i] where 0 <= i < n
	unordered_set<int> set;

	set.insert(0); // initialize the set with a 0.

	int sum = 0;

	for(int i = 0; i < size; i++)
	{
		sum += arr[i];

		if(set.find(sum) != set.end()) return true;
		else set.insert(sum);
	}

	return false;
}

int main()
{
	
	int arr[] = { 4, 5, 6, -1, 4, -8 };
	int size = sizeof(arr)/sizeof(arr[0]);

	zeroSumArray(arr, size) ? cout << "Subarray(s) exist" << endl :
							  cout << "Subarray(s) do not exist" << endl;
	return 0;

}
