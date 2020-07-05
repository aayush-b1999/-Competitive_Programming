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
		int n, k;
		cin >> n >> k;
		int a[n][n] = {};
		int row[n] = {};
		int col[n] = {};
		int i = 0, j = 0;
		int maxir = 0, minir = n;
		int maxic = 0, minic = n;
		int lim = 0;
		while (k--) {
			a[i][j] = 1;
			row[i]++;
			col[j]++;
			i++;
			j++;
			i %= n;
			j %= n;
			if (j == lim)lim++, j = lim;
		}
		for (int i = 0; i < n; i++) {
			maxir = max(maxir, row[i]);
			maxic = max(maxic, col[i]);
			minir = min(minir, row[i]);
			minic = min(minic, col[i]);
		}
		int ans = (maxir - minir) * (maxir - minir) + (maxic - minic) * (maxic - minic);
		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}
}