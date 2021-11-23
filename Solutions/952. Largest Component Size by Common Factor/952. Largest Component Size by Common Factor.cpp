#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, n) for (int i = 0; i < n; ++i)
// #define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
template <int MOD>
struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() const { return MOD; }
  constexpr Fp operator-() const noexcept { return val ? MOD - val : 0; }
  constexpr Fp operator+(const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator-(const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator*(const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator/(const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator+=(const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator-=(const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator*=(const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator/=(const Fp& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator==(const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator!=(const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr istream& operator>>(istream& is, Fp<MOD>& x) noexcept {
    is >> x.val;
    x.val %= MOD;
    if (x.val < 0) x.val += MOD;
    return is;
  }
  friend constexpr ostream& operator<<(ostream& os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD>& r, long long n) noexcept {
    if (n == 0) return 1;
    if (n < 0) return modpow(modinv(r), -n);
    auto t = modpow(r, n / 2);
    t = t * t;
    if (n & 1) t = t * r;
    return t;
  }
  friend constexpr Fp<MOD> modinv(const Fp<MOD>& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b, swap(a, b);
      u -= t * v, swap(u, v);
    }
    return Fp<MOD>(u);
  }
};
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
using mint = Fp<MOD>;
// EX:
// vector<mint> dp(n + 1);
// dp[0] = 1;
// dp[1] = 2;
// dp[2] = 7;
// for (ll i = 3; i <= n; ++i) {
// dp[i] = ((mint)3 * dp[i - 1] + dp[i - 2] - dp[i - 3]);
// }
// cout << dp[n] << "\n";

template <typename T, int D>
struct VEC : public vector<VEC<T, D-1>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  VEC(int n = 0, Args... args)
      : vector<VEC<T, D-1>>(n, VEC<T, D-1>(args...)) {}
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
    int find(VEC<int,1>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(begin(nums),end(nums));
        VEC<int,1> ds(n+1,-1);
        for(auto& x:nums){
            // There is an undirected edge between nums[i] and nums[j]
            // if nums[i] and nums[j] share a common factor greater than 1
            for(int r=2;r<=sqrt(x);++r){
                if(x%r==0){
                    int a,b;
                    // a represents x
                    // important to union to a
                    a=find(ds,x);
                    b=find(ds,r);
                    if(a!=b){
                        ds[a]+=ds[b];
                        ds[b]=a;
                    }
                    // a=find(ds,x);
                    b=find(ds,x/r);
                    if(a!=b){
                        ds[a]+=ds[b];
                        ds[b]=a;
                    }
                }
            }
        }
        unordered_map<int,int> m;
        int res=1;
        for(auto& x:nums){
            res=max(res,++m[find(ds,x)]);
        }
        return res;
    }
};