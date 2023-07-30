#include <iostream>
#include<algorithm>
#include <set>
#include <vector>
using namespace std;

void buy(int n, int m, vector<int> prices, vector<int> front, vector<int> back, vector<int> fav)
{
    set<int> s[4];

    for(int i=0; i<n; i++)
    {
        s[front[i]].insert(prices[i]);
        s[back[i]].insert(prices[i]); 
    }

    for(int i=0; i<m; i++)
    {
        if(!s[fav[i]].empty())
        {
            int element = *s[fav[i]].begin();
            cout << element << " ";
            s[1].erase(element);
            s[2].erase(element);
            s[3].erase(element);
        }
        
        else
        cout << "-1" << " ";
        
    }

    cout << endl;
}

int main()
{
    int n, m;
    cin >> n;

    vector<int> prices(n), front(n), back(n);

    for(int i=0; i<n; i++)
    cin >> prices[i];

    for(int i=0; i<n; i++)
    cin >> front[i];

    for(int i=0; i<n; i++)
    cin >> back[i];
    
    cin >> m;
    vector<int> fav(m);

    for(int i=0; i<m; i++)
    cin >> fav[i];

    buy(n, m, prices, front, back, fav);

    return 0;
}