#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline void solve(
        int &n, string &rule, int pos,
        vector<string> &out, vector<string> &dict, vector<string> &nums
)
{
    if (sz(rule) == pos)
    {
        for (const auto &x : out)
            cout << x;
        cout << "\n";
        return;
    }

    if (rule[pos] == '#')
    {
        for (const auto &x : dict)
        {
            out[pos] = x;
            solve(n, rule, pos + 1, out, dict, nums);
        }
    }

    if (rule[pos] == '0')
    {
        for (int i = 0; i < 10; i++)
        {
            out[pos] = nums[i];
            solve(n, rule, pos + 1, out, dict, nums);
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int t, n, i, j, x, cnt, r;
    string rule;
    vector<string> out;

    while (cin >> n)
    {
        vector<string> dict(n);

        for (auto &x : dict)
            cin >> x;

        cin >> r;

        cout << "--\n";

        while (r--)
        {
            cin >> rule;

            out = vector<string>(sz(rule));

            solve(n, rule, 0, out, dict, nums);
        }
    }
}