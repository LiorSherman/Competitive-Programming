#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int N = 1000005; // limit for array size
int n; // array size
int t[2 * N];
void build() { // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}
void modify(int p) { // set value at position p
    p+=n;
    t[p] = 1-t[p];
    for (; p > 1; p >>= 1){
        t[p>>1] = t[p] + t[p^1];
    }
}
int query(int l, int r) { // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    int k;
    cin >> n >> k;
    char fc;
    int i, l ,r;
    build();
    while (k--)
    {
        cin >> fc;
        switch (fc)
        {
            case 'F':
            {
                cin >> i;
                modify(i);
                break;
            }
            case 'C':
            {
                cin >> l >> r;
                cout << query(l,r + 1) << "\n";
                break;
            }

        }

    }
    return 0;
}