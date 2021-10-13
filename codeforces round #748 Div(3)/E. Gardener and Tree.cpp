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


const int N = 4e5 + 1;
vector<int>adj[N];
int n, k;

int dfs_find(int node, int parent, vector<int>&vec) {

    if (adj[node].empty()) {
        vec[0]++;
        return 1;
    }
    int ans = 0;
    for (auto x : adj[node]) {

        if (x != parent) {
            int val = dfs_find(x, node, vec);
            ans = max(ans, val);

        }
    }
    vec[ans]++;
    return ans + 1;
}
bool finding_path(int node, int dest, int parent, vector<int>&vec) {

    if (node == dest) {
        vec.pb(dest);
        return  true;
    }
    for (auto x : adj[node]) {
        if (x != parent) {
            bool ans = finding_path(x, dest, node, vec);
            if (ans ) {
                vec.push_back(x);
                return true;
            }

        }
    }
    return false;



}
pair<int, int> bfs(int root) {
    vector<int> dist(n + 1, 0);
    dist[root] = 1;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int curr = q.front();
        for (auto it : adj[curr]) {
            if (dist[it] != 0) {
                continue;
            }
            q.push(it);
            dist[it] = dist[curr] + 1;
        }
        q.pop();
    }
    int mx = INT_MIN, vertex = -1;
    for (int i = 1 ; i <= n ; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
            vertex = i;
        }
    }
    return make_pair(mx, vertex);
}

pair<int, pair<int, int>> diameter(int root) {
    pair<int, int> p1 = bfs(root), p2;
    p2 = bfs(p1.second);
    pair < int, pair<int, int>>ans;
    ans.first = p2.first;
    ans.ss.ff = p1.ss;
    ans.ss.ss = p2.ss;
    return ans;
}
void solve() {
    cin >> n >> k;
    int final = k;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (n == 1 or n == 2 ) {
        cout << 0 << endl;
        return ;

    }
    pair<int, pair<int, int>>nbr = diameter(1);
    vector<int>vec;
    // cout << nbr.ss.ff << " " << nbr.ss.ss << " " << nbr.ff << " ";
    finding_path(nbr.ss.ff, nbr.ss.ss, -1, vec);
    vec.push_back(nbr.ss.ff);
    debug(vec)
    int i = vec.size() - 1;
    int k = nbr.ff;
    int l = k;
    k = k / 2LL;
    int r ;

    while (k--) {
        i--;
    }
    if (l % 2 == 0) {
        r = l / 2 + 1;
    }
    else {
        r = ceil(l / 2.0);
    }
    int root = vec[i];
    debug(r)
    vector<int>freq(r, 0);
    dfs_find(root, -1, freq);
    int last = freq.size() - 1;
    if (freq[last] == freq[last - 1] == 1) {
        freq.pop_back();
    }
    if (final >= freq.size()) {
        cout << 0 << endl;
        return ;
    }
    int sum = 0;
    for (int i = 0; i < final; i++) {
        sum += freq[i];
    }
    cout << n - sum << endl;


    return ;


}

int32_t main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef PAL_SAAB
    freopen("error.txt", "w", stderr);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}