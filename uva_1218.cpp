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

#include <math.h>
#include <algorithm>
#define INF 1e6
#define MIN(a,b) (a < b? a : b)
#define MIN3(a,b,c) (MIN(MIN(a,b),c))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

enum option {IS_SERVER, IS_HOST_FATHER_IS_SERVER_ALL_SON_HOSTS, IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER};
int n, last, u =0, v;
vi v_len;
vvi g;
vi g_servers;
vvi g_directed;

int count_servers[10005][3];
void _dfs_recursive(const vvi& g, int s,  vvi& g_directed, vector<bool>& visible)
{
    visible[s] = true;
    for(int u : g[s])
        if(!visible[u])
        {
            g_directed[s].push_back(u);
            _dfs_recursive(g, u,g_directed,visible);
        }
}

void dfs(const vvi& g, int s, vvi& g_directed)
{
    vector<bool> visible;
    visible.assign(g.size(),false);
    g_directed.assign(g.size(), vi());
    _dfs_recursive(g, s, g_directed, visible);

}

void calcMinServers(int cur, int father)
{
    count_servers[cur][IS_SERVER] = 1;
    count_servers[cur][IS_HOST_FATHER_IS_SERVER_ALL_SON_HOSTS] = 0 ;
    count_servers[cur][IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER] = INF;
    for (int son: g[cur])
    {
        if (son != father)
        {
            calcMinServers(son, cur);
            count_servers[cur][IS_SERVER] += min(count_servers[son][IS_HOST_FATHER_IS_SERVER_ALL_SON_HOSTS],
                                                 count_servers[son][IS_SERVER]);

            count_servers[cur][IS_HOST_FATHER_IS_SERVER_ALL_SON_HOSTS] += count_servers[son][IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER];
        }


    }
    for (int son: g[cur])
    {
        if (son != father)
        {
            count_servers[cur][IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER] = min(
                    count_servers[cur][IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER],
                    (count_servers[son][IS_SERVER] + count_servers[cur][IS_HOST_FATHER_IS_SERVER_ALL_SON_HOSTS] -
                     count_servers[son][IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER]));
        }
    }

}
int main()
{
    //freopen("in.txt", "r", stdin);
    while (true)
    {
        //if (u == -1) break;
        cin >> n;
        if (n == -1) break;
        g.assign(n, vi());
        for(int i = 0; i < n-1; i++)
        {
            cin >> u;
            //if (u <= 0) break;
            cin >> v;
            u -= 1;
            v -= 1;
            g[v].push_back(u);
            g[u].push_back(v);
        }

        calcMinServers(0, -1);
        int result = MIN3(INF,count_servers[0][IS_SERVER], count_servers[0][IS_HOST_FATHER_IS_HOST_ONE_SON_SERVER]);
        cout << result << endl;
        cin >> n;
        if (n==-1) break;
    }
    return 0;
}


