// 25 The Best Time to Be Alive
// An editor of The History of the World Science wants to find out the time when
// the largest number of prominent scientists were alive. The prominent
// scientists are, by definition, the people mentioned in the book with the
// dates of their birth and death. (No living scientists are included in the book.)
// Device an algorithm for this task if it has the book's index as input. The
// entries in the index are sorted alphabetically and give the person's birth
// and death years. If person A died the same year person B was born, assume
// that the former event happened before the latter one.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int find_best_time(const vector<pair<int, int> > &scientists) {
	int min_b = INT_MAX;
	int max_d = INT_MIN;
	for(size_t i = 0; i < scientists.size(); i ++) {
		if(scientists[i].first < min_b)
			min_b = scientists[i].first;
		if(scientists[i].second > max_d)
			max_d = scientists[i].second;
	}

	vector<int> buf(max_d + 1, 0);
	for(size_t i = 0; i < scientists.size(); i ++) {
		buf[scientists[i].first] ++;
		buf[scientists[i].second] --;
	}

	int max_cnt = INT_MIN;
	int cnt = 0;
	for(int i = min_b; i <= max_d; i ++) {
		cnt += buf[i];
		if(cnt > max_cnt) {
			max_cnt = i;
		}
	}

	return max_cnt;
}

int main(void) {
	vector<pair<int, int> > scientists;
	scientists.push_back(pair<int, int>(1, 3));
	scientists.push_back(pair<int, int>(2, 10));
	scientists.push_back(pair<int, int>(2, 5));
	scientists.push_back(pair<int, int>(5, 8));
	const int t = find_best_time(scientists);
	cout << t << endl;
	if(t != 2)
		cout << "Error" << endl;
	return 0;
}
