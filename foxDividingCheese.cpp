#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int power_of_2(int num)
{
    int count = 0;

    while(num > 0 && num % 2 == 0)
    {
        count++;
        num /= 2;
    }

    return count;
}

int power_of_3(int num)
{
    int count = 0;

    while(num > 0 && num % 3 == 0)
    {
        count++;
        num /= 3;
    }

    return count;
}

int power_of_5(int num)
{
    int count = 0;

    while (num > 0 && num % 5 == 0)
    {
        count++;
        num /= 5;
    }

    return count;
}

void divide(int a, int b)
{
    if(a == b)
    {
        cout << "0" << "\n";
        return;
    }

    int two_a = power_of_2(a);
    int three_a = power_of_3(a);
    int five_a = power_of_5(a);

    int two_b = power_of_2(b);
    int three_b = power_of_3(b);
    int five_b = power_of_5(b);

    if((a / (pow(2,two_a) * pow(3,three_a) * pow(5,five_a))) != (b / (pow(2,two_b) * pow(3,three_b) * pow(5,five_b))))
    {
        cout << "-1" << endl;
        return;
    }

    int operations = (max(two_a, two_b) - min(two_a, two_b)) + (max(three_a, three_b) - min(three_a, three_b)) + (max(five_a, five_b) - min(five_a, five_b));
    cout << operations << endl;
}

int main()
{

    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    divide(a, b);

    return 0;
}