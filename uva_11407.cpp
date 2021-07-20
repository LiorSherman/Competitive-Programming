#include <iostream>
#include <stdio.h>
#include <cstdlib>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <unordered_map>
#include <bitset> // op[], size, test, any, none, all, set, reset, flip, to_string, to_ulong, to_ullong

#include <math.h>
#include <algorithm>
#include <cassert>
#include <fstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef set<int> si;
typedef vector <si> vsi;


int T;
int N = 10002;
vi dp;
int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if (ifile) freopen("in.txt", "r", stdin);
    dp.resize(N);
    for(int i = 0; i < N;i ++)
    {
        dp[i] = i;
    }
    for(int i = 0; i < sqrt(N); i++)
    {
        dp[i*i] = 1;
    }
    for(int i = 2; i < N; i++)
    {
        for(int j = 1; i-j*j >=0 ; j++)
        {
            dp[i] = min(dp[i], 1 + dp[i-j*j]);
        }
    }
    int n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
