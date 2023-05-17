#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

char c, d, e, f, j;
unordered_map<string, int> mp;

inline void precalc()
{
    int cnt = 1;

    for (c = 'a'; c <= 'z'; c++)
        mp[string(1, c)] = cnt++;

    for (c = 'a'; c <= 'z'; c++)
        for (d = c + 1; d <= 'z'; d++)
            mp[string(1, c) + string(1, d)] = cnt++;

    for (c = 'a'; c <= 'z'; c++)
        for (d = c + 1; d <= 'z'; d++)
            for (e = d + 1; e <= 'z'; e++)
                mp[string(1, c) + string(1, d) + string(1, e)] = cnt++;

    for (c = 'a'; c <= 'z'; c++)
        for (d = c + 1; d <= 'z'; d++)
            for (e = d + 1; e <= 'z'; e++)
                for (f = e + 1; f <= 'z'; f++)
                    mp[string(1, c) + string(1, d) + string(1, e) + string(1, f)] = cnt++;

    for (c = 'a'; c <= 'z'; c++)
        for (d = c + 1; d <= 'z'; d++)
            for (e = d + 1; e <= 'z'; e++)
                for (f = e + 1; f <= 'z'; f++)
                    for (j = f + 1; j <= 'z'; j++)
                        mp[string(1, c) + string(1, d) + string(1, e) + string(1, f) + string(1, j)] = cnt++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    precalc();

    while (cin >> s)
    {
        cout << mp[s] << "\n";
    }
}