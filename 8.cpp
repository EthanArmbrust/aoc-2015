#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input/8.txt");
	string s;
	int code_total = 0;
	int string_total = 0;

	while(getline(infile, s)){
		int code_len = s.length();
		int string_len = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '\"'){
				continue;
			}
			if(s[i] == '\\'){
				if(s[i + 1] == '\\' || s[i+1] == '\"'){
					i++;
				}
				else if(s[i+1] == 'x'){
					i += 3;
				}
			}
			string_len++;
		}
		code_total += code_len; 
		string_total += string_len;
	}
	cout << "Code len: " << code_total << endl;
	cout << "String len: " << string_total << endl;
	cout << code_total - string_total << endl;

	return 0;
}
