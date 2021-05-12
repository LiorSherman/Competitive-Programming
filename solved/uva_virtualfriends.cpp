#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
using namespace std;
typedef long long ll;
int names_count = 0;
unordered_map<string,int> ht;
struct unionfind
{
    vector<int> rank;
    vector<int> team_size;
    vector<int> parent;
    unionfind(int size)
    {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        team_size = vector<int>(size, 1);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }

    int find(int x){
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x)//for log*, not needed most of the time
        {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember;
        }
        return x;
    }
    void Union(int p, int q){
        p = find(p);
        q = find(q);
        if(q==p)
        {
            cout << team_size[p] << endl;
            return;
        }
        cout << team_size[p] + team_size[q] << endl;
        if(rank[p] < rank[q]){
            parent[p] = q;
            team_size[q] += team_size[p];
        }
        else{
            parent[q] = p;
            team_size[p] += team_size[q];
        }
        if(rank[p] == rank[q]) rank[p]++;
    }
};

int getWordKey(string& w)
{
    if (ht.find(w) != ht.end())
    {
        return ht[w];
    }

    ht[w] = names_count;
    names_count++;
    return ht[w];
}

int main() {
    //freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        int F;
        cin >> F;
        unionfind uf(2 * F);
        while (F--) {
            string fa, fb;
            int ka, kb;
            cin >> fa >> fb;
            ka = getWordKey(fa);
            kb = getWordKey(fb);
            uf.Union(ka, kb);
        }
        ht.clear();
        names_count = 0;
    }

    return 0;
}
