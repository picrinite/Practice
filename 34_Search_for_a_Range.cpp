/* Question

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]

*/

#include <iostream>
#include <string>
#include  <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//103125, my own method , easy for me to understand and code
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		int left = 0, right = nums.size() - 1, mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if (nums[left] != target) {
			ret.insert(ret.begin(), 2, -1);
			return ret;
		}
		ret.push_back(left);
		left = 0;
		right = nums.size() - 1;
		while (left < right) {
			mid = left + (right - mid) / 2 + 1;    // Here is the trick to avoid dead loop
			if (nums[mid] <= target)
				left = mid;
			else
				right = mid - 1;
		}
		ret.push_back(left);
		return ret;
	}
};
// 102515  Yiran's reference
// https://github.com/avocadoccme/leetcode-practice/blob/master/Search%20for%20a%20Range.py
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		int len = nums.size();
		int start = 0, end = len - 1, mid;
		// start will the first number equal to target
		// after while loop, start = end
		while (start < end) {
			mid = start + (end - start) / 2;  // to avoid dead loop, let start change by 1
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (nums[start] != target) {
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		ret.push_back(start);
		start = 0;
		end = len;
		// after while loop, start = end, which will point to the number larger than target
		while (start < end) {
			mid = start + (end - start) / 2;
			if (nums[mid] > target)
				end = mid;
			else
				start = mid + 1;
		}
		ret.push_back(end - 1);
		return ret;
	}
};
// easy to code version
/*
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left, right, mid, start, end;
        vector<int> res;
        start = -1;
        end = -1;
        left = 0;
        right = n - 1;
        while( left <= right ){   
            mid =( left + right ) / 2;
            if( A[mid] == target ){
                start = mid;
                right = mid - 1;
            }
            else if( A[mid] < target )
                left = mid + 1;
            else
                right = mid - 1;          
        }
        left = 0;
        right = n - 1;
        while( left <= right ){   
            mid =( left + right ) / 2;
            if( A[mid] == target ){
                end = mid;
                left = mid + 1;
            }
            else if( A[mid] < target )
                left = mid + 1;
            else
                right = mid - 1;          
        }
        res.push_back( start );
        res.push_back( end );
        return res;
    }
};
*/
int main(){
	Solution s;
	int A[6]={5,7,7,8,8,10};
	vector<int> res(A, A + 6);
	res = s.searchRange(res, 10);
	cout << res[0] << "," << res[1] << endl;
	return 0;
}


/*
//int v1[12] = {4, 9, 8, 6,5,1,4,4,4,4,9,9 };
	int v1[12] = {9,9,9,9,9,9,9,9,9,9,9,9 };
	vector<int> num ( &v1[0] , &v1[12] );
	*/
/*
ListNode one(1), two(2),three(3),four(4),five(5);
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	ListNode *res;
	res = s.removeNthFromEnd( &one, 2 ) ;
	while( res ){
		cout << res->val << endl;
		res = res->next;
	}
	for( int i = 0; i < size ; ++i ){
		cout << v1[i] << "," ;
	}

*/
