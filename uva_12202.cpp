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

bool inBoard(int x, int y, int X_T, int Y_T)
{
    return (0 <= x && x < X_T) && (0 <= y && y < Y_T);
}

//input : (x,y) coordinates in range [(0,0), (X_T-1, Y_T-1)]
//output: single index position in board in range [0, X_T-1*Y_T-1]
int coordinatesToSingle(int x, int y, int X_T, int Y_T)
{
    assert(inBoard(x,y,X_T,Y_T));

    return y*X_T + x;
}

//input : single index k position in board in range [0, X_T*Y_T]
//output: (x,y) coordinates in range [(0,0), (X_T, Y_T)]
ii singleToCoordinates(int k, int X_T, int Y_T)
{
    int y = k / (X_T);
    int x = k % (X_T);
    assert(inBoard(x,y,X_T,Y_T));
    return ii(x,y);
}

vi getNeighboursIndexes(int k, int X_T, int Y_T)
{
    vi neighbours;
    vii dirs = {ii(0,1), ii(0, -1), ii(1,0), ii(-1,0)};
    ii coords = singleToCoordinates(k, X_T, Y_T);
    for(ii dir : dirs)
    {
        int x = coords.first;
        int y = coords.second;
        int dx = dir.first;
        int dy = dir.second;
        if (inBoard(x+dx, y+dy, X_T, Y_T))
        {
            int neighbour_index = coordinatesToSingle(x+dx, y+dy, X_T, Y_T);
            neighbours.push_back(neighbour_index);
        }
    }
    return neighbours;
}



int W, H, G, E, X1 ,X2, Y1, Y2, T;
vvii g;
vi graves;
vii holes;
const int INF = 1e8;
void getGraves()
{
    cin >> G;
    int g = G;
    while (g--)
    {
        cin >> X1 >> Y1;
        int v_i = coordinatesToSingle(X1, Y1, W, H);
        graves[v_i] = 1;
    }
}

void getHoles()
{
    cin >> E;
    int h = E;
    while (h--)
    {
        cin >> X1 >> Y1 >> X2 >> Y2 >> T;
        int v_i = coordinatesToSingle(X1, Y1, W, H);
        int u_i = coordinatesToSingle(X2, Y2, W, H);
        holes[v_i] = ii(u_i,T);
    }
}


void createGraph()
{
    for(int v_i = 0; v_i < g.size()-1 ; v_i++ )
    {
        if (graves[v_i]) continue;
        else if (holes[v_i].first != -1)
        {
            g[v_i].push_back(ii(holes[v_i].first, holes[v_i].second));
            continue;
        }
        else
        {
            vi neighbours = getNeighboursIndexes(v_i, W, H);
            for (int u_i : neighbours)
            {
                if (graves[u_i]) continue;
                else g[v_i].push_back(ii(u_i, 1));
            }
        }
    }
}
bool BellmanFord(const vvii& g, int s, vi& d) {
    d.assign(g.size(), INF);
    d[s] = 0;
    bool changed = false;
    // V times
    for (int i = 0; i < g.size(); ++i) {
        changed = false;
        // go over all edges u->v with weight w
        for (int u = 0; u < g.size(); ++u) for (ii e : g[u]) {
                int v = e.first;
                int w = e.second;
                // relax the edge
                if (d[u] < INF && d[u]+w < d[v]) {
                    d[v] = d[u]+w;
                    changed = true;
                }
            }
    }
    // there is a negative cycle if there were changes in the last iteration
    return changed;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    while (true)
    {
        cin >> W >> H;
        if (!W && !H) break;
        int V = W * H;
        g.resize(V);
        graves.assign(V,0);
        holes.assign(V, ii(-1,-1));
        getGraves();
        getHoles();
        createGraph();
        vi distance;
        bool is_negative_cycle = BellmanFord(g, 0, distance);

        if (is_negative_cycle)
        {
            cout << "Never" << endl;
        }
        else if (distance[V-1] < INF)
        {
            cout << distance[V-1] << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        g.clear();
    }
    return 0;
}


