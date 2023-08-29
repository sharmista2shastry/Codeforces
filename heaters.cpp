#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

int main()
{
    int n,r;
    cin >> n >> r;
    vector<int> heaters(n);
    vector<int> cnt(n);
    for(int i=0; i<n; i++)
    cnt[i] = 0;

    int h = 0;

    for(int i=0; i<n; i++)
    {
        cin >> heaters[i];
        if(heaters[i] == 1)
        h++;
        if(heaters[i] == 1)
        {
            for(int j=max(0,i-r+1); j<min(n,i+r); j++)
            cnt[j]++;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(cnt[i] == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    for(int i=0; i<n; i++)
    {
        bool flag = true;
        if(heaters[i])
        {
            for(int j=max(0, i-r+1); j<min(n,i+r); j++)
            {
                if(cnt[j] == 1)
                {
                    flag = false;
                    break;
                }
            }
        }

        if(heaters[i] && flag)
        {
            h--;
            for(int j=max(0,i-r+1); j<min(n,i+r); j++)
            cnt[j]--;
        }
    }

    cout << h << endl;

    return 0;
}
