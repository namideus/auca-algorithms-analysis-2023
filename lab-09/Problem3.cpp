#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int t, m, n, i, j, sx, sy, dx, dy;

char lb[9][9];

const vector<char> path = {'I', 'E', 'H', 'O', 'V', 'A', '#'};

inline void solve(int x, int y, int id, bool &f)
{
    if (id == 7)
    {
        cout << "\n";
        return;
    }

    if (f)
        cout << " ";

    if (y - 1 >= 0 && lb[y - 1][x] == path[id])
    {
        f = true;
        cout << "forth";
        solve(x, y - 1, id + 1, f);
    }
    else if (x - 1 >= 0 && lb[y][x - 1] == path[id])
    {
        f = true;
        cout << "left";
        solve(x - 1, y, id + 1, f);
    }
    else if (x + 1 < n && lb[y][x + 1] == path[id])
    {
        f = true;
        cout << "right";
        solve(x + 1, y, id + 1, f);
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
        cin >> m >> n;

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
            {
                cin >> lb[i][j];

                if (lb[i][j] == '@')
                    sx = j;
            }

        bool f = false;

        solve(sx, m - 1, 0, f);
    }
}