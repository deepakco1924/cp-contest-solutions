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
int convert(string s) {


    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

int find_answer(string s, int a, int b, map<int, int>hp) {
    int val = INT_MAX;
    if (hp.count(a) == 0 or hp.count(b) == 0)return val;
    int inb = -1;
    int n = s.length();
    for (int i = n - 1 ; i >= 0; i--) {
        int x = s[i] - '0';
        if (x == b) {
            inb = i;
            break ;
        }
    }
    int ind = -1;
    for (int i = n - 1; i >= 0; i--) {
        int x = s[i] - '0';
        if (x == a and i < inb) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        return val;
    }

    int cnt = inb - ind - 1;
    cnt += n - inb - 1;
    return cnt;



}
void solve() {

    map<int, int>hp;
    string s;
    cin >> s;
    int n = convert(s);
    if (n % 25 == 0) {
        cout << 0 << endl;
        return ;
    }
    for (int i = 0; i < s.length(); i++) {
        hp[s[i] - '0']++;
    }
    debug(hp)
    int cnt1 = find_answer(s, 5, 0, hp);
    int cnt2 = find_answer(s, 2, 5, hp);
    int cnt3 = find_answer(s, 7, 5, hp);
    int cnt4 = find_answer(s, 0, 0, hp);
    int ans = min(cnt1, cnt2);
    ans = min(ans, min(cnt4, cnt3));
    cout << ans << endl;



    return  ;


}

int32_t main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef PAL_SAAB
    freopen("error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}