/**********************************************************************
 * Copyright (c) 2023
 *  Joowon park <ghonman2@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include "PmergeMe.hpp"

double calc_diff_time(struct timeval x, struct timeval y) {
	double x_us, y_us, diff;

	x_us = (double)x.tv_sec * 1000000 + (double)x.tv_usec;
	y_us = (double)y.tv_sec * 1000000 + (double)y.tv_usec;

	diff = (double)y_us - (double)x_us;

	return diff;
}

static void insertionSortVector(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

static void mergeVector(std::vector<int>& arr, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<int> L(n1), R(n2);

	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	i = 0; j = 0; k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

static void __PmergeMeVector(std::vector<int>& arr, int left, int right, int k) {
	if (left >= right) {
		return;
	}
	if ((right - left + 1) <= k) {
		insertionSortVector(arr, left, right);
		return;
	}

	int mid = left + (right - left) / 2;
	__PmergeMeVector(arr, left, mid, k);
	__PmergeMeVector(arr, mid + 1, right, k);
	mergeVector(arr, left, mid, right);
}


void PmergeMeVector(std::vector<int> &numbers, int rate)
{
	struct timeval start, end;
	double times;

	gettimeofday(&start, NULL);
	__PmergeMeVector(numbers,0, numbers.size() - 1,rate);
	gettimeofday(&end, NULL);
	times = calc_diff_time(start, end);
	std::cout << "Time to process a range of "<< numbers.size() <<" elements with std::vector :" << times  << "us"<< std::endl;
	return ;
}

static void insertionSortDeque(std::deque<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

static void mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::deque<int> L(n1), R(n2);

	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	i = 0; j = 0; k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

static void __PmergeMeDeque(std::deque<int>& arr, int left, int right, int k) {
	if (left >= right) {
		return;
	}
	if ((right - left + 1) <= k) {
		insertionSortDeque(arr, left, right);
		return;
	}

	int mid = left + (right - left) / 2;
	__PmergeMeDeque(arr, left, mid, k);
	__PmergeMeDeque(arr, mid + 1, right, k);
	mergeDeque(arr, left, mid, right);
}

void PmergeMeDeque(std::deque<int> &numbers, int rate)
{
	struct timeval start, end;
	double times;

	gettimeofday(&start, NULL);
	__PmergeMeDeque(numbers,0, numbers.size() -1, rate);
	gettimeofday(&end, NULL);
	std::cout << "After: ";
	for (size_t i = 0; i < numbers.size(); i ++)
		std::cout << " "<< numbers[i];
	std::cout << std::endl;
	times = calc_diff_time(start, end);
	std::cout << "Time to process a range of "<< numbers.size() <<" elements with std::deque :" << times << "us"<< std::endl;
	return ;
}
