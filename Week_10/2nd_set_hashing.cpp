#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

int unique_substrs(string str){
    unordered_set<string> s;
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
        s.insert(str.substr(i , j - i + 1));
    }
    }
    return s.size();
}
unordered_set<string> unique_substrs2(string str){
    unordered_set<string> s;
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
        s.insert(str.substr(i , j - i + 1));
    }
    }
    return s;
}
int common_substrs(string str1, string str2){
    unordered_set<string> s1 = unique_substrs2(str1);
    unordered_set<string> s2 = unique_substrs2(str2);
    int total = 0;
    for(auto word : s1){
        if(s2.count(word))
        total++;
    }
    return total;
}
int count_anagrams(string str){
    unordered_set<string> s;
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
            string temp = str.substr(i , j - i + 1);
            sort(temp.begin(),temp.end());
        s.insert(temp);
    }
    }
    return s.size();
}

int main()
{
    cout << count_anagrams("aabade");


    return 0;
}