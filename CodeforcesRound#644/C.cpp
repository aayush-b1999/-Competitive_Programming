#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define mp make_pair
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define pq priority_queue
#define M map
#define UM unordered_map
#define graph unordered_map<int,vector<int>>
#define graphw unordered_map<int,vector<pair<int,int>>>
#define V vector
#define mod 1000000007
#define inf 3000000000000000007ll
#define P pair
#define Fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) signed(a.size())
#define FIXED cout << fixed << setprecision(12)
#define L list
#define D deque
#define ld long double
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define deb(x) cout<<#x<<" "<<x<<endl;
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T, U> &rhs) {in >> rhs.first; in >> rhs.second; return in;}
template<class T, class U>ostream& operator<<(ostream& out, const pair<T, U> &rhs) {out << rhs.first; out << " "; out << rhs.second; return out;}
template<class T, class U>pair<T, U> operator+(pair<T, U> &a, pair<T, U> &b) {return pair<T, U>(a.first + b.first, a.second + b.second);}
template<class T, class U>pair<T, U> operator-(pair<T, U> &a, pair<T, U> &b) {return pair<T, U>(a.first - b.first, a.second - b.second);}
// Linear STL
// VECTOR
template<class T>istream& operator>>(istream& in, vector<T> &a) {for (auto &i : a)cin >> i; return in;}
template<class T>ostream& operator<<(ostream& out, const vector<T> &a) {for (auto &i : a)cout << i << " "; return out;}
// SET
template<class T>ostream& operator<<(ostream& out, const set<T> &a) {for (auto &i : a)cout << i << " "; return out;}
template<class T>ostream& operator<<(ostream& out, const unordered_set<T> &a) {for (auto &i : a)cout << i << " "; return out;}
template<class T>ostream& operator<<(ostream& out, const multiset<T> &a) {for (auto &i : a)cout << i << " "; return out;}
// MAP
template<class T, class U>ostream& operator<<(ostream& out, const map<T, U> &a) {for (auto &i : a)cout << "(" << i.first << ", " << i.second << "(\n"; return out;}
template<class T, class U>ostream& operator<<(ostream& out, const unordered_map<T, U> &a) {for (auto &i : a)cout << "(" << i.first << ", " << i.second << "(\n"; return out;}
template<typename... T>void write(T&... args) {((cout << args << " "), ...); cout << endl;}
struct custom_hash {
	static ull splitmix64(ull x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(ull x) const {
		static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
		map<int, int> e, o;
		int even = 0;
		int odd = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a % 2 == 0) {
				e[a]++;
				even++;
			}
			else {
				o[a]++;
				odd++;
			}
		}
		if (even % 2 == 0 && odd % 2 == 0) {
			cout << "YES" << endl;
			continue;
		}
		bool x = false;
		for (auto i : e) {
			if (o.count(i.first - 1)) {
				x = true;
				break;
			}
			if (o.count(i.first + 1)) {
				x = true;
				break;
			}
		}
		if (x) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}

}