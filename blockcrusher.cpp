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

#define min(a,b) (a<b? a: b)
#define max(a,b) (a<b? b: a)
int T;

enum{DOWN, LEFT, RIGHT, COUNT_OPTIONS};
char mat[20][60];
int dp[20][60][COUNT_OPTIONS];
int h,w;
#define INF 1e6

void Dijkstra(const vvii& g, int s, vi& dist, vi& parent) {
    dist = vi(g.size(), INF);
    parent = vi(g.size(), -1);

    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ii front = q.top(); q.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // We may have found a shorter way to get to u after inserting it to q.
        // In that case, we want to ignore the previous insertion to q.
        for (ii next : g[u]) {
            int v = next.first, w = next.second;
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                q.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}


bool inBoard(int x, int y)
{
    return ((0 <= x && x < h) && (0 <= y && y < w));
}

ii singleToCoordinates(int k)
{
    int x = k / (w);
    int y = k % (w);
    //assert(inBoard(x,y));
    return ii(x,y);
}

int coordinatesToSingle(int x, int y)
{
    assert(inBoard(x,y));
    return x*w + y;
}

void getPath(vi& parent, int j, vi& path)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    getPath(parent, parent[j], path);
    ii p = singleToCoordinates(parent[j]);
    if(inBoard(p.first, p.second))
    mat[p.first][p.second] = ' ';
    path.push_back(j %w);
    //printf("%d ", j % w);
}

int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if (ifile) freopen("in.txt", "r", stdin);


    while (1)
    {
        cin >> h >> w;
        if (!h && !w) break;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> mat[i][j];
            }
            mat[i][w] = '\0';
        }
        vvii g(h*w + 2);
        for (int u = 0; u < g.size() - 2; u++)
        {
           for(int dx = -1 ; dx <= 1; dx++)
               for(int dy = -1; dy<=1; dy++)
               {
                   if ((dx == 0) && (dy ==0)) continue;
                   ii p = singleToCoordinates(u);
                   int x = p.first;
                   int y = p.second;
                   int r_ = x + dx;
                   int c_ = y + dy;
                   if (inBoard(r_, c_))
                   {
                       int v = coordinatesToSingle(r_, c_);
                       int weight = mat[r_][c_] - '0';
                       g[u].push_back(ii(v,weight));
                   }
               }

        }
        int s = h*w;
        int t = h*w +1;

        for(int j = 0; j < w; j++)
        {
            g[s].push_back(ii(j,mat[0][j] - '0'));
            int u = coordinatesToSingle(h-1, j);
            g[u].push_back(ii(t,0));
        }

        vi parent;
        vi dist;
        Dijkstra(g, s, dist, parent);
        vi path;

        getPath(parent, t, path);
        for(int i =0; i<h; i++)
        {
            for (int j = 0; j<w; j++)
            {
                cout << mat[i][j];
//                int break_j = path[i];
//                if (j != break_j) cout << mat[i][j];
//                else cout <<' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}