#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int t, n, s, i, j, l, x, tmp_sum;

inline void solve(int id, int &sum, vector<int> &v, vector<bool> &used, vector<bool> &solution)
{
    if (id == t)
    {
        tmp_sum = 0;
        for (i = 0; i < t; i++)
            if (used[i])
                tmp_sum += v[i];

        if (tmp_sum <= n)
            if (sum < tmp_sum)
            {
                sum = max(sum, tmp_sum);
                for (i = 0; i < t; i++)
                    solution[i] = used[i];
            }

        return;
    }
    used[id] = true;
    solve(id + 1, sum, v, used, solution);
    used[id] = false;
    solve(id + 1, sum, v, used, solution);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> t)
    {
        vector<int> v(t);
        vector<bool> used(t+1, false), solution(t+1, false);

        for (auto &x : v) cin >> x;

        int sum = 0;
        solve(0, sum, v, used, solution);

        for (i = 0; i < t; i++)
            if (solution[i])
                cout << v[i] << " ";

        cout << "sum:" << sum << "\n";
    }
}