#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Deer{
    string name;
    int speed;
    int fly;
    int rest;
};


int main(){

    ifstream infile("input/14.txt");
    string s;
    vector<Deer> deerses;
    map<string, int> distances;
    const int racetime = 2503;


    while(getline(infile, s)){
        stringstream ss(s);
        vector<string> line;
        string temp;
        while(ss >> temp){
            line.push_back(temp);
        }
        string name = line[0];
        int speed = stoi(line[3]);
        int fly = stoi(line[6]);
        int rest = stoi(line[13]);

        Deer deer = {name, speed, fly, rest};
        deerses.push_back(deer);
    }

    for(Deer d : deerses){
		string name = d.name;
		int time_w_rest = d.fly + d.rest;
		//full cycles
		int cycles = racetime / time_w_rest;
		int cycle_dist = d.speed * d.fly * cycles;

		int remaining = racetime % time_w_rest;
		int finaldist;
		if(remaining > d.fly){
			finaldist = d.fly * d.speed;
		}
		else{
			finaldist = remaining * d.speed;
		}
		distances[name] = cycle_dist + finaldist;
    }


    for(auto d : distances){
        cout << d.first << " " << d.second << endl;
    }


    return 0;
}
