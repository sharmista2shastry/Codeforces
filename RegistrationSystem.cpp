#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
 
void registration(vector<string> &names, unordered_map<string, int> &mp, int n)
{
    for(int i=0; i<n; i++)
    {
        string name;
        cin >> name;
 
        if(mp.find(name) != mp.end() && mp[name] >= 1)
        {
            names.push_back(name + to_string(mp[name]));
            mp[name]++;
        }
 
        else
        {
            mp[name] = 1;
            names.push_back(name);
        }
        
    }
 
    for(int i=0; i<names.size(); i++)
    {
        if(names[i].back() - '0' >= 0 && names[i].back() - '0' <= 9)
        cout << names[i] << endl;
 
        else
        cout << "OK" << endl;
    }
}
 
int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    vector<string> names;
 
    registration(names, mp, n);
 
    return 0;
}
