#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

bool isParenthesesValid(string parentheses){
    //ここから書きましょう
    stack<char> s;
    
    map<char, char> m;
    m['('] = ')';
    m['{'] = '}';
    m['['] = ']';

    for(int i = 0; i < parentheses.size(); i++){
        if(m[s.top()] != parentheses[i]|| s.empty()){
            s.push(parentheses[i]);
        }else{
            s.pop();
        }
    }
    
    return s.empty() ? true : false;

}
