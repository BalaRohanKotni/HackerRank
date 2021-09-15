#include <iostream>

using namespace std;

void update(int *a, int *b) {
	int sum = (*a) + (*b);
	int diff = abs((*a) - (*b));
	*a = sum;
	*b = diff;
}

int main() {
	int a = 4;
	int b = 5;
	update(&a, &b);
	cout << a << endl << b << endl;
	return 0;
}