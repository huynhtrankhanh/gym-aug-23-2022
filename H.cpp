#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, g;
    cin >> n >> g;

    vector<ll> sum(1 << n);

    for (int i = 0; i < n; i++)
        cin >> sum[1 << i];

    auto lsb = [&](int x)
    { return x & (-x); };

    for (ll mask = 1; mask < (1 << n); mask++)
    {
        if (__builtin_popcount(mask) == 1)
            continue;

        sum[mask] = sum[mask - lsb(mask)] + sum[lsb(mask)];
    }

    int count = 0;
    int min_problem_count = 30;

    for (ll mask = 0; mask < (1 << n); mask++)
    {
        if (sum[mask] * 100 / sum[(1 << n) - 1] >= g)
        {
            min_problem_count = min(min_problem_count, __builtin_popcount(mask));
        }
    }

    for (ll mask = 0; mask < (1 << n); mask++)
    {
        if (sum[mask] * 100 / sum[(1 << n) - 1] >= g && __builtin_popcount(mask) == min_problem_count)
        {
            count++;
        }
    }

    cout << min_problem_count << " " << count << "\n";

    for (ll mask = 0; mask < (1 << n); mask++)
    {
        if (sum[mask] * 100 / sum[(1 << n) - 1] >= g && __builtin_popcount(mask) == min_problem_count)
        {
            cout << sum[mask] * 100 / sum[(1 << n) - 1] << " ";
            vector<int> stuff;
            for (int i = 0; i < n; i++)
                if (mask >> i & 1)
                    stuff.push_back(i);
            for (int i = 0; i < stuff.size(); i++)
                cout << stuff[i] + 1 << " \n"[i == stuff.size() - 1];
        }
    }
}
