#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    // Loop over each element of the array
    for (int i = 0; i < n - 1; i++) {
        // For each element, loop over the array again
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int rows, columns;
    // Ask the user for the number of rows and columns
    cout << "How many rows and columns will your matrix have? ";
    cin >> rows >> columns;
    
    // Create a 2D vector to represent the matrix
    vector<vector<int>> matrix(rows, vector<int>(columns));
    
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    
    // Fill the matrix with random numbers 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = distrib(gen);
        }
    }
    
    // Create a vector to hold the matrix elements
    vector<int> vec(rows * columns);
    int counter = 0;
    
    // Copy the matrix elements to the vector
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            vec[counter] = matrix[i][j];
            counter++;
        }
    }
    
    counter = 0;
    
    // Sort the vector using bubble sort
    bubbleSort(vec.data(), rows * columns);
    
    // Copy the sorted vector back to the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = vec[counter];
            counter++;
        }
    }
    
    // Print the sorted matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
