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

ll fun(ll a, ll b) {
	if (!b)return 1;
	ll ans = fun(a, b / 2);
	ans = ans * ans;
	if (b & 1) {
		ans = ans * a;
	}
	return ans;
}

int main() {
	Fast;
	ll t = 1;
	judge();
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> v;
		unordered_map<ll, ll> ignore;
		for (ll i = 0; i < n; i++) {
			string a;
			cin >> a;
			ll val = 0;
			for (auto j : a) {
				val = val * 2 + j - '0';
			}
			ignore[val]++;
			v.push_back(val);
		}
		sort(all(v));
		ll s = 0, e = fun(2, x) - 1;
		ll ans = (fun(2, x) - n - 1) / 2;
		ll m = (s + e) / 2;
		while (ignore.count(m))m++;
		ll ret = m - (lower_bound(all(v), m) - v.begin());
		while (ret < ans) {
			while (ignore.count(m))m++;
			ret = m - (lower_bound(all(v), m) - v.begin());
			if (ret == ans)break;
			m++;
		}
		while (ret > ans) {
			while (ignore.count(m))m--;
			ret = m - (lower_bound(all(v), m) - v.begin());
			if (ret == ans)break;
			m--;
		}
		string b = "";
		for (ll i = x - 1; i >= 0; i--) {
			if ((m >> i) & 1)b.push_back('1');
			else
				b.push_back('0');
		}
		cout << b << endl;
	}
}