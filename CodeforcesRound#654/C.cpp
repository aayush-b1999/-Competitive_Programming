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
		ll v, c, a, b;
		cin >> v >> c >> a >> b;
		if (a + b > v + c) {
			cout << "No" << endl;
			continue;
		}
		if (v > c) {
			if (c < b) {
				cout << "No" << endl;
				continue;
			}
		}
		else {
			if (v < b) {
				cout << "No" << endl;
				continue;
			}
		}
		cout << "Yes" << endl;
	}
}