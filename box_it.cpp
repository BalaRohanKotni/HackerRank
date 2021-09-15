#include <iostream>

using namespace std;

class Box {
private:
	int length;
	int breadth;
	int height;
public:
	Box(int l = 0, int b = 0, int h = 0) {
		length = l;
		breadth = b;
		height = h;
	}

	Box(Box &box){
		length = box.getLength();
		breadth = box.getBreadth();
		height = box.getHeight();
	}

	int getLength() {
		return length;
	}
	int getBreadth() {
		return breadth;
	}
	int getHeight() {
		return height;
	}

	long long CalculateVolume() {
		long long vol = length;
		vol *= breadth;
		vol *= height;
		return vol;
	}

	bool operator < (Box &b) {
		if (
		    this->getLength() < b.getLength() ||
		    (this->getBreadth() < b.getBreadth() && this->getLength() == b.getLength()) ||
		    (this->getHeight() < b.getHeight() && this->getBreadth() == b.getBreadth() && this->getLength() == b.getLength())) {
			return true;
		}
		return false;
	}

	friend ostream& operator << (ostream& os, Box &box){
		os << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();
		return os;
	}
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}