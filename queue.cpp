#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void optimiseQ(int n, vector<int> q)
{
    sort(q.begin(), q.end());

    int wait = 0;
    int satisfied = 0;

    for(int i=0; i<n; i++)
    {
        if(q[i] >= wait)
        {
            satisfied++;
            wait += q[i];
        }
    }

    cout << satisfied << endl;
}

int main()
{
    int n;
    cin >> n;

    if(n == 0)
    {
        cout << "0";
        return 0;
    }

    vector<int> q(n);

    for(int i=0; i<n; i++)
    cin >> q[i];

    optimiseQ(n, q);

    return 0;
}