/*
Author: Sergio Hernandez Castillo
Date: 03/09/2019
Description: A set of sorting programs with time execution calculation
*/

#include <iostream>
#include <chrono>
#include <array>
#include <algorithm> 
#include <vector>

using namespace std;
using namespace std::chrono;

//To fill the array with random elements
void scramble_array(int arr[],int size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%(size*10);
    }
}//Close scramble_array

void scramble_array_float(float arr[],int size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%(size*10);
    }
}//Close scramble_array

//To print the array
void print_arr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}//Close print_arr

void print_arr_float(float arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}//Close print_arr

//To swap elements in the array
void swap(int *x, int *y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}//Close swap

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}//Close BubbleSort

void CocktailSort(int a[], int n)
{
    bool swapped = true; 
    int begin = 0; 
    int end = n-1; 
  
    while (swapped)
    { 
        swapped = false; 
  
        for (int i = begin; i < end; ++i)
        { 
            if (a[i] > a[i+1]) 
            { 
                swap(a[i], a[i+1]); 
                swapped = true; 
            } 
        } 
  
        if (!swapped)
        {
            break; 
        }
  
        swapped = false; 
  
        --end; 
  
        for (int i = end-1; i >= begin; --i) 
        { 
            if (a[i] > a[i+1]) 
            { 
                swap(a[i], a[i+1]); 
                swapped = true; 
            } 
        } 
        
        ++begin; 
    }
}//Close CocktailSort

void InsertionSort(int a[], int n)
{
    
}//Close InsertionSort

void BucketSort(float a[], int n)
{
    // 1) Create n empty buckets 
    vector<float> b[n]; 
     
    // 2) Put array elements in different buckets 
    for (int i=0; i<n; i++) 
    { 
       int bi = n*a[i]; // Index in bucket 
       b[bi].push_back(a[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++)
    {
       sort(b[i].begin(), b[i].end()); 
    }
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        { 
            a[index++] = b[i][j]; 
        }
    }
}//Close BucketSort

void CountingSort(int a[], int n)
{
    
}//Close CountingSort

void MergeSort(int a[], int n)
{
    
}//Close MergeSort

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
    } 
}//Close storeSorted
  
Node* insert(Node* node, int key) 
{ 
    if (node == NULL)
    {
        return newNode(key); 
    }
  
    if (key < node->key)
    {
        node->left  = insert(node->left, key); 
    }
    
    else if (key > node->key) 
    {
        node->right = insert(node->right, key);
    }
  
    return node; 
} //Close insert

void BinaryTreeSort(int a[], int n)
{
    struct Node *root = NULL; 
  
    root = insert(root, a[0]);
     
    for (int i=1; i<n; i++)
    { 
        insert(root, a[i]);
    } 
   
    int i = 0; 
    storeSorted(root, a, i); 
}//Close BinaryTreeSort

void RadixSort(int a[], int n)
{
    
}//Close RadixSort

void ShellSort(int a[], int n)
{
    
}//Close ShellSort

void SelectionSort(int a[], int n)
{
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        
        for (j = i+1; j < n; j++)
        {
             if (a[j] < a[min_idx])
             {
                 min_idx = j;
             }
         }
  
        swap(&a[min_idx], &a[i]);  
    }  
}//Close SelectionSort

void HeapSort(int a[], int n)
{
    
}//Close HeapSort

int partition(int arr[], int low, int high)  
{  
    int pivot = arr[high];  
    int i = (low-1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    } 
    
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}//Close partition

void QuickSort(int arr[], int low, int high)
{
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
  
        QuickSort(arr, low, pi-1);  
        QuickSort(arr, pi+1, high);  
    }  
}//Close QuickSort

int main()
{
    int size, arr_size;
    bool menu = true;
    int menu_option = 0;

    while (menu)
    {
        cout << "Enter the size of the array: \n 1. 10 \n 2. 100 \n 3. 1,000 \n 4. 10,000 \n 5. 100,000 \n 6. 1,000,000" << endl;
        cout << "The program must be restarted to enter a new array size." << endl;
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
                size = 1000000;
                menu = false;
                break;
            default:
                cout << "\nInput not valid, please enter a valid option.";
                break;
        }
    }
    
    cout << "\nSize of the array:  " << size << endl;

    //Declaring size and randomizing the array.
    //int arr[size];
    int* arr = new int[size];
    arr_size = size ;//sizeof(arr)/sizeof(arr[0]);

    scramble_array(arr, arr_size);
    
    //print_arr(arr, arr_size);
    
    float* arr2 = new float[size];

    scramble_array_float(arr2, arr_size);
    
    //print_arr(arr, arr_size);
    
    auto start = high_resolution_clock::now();
    //BubbleSort(arr, arr_size);
    //CocktailSort(arr, arr_size);
    //InsertionSort(arr, arr_size);
    BucketSort(arr2, arr_size);
    //CountingSort(arr, arr_size);
    //MergeSort(arr, arr_size);
    //BinaryTreeSort(arr, arr_size);
    //RadixSort(arr, arr_size);
    //ShellSort(arr, arr_size);
    //SelectionSort(arr, arr_size);
    //HeapSort(arr, arr_size);
    //QuickSort(arr, 0, arr_size-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "\nTime of execution: " << duration.count() << " microseconds" << endl;
    
    //print_arr(arr, arr_size);
     
    delete [] arr;
    
    return 0;
}//Close main
