#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define Fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(v) v.begin(),v.end()
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void judge() {
#ifndef ONLINE_JUDGE
	FILE_READ_IN
	FILE_READ_OUT
#endif
}

int main() {
	Fast;
	int t = 1;
	judge();
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll a[n];
		for (ll i = 0; i < n; i++)cin >> a[i];
		ll dp[n][2] = {};
		dp[0][0] = a[0];
		dp[1][0] = a[0];
		dp[1][1] = a[1];
		for (ll i = 2; i < n; i++) {
			for (ll j = 0; j < 2; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			if (i % 2 == 0)dp[i][0] += a[i];
			else
				dp[i][1] += a[i];
		}
		// for (int j = 0; j < 2; j++) {
		// 	for (int i = 0; i < n; i++)cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		ll ans = dp[n - 1][0];
		for (ll i = 1; i < n; i++) {
			ll l = i - 2;
			if (l < 0)l = 0;
			else
				l = dp[i - 2][1];
			ll l2 = i - 3;
			if (l2 < 0)l2 = 0;
			else
				l2 = dp[i - 3][0];
			for (ll j = i; j < n; j += 2) {
				ll val = dp[j][1] - l;
				ll ret = dp[j][0] - l2;
				if (val > ret) {
					ans = max(ans, dp[n - 1][0] - ret + val);
					i = j;
				}
				else {
					break;
				}
			}
			// cout << ans << endl;
		}
		for (int i = 2; i < n; i += 2) {
			ll l = dp[i - 2][0];
			ll l2 = i - 3;
			if (i - 3 < 0)l2 = 0;
			else
				l2 = dp[i - 3][1];
			for (ll j = i; j < n; j += 2) {
				ll val = dp[j][0] - l;
				ll ret = dp[j][1] - l2;
				if (ret > val) {
					ans = max(ans, dp[n - 1][0] + ret - val);
					i = j;
				}
				else
					break;
			}
			// cout << "nakli " << ans << endl;
		}
		cout << ans << endl;
	}
}