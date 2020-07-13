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
		int n;
		cin >> n;
		int a[n] = {};
		int b[n] = {};
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			b[i] = x;
			a[i] = x;
		}
		int val = b[n - 1];
		int k = n - 1;
		a[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (val > b[i]) {
				val = b[i];
				k = i;
			}
			a[i] = k;
		}
		bool ret = 0;
		vector<int> y;
		for (int i = 1; i < n; i++) {
			if (b[i] == b[a[i]])continue;
			bool ans = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (b[j] < b[i]) {
					ans = 1;
					y.push_back(j);
					y.push_back(i);
					y.push_back(a[i]);
					break;
				}
			}
			if (ans) {
				ret = 1;
				break;
			}
		}
		if (ret) {
			cout << "YES" << endl;
			for (auto i : y) {
				cout << i + 1 << " ";
			}
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}