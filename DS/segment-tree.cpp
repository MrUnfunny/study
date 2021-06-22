#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define INOUT                         \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pb push_back
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define fab(i, a, b) for (int i = a; i <= b; i++)
#define f0r(i, n) for (int i = n - 1; i >= 0; i--)
#define f1r(i, n) for (int i = n; i >= 1; i--)
#define fabr(i, a, b) for (i = b; i >= a; i--)
#define hi cout << "\nhi\n";
#define ln "\n"
#define typeof(x) __typeof__(x)
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define modInt 1000000007

int getSum(vi &segTree, int segStart, int segEnd, int qStart, int qEnd, int cur)
{
    if (qStart <= segStart && qEnd >= segEnd)
    {
        return segTree[cur];
    }

    if (qStart > segEnd || qEnd < segStart)
    {
        return 0;
    }

    int mid = (segStart + segEnd) / 2;
    return getSum(segTree, segStart, mid, qStart, qEnd, (2 * cur) + 1) + getSum(segTree, mid + 1, segEnd, qStart, qEnd, (2 * cur) + 2);
}

int buildSegTree(vi &a, vi &segTree, int segStart, int segEnd, int cur)
{
    if (segStart == segEnd)
    {
        segTree[cur] = a[segStart];
        return a[segStart];
    }

    int mid = (segStart + segEnd) / 2;

    segTree[cur] = buildSegTree(a, segTree, segStart, mid, (2 * cur) + 1) +
                   buildSegTree(a, segTree, mid + 1, segEnd, (2 * cur) + 2);

    return segTree[cur];
}

vi createSegTree(vi &a, int n)
{

    int x = ceil(log2(n));
    int maxSize = 2 * pow(2, x) - 1;

    vi segTree(maxSize, 0);
    buildSegTree(a, segTree, 0, n - 1, 0);

    return segTree;
}

int main()
{
    vi a;
    a.pb(1);
    a.pb(3);
    a.pb(5);
    a.pb(7);
    a.pb(9);
    a.pb(11);

    vi b = createSegTree(a, 6);

    tr(b, it)
    {
        cout << *it << ' ';
    }
}