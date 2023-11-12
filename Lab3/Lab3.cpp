#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "Sorts.cpp"

int Length = 300;

std::vector<std::vector<int>> GenDataForQuickSort() {
	std::vector<std::vector<int>> test_data;

	for (int i = 1; i <= Length; i++) {
		std::vector<int> data(i);
		for (int j = 0; j < i; j++) data[j] = std::rand() % 1000000;
		test_data.push_back(data);
	}

	return test_data;
}

std::vector<std::vector<int>> GenDataForInsertionSort() {
	std::vector<std::vector<int>> test_data;

	for (int i = 1; i <= Length; i++) {
		std::vector<int> data(i);
		int base = std::rand() % 1000000;
		for (int j = 0; j < i; j++) data[j] = base - j;
		test_data.push_back(data);
	}

	return test_data;
}

std::vector<double> QuickSortTimeCount(std::vector<std::vector<int>>& test_data) {
	std::vector<double> sort_times;
	for (int i = 0; i < test_data.size(); i++) {
		std::vector<int> tmp = test_data[i];
		auto start = std::chrono::high_resolution_clock::now();
		QuickSort(tmp.data(), tmp.data() + tmp.size(), [](const int& a, const int& b) { return a < b; });
		auto end = std::chrono::high_resolution_clock::now();
		double total_time = std::chrono::duration<double, std::micro>(end - start).count();
		sort_times.push_back(total_time);
	}
	return sort_times;
}

std::vector<double> InsertionSortTimeCount(std::vector<std::vector<int>>& test_data) {
	std::vector<double> sort_times;
	for (int i = 0; i < test_data.size(); i++) {
		std::vector<int> tmp = test_data[i];
		auto start = std::chrono::high_resolution_clock::now();
		InsertionSort(tmp.data(), tmp.data() + tmp.size(), [](const int& a, const int& b) { return a < b; });
		auto end = std::chrono::high_resolution_clock::now();
		double total_time = std::chrono::duration<double, std::micro>(end - start).count();
		sort_times.push_back(total_time);
	}
	return sort_times;
}

void PrintTimes() {
	int N = 5000;
	std::vector<double> quick_sort_times(Length);
	std::vector<double> insert_sort_times(Length);
	std::vector<double> tmp_times(Length);
	// "разгон" CPU
	for (int i = 0; i < N; i++) {
		std::vector<std::vector<int>> test_data = GenDataForQuickSort();
		QuickSortTimeCount(test_data);
	}
	// замер времени
	for (int i = 0; i < N; i++) {
		std::vector<std::vector<int>> test_data1 = GenDataForQuickSort();
		tmp_times = QuickSortTimeCount(test_data1);
		for (int j = 0; j < Length; j++) {
			quick_sort_times[j] += tmp_times[j];
		}

		std::vector<std::vector<int>> test_data2 = GenDataForInsertionSort();
		tmp_times = InsertionSortTimeCount(test_data2);
		for (int j = 0; j < Length; j++) {
			insert_sort_times[j] += tmp_times[j];
		}
	}
	// вывод
	std::ofstream file1("QS_time.txt");
	std::ofstream file2("IS_time.txt");
	
	if (file1.is_open() && file2.is_open()) {
		for (int j = 0; j < Length; j++) {
			quick_sort_times[j] /= N;
			file1 << quick_sort_times[j] << std::endl;

			insert_sort_times[j] /= N;
			file2 << insert_sort_times[j] << std::endl;
		}
		file1.close();
		file2.close();
	}
}

int main()
{
	PrintTimes();
	//for (int i = 1; i <= Length; i++) std::cout << i << std::endl;
    return 0;
}