#include <iostream>
#include <vector>

using namespace std;

struct Ingredient{
	string name;
	int capacity;
	int durability;
	int flavor;
	int texture;
	int calories;
};


int main(){
	
	Ingredient Frosting = {"Frosting", 4, -2, 0, 0, 5};
	Ingredient Candy = {"Candy", 0, 5, -1, 0, 8};
	Ingredient Butterscotch = {"Butterscotch", -1, 0, 5, 0, 6};
	Ingredient Sugar = {"Sugar", 0, 0, -2, 2, 1};

	vector<int> scores;

	for(int a = 0; a <= 100; a++){
		for(int b = 0; b <= 100; b++){
			for(int c = 0; c <= 100; c++){
				for(int d = 0; d <= 100; d++){
					if(a + b + c + d != 100){
						continue;
					}
					else{
						int cap = Frosting.capacity * a + Candy.capacity * b + Butterscotch.capacity * c + Sugar.capacity * d;
					}
				}
			}
		}
	}
	

    return 0;
}

void fix_val(int &i){
	if(i < 0){
		i = 0;
	}
}
