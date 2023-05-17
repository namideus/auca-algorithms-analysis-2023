#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline const set<long> set_intersect(const set<long> &a, const set<long> &b)
{
    set<long> intersect;
    set_intersection(begin(a), end(a), begin(b), end(b), std::inserter(intersect, begin(intersect)));
    return intersect;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long n, m, d;

    while (cin >> n >> m && n + m)
    {
        set<long> a, b;

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

        cout << sz(set_intersect(a, b)) << "\n";
    }
}