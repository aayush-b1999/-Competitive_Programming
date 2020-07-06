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
		ll n, k;
		cin >> n >> k;
		map<ll, ll> ret;
		for (ll i = 0; i < n; i++) {
			ll a;
			cin >> a;
			ll b = k - a % k;
			b %= k;
			if (!b)continue;
			ret[b]++;
		}
		if (ret.empty()) {
			cout << 0 << endl;
			continue;
		}
		pair<ll, ll> ans;
		for (auto i : ret) {
			if (ans.second < i.second)ans = i;
			else if (ans.second == i.second)ans.first = i.first;
		}
		// cout << ans.first << " " << ans.second << endl;
		cout << k*(ans.second - 1) + ans.first + 1 << endl;
	}
}