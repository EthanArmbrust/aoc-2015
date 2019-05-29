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

		bool q1_sat = false;
		bool q2_sat = false;
		bool q3_sat = false;

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

		if(prop1 == "cats" || prop1 == "trees"){
			q1_sat = q1 > properties[prop1];
		}
		else if(prop1 == "pomeranians" || prop1 == "goldfish"){
			q1_sat = q1 < properties[prop1];
		}
		else{
			q1_sat = q1 == properties[prop1];
		}


		if(prop2 == "cats" || prop2 == "trees"){
			q2_sat = q2 > properties[prop2];
		}
		else if(prop2 == "pomeranians" || prop2 == "goldfish"){
			q2_sat = q2 < properties[prop2];
		}
		else{
			q2_sat = q2 == properties[prop2];
		}


		if(prop3 == "cats" || prop3 == "trees"){
			q3_sat = q3 > properties[prop3];
		}
		else if(prop1 == "pomeranians" || prop3 == "goldfish"){
			q3_sat = q3 < properties[prop3];
		}
		else{
			q3_sat = q3 == properties[prop3];
		}

		if(q1_sat && q2_sat && q3_sat){
			cout << auntNum << endl;
			return 0;
		}
	}



	return 0;
}
