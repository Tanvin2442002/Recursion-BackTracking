#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

const int N = 1e6 + 5;

vector<int> primes;

void sieve(int n) {
  vector<bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int findNumberofarray(int n, int i, vector<int>& primes, vector<int>& a, int m) {
  if (a.size() == m + 1)
    return 0;
  if (i == primes.size())
    return 0;
  a.push_back(primes[i]);
  int cnt = 0;
  int p = 1;
  bool flag = true;
  int sz = a.size()-1;
  for(int j=0;j<a.size()/2;j++){
     if(a[j]!=a[sz-j]){
        flag = false;
     }
  }

  for(int k:a){
    p*=k;
  }

  if (a.size() <= m && p <= n and flag) {
    cnt += ((1 + (findNumberofarray(n, i + 1, primes, a, m) + findNumberofarray(n, i, primes, a, m)))%mod);
    // dbg(cnt,a);
  }
  a.pop_back();
  cnt += (findNumberofarray(n, i + 1, primes, a, m)%mod);
  return cnt%mod;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n;
    cin >> n;
    sieve(n);
    int q;
    cin >> q;
    while (q--) {
      int m;
      cin >> m;
      vector<int> a;
      cout << findNumberofarray(n, 0, primes, a, m) << " ";
    }
  }
  return 0;
}