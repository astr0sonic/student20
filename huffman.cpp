#include "huffman.h"
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    string data;
    int freq;
    Node *left;
    Node *right;

    Node(string ch, int fr) {
        data = ch;
        freq = fr;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

std::string encode(const std::string &text) {
    std::string encoded = "";
    string a;
    getline(cin, a);
    map<char, int> mp;
    map<char, string> ans;
    for (auto i: a) {
        mp[i]++;
    }
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto i: mp) {
        string s = "";
        s += i.first;
        Node *newNode = new Node(s, i.second);
        pq.push(newNode);
    }
    while (pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        for (auto i: left->data) {
            ans[i] = '0' + ans[i];
        }
        for (auto i: right->data) {
            ans[i] = '1' + ans[i];
        }
        Node *node = new Node(left->data + right->data, left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    for (auto i: a) {
        encoded += ans[i];
    }
    return encoded;
}

std::string decode(const std::string &encoded, std::map<char, std::string> &codes) {
    std::string decoded = "";
    map<string, char> mp;
    for (auto i: codes) {
        mp[i.second] = i.first;
    }
    string now = "";
    for (auto i: encoded) {
        now += i;
        if (mp.find(now) != mp.end()) {
            decoded += mp[now];
            now = "";
        }
    }
    return decoded;
}
