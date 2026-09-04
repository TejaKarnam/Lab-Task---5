#include <iostream>
using namespace std;

void insertionSort(int bucket[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = bucket[i];
        int j = i - 1;

        while(j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(int a[], int n)
{
    int bucket[10][100] = {0};
    int count[10] = {0};

    int max = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        int index = (a[i] * 10) / (max + 1);
        bucket[index][count[index]] = a[i];
        count[index]++;
    }

    for(int i = 0; i < 10; i++)
    {
        insertionSort(bucket[i], count[i]);
    }

    int k = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    bucketSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}