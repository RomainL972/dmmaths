# dmmaths
A very incredible program

## Build

To build this program, you will need cmake, make and a c++ compiler

```bash
mkdir build
cd build
cmake ..
make
```

## Usage
There are three programs.

* DM is the actual program, you can start it with

```
./DM <number of disques>
```

  or

```
./DM <number of disques> 1
```

  to log every move to the file moves.txt (slower)

* Tester runs DM with every number of disques possible and checks the results, you can start it with

```
./tester
```

* display.py runs DM and displays the result with animated rectangles thanks to
the python module turtle. You need tkinter and python to run it. It has it's own
help page so try running

```
cd ..
./display.py -h
```
