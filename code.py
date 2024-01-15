import random

# Function to perform bubble sort on a list
def bubble_sort(lst):
    n = len(lst)
    # Loop over each element of the list
    for i in range(n):
        # For each element, loop over the list again
        for j in range(0, n - i - 1):
            # If the current element is greater than the next element, swap them
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]

# Ask the user for the number of rows and columns
rows = int(input("How many rows will your matrix have? "))
columns = int(input("How many columns will your matrix have? "))

# Create a 2D list to represent the matrix
matrix = [[0 for _ in range(columns)] for _ in range(rows)]

# Fill the matrix with random numbers 
for i in range(rows):
    for j in range(columns):
        matrix[i][j] = random.randint(1, 100)

# Create a list to hold the matrix elements
lst = [0 for _ in range(rows * columns)]
counter = 0

# Copy the matrix elements to the list
for i in range(rows):
    for j in range(columns):
        lst[counter] = matrix[i][j]
        counter += 1

# Sort the list using bubble sort
bubble_sort(lst)

counter = 0

# Copy the sorted list back to the matrix
for i in range(rows):
    for j in range(columns):
        matrix[i][j] = lst[counter]
        counter += 1

# Print the sorted matrix
for i in range(rows):
    for j in range(columns):
        print(matrix[i][j], end=" ")
    print()
