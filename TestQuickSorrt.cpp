#include <iostream>
#include <fstream>
#include "functions.h"
#include <map>
#include "GenerateData.h"

using namespace std;

bool isPeriod(char* c)
{
    for (int i = 0; i < strlen(c); i++)
        if (c[i] == 46)
            return 1;
    return 0;
}

bool writeFile(const char* fileName, int* a, int size)
{
    ofstream fout(fileName, ios::out);
    if (!fout)
    {
        cout << "Cannot create file";
        return false;
    }
    fout << size << endl;
    for (int i = 0; i < size; i++)
    {
        fout << a[i] << " ";
    }
    cout << "Create file success!";
    fout.close();
    return true;
}

void fileout(const char* filename, int* a, int datasize)
{
    ofstream fout(filename, ios::out);
    fout << datasize << endl;
    for (int i = 0; i < datasize; i++) {
        fout << a[i] << " ";
    }
    fout.close();
}

void readData(const char* filename, int*& a, int& datasize)
{
    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Mo file khong thanh cong" << endl;
        return;
    }
    fin >> datasize;
    a = new int[datasize];
    for (int i = 0; i < datasize; i++)
    {
        fin >> a[i];
    }
    fin.close();
}

void copyArray2Array(int* a, int* b, int size)
{
    for (int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
}

void writeArray2File(const char* filename, int* a, int size)
{
    ofstream fout(filename, ios::out);
    fout << size << endl;
    for (int i = 0; i < size; i++)
    {
        fout << a[i] << " ";
    }
}

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-a") == 0)
    {
        cout << "ALGORITHM MODE\n";
        cout << "Algorithm: " << argv[2];
        if (argc == 5)
        {
            if (isPeriod(argv[3]) == true)
            {
                int datasize = 0;
                int* a = new int[datasize];
                readData(argv[3], a, datasize);
                cout << "Input file: " << argv[3] << endl;
                cout << "Input size: " << datasize << endl;
                cout << "-------------------" << endl;
                long long countCompare = 0;
                double time = 0;
                if (strcmp(argv[4], "-both") == 0) {
                    if (strcmp(argv[2], "selection-sort") == 0) {
                        selectionSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        selectionSortComparisons(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "merge-sort") == 0) {
                        mergeSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        mergeSortComparisons(a, 0, datasize - 1, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "insertion-sort") == 0) {
                        insertionSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        insertionSortComparisions(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "bubble-sort") == 0) {
                        bubbleSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        bubbleSortComparisions(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "heap-sort") == 0) {
                        heapSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        heapSortComparisons(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "quick-sort") == 0) {
                        quickSortTime(a, 0, datasize - 1, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        quickSortComparisions(a, 0, datasize - 1, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "radix-sort") == 0) {
                        radixSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                        delete[] a;
                        readData(argv[3], a, datasize);

                        radixSortComparisions(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                }
                else if (strcmp(argv[4], "-time") == 0) {
                    if (strcmp(argv[2], "selection-sort") == 0) {
                        selectionSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                    }
                    else if (strcmp(argv[2], "merge-sort") == 0) {
                        mergeSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                    }
                    else if (strcmp(argv[2], "insertion-sort") == 0) {
                        insertionSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                    }
                    else if (strcmp(argv[2], "bubble-sort") == 0) {
                        bubbleSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                    }
                    else if (strcmp(argv[2], "heap-sort") == 0) {
                        heapSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                    }
                    else if (strcmp(argv[2], "quick-sort") == 0) {
                        quickSortTime(a, 0, datasize - 1, time);
                        cout << "Running time: " << time << endl;

                    }
                    else if (strcmp(argv[2], "radix-sort") == 0) {
                        radixSortTime(a, datasize, time);
                        cout << "Running time: " << time << endl;

                    }
                }
                else {
                    if (strcmp(argv[2], "selection-sort") == 0) {

                        selectionSortComparisons(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "merge-sort") == 0) {

                        mergeSortComparisons(a, 0, datasize - 1, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "insertion-sort") == 0) {

                        insertionSortComparisions(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "bubble-sort") == 0) {

                        bubbleSortComparisions(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "heap-sort") == 0) {

                        heapSortComparisons(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "quick-sort") == 0) {

                        quickSortComparisions(a, 0, datasize - 1, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                    else if (strcmp(argv[2], "radix-sort") == 0) {

                        radixSortComparisions(a, datasize, countCompare);
                        cout << "Comparisons :" << countCompare;
                    }
                }
                fileout("output.txt", a, datasize);
            }
            else
            {
                cout << "\nInput size: " << argv[3] << endl << endl;
                map<int, string> DataOrder;
                DataOrder[0] = "Random Data";
                DataOrder[1] = "Sorted Data";
                DataOrder[2] = "Reverse Data";
                DataOrder[3] = "Nearly Sorted Data";
                for (int i = 0; i < 4; i++)
                {
                    int n = atoi(argv[3]);
                    int* a = new int[n];
                    int* b = new int[n];
                    GenerateData(a, n, i);
                    copyArray2Array(a, b, n);
                    cout << "\nInput order: " << DataOrder[i] << endl;
                    cout << "--------------------------------------\n";
                    double time = 0;
                    long long countCompare = 0;
                    if (strcmp(argv[4], "-time") == 0)
                    {
                        if (strcmp(argv[2], "bubble-sort") == 0)
                        {
                            bubbleSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                        }
                        else if (strcmp(argv[2], "insertion-sort") == 0)
                        {
                            insertionSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                        }
                        else if (strcmp(argv[2], "selection-sort") == 0)
                        {
                            selectionSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                        }
                        else if (strcmp(argv[2], "radix-sort") == 0)
                        {
                            radixSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                        }
                        else if (argv[2] == "quick-sort")
                        {
                            quickSortTime(a, 0, n - 1, time);
                            cout << "Time: " << time << endl;
                        }
                        else if (strcmp(argv[2], "merge-sort") == 0)
                        {
                            mergeSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                        }
                        else if (strcmp(argv[2], "heap-sort") == 0)
                        {
                            heapSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                        }
                    }
                    else if (strcmp(argv[4], "-comp") == 0)
                    {
                        if (strcmp(argv[2], "bubble-sort") == 0)
                        {
                            bubbleSortComparisions(a, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "insertion-sort") == 0)
                        {
                            insertionSortComparisions(a, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "selection-sort") == 0)
                        {
                            selectionSortComparisons(a, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "radix-sort") == 0)
                        {
                            radixSortComparisions(a, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (argv[2] == "quick-sort")
                        {
                            quickSortComparisions(a, 0, n - 1, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "merge-sort") == 0)
                        {
                            mergeSortComparisons(a, 0, n - 1, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "heap-sort") == 0)
                        {
                            heapSortComparisons(a, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                    }
                    else if (strcmp(argv[4], "-both") == 0)
                    {
                        if (strcmp(argv[2], "bubble-sort") == 0)
                        {
                            bubbleSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                            bubbleSortComparisions(b, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "insertion-sort") == 0)
                        {
                            insertionSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                            insertionSortComparisions(b, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "selection-sort") == 0)
                        {
                            selectionSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                            selectionSortComparisons(b, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "radix-sort") == 0)
                        {
                            radixSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                            radixSortComparisions(b, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (argv[2] == "quick-sort")
                        {
                            quickSortTime(a, 0, n - 1, time);
                            cout << "Time: " << time << endl;
                            quickSortComparisions(b, 0, n - 1, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "merge-sort") == 0)
                        {
                            mergeSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                            mergeSortComparisons(b, 0, n - 1, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                        else if (strcmp(argv[2], "heap-sort") == 0)
                        {
                            heapSortTime(a, n, time);
                            cout << "Time: " << time << endl;
                            heapSortComparisons(b, n, countCompare);
                            cout << "Compare: " << countCompare << endl;
                        }
                    }
                }
            }
        }
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        cout << "COMPARE MODE" << endl;
        cout << "Algorithm: ";

        if (argc == 5)
        {
            double time1, time2;
            long long comparisons1, comparisons2;
            time1 = time2 = 0;
            comparisons1 = comparisons2 = 0;
            int size = 0;
            int* a; int* b;
            readData(argv[4], a, size);
            readData(argv[4], b, size);

            if (strcmp(argv[2], "heap-sort") == 0)
            {
                cout << "heap-sort | ";
                heapSortComparisons(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                heapSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "selection-sort") == 0)
            {
                cout << "selection-sort | ";
                selectionSortComparisons(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                selectionSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "merge-sort") == 0)
            {
                cout << "merge-sort | ";
                mergeSortComparisons(a, 0, size - 1, comparisons1); // Đếm phép so sánh
                delete[] a;

                mergeSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "insertion-sort") == 0)
            {
                cout << "insertion-sort | ";
                insertionSortComparisions(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                insertionSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "bubble-sort") == 0)
            {
                cout << "bubble-sort | ";
                bubbleSortComparisions(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                bubbleSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "radix-sort") == 0)
            {
                cout << "radix-sort | ";
                radixSortComparisions(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                radixSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "quick-sort") == 0)
            {
                cout << "quick-sort | ";
                quickSortComparisions(a, 0, size - 1, comparisons1); // Đếm phép so sánh
                delete[] a;

                quickSortTime(b, 0, size - 1, time1);
                delete[] b;
            }
            else
                return -1;

            readData(argv[4], a, size);
            readData(argv[4], b, size);

            if (strcmp(argv[3], "heap-sort") == 0)
            {
                cout << "heap-sort" << endl;
                heapSortComparisons(a, size, comparisons2); // Đếm phép so sánh
                delete[] a;

                heapSortTime(b, size, time2);
                delete[] b;
            }
            else if (strcmp(argv[3], "selection-sort") == 0)
            {
                cout << "selection-sort" << endl;
                selectionSortComparisons(a, size, comparisons2); // Đếm phép so sánh
                delete[] a;

                selectionSortTime(b, size, time2);
                delete[] b;
            }
            else if (strcmp(argv[3], "merge-sort") == 0)
            {
                cout << "merge-sort" << endl;
                mergeSortComparisons(a, 0, size - 1, comparisons2); // Đếm phép so sánh
                delete[] a;

                mergeSortTime(b, size, time2);
                delete[] b;
            }
            else if (strcmp(argv[3], "insertion-sort") == 0)
            {
                cout << "insertion-sort" << endl;
                insertionSortComparisions(a, size, comparisons2); // Đếm phép so sánh
                delete[] a;

                insertionSortTime(b, size, time2);
                delete[] b;
            }
            else if (strcmp(argv[3], "bubble-sort") == 0)
            {
                cout << "bubble-sort" << endl;
                bubbleSortComparisions(a, size, comparisons2); // Đếm phép so sánh
                delete[] a;

                bubbleSortTime(b, size, time2);
                delete[] b;
            }
            else if (strcmp(argv[3], "radix-sort") == 0)
            {
                cout << "radix-sort" << endl;
                radixSortComparisions(a, size, comparisons2); // Đếm phép so sánh
                delete[] a;

                radixSortTime(b, size, time2);
                delete[] b;
            }
            else if (strcmp(argv[3], "quick-sort") == 0)
            {
                cout << "quick-sort" << endl;
                quickSortComparisions(a, 0, size - 1, comparisons2); // Đếm phép so sánh
                delete[] a;

                quickSortTime(b, 0, size - 1, time2);
                delete[] b;
            }
            else
                return -1;
            cout << "Input file: " << argv[4] << endl;
            cout << "Input size: " << size << endl;
            cout << "--------------------------" << endl;
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout << "Comparisons: " << comparisons1 << " | " << comparisons2 << endl;

        }
        else if (argc == 6)
        {
            double time1, time2;
            long long comparisons1, comparisons2;
            time1 = time2 = 0;
            comparisons1 = comparisons2 = 0;

            int size = atoi(argv[4]);
            int dataType = 0;
            if (strcmp(argv[5], "-rand") == 0) dataType = 0;
            else if (strcmp(argv[5], "-sorted") == 0) dataType = 1;
            else if (strcmp(argv[5], "-rev") == 0) dataType = 2;
            else if (strcmp(argv[5], "-nsorted") == 0) dataType = 3;
            else
                return -1;

            int* a = new int[size];
            int* b = new int[size];
            int* a_copy = new int[size];
            int* b_copy = new int[size];
            GenerateData(a, size, dataType);
            copyArray2Array(a, b, size);
            copyArray2Array(a, a_copy, size);
            copyArray2Array(a, b_copy, size);

            writeArray2File("input.txt", a, size);

            if (strcmp(argv[2], "heap-sort") == 0)
            {
                cout << "heap-sort | ";
                heapSortComparisons(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                heapSortTime(b, size, time1);
                writeArray2File("heap-sorted.txt", b, size);//In test thử kết quả sắp xếp
                delete[] b;
            }
            else if (strcmp(argv[2], "selection-sort") == 0)
            {
                cout << "selection-sort | ";
                selectionSortComparisons(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                selectionSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "merge-sort") == 0)
            {
                cout << "merge-sort | ";
                mergeSortComparisons(a, 0, size - 1, comparisons1); // Đếm phép so sánh
                delete[] a;

                mergeSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "insertion-sort") == 0)
            {
                cout << "insertion-sort | ";
                insertionSortComparisions(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                insertionSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "bubble-sort") == 0)
            {
                cout << "bubble-sort | ";
                bubbleSortComparisions(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                bubbleSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "radix-sort") == 0)
            {
                cout << "radix-sort | ";
                radixSortComparisions(a, size, comparisons1); // Đếm phép so sánh
                delete[] a;

                radixSortTime(b, size, time1);
                delete[] b;
            }
            else if (strcmp(argv[2], "quick-sort") == 0)
            {
                cout << "quick-sort | ";
                quickSortComparisions(a, 0, size - 1, comparisons1); // Đếm phép so sánh
                delete[] a;

                quickSortTime(b, 0, size - 1, time1);
                delete[] b;
            }
            else
                return -1;

            // Thuan toan 2
            if (strcmp(argv[3], "heap-sort") == 0)
            {
                cout << "heap-sort" << endl;
                heapSortComparisons(a_copy, size, comparisons2); // Đếm phép so sánh
                delete[] a_copy;

                heapSortTime(b_copy, size, time2);
                delete[] b_copy;
            }
            else if (strcmp(argv[3], "selection-sort") == 0)
            {
                cout << "selection-sort" << endl;
                selectionSortComparisons(a_copy, size, comparisons2); // Đếm phép so sánh
                delete[] a_copy;

                selectionSortTime(b_copy, size, time2);
                delete[] b_copy;
            }
            else if (strcmp(argv[3], "merge-sort") == 0)
            {
                cout << "merge-sort" << endl;
                mergeSortComparisons(a_copy, 0, size - 1, comparisons2); // Đếm phép so sánh
                delete[] a_copy;

                mergeSortTime(b_copy, size, time2);
                delete[] b_copy;
            }
            else if (strcmp(argv[3], "insertion-sort") == 0)
            {
                cout << "insertion-sort" << endl;
                insertionSortComparisions(a_copy, size, comparisons2); // Đếm phép so sánh
                delete[] a_copy;

                insertionSortTime(b_copy, size, time2);
                delete[] b_copy;
            }
            else if (strcmp(argv[3], "bubble-sort") == 0)
            {
                cout << "bubble-sort" << endl;
                bubbleSortComparisions(a_copy, size, comparisons2); // Đếm phép so sánh
                delete[] a_copy;

                bubbleSortTime(b_copy, size, time2);
                delete[] b_copy;
            }
            else if (strcmp(argv[3], "radix-sort") == 0)
            {
                cout << "radix-sort" << endl;
                radixSortComparisions(a_copy, size, comparisons2); // Đếm phép so sánh
                delete[] a_copy;

                radixSortTime(b_copy, size, time2);
                delete[] b_copy;
            }
            else if (strcmp(argv[3], "quick-sort") == 0)
            {
                cout << "quick-sort" << endl;
                quickSortComparisions(a_copy, 0, size - 1, comparisons2); // Đếm phép so sánh
                writeArray2File("quick-sort.txt", a_copy, size); // in test thử kết quá sau khi sắp xếp
                delete[] a_copy;

                quickSortTime(b_copy, 0, size - 1, time2);
                delete[] b_copy;
            }
            else
                return -1;
            cout << "Input size: " << size << endl;
            cout << "Input Order: " << argv[5] << endl;
            cout << "----------------------" << endl;
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout << "Comparisons: " << comparisons1 << " | " << comparisons2 << endl;
        }
    }
    return 0;
}

//int main()
//{
//    map<int, string> order;
//    order[0] = "random";
//    order[1] = "sorted";
//    order[2] = "reversed";
//    order[3] = "nearly";
//
//    int size[3] = { 10000, 50000, 300000 };
//
//    map<int, string> algorithm;
//    algorithm[0] = "bubble";
//    algorithm[1] = "insertion";
//    algorithm[2] = "selection";
//    algorithm[3] = "heap";
//    algorithm[4] = "radix";
//    algorithm[5] = "quick";
//    algorithm[6] = "merge";
//
//    for (int i = 0; i < 4; i++)
//    {
//        cout << order[i] << endl;
//        for (int j = 0; j < 3; j++)
//        {
//            cout << "SIZE: " << size[j] << endl;
//            int n = size[j];
//            int* arr = new int[n];
//            GenerateData(arr, n, i);
//            for (int k = 0; k < 7; k++)
//            {
//                double time = 0;
//                long long countCompare = 0;
//                if (algorithm[k] == "bubble")
//                {
//                    cout << algorithm[k] << endl;
//                    bubbleSortTime(arr, n, time);
//                    cout << "Time: " << time << endl;
//                    bubbleSortComparisions(arr, n, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//                else if (algorithm[k] == "insertion")
//                {
//                    cout << algorithm[k] << endl;
//                    insertionSortTime(arr, n, time);
//                    cout << "Time: " << time << endl;
//                    insertionSortComparisions(arr, n, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//                else if (algorithm[k] == "selection")
//                {
//                    cout << algorithm[k] << endl;
//                    selectionSortTime(arr, n, time);
//                    cout << "Time: " << time << endl;
//                    selectionSortComparisons(arr, n, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//                else if (algorithm[k] == "heap")
//                {
//                    cout << algorithm[k] << endl;
//                    heapSortTime(arr, n, time);
//                    cout << "Time: " << time << endl;
//                    heapSortComparisons(arr, n, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//                else if (algorithm[k] == "radix")
//                {
//                    cout << algorithm[k] << endl;
//                    radixSortTime(arr, n, time);
//                    cout << "Time: " << time << endl;
//                    radixSortComparisions(arr, n, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//                else if (algorithm[k] == "merge")
//                {
//                    cout << algorithm[k] << endl;
//                    mergeSortTime(arr, n, time);
//                    cout << "Time: " << time << endl;
//                    mergeSortComparisons(arr, 0, n - 1, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//                else if (algorithm[k] == "quick")
//                {
//                    cout << algorithm[k] << endl;
//                    quickSortTime(arr, 0, n-1, time);
//                    cout << "Time: " << time << endl;
//                    quickSortComparisions(arr, 0, n - 1, countCompare);
//                    cout << "Compare: " << countCompare << endl;
//                }
//
//            }
//            delete[] arr;
//            cout << "------------------------\n";
//        }
//        cout << "-------------------------\n";
//    }
//
//    return 0;
//}