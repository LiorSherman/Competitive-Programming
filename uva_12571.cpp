#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int x[256];
int q[230];
int a, x_i;
using namespace std;
int main() {
    //freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    while(T>0) {
        for (int i = 0; i < 230; i++) {
            q[i] = 0;
        }
        for(int i =0 ; i < 256; i++)
        {
            x[i] = 0;
        }
        int N, Q;
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            cin >> x_i;
            x[x_i & 0xFF] = 1;

        }
        for (int i = 0; i < 256; i++) {
            if(x[i]){
                for (int j = 0; j < 230; j++) {
                    int cur = j & i;
                    q[j] = max(q[j], cur);
                }
            }

        }

        for (int i = 0; i < Q; i++) {
            cin >> a;
            cout << q[a] << "\n";

        }
        T--;

    }
    return 0;
}
