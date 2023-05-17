#include <bits/stdc++.h>
#define umint multiset<int>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n, m, d, t, i, j, ans, k, bill;

    while (cin >> n && n)
    {
        multiset<int> urn;
        ans = 0;

        for (i = 0; i < n; i++)
        {
            cin >> k;

            while (k--)
            {
                cin >> bill;
                urn.insert(bill);
            }

            auto lo = begin(urn);
            auto hi = --end(urn);

            ans += *hi - *lo;

            urn.erase(lo);
            urn.erase(hi);
        }

        cout << ans  << "\n";
    }
}