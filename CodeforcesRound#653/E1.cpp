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
		ll n, k;
		cin >> n >> k;
		priority_queue<ll, vector<ll>, greater<ll>> q[3];
		for (ll i = 0; i < n; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			if (b && c) {
				q[0].push(a);
			}
			else if (b) {
				q[1].push(a);
			}
			else if (c) {
				q[2].push(a);
			}
		}
		bool x = 1;
		ll ans = 0;
		while (k--) {
			if (q[0].size() && q[1].size() && q[2].size()) {
				if (q[0].top() < q[1].top() + q[2].top()) {
					ans += q[0].top();
					q[0].pop();
				}
				else {
					ans += q[1].top() + q[2].top();
					q[1].pop();
					q[2].pop();
				}
			}
			else if (q[0].size()) {
				ans += q[0].top();
				q[0].pop();
			}
			else if (q[1].size() && q[2].size()) {
				ans += q[1].top() + q[2].top();
				q[1].pop(); q[2].pop();
			}
			else {
				x = 0;
				break;
			}
		}
		if (!x) {
			cout << -1;
			return 0;
		}
		cout << ans << endl;
	}
}