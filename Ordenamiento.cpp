/*
Author: Sergio Hernandez Castillo
Date: 03/09/2019
Description: A set of sorting algorithms with time execution calculation
*/

#include <iostream>
#include <chrono>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;

void scramble_array(int arr[],int size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%(size*10);
    }//Close for
}//Close scramble_array

void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }//Close for
}//Close print_array

void swap(int *x, int *y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}//Close swap

int getMax(int arr[], int n)
{
    int mx = arr[0];

    for (int i = 1; i < n; i++)
    {
      if (arr[i] > mx)
      {
        mx = arr[i];
      }//Close if
    }//Close for

    return mx;
}//Close getMax

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }//Close if
        }//Close for
    }//Close for
}//Close bubbleSort

void cocktailSort(int a[], int n)
{
    bool swapped = true;
    int begin = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = begin; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }//Close if
        }//Close for

        if (!swapped)
        {
            break;
        }//Close if

        swapped = false;

        --end;

        for (int i = end - 1; i >= begin; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }//Close if
        }//Close for

        ++begin;
    }//Close while
}//Close cocktailSort

void insertionSort(int a[], int n)
{
  int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }//Close while

        a[j + 1] = key;
    }//Close for
}//Close insertionSort

void bucketSort(int* data, int count)
{
  int minValue = data[0];
	int maxValue = data[0];

	for (int i = 1; i < count; i++)
	{
    if (data[i] > maxValue)
    {
      maxValue = data[i];
    }//Close if

		if (data[i] < minValue)
    {
      minValue = data[i];
    }//Close if
	}//Close for

	int bucketLength = maxValue - minValue + 1;
	vector<int>* bucket = new vector<int>[bucketLength];

	for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();
	}//Close for

	for (int i = 0; i < count; i++)
	{
    bucket[data[i] - minValue].push_back(data[i]);
	}//Close for

	int k = 0;

	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}//Close for
		}//Close if
	}//Close for
}//Close bucketSort

void countingSort(int *array, int size)
{
  int sizep = size + 1;
  int *output= new int[sizep];
  int max = getMax(array, size);
  int *count = new int[max + 1];

   for(int i = 0; i<=max; i++)
   {
     count[i] = 0;
   }//Close for

   for(int i = 1; i <=size; i++)
   {
     count[array[i]]++;
   }//Close for

   for(int i = 1; i<=max; i++)
   {
     count[i] += count[i - 1];
   }//Close for

   for(int i = size; i>=1; i--)
   {
     output[count[array[i]]] = array[i];
     count[array[i]] -= 1;
   }//Close for

   for(int i = 1; i<=size; i++)
   {
     array[i] = output[i];
   }//Close for
}//Close countingSort

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
      L[i] = arr[l + i];
    }//Close for

    for (j = 0; j < n2; j++)
    {
      R[j] = arr[m + 1+ j];
    }//Close for

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }//Close if

        else
        {
            arr[k] = R[j];
            j++;
        }//Close else

        k++;
    }//Close while

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }//Close while

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }//Close while
}//Close merge

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
    {
      int m = l + (r - l) / 2;

      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);

      merge(arr, l, m, r);
    }//Close if
}//Close mergeSort

struct Node
{
    int key;
    struct Node *left, *right;
};//Close struct Node

struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}//Close struct node newNode

void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }//Close if
}//Close storeSorted

Node* insert(Node* node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }//Close if

    if (key < node->key)
    {
        node->left  = insert(node->left, key);
    }//Close if

    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }//Close else if

    return node;
}//Close insert

void binaryTreeSort(int a[], int n)
{
    struct Node *root = NULL;

    root = insert(root, a[0]);

    for (int i = 1; i < n; i++)
    {
        insert(root, a[i]);
    }//Close for

    int i = 0;
    storeSorted(root, a, i);
}//Close binaryTreeSort

void radixCountSort(int arr[], int n, int exp)
{
  int output[n];
  int i, count[10] = {0};

  for (i = 0; i < n; i++)
  {
    count[ (arr[i]/exp)%10 ]++;
  }//Close for

  for (i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
  }//Close for

  for (i = n - 1; i >= 0; i--)
  {
    output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
    count[ (arr[i]/exp)%10 ]--;
  }//Close for

  for (i = 0; i < n; i++)
  {
    arr[i] = output[i];
  }//Close for
}//Close radixCountSort

void radixSort(int a[], int n)
{
  int m = getMax(a, n);

  for (int exp = 1; m / exp > 0; exp *= 10)
  {
    radixCountSort(a, n, exp);
  }//Close for
}//Close radixSort

void shellSort(int a[], int n)
{
  for (int gap = n/2; gap > 0; gap /= 2)
  {
      for (int i = gap; i < n; i += 1)
      {
          int temp = a[i];

          int j;
          for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
          {
            a[j] = a[j - gap];
          }//Close for

          a[j] = temp;
      }//Close for
  }//Close for
}//Close shellSort

