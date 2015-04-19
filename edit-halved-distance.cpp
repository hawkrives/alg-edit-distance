#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;

typedef vector<vector<float> > matrix;

float diff(char a, char b) {
	return (a == b) ? 0 : 0.5;
}

float edit_distance(string one, string two) {
	matrix E;
	int m = one.size();
	int n = two.size();

	E.resize(m + 1);
	for (int i = 0; i <= m; i++) {
		vector<float> temp;
		temp.resize(n + 1);
		E.at(i) = temp;
	}

	for (int i = 0; i <= m; i++) {
		E.at(i).at(0) = i;
	}

	for (int j = 1; j <= n; j++) {
		E.at(0).at(j) = j;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			E.at(i).at(j) = min({
				E.at(i - 1).at(j) + 1,
				E.at(i).at(j - 1) + 1,
				E.at(i - 1).at(j - 1) + diff(one.at(i - 1), two.at(j - 1)),
			});
		}
	}

	return E.at(m).at(n);
}

int main(int argc, char const *argv[]) {
	if (argc < 3)
		cerr << argv[0] << " string1 string2" << endl;

	string one = argv[1];
	string two = argv[2];

	cout << edit_distance(one, two) << endl;

	return 0;
}
