#include "modular_arith.cpp"

#include <string>

const int m = 31;
const int p = 10e9 + 9;

//To be changed as per input
const int n = 100;

int power[n];
int inverse[n];
int hashes[n];

void preCompute()
{
    power[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        power[i] = mult(power[i - 1], m, p);
    }

    int inv = powerMod(m, p - 2, p);
    inverse[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        inverse[i] = mult(inverse[i - 1], inv, p);
    }
}

void buildHashes(std::string s)
{
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        hashes[i] = add(i == 0 ? 0 : hashes[i - 1], mult(power[i], s[i] - 'a' + 1, p), p);
    }
}

int getHash(int start, int end)
{
    int res = add(hashes[end], start < 2 ? 0 : -hashes[start - 1], p);
    res = mult(res, start == 0 ? 1 : inverse[start - 1], p);
    return res;
}