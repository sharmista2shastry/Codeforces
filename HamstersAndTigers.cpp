#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countHamster(int n, vector<char> animals)
{
    int count =0 ;

    for(int i=0; i<n; i++)
    {
        if(animals[i] == 'H')
        count++;
    }

    return count;
}

void solve(int n, int h, vector<char> animals)
{
    int minSwap = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(animals[i] == 'T')
        continue;

        int Swap = 0;
        int k = i;
        for(int j=0; j<h; j++)
        {
            if(animals[k] == 'T')
            Swap++;

            k = (k + 1) % n;
        }

        minSwap = min(minSwap, Swap);
    }

    cout << minSwap << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<char> animals(n);

    for(int i=0; i<n; i++)
    cin >> animals[i];

    int h = countHamster(n, animals);

    solve(n, h, animals);

    return 0;
}