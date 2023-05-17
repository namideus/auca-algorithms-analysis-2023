#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline string concat(const set<int> &v)
{
    string res;

    for (const auto &x : v)
        res += to_string(x);

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, l, j, ans, m;

    while (cin >> n && n)
    {
        unordered_map<string, int> cnt;
        m = ans = 0;
        for (i = 0; i < n; i++)
        {
            set<int> v;
            for (j = 0; j < 5; j++)
            {
                cin >> l;
                v.insert(l);
            }
            m = max(++cnt[concat(v)], m);
        }
        for (auto const &p : cnt)
            ans += p.second == m;
        cout << ans*m << "\n";
    }
}