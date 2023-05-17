#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

multimap<string, tuple<int, int, string>> calls;
unordered_map<string, bool> used;
string target, res;
int x, y;

inline string find_target_recursive(string source, int time)
{
    res = source;

    used[source] = true;
    for (auto const &p : calls)
    {
        x = get<0>(p.second);
        y = get<1>(p.second);
        target = get<2>(p.second);

        if (p.first == source && x <= time && x + y >= time)
        {
            if (used[target])
                res = "9999";
            else
                res = find_target_recursive(target, time);

            break;
        }
    }
    used[source] = false;

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    string source, target, time, duration, extension, ans;

    cin >> n;

    cout << "CALL FORWARDING OUTPUT\n";
    for (s = 1; s <= n; s++)
    {
        cout << "SYSTEM " << s << "\n";
        calls.clear();

        while (cin >> source && source != "0000")
        {
            cin >> x >> y >> target;
            calls.emplace(source, make_tuple(x, y, target));
        }

        while (cin >> time && time != "9000")
        {
            cin >> extension;
            ans = find_target_recursive(extension, stoi(time));
            cout << "AT " << time << " CALL TO " << extension << " RINGS " << ans << "\n";
        }
    }
    cout << "END OF OUTPUT\n";
}