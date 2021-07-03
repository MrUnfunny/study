int add(int n1, int n2, int mod)
{
    int res = (n1 + n2) % mod;
    if (res < 0)
        res += mod;
    return res;
}

int mult(int n1, int n2, int mod)
{
    int res = (n1 * 1LL * n2) % mod;
    if (res < 0)
    {
        res += mod;
    }
    return res;
}

int power(int n, int p, int mod)
{
    int res = 1;

    while (p)
    {
        if (p % 2 == 1)
        {
            res = mult(res, n, mod);
            n = mult(n, n, mod);
            p /= 2;
        }
    }
    return res;
}