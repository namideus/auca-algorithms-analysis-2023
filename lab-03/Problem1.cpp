#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, m, n, i, j, t, c;

    cin >> k;

    while (k--)
    {
        cin >> m >> n;

        vector<int> a(m);

        for (auto &x : a) cin >> x;

        multiset<int> bb;

        auto it = begin(a);
        auto itbb = begin(bb);

        while (n--)
        {
            cin >> t;
            while (sz(bb) < t)
            {
                bb.insert(*it);
                if (*itbb > *it || itbb == end(bb))
                    itbb--;
                it++;
            }
            cout << *itbb << "\n";
            itbb++;
        }

        if (k)
            cout << "\n";
    }
}
