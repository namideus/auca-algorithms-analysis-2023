#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    unordered_map<int, int> cnt;

    int n;

    while (cin >> n)
    {
        if (find(begin(v), end(v), n) == end(v))
        {
            v.push_back(n);
            cnt[n] = 1;
        }
        else
            cnt[n]++;
    }

    for (const auto &x : v)
        cout << x << " " << cnt[x] << "\n";

}