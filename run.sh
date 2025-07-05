#!/bin/bash

echo "Compiling the file nn.c..."
gcc nn.c -o nearestNeighbor -lm

if [ $? -eq 0 ]; then
  echo "Compilation completed successfully!"
  echo "Program execution:"
  ./nearestNeighbor
else
  echo "Compilation error."
fi

