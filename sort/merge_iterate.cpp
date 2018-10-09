#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> sorted;
	int i = 0, j = 0;

	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			sorted.push_back(a[i]);
			i++;
		}
		else if (a[i] == b[j]) {
			sorted.push_back(a[i]);
			sorted.push_back(b[j]);
			i++;
			j++;
		}
		else {
			sorted.push_back(b[j]);
			j++;
		}
	}

	while (i < a.size()) {
		sorted.push_back(a[i]);
		i++;
	}

	while (j < b.size()) {
		sorted.push_back(b[j]);
		j++;
	}

	return sorted;
}

vector<int> mergeSort(vector<int> numbers) {
	queue<vector<int> > sortedSegs;

	for (int i = 0; i < numbers.size(); i++) {
		vector<int> seg;
		seg.push_back(numbers[i]);
		sortedSegs.push(seg);
	}

	while (sortedSegs.size() > 1) {
		vector<int> seg1 = sortedSegs.front();
		sortedSegs.pop();

		vector<int> seg2 = sortedSegs.front();
		sortedSegs.pop();

		sortedSegs.push(merge(seg1, seg2));
	}

	return sortedSegs.front();
}

int main() {
	// int nums[] = {16, 2, 77, 29, 21, 62, 12, 74, 85};
	// int nums[] = {100, 94, 84, 74, 52, 32, 20, 11};
	// int nums[] = {1, 2, 3, 4, 5, 6, 52, 75, 100};
	int nums[] = {99, 98, 87, 76, 64, 43, 32, 22, 18, 15, 15, 15, 15, 14, 12, 8, 3, 2, 2, 2, 1, 1, 1};
	vector<int> numbers(nums, nums + sizeof(nums) / sizeof(int));

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;
	cout << "=============" << endl;

	numbers = mergeSort(numbers);

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

	return 0;
}