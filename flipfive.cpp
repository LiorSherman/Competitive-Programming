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
#include <bitset>

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


int P;
const int V = 512;



int inputBoardToIndex()
{
    char c;
    int index = 0;
    for(int i = 0; i<9; i++)
    {
        cin >> c;
        if(c == '*')
            index |= (1 << i);
    }
    return index;
}

bool inBoard(int x, int y, int X_T, int Y_T)
{
    return ((0 <= x && x < X_T) && (0 <= y && y < Y_T));
}

//input : (x,y) coordinates in range [(0,0), (X_T-1, Y_T-1)]
//output: single index position in board in range [0, X_T-1*Y_T-1]
int coordinatesToSingle(int x, int y, int X_T, int Y_T)
{
    assert(inBoard(x,y,X_T,Y_T));
    return x*Y_T + y;
}

//input : single index k position in board in range [0, X_T*Y_T]
//output: (x,y) coordinates in range [(0,0), (X_T, Y_T)]
void singleToCoordinates(int k, int X_T, int Y_T, ii& coords)
{
    int x = k / (X_T);
    int y = k % (X_T);
    assert(inBoard(x,y,X_T,Y_T));
    //return ii(x,y);
    coords.first = x;
    coords.second = y;
}

void getNeighboursIndexes(int k, int X_T, int Y_T, vi& neighbours)
{
    //vi neighbours;
    vii dirs = {ii(0,1), ii(0, -1), ii(1,0), ii(-1,0)};
    ii coords;
    //ii coords = singleToCoordinates(k, X_T, Y_T);
    singleToCoordinates(k, X_T, Y_T, coords);
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
    //return neighbours;
}


vi getBoardNextBoards(int v)
{
    vi next_boards(9);
    bitset<9> v_bitset(v);
    for(int i = 0; i < next_boards.size(); i++)
    {
        bitset<9> next = v_bitset;
        next.flip(i);
        vi neighbour_bits_to_flip;
        getNeighboursIndexes(i, 3, 3, neighbour_bits_to_flip);
        for (int bit : neighbour_bits_to_flip )
        {
            next.flip(bit);
        }
        next_boards[i] = (int) next.to_ulong();
    }
    return next_boards;
}
vvi createBoardsGraph()
{
    vvi g(V);
    for (int v=0; v<g.size(); v++)
    {
        g[v] = getBoardNextBoards(v);
    }
    return g;
}

void bfs(const vvi& g, int s, vi& dist) {
    queue<int> q; q.push(s);
    vector<bool> visible (g.size(),false);
    visible[s]=true;
    dist = vi(g.size(), -1);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        //printf(“%d\n”, u);
        for (int v : g[u]) if (!visible[v]) {
                visible[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }}}


int main()
{
    vvi g = createBoardsGraph();
    vi num_of_moves(V);
    bfs(g, 0, num_of_moves);

    //freopen("in.txt", "r", stdin);
    cin >> P;
    int b;
    while (P--)
    {
        b = inputBoardToIndex();
        cout << (int)num_of_moves[b] << endl;
    }
    return 0;
}

