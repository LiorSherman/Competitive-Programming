
#include <iostream>

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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned int uint;
// ll power(ll a, ll b)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     vector<ll> powers;
//     powers.push_back(1);
//     powers.push_back(a);
//     ll count = 1;
//     for (int i = 2; count < b; i++)
//     {
//         powers.push_back(powers[i - 1] * powers[i - 1]);
//         count *= 2;
//     }
//     ll retval = 1;
//     for (int i = (powers.size() - 1); b != 0; i--)
//     {
//         if (b >=count)
//         {
//             b -= count;
//             retval *= powers[i];
//             // cout<<b<< "  "<< count<<endl;
//         }
//         count /= 2;
//     }
//     return retval;

//     // return a*power(a,b-1);
// }
int main()
{
    int num_cases;
    cin >> num_cases;
    vector<ll> fiboniachi;
    fiboniachi.push_back(1);
    fiboniachi.push_back(2);
    for (int i = 2; i < 50; i++)
        fiboniachi.push_back(fiboniachi[i - 2] + fiboniachi[i - 1]);
    while (num_cases--)
    {
        ll n;
        cin >> n;

        int i = 49;
        bool start_print = false;
        for (; i >= 0; i--)
        {
            if (n >= fiboniachi[i])
            {
                start_print = true;
                cout << 1;
                n -= fiboniachi[i];
            }
            else
            {
                if (start_print)
                    cout << 0;
            }
        }
    cout << endl;
    }

    return 0;
}
