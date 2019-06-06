#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

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

    vector<string> replacements;
    for(auto p : input){
        string original = p.first;
        string replace = p.second;
        auto it = compound.find(original);
        while(it != string::npos){
            string str = compound;
            str.replace(it, original.length(), replace);
            if(find(replacements.begin(), replacements.end(), str) == replacements.end()){
                replacements.push_back(str);
            }
            it = compound.find(original, it+1);
        }
    }
    /*
    for(auto s : replacements){
        cout << s << endl;
    }
    */

    cout << replacements.size() << endl;

    return 0;
}
