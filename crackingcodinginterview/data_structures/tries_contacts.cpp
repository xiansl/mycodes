#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TrieNode {
	char ch;
	int num;
	vector<TrieNode*> children;
};

struct TrieNode* newTrieNode(char c) {
	TrieNode* node = new TrieNode;
	node->ch = c;
	node->num = 1;
	return node;
}

void addString(struct TrieNode* node, string str) {
	char head;
	string remaining;
	if(str.size() > 0) {
	    head = str[0];
	    remaining = str.substr(1);
	} else {
	    return;
	}
	bool found = false;
	for(struct TrieNode* child : node->children) {
		if(child->ch == head) {
			child->num ++;
			addString(child, remaining);
			found = true;
			break;
		}
	}
	if(!found) {
		struct TrieNode* newNode = newTrieNode(head);
		node->children.push_back(newNode);
		addString(newNode, remaining);
	}
}

int findString(struct TrieNode* node, string str) {
	int retNum = 0;
	char head;
	string remaining;
	head = str[0];
	if(str.size() > 1) {
	    remaining = str.substr(1);
	}
	bool found = false;
	for(struct TrieNode* child : node->children) {
		if(child->ch == head) {
			if(str.size()==1)
				retNum = child->num;
			else if(str.size()>1)
				retNum = findString(child, remaining);
			found = true;
			break;
		}
	}
	if(!found) {
		retNum = 0;
	}
	
	return retNum;
}

void printTrie(struct TrieNode* node, int level) {
	cout<<level<<"-("<<node->ch<<","<<node->num<<","<<node->children.size()<<")"<<endl;
	for(struct TrieNode* child : node->children) {
		cout<<"-";
		int newlevel = level + 1;
		printTrie(child, newlevel);
	}
}

int main(){
    int n;
    struct TrieNode* root;
    root = newTrieNode(' ');
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
	if(!op.compare("add")) {
		addString(root, contact);
	} else if(!op.compare("find")) {
		int re = findString(root, contact);
		cout<<re<<endl;
	} else {
		return -1;
	}
    }
    //printTrie(root, 1);
    //int re = findString(root, "ab");
    //cout<<"re="<<re<<endl;
    return 0;
}

