#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &numbers) {
	for (int i = 1; i < numbers.size(); i++) {
		int tmp = numbers[i];
		int j = 0;

		for (j = i - 1; j >= 0; j--) {
			if (numbers[j] > tmp) {
				numbers[j + 1] = numbers[j];
			}
			else {
				break;
			}
		}

		numbers[j + 1] = tmp;
	}
}

int main() {
	int nums[] = {16, 2, 77, 29, 21, 62, 12, 74, 85};
	// int nums[] = {100, 94, 84, 74, 52, 32, 20, 11};
	// int nums[] = {1, 2, 3, 4, 5, 6, 52, 75, 100};
	// int nums[] = {99, 98, 87, 76, 64, 43, 32, 22, 18, 15, 15, 15, 15, 14, 12, 8, 3, 2, 2, 2, 1, 1, 1};
	vector<int> numbers(nums, nums + sizeof(nums) / sizeof(int));

	insertionSort(numbers);

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << (*iter) << " ";
	}
	cout << endl;

	return 0;
}