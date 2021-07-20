#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
int postfix_count = 0;
unordered_map<string,int> ht;
const int N = 100001;
vector<pair<string,string>> vec_is_pairs, vec_not_pairs;

struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    unionfind(int size) {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }
    int find(int x){
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x) {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember; }
        return x;
    }
    void Union(int p, int q){
        p = find(p);
        q = find(q);
        if(q==p)
        {
            return;
        }
        if(rank[p] < rank[q]) parent[p] = q;
        else parent[q] = p;
        if(rank[p] == rank[q])
            rank[p]++;
    }
};
int getWordKey(string& w)
{
    int subw_size = min(3, (int)w.size());
    string subw;
    for(int i = 1; i <= subw_size ; i++)
    {
        subw = w.substr(w.size() - i);
        if (ht.find(subw) != ht.end())
        {
            return ht[subw];
        }
    }
    ht[subw] = postfix_count;
    postfix_count++;
    return ht[subw];
}


int main() {

    int n;
    unionfind uf(2*N);
    string wa, is_or_not, wb, res = "yes";
    int ka, kb;
    cin >> n;

    for (int i = 0; i<n; i++) {
        cin >> wa >> is_or_not >> wb;
        pair<string, string> p(wa, wb);
        if (is_or_not == "is") {
            vec_is_pairs.push_back(p);
        } else {
            vec_not_pairs.push_back(p);
        }
        getWordKey(wa);
        getWordKey(wb);
    }
    for (int i = 0; i<vec_is_pairs.size(); i++) {
        ka = getWordKey(vec_is_pairs[i].first);
        kb = getWordKey(vec_is_pairs[i].second);
        uf.Union(ka, kb);
    }
    for (int i = 0; i<vec_not_pairs.size(); i++) {
        ka = getWordKey(vec_not_pairs[i].first);
        kb = getWordKey(vec_not_pairs[i].second);
        if (uf.find(ka) == uf.find(kb))
        {
            res = "wait what?";
            break;
        }
    }
    cout << res << "\n";
    return 0;
}