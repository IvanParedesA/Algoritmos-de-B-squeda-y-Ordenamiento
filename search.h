// =================================================================
//
// File: search.h
// Author: Pedro Perez
// Description: This file contains the implementations of the
//				sequential and binary search algorithms.
//
//Complejidad: O(n)
//Por tener un solo ciclo for
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef SEARCH_H
#define SEARCH_H

#include "header.h"
#include <vector>

template <class T>
pair<int, int> sequentialSearch(const std::vector<T> &v, T key) {
	int contador=0;
	for (int i = 0; i < v.size(); i++) {
		contador++;
		if (v[i] == key) {
			return pair<int, int> (i, contador);
		}
	}
	return pair<int, int> (-1, contador);
}
template <class T>
pair<int, int> binarySearch(const std::vector<T> &v, T key) {
	int low, high, mid;
	int contador=0;
	low = 0;
	high = v.size() - 1;
	while (low <= high) {
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		contador++;
		if (key == v[mid]) {
			return pair<int, int> (mid, contador);
		} else if (key < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return pair<int, int> (-1, contador);
}
template <class T>
int binaryRSearch(const std::vector<T> &v, int low, int high, T key) {
	int mid;
	int contador=0;
	if (low > high) {
		return -1;
	} else {
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		if (key == v[mid]) {
			return mid;
		} else if (key < v[mid]) {
			return binaryRSearch(v, low, mid - 1, key);
		} else {
			return binaryRSearch(v, mid + 1, high, key);
		}
	}
}

#endif /* SEARCH_H */