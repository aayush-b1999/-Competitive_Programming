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
		string a;
		cin >> a;
		ll n = a.size();
		ll dp[n + 1] = {};
		for (ll i = 0; i < n; i++) {
			// dp[i + 1] = dp[i] + a[i] == '+' ? 1 : -1;
			if (a[i] == '+') {
				dp[i + 1] = dp[i] + 1;
			}
			else {
				dp[i + 1] = dp[i] - 1;
			}
		}
		// for (ll i = 1; i <= n; i++)cout << dp[i] << " ";
		// cout << endl;
		unordered_map<ll, ll> ans;
		ll x = 1;
		for (ll i = 1; i <= n; i++) {
			if (dp[i] + x == 0) {
				ans[x] = i;
				x++;
				ans[x] = i;
				continue;
			}
			ans[x] = i;
		}
		ll ret = 0;
		for (auto i : ans) {
			// cout << i.first << " " << i.second << endl;
			ret += i.second;
		}
		cout << ret << endl;
	}
}