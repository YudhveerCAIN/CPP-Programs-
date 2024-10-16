// This is a program for Bucket Sort Algorithm 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(const vector<float>& array) {
   for(float val : array)
      cout << val << " ";
   cout << endl;
}
void bucketSort(vector<float>& array) {
   int size = array.size();
   vector<vector<float>> bucket(size);
   for(int i = 0; i < size; i++) {          
      int bucketIndex = size * array[i];
      if(bucketIndex >= size) bucketIndex = size - 1; 
      bucket[bucketIndex].push_back(array[i]);
   }
   for(int i = 0; i < size; i++) {
      sort(bucket[i].begin(), bucket[i].end());
   }
   int index = 0;
   for(int i = 0; i < size; i++) {
      for(float val : bucket[i]) {
         array[index++] = val;
      }
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   vector<float> arr(n);
   cout << "Enter elements (between 0 and 1):" << endl;
   for(int i = 0; i < n; i++) {
      cin >> arr[i];
      if(arr[i] < 0 || arr[i] >= 1) {
         cout << "Error: Please enter numbers between 0 and 1.\n";
         return -1;
      }
   }

   cout << "Array before Sorting: ";
   display(arr);
   bucketSort(arr);
   cout << "Array after Sorting: ";
   display(arr);

   return 0;
}
