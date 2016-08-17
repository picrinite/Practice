#include <cstdio>
#include <iostream>
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
