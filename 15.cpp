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

void fix_val(int &i);

int main(){
	
	Ingredient Frosting = {"Frosting", 4, -2, 0, 0, 5};
	Ingredient Candy = {"Candy", 0, 5, -1, 0, 8};
	Ingredient Butterscotch = {"Butterscotch", -1, 0, 5, 0, 6};
	Ingredient Sugar = {"Sugar", 0, 0, -2, 2, 1};

	vector<int> scores;
	vector<int> lowCal;

	for(int a = 0; a <= 100; a++){
		for(int b = 0; b <= 100; b++){
			for(int c = 0; c <= 100; c++){
				for(int d = 0; d <= 100; d++){
					if(a + b + c + d != 100){
						continue;
					}
					else{
						int cap = Frosting.capacity * a + Candy.capacity * b + Butterscotch.capacity * c + Sugar.capacity * d;
						int dur = Frosting.durability * a + Candy.durability * b + Butterscotch.durability * c + Sugar.durability * d;
						int flav = Frosting.flavor * a + Candy.flavor * b + Butterscotch.flavor * c + Sugar.flavor * d;
						int tex = Frosting.texture * a + Candy.texture * b + Butterscotch.texture * c + Sugar.texture * d;
						int cal = Frosting.calories * a + Candy.calories * b + Butterscotch.calories * c + Sugar.calories * d;

						fix_val(cap);
						fix_val(dur);
						fix_val(flav);
						fix_val(tex);

						scores.push_back(cap * flav * dur * tex);
						if(cal == 500){
							lowCal.push_back(cap * flav * dur * tex);
						}
					}
				}
			}
		}
	}

	cout << *max_element(scores.begin(), scores.end()) << endl;
	cout << *max_element(lowCal.begin(), lowCal.end()) << endl;
	

    return 0;
}

void fix_val(int &i){
	if(i < 0){
		i = 0;
	}
}
