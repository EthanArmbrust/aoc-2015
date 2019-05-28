#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "hash-library/md5.h"

using namespace std;

int main(){

	string input = "bgvyzdsv";

	MD5 md5;

	int counter = 1;
	bool partOne = false;
	while(!partOne){
		string hash = md5(input + to_string(counter));
		if(hash.substr(0, 5) == "00000"){
			cout << "Part 1: " << counter << endl;
			partOne = true;
		}
		counter++;
	}

	counter = 1;
	while(true){
		string hash = md5(input + to_string(counter));
		if(hash.substr(0, 6) == "000000"){
			cout << "Part 2: " << counter << endl;
			return 0;
		}
		counter++;
	}
}
