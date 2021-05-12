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


int T;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    string D = "CW";
    double A = 0;
    vii p;
    while (true)
    {
        cin >> n;
        if(!n) break;
        int x, y;
        while(n--)
        {
            cin >> x >> y;
            p.push_back(ii(x,y));
        }
        double sum = 0;
        A = 0.0;

        for (int i = 0; i<p.size(); i++)
        {
            int x1 = p[i%p.size()].first;
            int y1 = p[i%p.size()].second;
            int x2 = p[(i+1)%p.size()].first;
            int y2 = p[(i+1)%p.size()].second;

            //sum += (x2 - x1) * (y2 + y1);
            A += (x1*y2 - x2*y1);
        }
        A *= 0.5;


        if (A < 0) D = "CW";
        else D = "CCW";
        cout.precision(1);
        cout << D << " ";
        printf("%.1f\n", abs(A) );
        //cout << D << " " << A << endl;
        p.clear();



    }
    return 0;
}
