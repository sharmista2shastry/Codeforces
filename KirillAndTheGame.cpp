#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r, x, y;
    float k;
    cin >> l >> r >> x >> y >> k;

    for(int i=x; i<=y; i++)
    {
        int j=i*k;
        if(j>=l && j<=r)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}