#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define RFOR(i, b, a) for (ll i = b; i >= a; --i)
#define DEBUG(x) cout << ">> " << #x << " : " << x << endl;
#define endl "\n"
#define F first
#define S second
#define pb(x) push_back(x)
#define ALL(x) x.begin(), x.end()
#define mp(x, y) make_pair(x, y)

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef unordered_map<ll, ll> STll;


/*************************************************************************
* UNION FIND - WITH RANK AND PATH-COMPRESSION
* @author Manish Joshi
*************************************************************************/
class UnionFind
{
    ll *id;
    ll *size;
    ll m_count;
public:
    UnionFind(ll n)
    {
        m_count = n;
        id = new ll[n];
        size = new ll[n];
        FOR(i, 0, n)
        {
            id[i] = i;
            size[i] = 1;
        }
    }
    ll find(ll x)
    {
        while(id[x] != x)
        {
            id[x] = id[id[x]];     // path compression
            x = id[x];
        }
        return x;
    }
    ll count()
    {
        return m_count;
    }
    void join(ll x, ll y)
    {
        ll xRoot = find(x);
        ll yRoot = find(y);
        if (xRoot == yRoot)
            return;

        // ranking the trees by sizes
        if (size[xRoot] < size[yRoot])
        {
            id[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
        else {
            id[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
        m_count--;
    }
    bool connected(ll v, ll w)
    {
        return find(v) == find(w);
    }
};
int main()
{
   // freopen("input.txt", "r", stdin);
    SPEED

    ll n;
    cin >> n;
    ll x, y;
    UnionFind uf(n);
    vpll p(n);
    FOR(i, 0, n)
    {
        cin >> p[i].F >> p[i].S;
    }
    FOR(i, 0, n)
    {
        FOR(j, i, n)
        {
            if (p[i].F == p[j].F || p[i].S == p[j].S)
            {
                uf.join(i, j);
            }
        }
    }
    cout << uf.count() - 1;
}
