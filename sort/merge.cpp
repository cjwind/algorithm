#include <vector>
#include <iostream>

using namespace std;

vector<int> merge(vector<int> nums1, vector<int> nums2) {
	vector<int> sorted;
	int i = 0, j = 0;

	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] < nums2[j]) {
			sorted.push_back(nums1[i]);
			i++;
		}
		else if (nums1[i] > nums2[j]) {
			sorted.push_back(nums2[j]);
			j++;
		}
		else {
			sorted.push_back(nums1[i]);
			sorted.push_back(nums2[j]);
			i++;
			j++;
		}
	}

	while (i < nums1.size()) {
		sorted.push_back(nums1[i]);
		i++;
	}

	while (j < nums2.size()) {
		sorted.push_back(nums2[j]);
		j++;
	}

	return sorted;
}

vector<int> mergeSort(vector<int> numbers, int start, int end) {
	if (start == end - 1) {
		vector<int> sorted;
		sorted.push_back(numbers[start]);
		return sorted;
	}

	int size = end - start;

	vector<int> sorted1 = mergeSort(numbers, start, start + size / 2);
	vector<int> sorted2 = mergeSort(numbers, start + size / 2, end);

	return merge(sorted1, sorted2);
}

int main() {
	// int nums[] = {16, 2, 77, 29, 21, 62, 12, 74, 85};
	int nums[] = {100, 94, 84, 74, 52, 32, 20, 11};
	//int nums[] = {1, 2, 3, 4, 5, 6, 52, 75, 100};
	vector<int> numbers(nums, nums + sizeof(nums) / sizeof(int));

	numbers = mergeSort(numbers, 0, numbers.size());

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

	return 0;
}
