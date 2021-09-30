#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<bool, pair<int, int>> nodepair;
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define endl "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define all(x) x.begin(), x.end()
#define clr(x, y) memset(x, y, sizeof(x))
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod = 1000000007;

const int MAXN = 222222LL;

int fact[MAXN], inv[MAXN], Tn;
int arr[MAXN];
int freq[MAXN];
int dp[MAXN];


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve() {
    int n;
    cin >> n;
    vi vec(n);
    for (int i = 0; i < n; i++)cin >> vec[i];
    deque<int>q;
    q.push_back(vec[0]);
    if (n == 1) {
        cout << 0 << endl;
        return ;
    }
    pbds<pii>s;
    s.insert({vec[0], 0});
    for (int i = 1; i < n; i++) {
        int a = s.order_of_key({vec[i], INT_MIN});
        int b = s.order_of_key({vec[i], INT_MAX});
        b = s.size() - b;
        s.insert({vec[i], i});
        if (a > b) {
            q.push_back(vec[i]);

        }
        else if (a < b) {
            q.push_front(vec[i]);

        }
        else {
            if (q.front() >= vec[i]) {
                q.push_front(vec[i]);
            }
            else {
                q.push_back(vec[i]);
            }

        }

    }
    vector<int>ans(all(q));
    int cnt = 0;
    s.clear();
    for (int i = 0; i < n; i++) {
        int a = s.order_of_key({ans[i], INT_MAX});
        cnt += s.size() - a;
        s.insert({ans[i], i});
    }
    cout << cnt << endl;

}

int32_t main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef PAL_SAAB
    freopen("error.txt", "w", stderr);
#endif
    w(x) {
        solve();
    }




}