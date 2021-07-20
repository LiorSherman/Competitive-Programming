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


int T,up_N, down_N;
unordered_map<string, int> hash;
int count = 0;
vii up, down;
string name, ost, v;
vvi dp, bridges;

int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if (ifile) freopen("in.txt", "r", stdin);

    cin >> T;
    while (T--)
    {
        cin >> N;
        while(N--)
        {
            cin >> name >> ost >> v;
            if(hash.find(ost) == hash.end())
            {
                hash[ost] = count;
                count++;
            }
            up.push_back(ii(hash[ost], v));
        }
        cin >> N;
        while(N--)
        {
            cin >> name >> ost >> v;
            if(hash.find(ost) == hash.end())
            {
                hash[ost] = count;
                count++;
            }
            down.push_back(ii(hash[ost], v));
        }
        dp.assign(up.size() + 1, vi(down.size() + 1, 0));
        bridges.assign(up.size() + 1, vi(down.size() + 1, 0));

        for(int  i = 0; i< dp.size(); i++)
        {
            int possible_br = 0;

            for(int j = 0; i<dp[0].size(); i++)
            {
                int count = bridges[i][j];
                if(up[i].first == down[j].first)
                {
                    possible_br = up[i].second + down[j].second;
                    count++;
                }

                if (dp[])
            }
        }
    }
    return 0;
}
