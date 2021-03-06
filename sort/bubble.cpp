#include <vector>
#include <iostream>

using namespace std;

void bubbleSort(vector<int> &numbers) {
	for (int i = 1; i <= numbers.size() - 1; i++) {
		bool swap = false;

		for (int j = 0; j < numbers.size() - i; j++) {
			if (numbers[j] > numbers[j + 1]) {
				int tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;

				swap = true;
			}
		}

		if (!swap) {
			break;
		}
	}
}

int main() {
	int nums[] = {16, 2, 77, 29, 21, 62, 12, 74, 85};
	// int nums[] = {100, 94, 84, 74, 52, 32, 20, 11};
	// int nums[] = {1, 2, 3, 4, 5, 6, 52, 75, 100, 111, 222, 345};
	// int nums[] = {99, 98, 87, 76, 64, 43, 32, 22, 18, 15, 15, 15, 15, 14, 12, 8, 3, 2, 2, 2, 1, 1, 1};
	vector<int> numbers(nums, nums + sizeof(nums) / sizeof(int));

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;
	cout << "=============" << endl;

	bubbleSort(numbers);

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

	return 0;
}