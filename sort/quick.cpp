#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector<int> &numbers, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = numbers[start];
	int i = start + 1, j = end;

	while (i < j) {
		while (i < j && numbers[i] <= pivot) i++;
		while (i < j && numbers[j] >= pivot) j--;

		if (i < j) {
			int tmp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = tmp;

			i++;
			j--;
		}
		else {
			break;
		}
	}

	int idx = (numbers[i] > pivot) ? i - 1 : i;

	numbers[start] = numbers[idx];
	numbers[idx] = pivot;

	quickSort(numbers, start, idx - 1);
	quickSort(numbers, idx + 1, end);
}

int main() {
	// int nums[] = {16, 2, 77, 29, 21, 62, 12, 74, 85};
	// int nums[] = {100, 94, 84, 74, 52, 32, 20, 11};
	// int nums[] = {1, 2, 3, 4, 5, 6, 52, 75, 100, 111, 222, 345};
	int nums[] = {99, 98, 87, 76, 64, 43, 32, 22, 18, 15, 15, 15, 15, 14, 12, 8, 3, 2, 2, 2, 1, 1, 1};
	vector<int> numbers(nums, nums + sizeof(nums) / sizeof(int));

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;
	cout << "=============" << endl;

	quickSort(numbers, 0, numbers.size() - 1);

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

	return 0;
}