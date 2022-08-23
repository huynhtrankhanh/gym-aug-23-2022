#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */
#pragma once

struct UF
{
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, b;
    cin >> n >> b;

    vector<int> A(n);

    for (int &x : A)
        cin >> x;

    UF dsu(n);

    // for (int i = 0; i < n; i++)
    // {
    //     int to_the_left = i == 0 ? n - 1 : i - 1;
    //     int to_the_right = i == n - 1 ? 0 : i + 1;

    //     if (A[to_the_left] == A[i])
    //         dsu.join(to_the_left, i);
    //     if (A[to_the_right] == A[i])
    //         dsu.join(to_the_right, i);
    // }

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
    {
        int to_the_left = (i == 0 ? n - 1 : i - 1);
        int to_the_right = (i == n - 1 ? 0 : i + 1);

        if (A[i] > A[to_the_left])
            graph[dsu.find(i)].push_back(dsu.find(to_the_left));
        // else if (A[i] < A[to_the_left])
        //     graph[dsu.find(to_the_left)].push_back(dsu.find(i));
        if (A[i] > A[to_the_right])
            graph[dsu.find(i)].push_back(dsu.find(to_the_right));
        // else if (A[i] < A[to_the_right])
        //     graph[dsu.find(to_the_right)].push_back(dsu.find(i));
    }

    // cout << "GRAPH:\n";
    // rep(i, 0, n) for (int x : graph[i]) cout << i << " " << x << "\n";
    // cout << "END\n";

    vector<int> dp(n, -1);

    auto dfs = [&](auto dfs, int vertex)
    {
        if (dp[vertex] != -1)
            return dp[vertex];

        if (A[vertex] == 0)
            dp[vertex] = 0;
        else
            dp[vertex] = 1;
        for (int adjacent : graph[vertex])
            dp[vertex] = max(dp[vertex], dfs(dfs, adjacent) + 1);

        return dp[vertex];
    };

    for (int i = 0; i < n; i++)
        cout << (long long)dfs(dfs, dsu.find(i)) * (long long)b << " \n"[i == n - 1];
}