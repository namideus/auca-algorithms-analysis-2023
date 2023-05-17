#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int t, n, i, cnt;

inline bool is_sqrt(int x)
{
    return (int)sqrt(x) * sqrt(x) == x;
}

inline void hanoi(int val, int id, vector<int> &pegs)
{
    if (n == id)
    {
        cout << cnt << "\n";
    }
    else if (!pegs[id])
    {
        cnt++;
        pegs[id] = val;
        return hanoi(val + 1, id, pegs);
    }
    else
    {
        for (i = 0; i <= id; i++)
        {
            if (is_sqrt(pegs[i] + val))
            {
                cnt++;
                pegs[i] = val;
                return hanoi(val + 1, id, pegs);
            }
        }

        return hanoi(val, id + 1, pegs);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> pegs(n + 1, 0);

        cnt = 0;

        hanoi(1, 0, pegs);
    }
}