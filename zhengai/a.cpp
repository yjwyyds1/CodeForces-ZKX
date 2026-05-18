#include <bits/stdc++.h>

using namespace std;

int main()
{
    int op;
    cin >> op;
    if (op == 1) {
        int k, x;
        cin >> k >> x;
        int n = 1 << k;
        vector<int> a(n);
        int p = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                p ^= i;
            }
        }
        int tar = x - 1;
        int y = p ^ tar;
        cout << y + 1 << '\n';
    } else {
        int k; cin >> k;
        int n = 1 << k;
        vector<int> a(n);
        int p = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                p ^= i;
            }
        }
        cout << (p + 1) << '\n';
    }
}