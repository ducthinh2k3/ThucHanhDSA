#include "myfunctions.h"

void selectionSort(int* a, int n)
{
    int min_idx = 0;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            swap(a[min_idx], a[i]);
        }
    }
}

void selectionSortTime(int* a, int datasize, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    selectionSort(a, datasize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}

void selectionSortComparisons(int* a, int n, long long& countCompare)
{
    int min_idx = 0;
    for (int i = 0; ++countCompare && i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; ++countCompare && j < n; j++) {
            if (++countCompare && a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (++countCompare && i != min_idx) {
            swap(a[min_idx], a[i]);
        }
    }
}

void merge(int*& a, int left, int mid, int right)
{
    int nb = mid - left + 1;
    int nc = right - mid;
    int* b = new int[nb];
    int* c = new int[nc];
    for (int i = 0; i < nb; i++) {
        b[i] = a[left + i];
    }
    for (int j = 0; j < nc; j++) {
        c[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, count = left;
    while (i < nb && j < nc) {
        if (b[i] < c[j]) {
            a[count] = b[i];
            i++;
        }
        else {
            a[count] = c[j];
            j++;
        }
        count++;
    }
    while (i < nb) {
        a[count++] = b[i++];
    }
    while (j < nc) {
        a[count++] = c[j++];
    }
    delete[] b;
    delete[] c;
}

void mergeSort(int* a, int begin, int end)
{
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    mergeSort(a, begin, mid);
    mergeSort(a, mid + 1, end);
    merge(a, begin, mid, end);
}

void mergeSortTime(int* a, int datasize, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    mergeSort(a, 0, datasize - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}

void mergeComparisons(int*& a, int left, int mid, int right, long long& countCompare)
{
    int nb = mid - left + 1;
    int nc = right - mid;
    int* b = new int[nb];
    int* c = new int[nc];
    for (int i = 0; ++countCompare && i < nb; i++) {
        b[i] = a[left + i];
    }
    for (int j = 0; ++countCompare && j < nc; j++) {
        c[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, count = left;
    while ((++countCompare && i < nb) && (++countCompare && j < nc)) {
        if (++countCompare && b[i] < c[j]) {
            a[count] = b[i];
            i++;
        }
        else {
            a[count] = c[j];
            j++;
        }
        count++;
    }
    while (++countCompare && i < nb) {
        a[count++] = b[i++];
    }
    while (++countCompare && j < nc) {
        a[count++] = c[j++];
    }
    delete[] b;
    delete[] c;
}

void mergeSortComparisons(int* a, int begin, int end, long long& countCompare)
{
    if (++countCompare && begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    mergeSortComparisons(a, begin, mid, countCompare);
    mergeSortComparisons(a, mid + 1, end, countCompare);
    mergeComparisons(a, begin, mid, end, countCompare);
}

void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortTime(int* a, int n, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    insertionSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}

void insertionSortComparisions(int* arr, int n, long long& countCompare)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        countCompare++;
        key = arr[i];
        j = i - 1;
        //
        if (j >= 0)
        {
            countCompare++;
        }
        else
        {
            countCompare += 2;
        }
        //
        while (j >= 0 && arr[j] > key)
        {
            //
            countCompare += 2;
            //
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int* a, int n)
{
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void bubbleSortTime(int* a, int n, double& time)
{
    auto start = high_resolution_clock::now();
    bubbleSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}

void bubbleSortComparisions(int* a, int n, long long& countCompare)
{
    countCompare = 0;
    for (int i = n - 1; ++countCompare && i > 0; i--)
        for (int j = 0; ++countCompare && j < i; j++)
            if (++countCompare && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

int soChuSo(int n)
{
    int i = 0;
    if (n == 0)
        return 1;
    while (n)
    {
        i++;
        n /= 10;
    }

    return i;
}

int soChuSoComparisons(int n, long long& countCompare)
{
    int i = 0;
    if (++countCompare && n == 0)
        return 1;
    while (++countCompare && n > 0)
    {
        i++;
        n /= 10;
    }

    return i;
}

void radixSort(int* a, int n)
{
    vector<int> chuSo[10];
    int soChuSoLonNhat = 0;
    for (int i = 0; i < n; i++)
    {
        int j = soChuSo(a[i]);
        if (j > soChuSoLonNhat)
            soChuSoLonNhat = j;
    }
    for (int i = 1; i <= soChuSoLonNhat; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Tinh chu so hang thu i
            int k = (a[j] / (int)pow(10, i - 1)) % 10;
            chuSo[k].push_back(a[j]);
        }
        int j = 0;
        for (int k = 0; k < 10; k++)
        {
            for (int temp = 0; temp < chuSo[k].size(); temp++)
                a[j++] = chuSo[k].at(temp);
            chuSo[k].clear();
        }
    }
}

void radixSortTime(int* a, int n, double& time)
{
    auto start = high_resolution_clock::now();
    radixSort(a, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}

void radixSortComparisions(int* a, int n, long long& countCompare)
{
    countCompare = 0;
    vector<int> chuSo[10];
    int soChuSoLonNhat = 0;
    for (int i = 0; ++countCompare && i < n; i++)
    {
        int j = soChuSoComparisons(a[i], countCompare);
        if (++countCompare && j > soChuSoLonNhat)
            soChuSoLonNhat = j;
    }
    for (int i = 1; ++countCompare && i <= soChuSoLonNhat; i++)
    {
        for (int j = 0; ++countCompare && j < n; j++)
        {
            // Tinh chu so hang thu i
            int k = (a[j] / (int)pow(10, i - 1)) % 10;
            chuSo[k].push_back(a[j]);
        }
        int j = 0;
        for (int k = 0; ++countCompare && k < 10; k++)
        {
            for (int temp = 0; ++countCompare && temp < chuSo[k].size(); temp++)
                a[j++] = chuSo[k].at(temp);
            chuSo[k].clear();
        }
    }
}

void heapify(int*& a, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root 
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(a, n, largest);
    }
}

// main function to do heap sort 
void heapSort(int*& a, int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end 
        swap(a[0], a[i]);

        // call max heapify on the reduced heap 
        heapify(a, i, 0);
    }
}

void heapifyComparisons(int* a, int n, int i, long long& countCompare)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if ((++countCompare && l < n) && (++countCompare && a[l] > a[largest]))
        largest = l;

    // If right child is larger than largest so far 
    if ((++countCompare && r < n) && (++countCompare && a[r] > a[largest]))
        largest = r;

    // If largest is not root 
    if (++countCompare && largest != i)
    {
        swap(a[i], a[largest]);

        // Recursively heapify the affected sub-tree 
        heapifyComparisons(a, n, largest, countCompare);
    }
}

void heapSortComparisons(int* a, int n, long long& countCompare)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; (++countCompare && i >= 0); i--)
        heapifyComparisons(a, n, i, countCompare);

    // One by one extract an element from heap 
    for (int i = n - 1; (++countCompare && i > 0); i--)
    {
        // Move current root to end 
        swap(a[0], a[i]);

        // call max heapify on the reduced heap 
        heapifyComparisons(a, i, 0, countCompare);
    }
}

void heapSortTime(int* a, int datasize, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    heapSort(a, datasize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}


/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
int partitionComparisions(int* a, int low, int high, long long& countCompare)
{
    int pivot = a[high];    // pivot
    int left = low;
    int right = high - 1;
    while (++countCompare && true) {
        while ((++countCompare && left <= right) && (++countCompare && a[left] < pivot)) left++; // Tìm phần tử >= arr[pivot]
        while ((++countCompare && right >= left) && (++countCompare && a[right] > pivot)) right--; // Tìm phần tử <= arr[pivot]
        if (++countCompare && left >= right) break; // Đã duyệt xong thì thoát vòng lặp
        swap(a[left], a[right]); // Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(a[left], a[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
void quickSortComparisions(int* a, int low, int high, long long& countCompare)
{
    if (++countCompare && low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(a, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSortComparisions(a, low, pi - 1,countCompare);
        quickSortComparisions(a, pi + 1,high, countCompare);
    }
}
int partition(int* a, int low, int high)
{
    int pivot = a[high];    // pivot
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && a[left] < pivot) left++; // Tìm phần tử >= arr[pivot]
        while (right >= left && a[right] > pivot) right--; // Tìm phần tử <= arr[pivot]
        if (left >= right) break; // Đã duyệt xong thì thoát vòng lặp
        swap(a[left], a[right]); // Nếu chưa xong, đổi chỗ.
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(a[left], a[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đổi mảng
}
void quickSort(int* a, int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(a, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
void quickSortTime(int* a, int low, int high, double& time)
{
    auto start = chrono::high_resolution_clock::now();
    quickSort(a, low, high);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    time = duration.count();
}
bool isPeriod(char* c)
{
    for (int i = 0; i < strlen(c); i++)
        if (c[i] == 46)
            return 1;
    return 0;
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
void copyArray2Array(int* a, int*& b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
