#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;


int main(){

	ifstream infile("input/16.txt");
	string s;

	map<string, int> properties;
	properties["children"] = 3;
	properties["cats"] = 7;
	properties["samoyeds"] = 2;
	properties["pomeranians"] = 3;
	properties["akitas"] = 0;
	properties["vizslas"] = 0;
	properties["goldfish"] = 5;
	properties["trees"] = 3;
	properties["cars"] = 2;
	properties["perfumes"] = 1;

	while(getline(infile, s)){
		vector<string> input;
		stringstream ss(s);
		string temp;
		while(ss >> temp){
			input.push_back(temp);
		}

		string auntNum = input[1];
		auntNum.pop_back();
		string prop1 = input[2];
		prop1.pop_back();
		string quant1 = input[3];
		quant1.pop_back();
		int q1 = stoi(quant1);
		string prop2 = input[4];
		prop2.pop_back();
		string quant2 = input[5];
		quant2.pop_back();
		int q2 = stoi(quant2);
		string prop3 = input[6];
		prop3.pop_back();
		string quant3 = input[7];
		int q3 = stoi(quant3);

		if(properties[prop1] == q1 && properties[prop2] == q2 && properties[prop3] == q3){
			cout << auntNum << endl;
			return 0;
		}
	}



	return 0;
}
