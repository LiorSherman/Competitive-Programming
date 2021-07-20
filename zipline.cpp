#include <iostream>
#include <cstdlib>
#include <stdio.h>

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
#include <math.h>
#include <cassert>
#include <fstream>
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




int n;
double w, g, h, r;
ll MOD = 1000000;

double calcMaxL()
{
    if(g==h)
    {
        double x = 0.5 * w;
        double y = g - r;
        return (2*sqrt(x*x + y*y));
    }
    else
    {
        double y1 = min(g,h) -r;
        double y2 = max(g,h) -r;
        double x1 = (y1 * w) /(y1 + y2);
        double x2 = w - x1;
        return sqrt(x1*x1 + y1*y1) + sqrt(x2*x2 + y2*y2);
    }
}

double calcMinL()
{
    if (g==h)
        return w;

    double x = w;
    double y = fabs(g-h);
    return sqrt(x*x + y*y);
}

int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if(ifile) freopen("in.txt", "r", stdin);
    cin >> n;
    while (n--)
    {
        cin >> w >> g >> h >> r;
        printf("%.8f %.8f\n", calcMinL(), calcMaxL());
    }
    return 0;
}
