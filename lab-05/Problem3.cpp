#include <bits/stdc++.h>
#define lli long long int

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool f = false;
    lli cnt;
    string str, project, signee;

    unordered_map<string, set<string>> fair, signups;
    unordered_map<string, lli> result;
    vector<pair<string, lli>> sorted;

    while (getline(cin, str) && str != "0")
    {
        if (str == "1")
        {
            for (auto &x : fair)
            {
                cnt = 0;

                for (auto &s : x.second)
                    if (sz(signups[s]) > 1)
                        cnt++;

                result[x.first] = sz(fair[x.first]) - cnt;
            }

            sorted = vector<pair<string, lli>>(begin(result), end(result));
            sort(begin(sorted), end(sorted), [](const pair<string, lli> & p1, const pair<string, lli> & p2) {
                if (p1.second == p2.second)
                    return p1.first < p2.first;
                return p1.second > p2.second;
            });

            for (auto &x : sorted)
                cout << x.first << " " << x.second << "\n";

            sorted.clear();
            fair.clear();
            signups.clear();
            result.clear();
        }
        else if (isupper(str[0]))
        {
            project = str;
            fair[project] = set<string>();
        }
        else
        {
            signups[str].insert(project);
            fair[project].insert(str);
        }
    }

}
