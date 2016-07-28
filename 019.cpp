// 20. Maximum Sum Descent
// Some positive integers are arranged in a triangle like the one shown below.
// Design an algorithm to find the largest sum in a descent from its apex to the
// base through a sequence of adjacent numbers, one number per each level.
//
//          (2)
//        5    (4)
//     3    4     (7)
//  1    6    (9)     6

#include <iostream>
#include <vector>
using namespace std;


int find_max_sum(const vector<vector<int> > &triangle) {

	cout << "start..." << endl;

	const int N = int(triangle.size());

	vector<vector<int> > nodes = triangle;
	for(int layer = 0; layer < (N - 1); layer ++) {
		for(size_t j = 0; j < nodes[layer].size(); j ++)
			nodes[layer][j] = 0;
	}

	cout << "ready empty nodes..." << endl;

	for(int layer = (N - 1); layer > 0; layer --) {
		const int layer_size = int(triangle[layer].size());
		for( int j = 0; j < (layer_size - 1); j ++) {
			const int parent_index = j;
			const int parent_node = triangle[layer -1][parent_index];
			const int sum_candidate1 = parent_node + nodes[layer][j];
			const int sum_candidate2 = parent_node + nodes[layer][j + 1];
			const int parent_node_sum = nodes[layer -1][parent_index];
			const int new_sum = max(max(sum_candidate1, sum_candidate2), parent_node_sum);
			nodes[layer -1][parent_index] = new_sum;

			cout << "set: " << int(layer - 1) << ", " << parent_index << ": " << new_sum << endl;
		}
	}



	return nodes[0][0];
}

int main(void) {
	vector<vector<int> > triangle;
	for(int layer = 0; layer < 4; layer ++)
		triangle.push_back(vector<int>(layer + 1));
	triangle[0][0] = 2;

	triangle[1][0] = 5;
	triangle[1][1] = 4;

	triangle[2][0] = 3;
	triangle[2][1] = 4;
	triangle[2][2] = 7;

	triangle[3][0] = 1;
	triangle[3][1] = 6;
	triangle[3][2] = 9;
	triangle[3][3] = 6;


	const int s = find_max_sum(triangle);
	cout << s << endl;
	if(s == 22)
		cout << "OK" << endl;
	else
		cout << "ERROR" << endl;
	return 0;
}
