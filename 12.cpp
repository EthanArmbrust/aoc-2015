#include <iostream>
#include <fstream>

using namespace std;


int main(){
	ifstream infile("input/12.txt");
	string s;
	getline(infile, s);

	int sum = 0;

	string currentNum = "";

	for(char c : s){
		if(isdigit(c) || c == '-'){
			currentNum += c;
		}
		else{
			if(currentNum != ""){
				sum += stoi(currentNum);
				currentNum = "";
			}
		}
	}

	cout << sum << endl;
	return 0;
}

