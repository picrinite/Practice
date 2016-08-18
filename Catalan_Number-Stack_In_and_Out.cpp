#include <cstdio>
#include <iostream>

// numIn is # in the stack, numLeft is # to be put in stack
int calCatalan(int numIn, int numLeft, int (*dict)[100]) {
	if (numLeft == 0)
		return 1;
	if (dict[numIn][numLeft])
		return dict[numIn][numLeft];
	int res = calCatalan(numIn + 1, numLeft - 1, dict) + (numIn >= 1 ? calCatalan(numIn - 1, numLeft, dict) : 0);
	dict[numIn][numLeft] = res;
	return res;
}
int main() {
	int num;
	scanf("%d", &num);
	int dict[100][100] = { {} };
	std::cout << calCatalan(0, num, dict) << std::endl;
}

// worse implementation
/*
int calCatalan(int numIn, int numLeft) {
	if (numLeft == 0)
		return 1;
	return calCatalan(numIn + 1, numLeft - 1) + (numIn >= 1 ? calCatalan(numIn - 1, numLeft) : 0);
}
int main() {
	int num;
	scanf("%d", &num);
	std::cout << calCatalan(0, num) << std::endl;
}
*/
