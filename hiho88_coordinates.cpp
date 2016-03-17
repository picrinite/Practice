/* Question

*/
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

void getDividors(set<int> &st_dividors, int num, map<int, int> &mp_prime_factors, 
	map<int, int> mp_cur_prime_factors) {

	for (auto it : mp_prime_factors) {
		if (mp_cur_prime_factors[it.first] < it.second) {
			st_dividors.insert(num * it.first);
			mp_cur_prime_factors[it.first]++;
			getDividors(st_dividors, num * it.first, mp_prime_factors, mp_cur_prime_factors);
		}	
	}

}

void getPrimeFactors(int n, map<int, int> & mp_prime_factors) {
	vector<int> vec_prime_factors;
	while ((n & 1) == 0) {
		n >>= 1;
		vec_prime_factors.push_back(2);
	}
	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			n /= i;
			vec_prime_factors.push_back(i);
		}
	}
	if (n > 1)
		vec_prime_factors.push_back(n);
	for (int num : vec_prime_factors)
		if (mp_prime_factors.find(num) == mp_prime_factors.end())
			mp_prime_factors[num] = 1;
		else
			++mp_prime_factors[num];
}

vector<int> getDividors(int n) {
	map<int, int> mp_prime_factors;
	getPrimeFactors(n, mp_prime_factors);	
	map<int, int> mp_cur_prime_factors;
	set<int> st_dividors;
	for (auto it : mp_prime_factors)
		mp_cur_prime_factors[it.first] = 0;
	getDividors(st_dividors, 1, mp_prime_factors, mp_cur_prime_factors);
	for (auto it : st_dividors)
		cout << it << endl;
	st_dividors.insert(1);
	vector<int> res(st_dividors.begin(), st_dividors.end() );
	return res;
}

int main(){
	int p, q;
	scanf("%d%d", &p, &q);
	vector<int> dividors_p, dividors_q;
	dividors_p = getDividors(p);
	dividors_q = getDividors(q);
	for (auto pi : dividors_p)
		for (auto pj : dividors_q)
			printf("%d %d\n", pi, pj);
}