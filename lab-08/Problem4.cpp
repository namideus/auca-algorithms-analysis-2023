#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

inline void permutate(
        vector<vector<int>> &res, const vector<int> &v, vector<int> &p, vector<bool> &used
)
{
    if (sz(p) == 5)
    {
        res.push_back(p);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            p.push_back(v[i]);
            permutate(res, v, p, used);
            p.pop_back();
            used[i] = false;
        }
    }
}

inline int compute_possibility(const vector<int> &v, int id, int res)
{
    if (id == 5)
        return res == 23;

    return compute_possibility(v, id + 1, res + v[id])
           || compute_possibility(v, id + 1, res - v[id])
           || compute_possibility(v, id + 1, res * v[id]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, e;

    while (cin >> a >> b >> c >> d >> e && a + b + c + d + e)
    {
        vector<int> v = {a, b, c, d, e}, permutation;
        vector<vector<int>> res;
        vector<bool> used(5, false);
        permutate(res, v, permutation, used);

        bool f = false;
        for (auto const &perm : res)
        {
            f = compute_possibility(perm, 1, perm[0]);

            if (f) break;
        }

        cout << (f ? "Possible" : "Impossible") << "\n";
    }
}
