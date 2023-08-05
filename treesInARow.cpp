#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
 
void minTime(vector<int> treeHeights, int n, int k)
{
    int minOperations = n+1;
    int val = -1;

    for(int i=1; i<=1000; i++)
    {
        int op = 0;
        for(int j=0; j<n; j++)
        {
            if(treeHeights[j] != i + j*k)
            op++;
        }
        
        if(op < minOperations)
        {
            minOperations = op;
            val = i;
        }
    }

    cout << minOperations << endl;

    for(int i=0; i<n; i++)
    {
        if(treeHeights[i] - (val + i*k) < 0)
        cout << "+ " << i+1 << " " << (val + i*k) - treeHeights[i] << endl;

        else if(treeHeights[i] - (val + i*k) > 0)
        cout << "- " << i+1 << " " << treeHeights[i] - (val + i*k) << endl;
    }
} 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
 
    vector<int> treeHeights(n);
 
    for(int i=0; i<n; i++)
    cin >> treeHeights[i];
 
    minTime(treeHeights, n, k);
 
    return 0;
}
