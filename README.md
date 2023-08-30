# SquareSolver

SquareSolver is a console program for solving square equations

## Installation

Download all the files and use makefile to build them

```bash
$ make
```

## Usage

Launch main.exe and input the coefficients

```bash
$ main
# Square equation solver
# Made by: Nucc1e4r

ax^2 + bx + c = 0
Input a, b, c:

1 -6 5

two roots: x1 = 5, x2 = 1
```

## Debug mode

Launch main.exe with -t flag to run default tests.

```bash
$ main -t
# Square equation solver
# Made by: Nucc1e4r

Test 0 passed
Test 1 passed
Test 2 passed
Test 3 passed
Test 4 passed
Test 5 passed
Test 6 passed
Test 7 passed
Test 8 passed
Test 9 passed
All tests ran successfully
```

You can create your own tests in .txt files and run them using main -t -f *filename.txt*

Your .txt file should look like this:

```
3
0 0 1 0 0 0 1
1 0 1 1 -1 0 1
2 1 0 0 0 0 1
```
Where the first number `3` is amount of tests (must be less or equal to maxTestAmount in sqrconst.h!) and every line is a test: `testID, coeff a, coeff b, coeff c, root x1, root x2, amount of roots ` Roots must be written so that x1 > x2. If there is only x1, or no solutions, or infinite amount of solutions, set unused values (x2 or (x1 and x2)) to zero. If there is infinite amount solutions, set `amount of roots` to -1.
## License

MIPT, 2023
Copyright, copyleft, copycenter
