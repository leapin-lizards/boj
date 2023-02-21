#include <stdio.h>
#include <stdlib.h>
long count = 0;
long sorted[5000000];
long arr[5000000];
long n, k2;
bool finished = false;
void merge(long *data, long start, long mid, long end)
{
    long i = start;
    long j = mid + 1;
    long k = start;

    while (i <= mid && j <= end)
    {
        if (data[i] <= data[j])
        {
            sorted[k] = data[i];
            i++;
        }
        else
        {
            sorted[k] = data[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        for (long t = j; t <= end; t++)
        {
            sorted[k] = data[t];
            k++;
        }
    }
    else
    {
        for (long t = i; t <= mid; t++)
        {
            sorted[k] = data[t];
            k++;
        }
    }
    for (long t = start; t <= end; t++)
    {
        data[t] = sorted[t];
        if (count == k2 - 1)
        {
            printf("%ld\n", data[t]);
            finished = true;
        }
        count++;
    }
}

void mergeSort(long *data, long start, long end)
{
    if (start < end)
    {
        long mid = (start + end) / 2;
        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

int main()
{
    scanf("%ld %ld", &n, &k2);
    for (long i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);

    if (!finished)
    {
        printf("-1");
    }
    return 0;
}