#include <iostream>
using namespace std;

void main(){
    char choice;
    cout<<"Type b for bubble sort and r for radix sort";
    cin>>choice;
    switch (choice){
        case 'b':
         int n;
        cout<<"Enter the size of your desired array: ";
        cin>>n;
    
        int arr[n];
    
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }    
    
        int counter=1;
        while(counter<n){
            for(int i=0; i<n-counter; i++){
                if(arr[i]>arr[i+1]){
                    int temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
            counter++;
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        return 0;
        break;
        
        
        
        case 'r':
        int getMax(int arr[], int n)
        {
            int mx = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > mx)
                    mx = arr[i];
            return mx;
        }
         
        // A function to do counting sort of arr[] according to
        // the digit represented by exp.
        void countSort(int arr[], int n, int exp)
        {
            int output[n]; // output array
            int i, count[10] = { 0 };
         
            // Store count of occurrences in count[]
            for (i = 0; i < n; i++)
                count[(arr[i] / exp) % 10]++;
         
            // Change count[i] so that count[i] now contains actual
            //  position of this digit in output[]
            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];
         
            // Build the output array
            for (i = n - 1; i >= 0; i--) {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }
         
            // Copy the output array to arr[], so that arr[] now
            // contains sorted numbers according to current digit
            for (i = 0; i < n; i++)
                arr[i] = output[i];
        }
         
        // The main function to that sorts arr[] of size n using
        // Radix Sort
        void radixsort(int arr[], int n)
        {
            // Find the maximum number to know number of digits
            int m = getMax(arr, n);
         
            // Do counting sort for every digit. Note that instead
            // of passing digit number, exp is passed. exp is 10^i
            // where i is current digit number
            for (int exp = 1; m / exp > 0; exp *= 10)
                countSort(arr, n, exp);
        }
         
        // A utility function to print an array
        void print(int arr[], int n)
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        }
         
        // Driver Code
        int main()
        {
            int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
            int n = sizeof(arr) / sizeof(arr[0]);
             
              // Function Call
              radixsort(arr, n);
            print(arr, n);
            return 0;
        }
        break;
    }
    
}
