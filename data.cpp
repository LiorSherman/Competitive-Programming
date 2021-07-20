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

int getNumDistincPrimaryFactors(int n) {
    int result = 0;
    int sqrt_n = sqrt(n);
    //
    for(int i = 2; i <= sqrt_n; i++)
    {
        if (n % i == 0)
        {
            result++;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1) result++;
    return result;
}

int N;
vi vec, max_revenue;

int getSubSetSum(int bit_num_indicator)
{
    int sum = 0;
    int mask = 1;
    for (int i = 0; i < N; i++)
    {
        if(bit_num_indicator & mask << i) sum+=vec[i];
    }
    return sum;
}
int main()
{
    ifstream ifile;
    ifile.open("in.txt");
    if (ifile) freopen("in.txt", "r", stdin);

    cin >> N;
    vec.clear();
    vec.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int partition_vec_size = 1 << N;
    max_revenue.assign(partition_vec_size, 0);
    for(int sub_group = 0; sub_group < partition_vec_size; sub_group++)
    {
        max_revenue[sub_group] = getNumDistincPrimaryFactors(getSubSetSum(sub_group));
    }
    for(int sub_group = 0; sub_group < partition_vec_size; sub_group++)
    {
        for (int l_group = sub_group; l_group > 0; l_group = (l_group - 1) & sub_group)
        {
            int r_group = sub_group ^ l_group;
            max_revenue[sub_group] = max(max_revenue[sub_group], max_revenue[l_group] + max_revenue[r_group]);
        }
    }
    cout << max_revenue[partition_vec_size - 1] << "\n";
    return 0;
}