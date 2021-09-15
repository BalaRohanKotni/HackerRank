#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <limits>
#include <typeinfo>
#include <algorithm>

using namespace std;

vector<string> tokenize(string s, string del = " ")
{
	vector<string> splitted;
	int start = 0;
	int end = s.find(del);
	while (end != -1)
	{
		splitted.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	splitted.push_back(s.substr(start, end - start));
	return splitted;
}

string erase_part(string mainStr, string toErase) {
	size_t pos = mainStr.find(toErase);
	if (pos != string::npos) {
		mainStr.erase(pos, toErase.length() + 1);
	}
	return mainStr;
};


int main() {
	int n , q;
	string curr;

	vector<string> script;
	vector<string> query;
	vector<string> closing_ones;

	map<string, string> values;

	cin >> n >> q;
	cin.ignore();

// input the hrml listing
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		script.push_back(s);
	}

	// input the queries
	for (int i = 0; i < q; i++) {
		string s;
		getline(cin, s);
		query.push_back(s);
	}

	for (int i = 0; i < script.size(); i++) {
		string tag = script[i];

		// remove the first and last character of the tag
		tag.erase(0, 1);
		tag.erase(tag.length() - 1);

		string tagName = tokenize(tag)[0];
		// check if its a starting or ending tag
		if (tag[0] != '/') {
			tag = erase_part(tag, tagName);

			// remove spacing between attr and value (attr = value) to (attr=value)

			size_t eqToPos = tag.find("=");
			while (eqToPos != string::npos) {
				if (tag[eqToPos - 1] == ' ') {
					tag.erase(eqToPos - 1, 1);
				}
				eqToPos = tag.find("=", eqToPos + 1);
			}
			eqToPos = tag.find("=");
			while (eqToPos != string::npos) {
				if (tag[eqToPos + 1] == ' ') {
					tag.erase(eqToPos + 1, 1);
				}
				eqToPos = tag.find("=", eqToPos + 1);
			}

			// now split the tag by space as delimiter
			vector<string> atts_values = tokenize(tag);

			// now store the values as map
			for (int l = 0; l < atts_values.size(); l++) {
				string map_key = curr + tagName + '~' + tokenize(atts_values[l], "=")[0];
				string map_value = tokenize(atts_values[l], "=")[1];
				map_value.erase(0,1);
				map_value.erase(map_value.length()-1);
				values.insert(pair<string, string>(map_key, map_value));
			}
			closing_ones.push_back(tagName);
			curr += tagName + ".";
		}
		else {
			string stripped_tag = tagName;
			stripped_tag.erase(0, 1);
			auto it = find(closing_ones.begin(), closing_ones.end(), stripped_tag);
			if (it != closing_ones.end()) {
				auto found = curr.find(closing_ones[it - closing_ones.begin()]);
				if (found != string::npos) {
					string as = closing_ones[it - closing_ones.begin()];
					curr.erase(found, as.length() + 1);
				}

			}
			else curr = "";
		}
	}
	
	for(int i=0; i < q; i++){
		auto ite = values.find(query[i]);

		if (ite != values.end()) cout << ite->second << endl;
		else cout << "Not Found!" << endl;
	}

	return 0;
}

/*
4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
*/

/*
tag1 value = "value"    0
*/