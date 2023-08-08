# include <iostream>
# include <vector>
using namespace std;

void solve(int n, vector<int> time)
{
    int left = 0, right = n-1, a = 0, b = 0;
    vector<char> visited(n);

    for(int i=0; i<n; i++)
    visited[i] = 'n';

    while(left <= right)
    {
        if(left < right)
        {
            if(time[left] < time[right])
            {
                visited[left] = 'a';
                visited[right] = 'b';
                time[right] -= time[left];
                time[left] = 0;
                left++;
                a++;
            }

            else if(time[left] > time[right])
            {
                visited[left] = 'a';
                visited[right] = 'b';
                time[left] -= time[right];
                time[right] = 0;
                right--;
                b++;
            }

            else
            {
                visited[left] = 'a';
                visited[right] = 'b';
                time[left] = 0;
                time[right] = 0;
                left++;
                right--;
                a++;
                b++;
            }
        }

        else
        {
            if(visited[left] == 'n')
            {
                left++;
                a++;
                visited[left] = 'a';
            }

            else if(visited[left] == 'a')
            {
                a++;
                visited[left] = 'a';
                break;
            }

            else if(visited[left] == 'b')
            {
                b++;
                right--;
                break;
            }
        }
    }
    
    cout << a << " " << b << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> time(n);

    for(int i=0; i<n; i++)
    cin >> time[i];

    solve(n, time);

    return 0;
}