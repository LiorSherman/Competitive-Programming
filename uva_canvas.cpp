#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int main() {
    int T, N;

    //freopen("in.txt","r",stdin);
    cin >> T;
    while(T--)
    {
        cin >> N;
        int sizes[N];
        ll cur = 0, ink = 0;
        priority_queue<ll, vector<ll>, greater<ll> > min_heap;
        for (int i = 0; i<N; i++)
            cin >> sizes[i];
        for (int i = 0; i<N; i++)
            min_heap.push(sizes[i]);


        while(min_heap.size() > 1)
        {
            cur = 0;
            int t = 2;
            while(t--)
            {
                cur += min_heap.top();
                min_heap.pop();
            }
            min_heap.push(cur);
            ink += cur;
        }

        cout << ink << "\n";


    }

    return 0;
}