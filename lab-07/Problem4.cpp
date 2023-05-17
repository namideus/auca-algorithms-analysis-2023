#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, k, n, i, j, d, m;
    double total;

    cin >> k;

    for (t = 1; t <= k; t++)
    {
        cin >> n;

        map<int, set<int>> stamps, ownby;
        map<int, int> result;
        total = 0;

        for (i = 0; i < n; i++)
        {
            result[i] = 0;

            cin >> m;

            for (j = 0; j < m; j++)
            {
                cin >> d;
                stamps[i].insert(d);
                ownby[d].insert(i);
            }
        }

        for (auto const &x : stamps)
            for (auto const &e : x.second)
                if (sz(ownby[e]) == 1)
                {
                    result[x.first]++;
                    total++;
                }

        cout << "Case " << t << ": ";

        bool f = true;
        for (auto const &x : result)
        {
            if (!f) cout << " ";
            cout << fixed << setprecision(6) << (x.second / total) * 100 << "%";
            f = false;
        }
        cout << "\n";
    }
}