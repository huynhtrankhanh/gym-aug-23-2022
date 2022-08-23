#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2016-07-24
 * License: CC0
 * Source: Russian page
 * Description: Pre-computation of modular inverses. Assumes LIM $\le$ mod and that mod is a prime.
 * Status: Works
 */
#pragma once

const ll mod = 1000000007, LIM = 500000; /// include-line
ll inv[LIM + 50];
ll fac[LIM + 50], invfac[LIM + 50];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    inv[1] = 1;
    rep(i, 2, LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;

    fac[0] = 1;
    invfac[0] = 1;

    for (int i = 1; i <= 500000; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = (invfac[i - 1] * inv[i]) % mod;
    }

    auto comb = [&](ll n, ll k)
    {
        if (k > n)
            return 0ll;
        if (k < 0)
            return 0ll;
        return (fac[n] * invfac[k] % mod) * invfac[n - k] % mod;
    };

    int t;
    cin >> t;

    auto sub = [&](ll a, ll b)
    {
        return (a + mod - b) % mod;
    };

    auto add = [&](ll a, ll b)
    {
        return (a + b) % mod;
    };

    while (t--)
    {
        ll A, B, C, K, c;
        cin >> A >> B >> C >> K >> c;
        if (K == c || K == c + 1)
        {
            cout << "0\n";
            continue;
        }
        cout << (comb(C, c) * sub(comb(A + B, K - c), add(comb(A, K - c), comb(B, K - c)))) % mod << "\n";
    }
}
