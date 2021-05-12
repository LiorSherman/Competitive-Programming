#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int K,M,N, a, u;

int main() {
    //freopen("in.txt","r",stdin);
    cin >> K;
    while(K--)
    {
        priority_queue<int> max_heap;
        queue<int> q;
        stack<int> q_in_temp;
        int in = 0;
        int idx = 0;
        cin >> M >> N;
        for (int i = 0; i < M; i++)
        {
            cin >> a;
            q.push(a);
        }
        for (int i = 0; i< N ; i++)
        {
            cin >> u;
            idx++;
            int left_to_push = u - max_heap.size();
            while (!q_in_temp.empty() && left_to_push)
            {
                max_heap.push(q_in_temp.top());
                q_in_temp.pop();
                left_to_push--;
            }
            while(left_to_push)
            {
                max_heap.push(q.front());
                q.pop();
                left_to_push--;
            }
            int left_to_remove = u - idx;
            while(left_to_remove)
            {
                q_in_temp.push(max_heap.top());
                max_heap.pop();
                left_to_remove--;
            }

            cout << max_heap.top() << "\n";
        }
        if(K)
            cout <<"\n";

    }

    return(0);
}