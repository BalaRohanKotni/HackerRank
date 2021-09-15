#include <iostream>

using namespace std;

int main(){
	string numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int start ;
	int end;
	cin >> start;
	cin >> end;

	for(int i=start; i <= end; i++){
		if(i <= 9){
			cout << numbers[i-1] << endl;
		}
		else if(i%2==0){
			cout << "even" << endl; 
		}
		else{
			cout << "odd" << endl;
		}
	}

} 