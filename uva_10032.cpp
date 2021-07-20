#include <iostream>
#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int weight[101];
ll dp[45002];
int counter, total;

int main(){
    int T;
    cin >> T;

    bool flag = false;

    while(T--){
        cin >> counter;
        total=0;
        for(int i=0; i<counter; i++){
            cin >> weight[i];
            total+=weight[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1<<0;

        for(int i=0; i<counter; i++){
            for(int j=total; j>=0; j--){
                if(dp[j]) dp[j+weight[i]] |= (dp[j]<<1);
            }
        }
        ll bit = counter/2;
        bit = 1LL<<bit;
        int tmp;

        for(int i=total/2, j=total/2; i>=0 && j<=total; i--, j++){
            if((dp[i] & bit)){
                tmp = i;
                break;
            }
            if((dp[j] & bit)){
                tmp = j;
                break;
            }
        }
        if(flag == true) cout << endl;
        flag = true;
        cout << min(tmp, total-tmp) << " " << max(tmp, total-tmp) << endl;
    }

    return 0;
}