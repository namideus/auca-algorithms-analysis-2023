#include <bits/stdc++.h>
#define INF 1e9

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct car
{
    int car_length, id;

    car(int l, int i) {
        car_length = l;
        id = i;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l, c, t, m, a, ans, total_length;
    string s;
    char fs;

    cin >> c;

    while (c--)
    {
        cin >> l >> m;

        l *= 100;

        queue<car> left, right;

        for (int i = 0; i < m; ++i)
        {
            cin >> a >> s;

            if (s.front() == 'l')
                left.emplace(a, i);
            else
                right.emplace(a, i);
        }

        fs = 'l';
        ans = 0;

        while (!left.empty() || !right.empty())
        {

            total_length = 0;

            while (true)
            {
                if (fs == 'l' && left.empty())
                    break;

                if (fs == 'r' && right.empty())
                    break;

                if (fs == 'l' && total_length + left.front().car_length > l)
                    break;

                if (fs == 'r' && total_length + right.front().car_length > l)
                    break;

                if (fs == 'l' && !left.empty())
                {
                    total_length += left.front().car_length;
                    left.pop();
                }

                if (fs == 'r' && !right.empty())
                {
                    total_length += right.front().car_length;
                    right.pop();
                }
            }
            fs = (fs == 'l' ?  'r' : 'l');
            ans++;
        }
        cout << ans << "\n";
    }
}