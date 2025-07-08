# 1-NN Classifier (1-Nearest Neighbor)

This project contains a simple 100-line implementation of a 1-NN (1-Nearest Neighbor) classifier. It is based on 5 numeric features and a class label for each data point. This project was developed in a short time and serves only educational purposes — to better understand how a basic classifier works.

## 📂 File

- `nn.c` - Classifier source code 
- `dataset.txt` – CSV file containing a small training set for testing
- `Makefile` – Script to compile the project

## Dataset Format

Each row must contain 5 numeric values and a class label, separated by commas:

```
0.1,0.2,0.3,0.4,0.5,1
0.2,0.3,0.4,0.5,0.6,2
...
```

## How to Compile and Run

Make sure to have `gcc` installed, then run:

```bash
make nn
```
Or compile and run manually:
```
gcc nn.c -o nearestNeighbor -lm
./nearestNeighbor
```

## How it works

* Reads data from `dataset.txt`
* Prints the dataset to the console
* Asks the user to input a new point
* Calculates the Euclidean distance from the new point to every point in the dataset
* Assigns the class of the nearest neighbor to the new point

## License

This project is distributed with MIT license. Feel free to modify and reuse.
