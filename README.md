# Stall Profit and Loss Calculator

This C++ program reads data about stalls from a file, calculates net income for each stall, and determines the total profit or loss.

## Files

- `StallProfitAndLossCalculator.cpp`: The main C++ source file containing the implementation.
- `stalls.txt`: Input file containing data about each stall (name, income, expenses).
- `stalls_output.txt`: Output file where results are written.

## Requirements

- A C++ compiler such as g++.
- Input data file `stalls.txt` located in the specified directory.

## Compilation and Execution

1. **Compile the program** using a C++ compiler:

   ```bash
   g++ -o stall_calculator StallProfitAndLossCalculator.cpp
   ```

2. **Run the executable**:

   ```bash
   ./stall_calculator
   ```

   Make sure that `stalls.txt` is in the correct directory (`C:\\comp1602asg1\\asg1\\`) or modify the file paths in the code accordingly.

## Input File Format

- Each line in `stalls.txt` should contain the name of the stall followed by its income and expenses.
- Use "XXXXXX" or "xxxxxx" as a sentinel value to indicate the end of data.

Example:
```
StallA 1000 500
StallB 1500 700
XXXXXX
```

## Output

- The program writes the net income of each stall and the total profit or loss to `stalls_output.txt`.

## How It Works

- The program reads each stall's data and calculates net income by subtracting expenses from income.
- It accumulates the total profit or loss across all stalls.
- Results are written to an output file for review.
