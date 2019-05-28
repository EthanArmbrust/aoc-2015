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

    ifstream infile("input/test14.txt");
    string s;
    vector<Deer> deerses;
    map<string, int> distances;
    const int racetime = 12;


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
        int real_time_tm = d.fly + d.rest;
        int mainpart = racetime / real_time_tm;
        int remaining = racetime % real_time_tm;

        int first_part_dist = mainpart * d.speed;
        int second_part;
        if(remaining - d.fly > 0){
            second_part = d.fly * d.speed;
        }
        else{
            second_part = remaining * d.speed;
        }
       distances[d.name] = first_part_dist + second_part; 
    }


    for(auto d : distances){
        cout << d.first << " " << d.second << endl;
    }


    return 0;
}
