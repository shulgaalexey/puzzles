// 13 Blocked Paths
// Find the number of different shortest paths from point A to point B in a city
// with perfectly horizontal streets and vertical avenues as shown in figure.
// No path can cross the fenced off area shown in grey in the figure.
//
//  -A---|---|---|---|-
//   |   |   |   |   |
//  -|---|---|---|---|-
//   |   | ##### |   |
//  -|---|-#####-|---|-
//   |   | ##### |   |
//  -|---|---|---|---B-

#include <iostream>
using namespace std;

int count_paths(int *G, int M, int N) {

	// Populate the top row with 1s
	for(int i = 0; i < N; i ++)
		if(!G[i])
			G[i] = 1;

	// Populate the left column with 1s
	for(int i = 0; i < M; i ++)
		if(!G[i * N])
			G[i * N] = 1;

	for(int i = 1; i < M; i ++) {
		for(int j = 1; j < N; j ++) {
			if(G[i * N + j] == (-1))
				continue; // This is obstacle


			G[i * N + j] = max(0, G[(i - 1) * N + j])   // top cell
					+ max(0, G[i * N + j - 1]); // left cell
		}
	}

	return G[M * N - 1];
}

int main(void) {
	const int M = 4;
	const int N = 5;
	int G[M * N] = {0};
	G[2 * N + 2] = -1; // Obstacle
	const int n = count_paths(G, M, N);
	if(n == 17)
		cout << "OK" << endl;
	else
		cout << "Error" << endl;

#if 0
	// Debug
	cout << n << endl;
	for(int i = 0; i < M; i ++) {
		for(int j = 0; j < N; j ++) {
			cout << G[i * N + j] << " ";
		}
		cout << endl;
	}
#endif

	return 0;
}
