#include <bits/stdc++.h>
using namespace std;
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Best Case: Theta(n log n)
// Average Case: O(n log n)
// Worst Case: Theta(n^2)

// Using Lomuto Partitioning+

int lPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lPartition(arr, l, h);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, h);
    }
}

// Using HOARE'S Partitioning
int hPartition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void qSort2(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = hPartition(arr, l, h);
        qSort2(arr, l, p); // This is where qSort (Hoare's) differs from qSort(Lomuto)
        qSort2(arr, p + 1, h);
    }
}
int main()
{
    FIO int arr1[] = {5, 8, 1, 6, 3};
    int arr2[] = {9, 2, 4, 3, 6};
    qSort(arr1, 0, 4);
    qSort2(arr2, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr1[i] << " ";

    cout << endl;
    
    for (int j = 0; j < 5; j++)
        cout << arr2[j] << " ";

    return 0;
}
