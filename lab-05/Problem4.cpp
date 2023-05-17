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

    llui cnt, t, n, s, i, j, ans;

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<llui> v(n);
        set<llui> st;

        for (auto &x : v) cin >> x;

        ans = 0;

        for (j = 0, i = 0; i < n; i++)
        {
            while (j < n && st.find(v[j]) == end(st))
                st.insert(v[j++]);

            if (sz(st) > ans)
                ans = sz(st);

            st.erase(v[i]);
        }

        cout << ans << "\n";
    }

}
