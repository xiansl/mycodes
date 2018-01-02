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

bool is_balanced(string expression) {
    stack<char> st;
    for(int i=0; i<expression.size(); i++) {
    	char c = expression[i];
	if(st.empty()) {
		if(c=='(' || c=='[' || c=='{') st.push(c);
		else return false;
	} else {
		char t = st.top();
		if(t=='(') { 
			if(c==')') st.pop();
			else if(c=='(' || c=='[' || c=='{') st.push(c);
			else return false;
		} else if(t=='[') { 
			if(c==']') st.pop();
			else if(c=='(' || c=='[' || c=='{') st.push(c);
			else return false;
		} else if(t=='{') { 
			if(c=='}') st.pop();
			else if(c=='(' || c=='[' || c=='{') st.push(c);
			else return false;
		} else return false;
	}
    }
    if(st.empty()) return true;
    else return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

