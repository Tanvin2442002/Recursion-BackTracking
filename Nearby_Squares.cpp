#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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

int calculate(int i, int n, int sumB, int sumC, vector<int>& v) {
  if (i == n) {
    return abs(sumB*sumB - sumC*sumC);
  }
  return min(calculate(i + 1, n, sumB + v[i], sumC, v), calculate(i + 1, n, sumB, sumC + v[i], v));         
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cout << calculate(0, n, 0, 0, v) << endl;
  }
  return 0;
}