#!/bin/bash

# Compile the program
mkdir -p build
cd build
cmake ..
cmake --build .

# Run the program with the test input and compare the output
./bin/firewall ../ruleset_1.txt < ../test/packets.txt > output.txt

if diff output.txt ../test/expected_output.txt; then
    echo "|PASS|"
else
    echo "|FAIL|"
fi

# Clean up
rm output.txt
cd ..
rm -rf build