void selectionSort(int a[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
             if (a[j] < a[min_idx])
             {
                 min_idx = j;
             }//Close if
         }//Close for

        swap(&a[min_idx], &a[i]);
    }//Close for
}//Close selectionSort

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
  {
    largest = l;
  }//Close if

  if (r < n && arr[r] > arr[largest])
  {
    largest = r;
  }//Close if

  if (largest != i)
  {
    swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }//Close if
}//Close heapify

void heapSort(int a[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(a, n, i);
  }//Close for

  for (int i = n - 1; i >= 0; i--)
  {
    swap(a[0], a[i]);

    heapify(a, i, 0);
  }//Close for
}//Close heapSort

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }//Close if
    }//Close for

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}//Close partition

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }//Close if
}//Close quickSort

int main()
{
    int size, arr_size;
    bool menu = true, menu2 = true;
    int menu_option = 0, menu_option2 = 0;

    cout << "Enter the size of the array: \n 1. 10 \n 2. 100 \n 3. 1,000";
    cout << "\n 4. 10,000 \n 5. 100,000 \n 6. 300,000 \n 7. 1,000,000" << endl;
    cout << "The program must be restarted to enter a new array size." << endl;

    while (menu)
    {
        cin >> menu_option;

        switch (menu_option)
        {
            case 1:
                size = 10;
                menu = false;
                break;
            case 2:
                size = 100;
                menu = false;
                break;
            case 3:
                size = 1000;
                menu = false;
                break;
            case 4:
                size = 10000;
                menu = false;
                break;
            case 5:
                size = 100000;
                menu = false;
                break;
            case 6:
                size = 300000;
                menu = false;
                break;
            case 7:
                size = 1000000;
                menu = false;
                break;
            default:
                cout << "\nInput not valid, please enter a valid option." << endl;
                break;
        }//Close switch
    }//Close while

    cout << "\nSize of the array:  " << size << endl;

    int* arr = new int[size];
    arr_size = size;

    scramble_array(arr, arr_size);
    //print_array(arr, arr_size);

    cout << "\nSelect a sorting algorithm: \n 1. Bubble Sort \n 2. Cocktail Sort \n 3. Insertion Sort";
    cout << "\n 4. Bucket Sort \n 5. Counting Sort \n 6. Merge Sort \n 7. Binary Tree Sort";
    cout << "\n 8. Radix Sort \n 9. Shell Sort \n 10. Selection Sort \n 11. Heap Sort \n 12. Quick Sort" << endl;

    while (menu2)
    {
        cin >> menu_option2;

        if (menu_option2 == 1)
        {
          cout << "\nAlgorithm selected: Bubble Sort" << endl;
          auto start = high_resolution_clock::now();
          bubbleSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 2)
        {
          cout << "\nAlgorithm selected: Cocktail Sort" << endl;
          auto start = high_resolution_clock::now();
          cocktailSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 3)
        {
          cout << "\nAlgorithm selected: Insertion Sort" << endl;
          auto start = high_resolution_clock::now();
          insertionSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 4)
        {
          cout << "\nAlgorithm selected: Bucket Sort" << endl;
          auto start = high_resolution_clock::now();
          bucketSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 5)
        {
          cout << "\nAlgorithm selected: Counting Sort" << endl;
          auto start = high_resolution_clock::now();
          countingSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 6)
        {
          cout << "\nAlgorithm selected: Merge Sort" << endl;
          auto start = high_resolution_clock::now();
          mergeSort(arr, 0, arr_size - 1);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 7)
        {
          cout << "\nAlgorithm selected: Binary Tree Sort" << endl;
          auto start = high_resolution_clock::now();
          binaryTreeSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 8)
        {
          cout << "\nAlgorithm selected: Radix Sort" << endl;
          auto start = high_resolution_clock::now();
          radixSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 9)
        {
          cout << "\nAlgorithm selected: Shell Sort" << endl;
          auto start = high_resolution_clock::now();
          shellSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 10)
        {
          cout << "\nAlgorithm selected: Selection Sort" << endl;
          auto start = high_resolution_clock::now();
          selectionSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 11)
        {
          cout << "\nAlgorithm selected: Heap Sort" << endl;
          auto start = high_resolution_clock::now();
          heapSort(arr, arr_size);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else if (menu_option2 == 12)
        {
          cout << "\nAlgorithm selected: Quick Sort" << endl;
          auto start = high_resolution_clock::now();
          quickSort(arr, 0, arr_size-1);
          auto stop = high_resolution_clock::now();
          auto duration = duration_cast<microseconds>(stop - start);
          cout << "\nTime of execution: " << duration.count() << " microseconds." << endl;
          menu2 = false;
        }//Close if

        else
        {
          cout << "\nInput not valid, please enter a valid option." << endl;
        }//Close else
    }//Close while

    //print_array(arr, arr_size);

    cout << "\n";

    delete [] arr;

    return 0;
}//Close main
