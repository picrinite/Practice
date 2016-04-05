/* Question
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
*/
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//040416  Topologic sort
class Solution {
	bool dfs(int cur, vector<int> &visited, vector<vector<int> > &matrix, vector<int> &ret, vector<int> &black) {
		visited[cur] = 1;
		for (auto i : matrix[cur]) {
			if (!black[i]) {
				if (visited[i])
					return true;
				bool has_cycle = dfs(i, visited, matrix, ret, black);
				if (has_cycle)
					return true;
			}
		}
		ret.emplace_back(cur);
		black[cur] = 1;
		return false;
	}
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> vec_adj_list;
		vector<vector<int> > matrix(numCourses, vec_adj_list);
		vector<int> vec_root(numCourses, 1);
		for (auto p : prerequisites) {
			matrix[p.first].push_back(p.second);
			vec_root[p.second] = 0;
		}
		vector<int> ret;
		vector<int> black(numCourses);
		for (size_t i = 0; i < numCourses; ++i) {
			if (vec_root[i]) {
				vector<int> visited(numCourses);
				bool has_cycle = dfs(i, visited, matrix, ret, black);
				if (has_cycle)
					return vector<int>{};
			}
		}
		if (ret.size() != numCourses)
			return vector<int>{};
		return ret;
	}
};
//040416  Memory limit exceeded
/*
class Solution {
	bool dfs(int cur, vector<int> &visited, vector<vector<int> > &matrix, vector<int> &ret, vector<int> &black) {
		visited[cur] = 1;
		for (size_t i = 0; i < black.size(); ++i) {
			if (matrix[cur][i] && !black[i]) {
				if (visited[i])
					return true;
				bool has_cycle = dfs(i, visited, matrix, ret, black);
				if (has_cycle)
					return true;
			}
		}
		ret.emplace_back(cur);
		black[cur] = 1;
		return false;
	}
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> vec_adj_list(numCourses);
		vector<vector<int> > matrix(numCourses, vec_adj_list);
		vector<int> vec_root(numCourses, 1);
		for (auto p : prerequisites) {
			matrix[p.first][p.second] = 1;
			vec_root[p.second] = 0;
		}
		vector<int> ret;
		vector<int> black(numCourses);
		for (size_t i = 0; i < numCourses; ++i) {
			if (vec_root[i]) {
				vector<int> visited(numCourses);
				bool has_cycle = dfs(i, visited, matrix, ret, black);
				if (has_cycle)
					return vector<int>{};
			}
		}
		if (ret.size() != numCourses)
			return vector<int>{};
		return ret;
	}
};
*/

//112515  
/*
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ret;
		vector<unordered_set<int> > parents(numCourses);
		vector<unordered_set<int> > children(numCourses);
		for (auto it : prerequisites) {
			parents[it.second].insert(it.first);
			children[it.first].insert(it.second);
		}
		unordered_set<int> notFinished;
		for (int i = 0; i < numCourses; ++i)
			notFinished.insert(i);
		while (!notFinished.empty()) {
			bool found = false;
			for (auto i : notFinished) {
				if (children[i].size() == 0) {
					found = true;
					ret.push_back(i);
					notFinished.erase(i);
					for (auto p : parents[i])
						children[p].erase(i);
					break;
				}
			}
			if (!found)
				return vector<int>{};
		}
		return ret;
	}
};
*/
int main() {
	Solution s;
	vector<pair<int, int> > arr;
	arr.push_back(make_pair(1, 0));
	arr.push_back(make_pair(2, 0));
	arr.push_back(make_pair(3, 1));
	arr.push_back(make_pair(3, 2));
	vector<int> res = s.findOrder(4, arr);
	for (auto it : res)
		cout << it << ",";
}