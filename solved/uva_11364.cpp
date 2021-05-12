#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
#define MAX 100
#define MIN -1
int main() {
    int d[100][20];
    int num_stores[100];
    int t;

    cin >> t;
    for (int i = 0; i<t; ++i)
    {
        cin >> num_stores[i];

        for (int j = 0; j<num_stores[i]; ++j)
        {
            cin >> d[i][j];;
        }

    }
    for (int i = 0; i<t; ++i)
    {
        int min = MAX, max = MIN;
        for (int j = 0; j<num_stores[i]; ++j)
        {
              min = d[i][j] < min ? d[i][j] : min;
              max = d[i][j] > max ? d[i][j] : max;
        }
        cout << 2*(max-min);
        cout << '\n';
    }

    return 0;
}