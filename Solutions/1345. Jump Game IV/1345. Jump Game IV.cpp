#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,l,r) for (int i = l; i < r; ++i)
#define repe(i,l,r) for (int i = l; i <= r; ++i)
#define repde(i,r,l) for (int i = r; i >= l; --i)
#define repall(v,a) for (const auto& v:a)
// #define rep(i, n) for (ll i = 0; i < n; ++i)
#define maxint INT_MAX
#define maxll std::numeric_limits<long long int>::max()
#define minint INT_MIN
#define minll std::numeric_limits<long long int>::min()
typedef long long ll;
typedef unsigned long long ull;


constexpr unsigned mod = 1000000007;


struct mint{
    unsigned num = 0;
    constexpr mint() noexcept {}
    constexpr mint(const mint &x) noexcept : num(x.num){}
    inline constexpr operator ll() const noexcept { return num; }
    inline constexpr mint& operator+=(mint x) noexcept { num += x.num; if(num >= mod) num -= mod; return *this; }
    inline constexpr mint& operator++() noexcept { if(num == mod - 1) num = 0; else num++; return *this; }
    inline constexpr mint operator++(int) noexcept { mint ans(*this); operator++(); return ans; }
    inline constexpr mint operator-() const noexcept { return mint(0) -= *this; }
    inline constexpr mint operator-(mint x) const noexcept { return mint(*this) -= x; }
    inline constexpr mint& operator-=(mint x) noexcept { if(num < x.num) num += mod; num -= x.num; return *this; }
    inline constexpr mint& operator--() noexcept { if(num == 0) num = mod - 1; else num--; return *this; }
    inline constexpr mint operator--(int) noexcept { mint ans(*this); operator--(); return ans; }
    inline constexpr mint& operator*=(mint x) noexcept { num = ull(num) * x.num % mod; return *this; }
    inline constexpr mint& operator/=(mint x) noexcept { return operator*=(x.inv()); }
    template<class T> constexpr mint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(mod); if(y < 0) y += mod; num = unsigned(y);
    }
    template<class T> inline constexpr mint operator+(T x) const noexcept { return mint(*this) += x; }
    template<class T> inline constexpr mint& operator+=(T x) noexcept { return operator+=(mint(x)); }
    template<class T> inline constexpr mint operator-(T x) const noexcept { return mint(*this) -= x; }
    template<class T> inline constexpr mint& operator-=(T x) noexcept { return operator-=(mint(x)); }
    template<class T> inline constexpr mint operator*(T x) const noexcept { return mint(*this) *= x; }
    template<class T> inline constexpr mint& operator*=(T x) noexcept { return operator*=(mint(x)); }
    template<class T> inline constexpr mint operator/(T x) const noexcept { return mint(*this) /= x; }
    template<class T> inline constexpr mint& operator/=(T x) noexcept { return operator/=(mint(x)); }
    inline constexpr mint inv() const noexcept { ll x = 0, y = 0; extgcd(num, mod, x, y); return x; }
    static inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    inline constexpr mint pow(ull x) const noexcept { mint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
};
std::istream& operator>>(std::istream& is, mint& x) noexcept { ll a; cin >> a; x = a; return is; }
inline constexpr mint operator""_M(ull x) noexcept { return mint(x); }
std::vector<mint> fac(1, 1), inv(1, 1);
inline void reserve(ll a){
    if(fac.size() >= a) return;
    if(a < fac.size() * 2) a = fac.size() * 2;
    if(a >= mod) a = mod;
    while(fac.size() < a) fac.push_back(fac.back() * mint(fac.size()));
    inv.resize(fac.size());
    inv.back() = fac.back().inv();
    for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline mint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline mint perm(ll n, ll r){
    if(r < 0 || n < r) return 0;
    if(n >> 24){ mint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
    reserve(n + 1); return fac[n] * inv[n - r];
}
inline mint comb(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(r + 1); return perm(n, r) * inv[r]; }
inline mint Mcomb(ll n, ll r){ return comb(n + r - 1, n - 1); } 
inline mint catalan(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }




template <typename T, int D>
struct VEC : public vector<VEC<T, D - 1>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  VEC(int n = 0, Args... args)
      : vector<VEC<T, D - 1>>(n, VEC<T, D - 1>(args...)) {}
};
template <typename T>
struct VEC<T, 1> : public vector<T> {
  VEC(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
// EX:
// ---------------------------------------
// int a[10][50] initialized with zero
// VEC<int, 2> a(10, 50);
// ---------------------------------------
// double b[n][m][k] initialized with 3.14
// VEC<double, 3> b(n, m, k, 3.14);
// ---------------------------------------
// the third dimension has no value yet
// VEC<long long, 3> c(5, 5);
// now c[0][0][0] has a value (100) but others don't
// c[0][0].push_back(100);
// ---------------------------------------
// VEC<int, 4> d(10, 10);
// now d[2][3][0] is a vector with 100 values of 12345
// d[2][3].push_back(VEC<int, 1>(100, 12345));
// ---------------------------------------
// just blank vector of strings
// VEC<string, 1> e;
// ---------------------------------------

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> idxtoval;
        rep(i,0,n){
            idxtoval[arr[i]].pb(i);
        }
        VEC<bool,1> visited(n);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        int step=0;
        while(q.size()){
            repde(sz,q.size(),1){
                int idx=q.front();q.pop();
                if(idx==n-1){
                    return step;
                }
                auto& next=idxtoval[arr[idx]];
                next.pb(idx-1);
                next.pb(idx+1);
                repall(idx2,next){
                    if(idx2>=0 and idx2<n and !visited[idx2]){
                        visited[idx2]=true;
                        q.push(idx2);
                    }
                }
                next.clear();
            }
            ++step;
        }
        return 0;
    }
};