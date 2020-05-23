// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"

// void insert(int idx, int num, int arr[], int &len)
// {
//     int *temp = new int[len + 1];
//     temp[idx] = num;
//     for (int i = 0; i < idx; i++)
//     {
//         temp[i] = arr[i];
//     }
//     for (int i = idx; i < len; i++)
//     {
//         temp[i + 1] = arr[i];
//     }
//     for (int i = 0; i < len + 1; i++)
//     {
//         cout << temp[i] << " ";
//     }
//     // arr = temp;
// }
// void erase(int idx, int arr[], int &len);
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int arr[10] = {10, 50, 40, 30, 70, 20};
//     int len = 6;
//     insert(3, 60, arr, len);
//     // for (int i = 0; i < len + 1; i++)
//     // {
//     //     cout << arr[i] << " ";
//     // }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int &len)
{
    for (int i = len; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    len++;
    arr[idx] = num;
}

void erase(int idx, int arr[], int &len)
{
    for (int i = idx + 1; i < len; i++)
    {
        arr[i - 1] = arr[i];
    }
    len--;
}

void printArr(int arr[], int &len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test()
{
    cout << "***** insert_test *****\n";
    int arr[10] = {10, 20, 30};
    int len = 3;
    insert(3, 40, arr, len); // 10 20 30 40
    printArr(arr, len);
    insert(1, 50, arr, len); // 10 50 20 30 40
    printArr(arr, len);
    insert(0, 15, arr, len); // 15 10 50 20 30 40
    printArr(arr, len);
}

void erase_test()
{
    cout << "***** erase_test *****\n";
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    erase(4, arr, len); // 10 50 40 30 20
    printArr(arr, len);
    erase(1, arr, len); // 10 40 30 20
    printArr(arr, len);
    erase(3, arr, len); // 10 40 30
    printArr(arr, len);
    erase(1, arr, len);
    printArr(arr, len);
}

int main(void)
{
    insert_test();
    erase_test();
}