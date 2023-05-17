#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline const set<int> set_diff(const set<int> &a, const set<int> &b)
{
    vector<int> v(100001);
    auto it = set_difference(begin(a), end(a), begin(b), end(b), begin(v));
    return set<int>(begin(v), it);
}

inline const set<int> set_union(const set<int> &a, const set<int> &b)
{
    vector<int> v(100001);
    auto it = set_union(begin(a), end(a), begin(b), end(b), begin(v));
    return set<int>(begin(v), it);
}

inline const set<int> set_intersect(const set<int> &a, const set<int> &b)
{
    vector<int> v(100001);
    auto it = set_intersection(begin(a), end(a), begin(b), end(b), begin(v));
    return set<int>(begin(v), it);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, l, r, s, x, i, me, others;

    cin >> t;

    for (int test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ":\n";
        cin >> l >> r >> s;
        set<int> a, b, c;
        while (l--)
        {
            cin >> x;
            a.insert(x);
        }
        while (r--)
        {
            cin >> x;
            b.insert(x);
        }
        while (s--)
        {
            cin >> x;
            c.insert(x);
        }

        cout << sz(set_diff(a, set_union(b, c))) << " " << sz(set_diff(set_intersect(b, c), a)) << "\n";
        cout << sz(set_diff(b, set_union(a, c))) << " " << sz(set_diff(set_intersect(a, c), b)) << "\n";
        cout << sz(set_diff(c, set_union(a, b))) << " " << sz(set_diff(set_intersect(a, b), c)) << "\n";
    }
}