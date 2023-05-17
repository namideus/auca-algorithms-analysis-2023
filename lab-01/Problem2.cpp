#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t, x;

    while (cin >> n && n > 0)
    {
        while (cin >> x)
        {
            if (x == 0)
            {
                cout << "\n";
                break;
            }

            vector<int> v(n);

            v[0] = x;

            for (int i = 1; i < n; i++) cin >> v[i];

            stack<int> st;

            for (int j = 0, cur = 1; cur <= n; cur++)
            {
                st.push(cur);

                for (; !st.empty() && st.top() == v[j]; j++)
                    st.pop();
            }

            cout << (st.empty() ? "Yes" : "No" ) << "\n";
        }
    }
}