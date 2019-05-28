#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input/2.txt");
	vector<string> input;

	string s;

	while(getline(infile, s)){
		input.push_back(s);
	}

	int sum = 0;

	for(string str : input){
		int l,w,h;
		auto first_x = str.find('x');
		l = stoi(str.substr(0, first_x));
		string second_half = str.substr(first_x + 1, str.length() - 1);
		auto second_x = second_half.find('x');
		w = stoi(second_half.substr(0, second_x));
		h = stoi(second_half.substr(second_x + 1, second_half.length() - 1));

		//int ribbon = (2 * l) + (2 * w);
		int wh = (w * 2) + (h * 2);
		int wl = (w * 2) + (l * 2);
		int hl = (h * 2) + (l * 2);

		int ribbon = min(wh, min(wl, hl));

		int bow = l * w * h;

		sum += ribbon + bow;

	}

	cout << sum << endl;

	return 0;
}
