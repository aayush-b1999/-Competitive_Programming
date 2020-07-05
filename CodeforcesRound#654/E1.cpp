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
	// cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		int a[n];
		int dp[4001] = {};
		for (int i = 0; i < n; i++)cin >> a[i], dp[a[i]]++;
		sort(a, a + n);
		for (int i = 1; i <= 4000; i++) {
			dp[i] += dp[i - 1];
		}
		vector<int> ans;
		for (int i = a[0]; i <= 2000; i++) {
			ll v = i;
			ll x = 0;
			bool y = 1;
			while (1) {
				int ret = dp[v];
				ret -= x;
				if (ret % p == 0) {
					y = 0;
					break;
				}
				if (!ret)break;
				x++;
				if (x == n)break;
				v++;
				// cout << ret << " " << x << " " << v << endl;
			}
			if (x == n && y) {
				ans.push_back(i);
			}
		}
		cout << ans.size() << endl;
		for (auto i : ans) {
			cout << i << " ";
		}
	}
}