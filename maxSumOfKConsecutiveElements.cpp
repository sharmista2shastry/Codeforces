# include <iostream>
# include <vector>
#include <climits>
using namespace std;

void solve(vector<long long> a, int n, int k)
{
    // Constraints: 
    // n <= 10^5 k <= 10^5
    // -10^9 <= ai <= 10^9, Therefore use long long
    if(k == 0 || k > n)
    {
        cout << "Invalid input!" << endl;
        return;
    }

    long long maxSum = LONG_MIN;
    long long currSum = 0;

    for(int i=0; i<n; i++)
    {
        if(i < k)
        currSum += a[i];

        if(i == k-1)
        maxSum = max(maxSum, currSum);

        else if(i >= k)
        {
            currSum += a[i];
            currSum -= a[i-k];
            maxSum = max(maxSum, currSum);
        }
    }

    cout << maxSum << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        solve(a, n, k);
    }

    return 0;
}