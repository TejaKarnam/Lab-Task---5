#include <iostream>
using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(a[i] <= pivot && i < high)
        {
            i++;
        }

        while(a[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int j = partition(a, low, high);

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}