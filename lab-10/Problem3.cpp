#include <bits/stdc++.h>
typedef long long int lli;

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t, n, h;

    cin >> t;

    while (t--)
    {
        cin >> n >> h;

        string bits = string(n - h, '0') + string(h, '1');

        do
            cout << bits << "\n";
        while (next_permutation(begin(bits), end(bits)));

        if (t)
            cout << "\n";
    }
}