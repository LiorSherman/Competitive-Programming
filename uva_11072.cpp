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
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point_i { int x, y;     // whenever possible, work with point_i
    point_i() { x = y = 0; }                      // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {} };         // user-defined

struct point { double x, y;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)                 // useful for sorting
            return x < other.x;          // first criteria , by x-coordinate
        return y < other.y; }          // second criteria, by y-coordinate
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
typedef point pt;
/*****functions on points*****/
double dist(point p1, point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

struct vec { double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s); }               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
    return point(p.x + v.x , p.y + v.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

//// another variant
//int area2(point p, point q, point r) { // returns 'twice' the area of this triangle A-B-c
//  return p.x * q.y - p.y * q.x +
//         q.x * r.y - q.y * r.x +
//         r.x * p.y - r.y * p.x;
//}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

bool inPolygon(point p, const vector<point> &P) {
    if ((int) P.size() == 0)
        return false;
    double sum = 0; // assume first vertex = last vertex
    for (int i = 0; i < (int) P.size() - 1; i++) {
        if (ccw(p, P[i], P[i + 1]))
            sum += angle(P[i], p, P[i + 1]);   // left turn/ccw
        else
            sum -= angle(P[i], p, P[i + 1]);
    } // right turn/cw
    return fabs(fabs(sum) - 2 * PI) < EPS;
}
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));                  // translate a to c
    return dist(p, c); }

float sign (point p1, point p2, point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}
bool inLine(point p, point a, point b)
{
    double m = (b.y - a.y) / (b.x - a.x);
    double n = (b.y - m * b.x);
    return (p.y == m*a.x + n);
}

double area2(point p, point q, point r) { // returns 'twice' the area of this triangle A-B-c
  return 0.5 * abs(p.x * q.y - p.y * q.x +
         q.x * r.y - q.y * r.x +
         r.x * p.y - r.y * p.x);
}
bool inTriangle(point p, const vector<point> &T)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(p, T[0], T[1]);
    d2 = sign(p, T[1], T[2]);
    d3 = sign(p, T[2], T[0]);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}


vector<point> convex_hull(vector<point> Points) {

    //-------------- incremental alg. ---------
    // upper hull
    sort(Points.begin(), Points.end());
    stack<point> stk_up;
    stk_up.push(Points[0]);
    stk_up.push(Points[1]);
    for (int i=2; i<Points.size(); i++) {
        while ((stk_up.size() >= 2)) {
            point p2, p3;
            p2 = stk_up.top();
            stk_up.pop();
            p3 = stk_up.top();
            if (ccw(Points[i], p2, p3)){
                stk_up.push(p2);
                break;
            }
        }
        stk_up.push(Points[i]);
    }
    // lower hull
    for (int i=0; i<Points.size(); i++) {
        Points[i].x = -Points[i].x;
        Points[i].y = -Points[i].y;
    }
    sort(Points.begin(), Points.end());
    stack<point> stk_low;
    stk_low.push(Points[0]);
    stk_low.push(Points[1]);
    for (int i=2; i<Points.size(); i++) {
        while ((stk_low.size() >= 2)) {
            point p2, p3;
            p2 = stk_low.top();
            stk_low.pop();
            p3 = stk_low.top();
            if (ccw(Points[i], p2, p3)){
                stk_low.push(p2);
                break;
            }
        }
        stk_low.push(Points[i]);
    }

    // print convex hull - cw order from leftmost point
    vector<point> CH;
    stk_low.pop();
    point p;
    while (!stk_low.empty()) {
        p = stk_low.top();
        p.x = -p.x;
        p.y = -p.y;
        CH.push_back(p);
        stk_low.pop();
    }
    stk_up.pop();
    while (!stk_up.empty()) {
        CH.push_back(stk_up.top());
        stk_up.pop();
    }
    reverse(CH.begin(), CH.end());  // ccw -> cw
    return CH;
}
#define INF 1E8
point P0(INF,INF);
int P0_i;

bool inCH(pt p, const vector<point> &P)
{
    if ((int) P.size() < 3)
        return false;
    point p0 = P[0];
    int l = 1;
    int r = P.size()-1;

    while ((r - l) > 1)
    {
        int m = (l + r) / 2;
        if (ccw(p0, p, P[m])) l = m;
        else r = m;
    }
    vector<point> T;
    T.push_back(P[l]);
    T.push_back(P[l+1]);
    T.push_back(p0);
    return (inTriangle(p, T) );
}

int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if (ifile) freopen("in.txt", "r", stdin);
    vector<point> P;
    int N;
    //cin >> N;
    int x, y;
    while(cin >> N)
    {
        P.clear();
        while (N--)
        {
            cin >> x >> y;
            P.push_back(point(x, y));
        }
        vector<point> ch = convex_hull(P);
        cin >> N;
        while (N--)
        {
            cin >> x >> y;
            if (inCH(point(x, y), ch))
                cout << "inside" << endl;
            else
                cout << "outside" << endl;
        }
    }

    return 0;
}
