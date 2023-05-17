#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

bool is_str_alpha(const string &s)
{
    for (auto c : s)
        if (isalpha(c))
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t, guess, in, comp;
    int i, j, p, g, n, sum;
    double b;
    bool f;

    cin >> p >> g;

    map<string, int> parties;

    while (p--)
    {
        cin >> s >> b;
        parties[s] = (int)(b * 10);
    }

    cin.ignore();

    for (i = 1; i <= g; i++)
    {
        getline(cin, guess);
        istringstream iss(guess);
        n = 0;
        sum = 0;
        comp = "";

        while (iss >> in)
        {
            if (in == "+") continue;

            if (is_str_alpha(in))
                sum += parties[in];
            else if (isdigit(in[0]))
                n = stoi(in);
            else
                comp = in;
        }

        n *= 10;

        f = false;
        if (comp == "=")
            f = sum == n;
        else if (comp == "<")
            f = sum < n;
        else if (comp == ">")
            f = sum > n;
        else if (comp == "<=")
            f = sum <= n;
        else if (comp == ">=")
            f = sum >= n;

        cout << "Guess #" << i << " was " << (f ? "correct." : "incorrect.") << "\n";
    }
}