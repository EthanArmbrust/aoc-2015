#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//https://old.reddit.com/r/adventofcode/comments/3xflz8/day_19_solutions/cy4h7ji/

int main(){

	ifstream infile("input/19.txt");
	string s;
	vector<pair<string, string>> input;
    string compound;

	while(getline(infile, s)){
        stringstream ss(s);
        vector<string> temp;
        string str;
        while(ss >> str){
            temp.push_back(str);
        }
        if(temp.size() == 3){
            input.push_back(make_pair(temp[0], temp[2]));
        }
        else if(temp.size() == 1){
            compound = temp[0];
        } 
	}

	int symbolCount = 0;
	for(auto c : compound){
		if(isupper(c)){
			symbolCount++;
		}
	}

	int RnCount = 0;
	int ArCount = 0;

	auto it = compound.find("Rn");
	while(it != string::npos){
		RnCount++;
		it = compound.find("Rn", it + 1);
	}
	it = compound.find("Ar");
	while(it != string::npos){
		ArCount++;
		it = compound.find("Ar", it + 1);
	}
	
	int yCount = count(compound.begin(), compound.end(), 'Y');

	int total = symbolCount - RnCount - ArCount - (2 * yCount) - 1;

	cout << total << endl;


    return 0;
}
