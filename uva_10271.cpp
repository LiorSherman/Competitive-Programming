#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
int dp[1002][5001];
int sizes[5001], badness[5001];
int MAX=1000000000;
int cmp(const void *i, const void *j) {
    return *(int *)j - *(int *)i;
}
int min(int a, int b){
    return a > b ? b :a;
}
int getbest(int guests,int chops){
    if(dp[guests][chops] != -1){
        return dp[guests][chops];
    }
    if( chops < 3*guests){
        return dp[guests][chops] = MAX;
    }else if( guests ==0 ){
        return dp[guests][chops] = 0;
    }else{
        return dp[guests][chops] = min(getbest(guests, chops-1),getbest( guests-1, chops-2)+badness[chops]);
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int guests;
        cin >> guests;
        guests+=8;
        int chops;
        cin >> chops;
        for(int i=1 ; i <= chops ; i++){
            int size;
            cin >> size;
            sizes[i] = size;
        }
        qsort(sizes+1, chops, sizeof(int), cmp);
        for(int i=2 ; i <chops+1 ; i++){
            badness[i]= (sizes[i]-sizes[i-1])*(sizes[i]-sizes[i-1]);
        }
        for(int i=0; i <guests+1 ; i++ ){
            for(int j=0; j <chops+1 ; j++){
                dp[i][j]=-1;
            }
        }
        cout << getbest(guests,chops) << endl;
    }
    return 0;
}