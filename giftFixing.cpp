 #include<bits/stdc++.h>
using namespace std;

long long fixing(vector<int> candies, vector<int> oranges, int n){

    long long ans = 0;
    int min_a = *min_element(candies.begin(), candies.end());
    int min_b = *min_element(oranges.begin(), oranges.end());
    for(int i=0; i<n; i++)
    ans += max(candies[i] - min_a, oranges[i] - min_b);

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> candies(n);
        vector<int> oranges(n);

        for(int i=0; i<n; i++)
        cin >> candies[i];

        for(int i=0; i<n; i++)
        cin >> oranges[i];

        cout << fixing(candies, oranges, n) << endl;
    }
    return 0;
}
