#include<bits/stdc++.h>

using namespace std;

char a1 = '{';
char b1 = '(';
char c1 = '[';

char a2 = '}';
char b2 = ')';
char c2 = ']';


bool check_parenthesis(string str){

	stack<char> s;

	for(int i = 0;i<str.length();i++){

		if(str[i] == a1){

			if(s.empty()){
				s.push(a1);
			}else{
				s.push(a1);
			}

		}else if(str[i] == b1){

			if(s.empty()){
				s.push(b1);
			}else{
				s.push(b1);
			}

		}else if(str[i] == c1){

			if(s.empty()){
				s.push(c1);
			}else{
				s.push(c1);
			}

		}else if(str[i] == a2){

			if(s.empty()){
				return false;
			}

			if(s.top() == b1 || s.top() == c1){
				return false;
			}

			s.pop();

		}else if(str[i] == b2){

			if(s.empty()){
				return false;
			}

			if(s.top() == a1 || s.top() == c1){
				return false;
			}

			s.pop();

		}else if(str[i] == c2){
			
			if(s.empty()){
				return false;
			}

			if(s.top() == b1 || s.top() == a1){
				return false;
			}

			s.pop();
		}
	}

	if(!s.empty())
		return false;

	return true;
}

int main(){

	int t;
	cin>>t;

	string s;

	while(t--){

		cin>>s;

		if(check_parenthesis(s)){
			cout<<"balanced\n";
		}else{
			cout<<"not balanced\n";
		}
	}

	return 0;
}