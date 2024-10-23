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

    ll maxElem = 0;
    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        maxElem = max(maxElem, arr[i]);
        if (maxElem == i)
        {
            ans++;
        }
    }

    cout << maxElem - ans << endl;
    return 0;
}