#include "lzw.h"
#include "bits/stdc++.h"
using namespace std;

std::vector<int> compress(const std::string& text) {
    std::vector<int> compressed;
    string b = "", c;
    map<string, pair<int, int>> table;
    for (int i = 0; i < 256; i++) {
        c = char(i);
        table[c] = {i, -1};
    }
    for (auto i: text) {
        c = b + i;
        if (table[c].second == 0) {
            table[c] = {table.size() - 1, table[b].first};
            compressed.push_back(table[b].first);
            b = i;
        } else {
            if (table[c].second == -1) {
                table[c].second--;
            }
            b = c;
            continue;
        }
    }
    compressed.push_back(table[b].first);
    return compressed;
}

std::string decompress(const std::vector<int>& compressed) {
    std::string decompressed = "";
    string s = "", c;
    map<int,string> table;
    for (int i = 0; i < 256; i++) {
        c = char(i);
        table[i] = c;
    }
    int old=compressed[0],now,siz=256;
    s=table[compressed[0]];
    decompressed+=s;
    c=s[0];
    for (int i=1;i<compressed.size();i++) {
        now=compressed[i];
        if(table[now]==""){
            s=table[old];
            s+=s[0];
        }
        else{
            s=table[now];
        }
        decompressed+=s;
        table[siz++]=c+s[0];
        c=s;
        old=now;
    }
    return decompressed;
}
