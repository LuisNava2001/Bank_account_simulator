# Bank Account Simulator in C

This project is a console-based bank account simulator written in C. It allows users to deposit money, withdraw funds, check their balance, and view transaction history, with each transaction storing a timestamp.

## Features
- Deposit funds (rejects zero or negative amounts)
- Withdraw funds (prevents overdrawing)
- Check balance anytime
- Transaction history with description, amount, and date/time
- Input validation to prevent invalid menu selections
- Formatted timestamps for each transaction

## Technical Details
- Written in C using the `time.h` library for timestamps
- Uses a `Transaction` struct to store:
  - Description
  - Amount
  - Timestamp
- Stores up to 100 transactions in memory
- Implements date/time formatting with `strftime()`
- Clears invalid inputs from the buffer to prevent runtime errors

## How to Compile and Run
```bash
# Compile
gcc bank_simulator.c -o bank_simulator

# Run
./bank_simulator
```

## Example Output
```
1. Deposit $ 100.00 --- 2025-08-11 14:30:45
2. Withdrawal $ 50.00 --- 2025-08-11 15:05:12
```
