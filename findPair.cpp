#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// These are my solutions from most efficient to least for the popular find Pair problem.

// hash O(N)
void hashFindPair(vector<int> v, int sum)
{
    int n = v.size();
    
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
    {
        if(map.find(sum - v[i]) != map.end())
        {
            cout << "Pair found at indices " << map[sum - v[i]] << " and " << i << endl;
        }
        
        map[v[i]] = i;
    }
}



// n log n Solution

void sortFindPair(vector<int> v, int sum)
{
    int n = v.size();
    int c = n/2;
    sort(v.begin(), v.end());
    
    int low = 0,
        high = n-1;
    
    while(low < high)
    {
        if(v[low] + v[high] == sum)
        {
            cout << "Pair found" << endl;
        }
        
        (v[low] + v[high] < sum) ? low++: high--;
    }
    
    
}

// Naive Solution
void naiveFindPair(const vector<int> &v, int sum)
{

    for(int i=0; i < v.size()-1; i++)
    {
        for(int j = i + 1; j < v.size()-1; j++)
        {
            int s = v[i] + v[j];
            if(s == sum) cout << "Pair found at index " << i << " and index " << j << endl;
        }
    }
}

int main()
{
    vector<int> v = {8, 7, 2, 5, 3, 1};
    int sum = 10;
    
    // naiveFindPair(v, sum);
    //sortFindPair(v, sum);
    hashFindPair(v, sum);

    return 0;
}


