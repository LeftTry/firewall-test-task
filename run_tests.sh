#!/bin/bash

run_test() {
    local rulenum=$1
    local input=$2
    local expected_output=$3

    # Compile the program
    mkdir -p build
    cd build
    cmake ..
    cmake --build .
    cd ..

    # Run the program with the test input and compare the output
    ./build/bin/firewall $rulenum < $input > output.txt

    if diff output.txt $expected_output; then
        echo "Test with $input passed."
    else
        echo "Test with $input failed."
        diff output.txt $expected_output
    fi

    # Clean up
    rm output.txt
    rm -rf build
}

# Run tests for both rulesets
run_test 1 test/packets_1.txt test/expected_output_1.txt
run_test 2 test/packets_2.txt test/expected_output_2.txt
