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
#include <sstream>
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

bool inBoard(int x, int y, int X_T, int Y_T)
{
    return (0 <= x && x < X_T) && (0 <= y && y < Y_T);
}

void bfs(const vvi& g, int s) {
    queue<int> q; q.push(s);
    vector<bool> visible (g.size(),false);
    visible[s]=true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        //printf(“%d\n”, u);
        for (int v : g[u]) if (!visible[v]) {
                visible[v] = true;
                q.push(v);
            }}}
void getNeighbours(vector<string>& origin, int i, int j, vii neighbours)
{
    neighbours.clear();
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for (int k = 0; k < 4; k++)
    {
        int dx = dirs[k][0];
        int dy = dirs[k][1];
        int i_ = i+dx;
        int j_ = j+dy;
        if (inBoard(i_, j_, origin.size(), origin[0].size()))
        {
            if(origin[i][j] == origin[i_][j_])
                neighbours.push_back(ii(i_, j_));
        }
    }
}
string hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

string hex_string_to_bin(string s)
{
    string bin_s;
    for(char c: s)
        bin_s += hex_char_to_bin(c);
    return bin_s;
}

const string zero_s = "0000000000000000000000000000000000000000000000000000";

int H, W;
//char in[52];
string in;
vector<string> image;
char to_code[] = {'W', 'A', 'K', 'J', 'S', 'D' };
#define ii2i(i, j) (i*image[0].size() + j)

void fillHole(int i, int j)
{
    image[i][j] = '$';
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for (int k = 0; k < 4; k++)
    {
        int dx = dirs[k][0];
        int dy = dirs[k][1];
        int i_ = i+dx;
        int j_ = j+dy;
        if (inBoard(i_, j_, image.size(), image[0].size()) && image[i_][j_] == '0')
        {
            fillHole(i_, j_);
        }
    }
}

void fillFig(int i, int j)
{
    image[i][j] = '$';
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for (int k = 0; k < 4; k++)
    {
        int dx = dirs[k][0];
        int dy = dirs[k][1];
        int i_ = i+dx;
        int j_ = j+dy;
        if (inBoard(i_, j_, image.size(), image[0].size()) && image[i_][j_] == '1')
        {
            fillFig(i_, j_);
        }
    }
}

void analyzeFig(int i, int j, int* number_of_holes)
{
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    image[i][j] = '$';
    for (int k = 0; k < 4; k++)
    {
        int dx = dirs[k][0];
        int dy = dirs[k][1];
        int i_ = i+dx;
        int j_ = j+dy;
        if (inBoard(i_, j_, image.size(), image[0].size()))
        {
            if(image[i_][j_] == '1')
            {
                analyzeFig(i_, j_, number_of_holes);
            }
            else if(image[i_][j_] == '0')
            {
//                cout << "hole found" <<endl;
//                image[i][j] = "%";
//                printImage();
//                image[i][j] = '0'
                *number_of_holes +=1;
                fillHole(i_,j_);
            }
        }
    }
}

std::string& SSS (const char* s)
{
    return *(new std::string(s));
}
void printImage()
{
    for (int i = 0; i< image.size(); i++)
    {
        cout << image[i] << endl;
    }
    cout <<endl;
    cout <<endl;
}
int main()
{

    int case_n = 0;

//    while (true)
//    {
//        cin >> H >> W;
//        if (!H && !W) break;
    while(cin >> H >> W)
    {
        if(!H && !W) break;
        case_n++;
        string to_print;
        image.clear();
        image.resize(H+2);
        for (int i = 1; i <= H; i++)
        {
            in = "";
            char c;
//            for(int j = 0; j < W; j++)
//            {
//                cin >>c;
//                in+=c;
//            }
            cin >> in;
            if(in.size() !=W)
            {
                break;
            }
//            cin.getline(in+1, 50);
            //if (i == 0) continue;
//            in[0] = '0';
//            in[W+1] = '0';
//            in[W+2] = '\0';
            in = "0" + in + "0";
            image[i] = hex_string_to_bin(in);
        }

        image[0] = image[H+1] = hex_string_to_bin(zero_s.substr(0,W+2));
//        printImage();
        fillHole(0,0);
//        printImage();
        //get rid of the background
        int count_holes = 0;
        for (int i = 0; i< image.size(); i++)
        {
            for(int j = 0; j<image[0].size(); j++)
            {
                if (image[i][j] == '1') //fig found
                {
//                    cout << "fig found" <<endl;
//                    image[i][j] = '%';
//                    printImage();
                    image[i][j] = '1';
                    analyzeFig(i,j, &count_holes);
//                    printImage();
                    //fillFig(i,j);
//                    printImage();
                    to_print += to_code[count_holes];
                    count_holes = 0;
                }
            }
        }

        sort(to_print.begin(), to_print.end());
        cout << "Case " << case_n << ": " << to_print << endl;
    }
    return 0;
}
