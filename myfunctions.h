#ifndef myfunctions
#define myfunctions

#include <iostream>
#include <chrono>
#include <vector>
#include<fstream>
using namespace std;
using namespace std::chrono;

void bubbleSort(int* a, int n);

void bubbleSortTime(int* a, int n, double& time);

void bubbleSortComparisions(int* a, int n, long long& countCompare);

int soChuSo(int n);

void radixSort(int* a, int n);

void radixSortTime(int* a, int n, double& time);

void radixSortComparisions(int* a, int n, long long& countCompare);

void selectionSort(int* a, int n);
void selectionSortTime(int* a, int datasize, double& time);
void selectionSortComparisons(int* a, int n, long long& countCompare);
void merge(int*& a, int left, int mid, int right);
void mergeSort(int* a, int begin, int end);
void mergeSortTime(int* a, int datasize, double& time);
void mergeComparisons(int*& a, int left, int mid, int right, long long& countCompare);
void mergeSortComparisons(int* a, int begin, int end, long long& countCompare);
void insertionSort(int* arr, int n);
void insertionSortTime(int* a, int n, double& time);
void insertionSortComparisions(int* arr, int n, long long& countCompare);
void heapify(int*& a, int n, int i);
void heapSort(int*& a, int n);
void heapifyComparisons(int* a, int n, int i, long long& countCompare);
void heapSortComparisons(int* a, int n, long long& countCompare);
void heapSortTime(int* a, int datasize, double& time);
int partition(int* a, int low, int high);
void quickSort(int* a, int low, int high);
int partionForComparisions(int* a, int low, int high, long long& countCompare);
void quickSortComparisions(int* a, int low, int high, long long& countCompare);
void quickSortTime(int* a, int low, int high, double& time);

bool isPeriod(char* c);

void fileout(const char* filename, int* a, int datasize);
void readData(const char* filename, int*& a, int& datasize);
void copyArray2Array(int* a, int*& b, int n);
#endif myfunctions
