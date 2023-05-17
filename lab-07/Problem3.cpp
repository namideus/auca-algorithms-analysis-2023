#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    double total;
    string s;

    cin >> t;

    cin.ignore();
    cin.ignore();

    while (t--)
    {
        total = 0;
        map<string, int> mp;

        while (getline(cin, s) && s != "")
            mp[s]++, total++;

        for (auto const &x : mp)
            cout << x.first << " " << fixed << setprecision(4) << (x.second / total) * 100 << "\n";

        if (t)
            cout << "\n";
    }
}