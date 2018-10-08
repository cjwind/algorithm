#include <vector>
#include <iostream>

using namespace std;

void selectionSort(vector<int> &numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		int min = numbers[i];
		int minJ = i;

		for (int j = i + 1; j < numbers.size(); j++) {
			if (min > numbers[j]) {
				min = numbers[j];
				minJ = j;
			}
		}

		if(minJ != i) {
			int tmp = numbers[minJ];
			numbers[minJ] = numbers[i];
			numbers[i] = tmp;
		}
	}
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

	selectionSort(numbers);

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

	return 0;
}