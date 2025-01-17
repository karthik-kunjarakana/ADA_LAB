// 11 Design and implement C/C++ Program to sort a given set of n integer elements using Merge Sort
// method and compute its time complexity. Run the program for varied values of n> 5000, and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000
void merge(int array[], int low, int mid, int high) {
int i = low;
int j = mid + 1;
int k = low;
int resarray[MAX];
while (i <= mid && j <= high)
{
if (array[i] < array[j])
{
resarray[k++] = array[i++];
}
else
{
resarray[k++] = array[j++];
}
}
while (i <= mid)
{
resarray[k++] = array[i++];
}
while (j <= high)
{
resarray[k++] = array[j++];
}
for (int m = low; m <= high; m++)
{
array[m] = resarray[m];
}
}
void sort(int array[], int low, int high) {
if (low < high) {
int mid = (low + high) / 2;
sort(array, low, mid);
sort(array, mid + 1, high);
merge(array, low, mid, high);
}
}
// Function to generate an array of random integers
void generateRandomArray(int arr[], int n)
{
srand(time(NULL));
for (int i = 0; i < n; i++) {
arr[i] = rand();
}
}
int main() {
int n_values[] = {5000, 10000, 15000, 20000}; // Array of n values
int num_values = sizeof(n_values) / sizeof(n_values[0]);
double time_taken[num_values];
for (int i = 0; i < num_values; i++) {
int n = n_values[i];
int *arr = (int*)malloc(n * sizeof(int));
generateRandomArray(arr, n);
clock_t start = clock();
sort(arr, 0, n - 1);
clock_t end = clock();
time_taken[i] = ((double)(end - start)) / CLOCKS_PER_SEC;
free(arr);
}
// Output time taken for sorting each value of n
printf("n\tTime Taken (s)\n");
for (int i = 0; i < num_values; i++) {
printf("%d\t%f\n", n_values[i], time_taken[i]);
}
return 0;
}