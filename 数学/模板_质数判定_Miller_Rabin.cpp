#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using int128 = __int128_t;
bool miller_rabin(ll n) {
    if (n <= 1) return false;
    vector<int128> bases = {2, 325, 9375, 28178, 450755, 9780504, 1795265022};
    vector<ll> vals = {2, 3, 5, 13, 17, 19, 73, 193, 5303, 407521, 299210837};
    set<ll> primes(vals.begin(), vals.end());
	if (primes.find(n) != primes.end()) return true;
    for (int i = 0; i < 7; i++) {
        ll d = n - 1; int s = 0;
        while (!(d & 1LL)) {
            d /= 2;
            s++;
        }
        int128 res = 1, tmp = bases[i];
        while (d > 0) {
            if (d & 1) res = res * tmp % (int128)n;
            tmp = tmp * tmp % (int128)n;
            d /= 2;
        }
        int128 x = res, y;
        for (int j = 0; j < s; j++) {
            y = x * x % (int128)n;
            if (y == 1 && x != 1 && x != n - 1) {
                return false;
            }
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        ll n; cin >> n;
        cout << (miller_rabin(n) ? "YES" : "NO") << "\n";
    }   
    return 0;
}