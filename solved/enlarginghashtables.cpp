#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int T;
ll mulmodn(ll a, ll b, ll n){
    ll res = 0;
    while(b){
        if(b & 1) res= (res+a) %n;
        a = (a*2)%n;
        b >>= 1;
    }
    return res;
}

ll powmodn(ll a, ll q, ll n){
    ll res = 1;
    while(q){
        if (q & 1) res = mulmodn(res,a,n);
        a = mulmodn(a,a,n);
        q >>= 1;
    }
    return res;
}
bool isPrime(ll n){
    if(n<2)
        return false;
    ll sqrtn = sqrt(n);
    for (ll i = 2; i <= sqrtn; ++i) {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool MR(ll n, int k=5){
    if(n==1 || n==4)
        return false;
    if(n==2 || n==3)
        return true;
    ll m = n - 1;
    int r = 0;
    while (m%2 == 0){
        m >>= 1;
        r+=1;
    }
    /* !!! Deterministic version for n<2^64 !!! */
    int dtrm_set[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for(ll a: dtrm_set){
        if(a >= n) break;
    /* !!! End of deterministic version !!! */

    /* !!! Probablistic version !!! */
//    while(k--){
//        ll a = rand() % (n-4) + 2;
        /* !!! end of probablisitic version !!! */
        a = powmodn(a,m,n);
        if(a==1) continue;
        int i = r;
        while(i-- && a != n-1){
            a = mulmodn(a,a,n);
            if(a == 1) return false;
        }
        if(i == -1) return false;
    }
    return true;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ll n;

    while(true)
    {
        cin >> n;
        if (!n) break;
        string s = "\n";
        if (!MR(n))
            s = " (" + to_string(n) + " is not prime)\n";
        ll n_2 = 2 * n;
        while(!MR(n_2))
        {
            n_2++;
        }
        cout << n_2 << s;
    }
    return 0;
}
