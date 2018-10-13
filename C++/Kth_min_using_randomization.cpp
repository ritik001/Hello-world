#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int partition(int, int, int);
int find_smallest_element(int, int, int);
int n;

int partition(int random_pivot, int low, int high)
{
    swap(arr[random_pivot], arr[low]);
    int x = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);

    return i;
}

int find_smallest_element(int k, int low, int high)
{
    int random_pivot = (rand() % (high - low + 1)) + low;
    int index = partition(random_pivot, low, high);

// Testing Part
/* 
cout << "Check:low high " << low << " " << high << "\n";
cout << "Check: " << random_pivot << " " << index << "\n";
for(int i=0;i<n;i++)
    cout << arr[i] << " ";
cout << "\n";
*/

    if (k - 1 == index)
        return arr[index];
    else if (k - 1 > index)
        return find_smallest_element(k, index + 1, high);
    else
        return find_smallest_element(k, low, index - 1);
}

int main()
{
    int k;
    cout << "Enter the number of elements in array \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the k(th) smallest element to be searched \n";
    cin >> k;

    if (k > n || k <= 0)
        cout << "Invalid value of k\n";
    else
    {
        cout << find_smallest_element(k, 0, n - 1) << "\n";
    }

    return 0;
}