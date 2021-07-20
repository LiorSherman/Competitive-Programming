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
#define INF 1E9


int T;
int V, E;
int u, v, w, s, t;
vvii g;
vi dist , num_shortest;

//modified version of dijakstra
void FindAllShortestPaths(const vvii& g, int s) {
    dist = vi(g.size(), INF);
    dist[s] = 0;
    num_shortest = vi(g.size(), 0);
    num_shortest[s] = 1;
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
                num_shortest[v] = num_shortest[u]; //modified version only
                q.push({dist[v], v});
            }
            else if (dist[u]+w == dist[v]) //modified version only
            {
                num_shortest[v] += num_shortest[u]; //modified version only
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> V >> E;
    g = vvii(V);
    num_shortest = vi(V, 0);
    while (E--)
    {
        cin >> u >> v >> w;
        g[u].push_back(ii(v,w));
    }
    cin >> s >> t;
    FindAllShortestPaths(g, s);
    cout << num_shortest[t] << endl;
    return 0;
}
