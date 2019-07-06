#include <bits/stdc++.h>
using namespace std;
 
// function to print combinations that contain
// one element from each of the given arrays
void print(vector<vector<int> >& arr)
{
    // number of arrays
    int n = arr.size();
 
    // to keep track of next element in each of
    // the n arrays
    int* indices = new int[n];
 
    // initialize with first element's index
    for (int i = 0; i < n; i++)
        indices[i] = 0;
 
    while (1) {
 
        // print current combination
        for (int i = 0; i < n; i++)
            cout << arr[i][indices[i]] << " ";
        cout << endl;
 
        // find the rightmost array that has more
        // elements left after the current element 
        // in that array
        int next = n - 1;
        while (next >= 0 && 
              (indices[next] + 1 >= arr[next].size()))
            next--;
 
        // no such array is found so no more 
        // combinations left
        if (next < 0)
            return;
 
        // if found move to next element in that 
        // array
        indices[next]++;
 
        // for all arrays to the right of this 
        // array current index again points to 
        // first element
        for (int i = next + 1; i < n; i++)
            indices[i] = 0;
    }
}
 
// driver function to test above function
int main()
{
    // initializing a vector with 3 empty vectors
    vector<vector<int> > arr(3, vector<int>(0, 0));
 
    // now entering data
    // [[1, 2, 3], [4], [5, 6]]
    arr[0].push_back(1);
    arr[0].push_back(2);
    arr[0].push_back(3);
    arr[1].push_back(4);
    arr[2].push_back(5);
    arr[2].push_back(6);
 
    print(arr);
    return 0;
}
