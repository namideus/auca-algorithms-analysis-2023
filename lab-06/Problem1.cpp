#include <bits/stdc++.h>
#define llui long long unsigned int

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    llui t, i, j;
    string s, ans, a, b;
    cin >> t;
    getline(cin, s);
    getline(cin, s);

    while (t--)
    {
        unordered_map<string, int> res;
        vector<string> v;

        while (getline(cin, s) && !s.empty()) v.push_back(s);

        for (i = 0; i < sz(v); i++)
            for (j = i + 1; j < sz(v); j++)
            {
                a = v[i] + v[j], b = v[j] + v[i], res[a]++, res[b]++;
                if (res[a] >= sz(v) / 2) ans = a;
                if (res[b] >= sz(v) / 2) ans = b;
            }

        cout << ans << "\n";

        if (t) cout << "\n";
    }

}
