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


typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int T;
ll c[100003];
ll MOD = 1e9 + 7;
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


ll f(ll n)
{
    ll a, b , c, d;
    a = 2 * n + 2;
    b = 2*n + 1;
    c = n + 2;
    d = n + 1;
    return (a * b) / (c * d);
}
int main()
{

    ll n;
    //freopen("in.txt", "r", stdin);
    cin >> n;
    ll num = n;
    ll num2 = 2 * num;
    int i = num2;

    while(i-- > 1)
    {
        num2 = mulmodn(num2, i, MOD);
    }

    i = n;
    while(i-- > 1)
    {
        num = mulmodn(num, i, MOD );
    }

    num = mulmodn(powmodn(num, 2, MOD), n + 1, MOD);
    ll result = mulmodn(num2, powmodn(num, MOD-2, MOD), MOD);
    cout << result << endl;

    return 0;
}

