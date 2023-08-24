#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> boxes(n);
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++)
    {
        cin >> boxes[i];
        mp[boxes[i]]++;
    }

    for(auto i: mp)
    {
        count = max(count, i.second);
    }

    cout << count << endl;

    return 0;
}
