#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;
using std::reverse;
#include <utility>
using std::pair;

typedef vector<vector<int> > matrix;

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
	s.put('[');
	char comma[3] = {'\0', ' ', '\0'};
	for (const auto& e : v) {
		s << comma << e;
		comma[0] = ',';
	}
	return s << ']';
}

std::ostream& operator<<(std::ostream& s, const std::pair<int, std::string>& p) {
	s << '(' << p.first << ", '" << p.second << "')" << endl;
	return s;
}

int diff(char a, char b) {
	return (a == b) ? 0 : 10000;
}

matrix edit_distance(string one, string two) {
	matrix E;
	int m = one.size();
	int n = two.size();

	E.resize(m + 1);
	for (int i = 0; i <= m; i++) {
		vector<int> temp;
		temp.resize(n + 1);
		E.at(i) = temp;
	}

	// set up top row
	for (int i = 0; i <= m; i++) {
		E.at(i).at(0) = i;
	}

	// set up left column
	for (int j = 1; j <= n; j++) {
		E.at(0).at(j) = j;
	}

	string path = "";
	// find distances
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			// (cell above)
			int option1 = E.at(i - 1).at(j) + 1;
			// (cell left)
			int option2 = E.at(i).at(j - 1) + 1;
			// (cell top-left) [match]
			int option3 = E.at(i - 1).at(j - 1) + diff(one.at(i - 1), two.at(j - 1));

			int minOption = min({
				option1,
				option2,
				option3,
			});

			E.at(i).at(j) = minOption;
		}
	}

	return E;
}

void trace_back(const matrix mat, int col, int row, const string one, const string two, vector<char> &path) {
	if (col == 0 && row == 0) {
		return;
	}

	if (col < 0) col = 0;
	if (row < 0) row = 0;

	int left = mat.at(col - 1 < 0 ? 0 : col - 1).at(row);
	int above = mat.at(col).at(row - 1 < 0 ? 0 : row - 1);

	cout << col << " " << row << " " << one.size() << " " << two.size() << endl;
	if (one.at(col - 1 < 0 ? 0 : col - 1) == two.at(row - 1 < 0 ? 0 : row - 1)) {
		path.push_back(one.at(col-1));
		trace_back(mat, col - 1, row - 1, one, two, path);
	}
	else if (left < above) {
		trace_back(mat, col - 1, row, one, two, path);
	}
	else {
		trace_back(mat, col, row - 1, one, two, path);
	}
}

int main(int argc, char const *argv[]) {
	if (argc < 3)
		cerr << argv[0] << " string1 string2" << endl;

	string two = argv[1];
	string one = argv[2];

	matrix mat = edit_distance(one, two);
	int longestDistance = mat.back().back();
	vector<char> path;
	cout << '[' << endl;
	for (auto row : mat)
		cout << '\t' << row << endl;
	cout << ']' << endl;
	trace_back(mat, mat.size() - 1, mat.back().size() - 1, one, two, path);
	cout << longestDistance << ": ";
	cout << path.size() << endl;
	for(int i=path.size()-1; i >= 0; i--){
		cout << path[i];
	}
	cout << endl;

	return 0;
}