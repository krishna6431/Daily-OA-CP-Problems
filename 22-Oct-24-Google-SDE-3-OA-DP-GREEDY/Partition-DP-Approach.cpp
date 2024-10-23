// CODE WRITTEN BY mr_krishna(cc,cf,google)/krishna_6431(gfg,leet)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // dp[i] = minimum total cost of operations required to make the entire sequence sorted till index i
    vector<ll> dp(n + 1, 1e9);
    /**
     *  1 2 3 4 5 6 7 8
     *  3 2 1 5 4 7 6 8
     *
     * lets say we are at index j, here j = 8
     * dp[8] = (8-8) + dp[7]
     * dp[8] = (8-7) + dp[6]
     * dp[8] = (8-6) + dp[5]
     * dp[8] = (8-4) + dp[4]  ----> this state is not valid coz it will never be possible that 4 will not be added with 6,7,8 in a box before 5
     *
     * So there is conditional State ...Trasistions Are only Valid if maxx(1..j) < min(j..n) otherwise it will be invalid.
     */
    vector<vector<ll>> prefixMax(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> prefixMin(n + 1, vector<ll>(n + 1, 1e9));
    for (ll i = 1; i <= n; i++)
    {
        prefixMax[i][i] = arr[i];
        prefixMin[i][i] = arr[i];
        for (ll j = i + 1; j <= n; j++)
        {
            prefixMax[i][j] = max(prefixMax[i][j - 1], arr[j]);
            prefixMin[i][j] = min(prefixMin[i][j - 1], arr[j]);
        }
    }

    // DP Step
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j >= 1; j--)
        {
            ll minSuffix = prefixMin[j][i];
            ll maxSuffix = prefixMax[j][i];
            ll maxPrefix = prefixMax[1][j - 1];
            if (maxPrefix <= minSuffix)
            {
                dp[i] = min(dp[i], (maxSuffix - minSuffix) + dp[j - 1]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}