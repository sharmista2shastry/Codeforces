#include <iostream>
#include <vector>
using namespace std;

int review(vector<int> reviewer, int n)
{
    int s1_uv = 0, s1_dv = 0, s2_uv = 0, s2_dv = 0;

    for(int i=0; i<n; i++)
    {
        if(reviewer[i] == 1)
        {
            if(s1_uv >= s2_uv)
            s1_uv++;

            else 
            s2_uv++;
        }

        else if(reviewer[i] == 2)
        {
            if(s2_dv >= s1_dv)
            s2_dv++;

            else
            s1_dv++;
        }

        else
        {
            if(s1_uv >= s1_dv)
            s1_uv++;

            else if(s2_uv >= s2_dv)
            s2_uv++;

            else if(s1_dv > s1_uv)
            s1_dv++;

            else
            s2_dv++;
        }
    }
    return s1_uv + s2_uv;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> reviewer(n);

        for(int i=0; i<n; i++)
        cin >> reviewer[i];

        cout << review(reviewer, n) << endl;
    }
    return 0;
}
