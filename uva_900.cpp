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


int N = 51;
int fib[51];
int main()
{
    //freopen("in.txt", "r", stdin);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int x;
    while(true)
    {
        cin >> x;
        if (!x) break;
        cout << fib[x] << endl;
    }
    return 0;
}
