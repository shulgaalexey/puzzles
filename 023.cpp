// 23 Polish National Flag Problem
// There is a row of n > 1 checkers on the table, some ot rhem are red and some
// are white. (Red and white are the colors of the Polish national flag.)
// Design an algorithm to rearrange the checkers so that all the red checkers
// precede all the white ones. The only operations allowed are the examination
// of a checker's color ant the swapping of two checkers. Try to minimize the
// number of swaps made by your algorithm.
#include <iostream>
using namespace std;

void rearrange_to_polish_flag(int *a, int n) {
	int p1 = 0;
	int p2 = n - 1;

	while(p1 < p2) {
		while((p1 != p2) && (a[p1] == 0))
			p1 ++;
		if(p1 == p2)
			break;

		while((p1 != p2) && (a[p2] == 1))
			p2 --;
		if(p1 == p2)
			break;

		a[p1 ++] = 0;
		a[p2 --] = 1;
	}
}

int main(void) {
	{ // 1
		int a[] = {1, 0, 0, 1, 1, 0, 0, 1};
		rearrange_to_polish_flag(a, 8);
		for(int i = 0; i < 8; i ++) cout << a[i] << " ";
		cout << endl;

	}

	{ // 2
		int a[] = {1, 0, 0, 1, 1, 0, 0, 1, 0};
		rearrange_to_polish_flag(a, 9);
		for(int i = 0; i < 9; i ++) cout << a[i] << " ";
		cout << endl;

	}

	return 0;
}
