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
typedef vector <string> vs;


int T,N;
string KMP_str; // The string to search in
string KMP_pat; // The pattern to search
vi lps;

// KMP Init
void KMP_init(){
    int m = KMP_pat.length();
    lps.resize(m+1,0);
    lps[0]=-1;
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && KMP_pat[i] != KMP_pat[j]) j = lps[j];
        i++; j++;
        lps[i] = j;
    }
}

// Search a pattern in a string
// Assuming lps is allready initialized with KMP_init
void KMP_search() {
    int n = KMP_str.length();
    int m = KMP_pat.length();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && KMP_str[i] != KMP_pat[j]) j = lps[j];
        i++; j++;
        if (j == m) { // Pattern found
            cout << "The pattern is found at index " << i-j << endl;
            j = lps[j];
        }
    }
}

int KMP_search_count() {
    int count = 0;
    int n = KMP_str.length();
    int m = KMP_pat.length();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && KMP_str[i] != KMP_pat[j]) j = lps[j];
        i++; j++;
        if (j == m) { // Pattern found
            //cout << "The pattern is found at index " << i-j << count <<endl ;
            j = lps[j];
            count++;
        }
    }
    return count;
}

int main()
{
//    ifstream ifile;
//    ifile.open("in.txt");
//    if (ifile) freopen("in.txt", "r", stdin);
    vs KMP_pats(N);
    while (1)
    {
        int max = 0;
        vi max_is;
        cin >> N;
        if (N == 0) break;
        vs KMP_pats(N);
        for(int i = 0; i < N; i++)
        {
            string pat;
            cin >> pat;
            KMP_pats[i] = pat;
        }
        cin >> KMP_str;

        for(int i = 0; i < N; i++)
        {
            KMP_pat = KMP_pats[i];
            KMP_init();
            if (max < KMP_search_count())
            {
                max =  KMP_search_count();
                max_is.clear();
                max_is.push_back(i);
            }
            else if (max == KMP_search_count())
            {
                max_is.push_back(i);
            }
        }
        cout << max << endl;
        for(int i: max_is)
        {
            cout << KMP_pats[i] << endl;
        }




    }
    return 0;
}
