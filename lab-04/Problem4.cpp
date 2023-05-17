#include <bits/stdc++.h>
#define umint unordered_multiset<int>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline umint set_diff(const umint &a, const umint &b)
{
    umint diff;
    auto a_ord = multiset<int>(begin(a), end(a));
    auto b_ord = multiset<int>(begin(b), end(b));
    set_difference(begin(a_ord), end(a_ord), begin(b_ord), end(b_ord),
                   std::inserter(diff, begin(diff)));
    return diff;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, d, t, i, j;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        umint a, b;

        while (n--)
        {
            cin >> d;
            a.insert(d);
        }

        while (m--)
        {
            cin >> d;
            b.insert(d);
        }

        cout << sz(set_diff(a, b)) + sz(set_diff(b, a)) << "\n";
    }
}






