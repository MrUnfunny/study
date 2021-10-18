#include <bits/stdc++.h>
using namespace std;

int binaryExpo(int n, int e)
{
    int res = 1;
    while (e > 0)
    {
        if (e & 1)
        {
            res *= n;
        }
        n *= n;
        e >>= 1;
    }

    return res;
}

int main()
{
    int n, e;
    cout << "Enter number and the exponent" << endl;
    cin >> n >> e;

    cout << binaryExpo(n, e) << endl;
}