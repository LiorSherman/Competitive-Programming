//
// Created by liorsher on 06/04/2021.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int main(){
    std::string s="";
    //std::getline(std::cin, s);

    //while (scanf("%s", &s)!=EOF)

    while (true){
        std::getline(std::cin, s);
        if (s == "DONE") break;
        int l = 0;
        int r = s.size()-1;
        for (int i=0; i<s.size() ; i++){
            s.at(i) = std::isalpha(s[i])? tolower(s.at(i)) : '_';
        }
        while(l<r) {
            if (s[l] == s[r]) {l++; r--;}
            else if (s[l]=='_') {l++;}
            else if (s[r]=='_') {r--;}
            else {
                break;
            }

        }
       if (l>=r)
        {
            printf("You won't be eaten!\n");
        } else{
            printf("Uh oh..\n");
        }
//        printf("You won't be eaten!\n");
//        std::vector<char> v;
//        int size = 0;

//        for (int i=0; i<s.size() ; i++){
//            if(std::isalpha(s[i])) {
//                v.push_back(tolower(s[i]));
//                size++;
//            }
//        }
//        int l = 0;
//        int r = size-l-1;
//        while(v[l] == v[r] && l<r) {
//            l++;
//            r--;
//
//        }
//        if (l>=r)
//        {
//            printf("You won't be eaten!\n");
//        } else{
//            printf("Uh oh..\n");
//        }
//    }
}}