#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void shuffle(int n, int x, int m, vector<pair<int,int> > operations)
{
    int l=-1, u=-1;

    for(int i=0; i<m; i++)
    {
        int fI = operations[i].first;
        int sI = operations[i].second;

        if(x >= fI && x <=sI && l == -1 && u == -1)
        {
            l = fI;
            u = sI;
        }

        else if(l != -1 && u != -1)
        {
            if(fI <= l && sI >= l && sI <= u)
            l = fI;

            else if(sI >= u && fI >=l && fI <= u)
            u = sI;

            else if(fI <= l && sI >= u)
            {
                l = fI;
                u = sI;
            }
        }
    }

    cout << u - l + 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x, m;
        cin >> n >> x >> m;

        vector<pair<int,int> > operations(m);

        for(int i=0; i<m; i++)
        {
            cin >> operations[i].first;
            cin >> operations[i].second;
        }

        shuffle(n, x, m, operations);

    }
    return 0;
}