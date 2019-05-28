#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input/3.txt");
	string s;
	vector<pair<int,int>> visited;

	getline(infile, s);

	int santax = 0, santay = 0;
	int robox = 0, roboy = 0;

	bool isSanta = true;
	for(char c : s){
		int x, y;
		if(isSanta){
			x = santax;
			y = santay;
		}
		else{
			x = robox;
			y = roboy;
		}
		if(c == '^'){
			y++;
		}
		if(c == 'v'){
			y--;
		}
		if(c == '>'){
			x++;
		}
		if(c == '<'){
			x--;
		}
		if(isSanta){
			santax = x;
			santay = y;
		}
		else{
			roboy = y;
			robox = x;
		}
		pair<int,int> position(x,y);
		auto it = find(visited.begin(), visited.end(), position);
		if(it == visited.end()){
			visited.push_back(position);
		}
		isSanta = !isSanta;
	}

	cout << visited.size() << endl;


	return 0;
}
