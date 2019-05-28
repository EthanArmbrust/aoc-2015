#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream infile("input/1.txt");
	string input;

	getline(infile, input);

	int floor = 0;
	int count = 0;

	for(char c : input){
		if(c == '('){
			floor++;
		}
		else floor--;
		count++;
		if(floor < 0){
			cout << count << endl;
			return 0;
		}
	}

	cout << floor << endl;

	return 0;
}
