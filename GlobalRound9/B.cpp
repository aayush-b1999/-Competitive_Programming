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
		int m, n;
		cin >> m >> n;
		int a[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		if (a[0][0] > 2 || a[m - 1][0] > 2 || a[m - 1][n - 1] > 2 || a[0][n - 1] > 2) {
			cout << "NO" << endl;
			continue;
		}
		a[0][0] = 2;
		a[m - 1][0] = 2;
		a[m - 1][n - 1] = 2;
		a[0][n - 1] = 2;
		bool ans = 1;
		for (int i = 1; i < m - 1; i++) {
			if (a[i][0] > 3 || a[i][n - 1] > 3)ans = 0;
			a[i][0] = a[i][n - 1] = 3;
		}
		for (int i = 1; i < n - 1; i++) {
			if (a[0][i] > 3 || a[m - 1][i] > 3)ans = 0;
			a[0][i] = a[m - 1][i] = 3;
		}
		for (int i = 1; i < m - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (a[i][j] > 4)ans = 0;
				a[i][j] = 4;
			}
		}
		if (!ans) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
}