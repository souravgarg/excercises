#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class FindDuplicate {
	public:
	void find_duplicate(vector<int> input_array) {
		int size = input_array.size();
		if (size < 2) {
			cout << "No duplicate element exist" << endl;
			return;
		}
		map<int, int> arr_map;
		for (int i = 0; i < size; i++) {
				arr_map[input_array[i]]++;
		}

		// pair is used for storing the duplicate element and its count
		// in the input array.
		vector<pair<int, int> > dup_val_pairs;
		map<int, int>:: iterator i;
		for (i = arr_map.begin(); i != arr_map.end(); i++) {
			// Store duplicate elements in dup_val_pairss.
			if (i->second > 1)
				dup_val_pairs.push_back(make_pair(i->first, i->second));
		}

		int dup_size = dup_val_pairs.size();
		if (dup_size == 0) {
			cout << "No duplicate element exist" << endl;
			return;
		}

		// Sort the dup_val_pairs in non-increasing order.
		sort(dup_val_pairs.begin(), dup_val_pairs.end(), rev_sort);
		for(int i = 0; i < dup_size; i++) {
			cout << dup_val_pairs[i].first << endl;
		}
	}

	static bool rev_sort(const pair<int, int> &i, const pair<int, int> &j) {
		if (i.second > j.second)
			return true;
		return false;
	}
};

int main() {
	FindDuplicate *test_object = new FindDuplicate();
	
	vector<int> test_input;	
	test_input.push_back(2);
	test_input.push_back(2);
	test_input.push_back(3);
	test_input.push_back(3);
	test_input.push_back(3);
	test_input.push_back(2);
	test_input.push_back(1);
	test_input.push_back(2);
	test_input.push_back(3);
	test_input.push_back(5);
	test_input.push_back(3);
	test_input.push_back(1);
	test_input.push_back(2);
	test_input.push_back(2);
	test_input.push_back(3);
	test_input.push_back(7);
	test_input.push_back(3);
	test_input.push_back(7);
	test_input.push_back(12);
	test_input.push_back(2);
	test_input.push_back(31);
	test_input.push_back(52);
	test_input.push_back(31);
	test_input.push_back(11);

	test_object->find_duplicate(test_input); 
}
