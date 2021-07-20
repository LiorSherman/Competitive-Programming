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

#define INF 1e9

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


int H,B, pack;
vi h, b;

void getPacksAndCombinations(vi& vec)
{
    vec.assign(100010, INF);
    int len;
    cin >> len;
    int maxSum = 0;
    vec[0] = 0;
    while (len--)
    {
        cin >> pack;
        for (int i = maxSum ; i>=0; i--)
        {
            if (vec[i] + 1 < vec[i+pack])
                vec[i+pack] = vec[i] + 1;
        }
        maxSum +=pack;
    }
}
int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if (ifile) freopen("in.txt", "r", stdin);
    getPacksAndCombinations(h);
    getPacksAndCombinations(b);
    int min = INF;
    for (int i = 1; i < b.size(); i++)
    {
        if (h[i] + b[i] < min)
            min = h[i]+b[i];
    }

    if (min < INF)
        cout << min << endl;
    else
        cout << "impossible" << endl;
    return 0;
}