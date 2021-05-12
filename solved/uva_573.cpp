#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main() {
    double h , u , d, f;
    while (cin >> h >> u >> d >> f)
    {
        if (h == 0)
            break;
        f = f * u / 100;
        double cur_h = 0;
        int day_count = 1;
        while (true)
        {
            //morning
            cur_h += u;
            if (cur_h > h)
            {
                cout << "success on day " << day_count << "\n";
                break;
            }
            //evening
            cur_h -= d;
            if (cur_h < 0)
            {
                cout << "failure on day " << day_count << "\n";
                break;
            }
            //next day
            u = max(0.0, u - f);
            day_count ++;
        }
    }

    return 0;
}
//
// Created by liorsher on 13/04/2021.
//

