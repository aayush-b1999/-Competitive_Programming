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
const int N = 2e2 + 1;
int par[N];

int parent(int a) {
	if (par[a] == a)return a;
	return par[a] = parent(par[a]);
}

void uni(int a, int b) {
	par[a] = b + 1;
	par[b] = b + 1;
}

int main() {
	Fast;
	int t = 1;
	judge();
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		int n = a.size();
		int ans = 0;
		for (int i = 0; i <= n; i++)par[i] = i;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				int x = parent(j);
				int y = parent(j + 1);
				// cout << x << " " << y << endl;
				if (y == n)continue;
				if (x == y)continue;
				if (a[x] == a[y])continue;
				ans++;
				uni(x, y);
			}
		}
		// cout << ans << endl;
		if (ans % 2 == 0) {
			cout << "NET";
		}
		else {
			cout << "DA";
		}
		cout << endl;
	}
}