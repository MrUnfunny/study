#include "modular_arith.cpp"

#include <bits/stdc++.h>
#include <string>

using namespace std;

//p because it's often prime
const int p = 31;

// m because it's used as modulus
const int m = 10e9 + 9;

vector<int> power;
vector<int> inverse;
vector<int> hashes;

void preCompute(int n)
{
    power.push_back(1);

    for (int i = 1; i < n; ++i)
    {
        power.push_back(mult(power[i - 1], p, m));
    }

    int inv = powerMod(p, m - 2, m);
    inverse.push_back(1);
    for (int i = 1; i < n; ++i)
    {
        inverse.push_back(mult(inverse[i - 1], inv, m));
    }
}

void buildHashes(std::string s)
{
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        hashes.push_back(add(i == 0 ? 0 : hashes[i - 1], mult(power[i], s[i] - 'a' + 1, m), m));
    }
}

int getHash(int start, int end)
{
    int res = add(hashes[end], start < 2 ? 0 : -hashes[start - 1], m);
    res = mult(res, start == 0 ? 1 : inverse[start - 1], m);
    return res;
}