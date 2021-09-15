#include <iostream>
#include <string>

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	cout << a.length() << " " << b.length() << endl;
	cout << a + b << endl;
	char a1 = a[0];
	char b1 = b[0];
	a.erase(0,1);
	b.erase(0,1);
	cout << b1 << a << " " << a1 << b << endl; 

}