#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int ans, mn;

inline bool not_attacked(const int &r, const int &c, const vector<int> &new_r)
{
    for (int col = 1; col < c; col++)
        if (r == new_r[col] || r + c == new_r[col] + col || r - c == new_r[col] - col)
            return false;

    return true;
}

inline void solve(int col, const vector<int> &b, vector<int> &new_r)
{
    for (int row = 1; row <= 8; row++)
        if (not_attacked(row, col, new_r))
        {
            new_r[col] = row;

            if (col == 8)
                for (int c = 1, mn = 8; c <= 8; c++)
                    mn -= (new_r[c] == b[c] ? 1 : 0), ans = min(ans, mn);
            else
                solve(col + 1, b, new_r);
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c = 1;

    vector<int> b(9), new_r(9);

    while (cin >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6] >> b[7] >> b[8])
    {
        ans = 8;

        solve(1, b, new_r);

        cout << "Case " << c << ": " << ans << "\n";

        c++;
    }
}