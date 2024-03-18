GeneratePattern(n, row, col):
    // Base case: If the row exceeds n, stop recursion
    if row > n:
        return
    
    // If the column is less than or equal to the row, print the column number
    if col <= row:
        print col
        // Recursive call to print the next column
        GeneratePattern(n, row, col + 1)
    else:
        // Move to the next row and reset the column to 1
        print newline
        GeneratePattern(n, row + 1, 1)

Main:
    n = 4 // Example value, change as needed
    // Start generating the pattern from the first row and first column
    GeneratePattern(n, 1, 1)