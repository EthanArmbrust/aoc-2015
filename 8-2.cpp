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
		string new_s = "\"";

		for(int i = 0; i < s.length(); i++){
			if(s[i] == '\"'){
				new_s += "\\\"";
				continue;
			}
			else if(s[i] == '\\'){
				if(s[i + 1] == '\\'){
					new_s += "\\\\\\\\";
					i++;
				} else if(s[i+1] == '\"'){
					new_s += "\\\\\\\"";
					i++;
				}
				else if(s[i+1] == 'x'){
					new_s += "\\\\" + s.substr(i+1, 3);
					i += 3;
				}
			}
			else{
				new_s += s[i];
			}
			string_len++;
		}
		new_s += "\"";
		cout << new_s << endl;
		code_total += code_len; 
		string_total += new_s.length();
	}
	cout << "Code len: " << code_total << endl;
	cout << "String len: " << string_total << endl;
	cout << string_total - code_total << endl;

	return 0;
}
