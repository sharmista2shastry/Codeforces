#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int permutation(int n, vector<int> arr)
{
    int count = 0;
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++)
    mp[arr[i]]++;

    for(int i=1; i<=n; i++)
    {
        if(mp.count(i) > 0)
        continue;

        count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
    cin >> arr[i];

    cout << permutation(n, arr) << endl;

    return 0;
}
