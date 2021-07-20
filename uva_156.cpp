#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define MAX 100
#define MIN -1
int main() {
    string words[1000];
    map<string, int> dict;
    string s;
    int n = 0;
    while (cin >> s) {
        if (s == "#") break;
        words[n++] = s;
    }
    for (int i=0; i<n; i++)
    {
        string temp_s = words[i];
        for (int j=0; j<words[i].size(); j++)
            temp_s[j] = tolower(temp_s[j]);
        sort(temp_s.begin(), temp_s.end());

        if (dict.find(temp_s) == dict.end())
        {
            dict[temp_s] = 1;
        } else
        {
            dict[temp_s]++;
        }
    }
    sort(words, words+n);
    for (int i=0; i<n; i++)
    {
        string temp_s = words[i];
        for (int j=0; j<words[i].size(); j++)
            temp_s[j] = tolower(temp_s[j]);
        sort(temp_s.begin(), temp_s.end());
        if (dict[temp_s] == 1)
        {
            cout << words[i] << '\n';
        }

    }


};