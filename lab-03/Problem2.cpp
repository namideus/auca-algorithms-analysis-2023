#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, t, m, n, cnt;
    string w;

    cin >> t;

    for (test = 1; test <= t; test++)
    {
        cin >> m >> n;
        cin.ignore();

        set<string> a, b;

        for (int i = 0; i < m; ++i)
        {
            getline(cin, w);
            a.insert(w);
        }

        for (int i = 0; i < n; ++i)
        {
            getline(cin, w);

            for (auto s : a)
                b.insert(s + w);
        }

        cout << "Case " << test << ": " << sz(b) << "\n";
    }
}


