# Firewall Testing Task

## Description
This is testing task for the C developer internship in the [Ideco company](ideco.ru). This testing task is a simple 
firewall that takes for the `stdin` list of packets, check it in the database of the rules and according to these rules
generates a verdict (ACCEPT or DROP).
## Building & Running

Program is building through the `cmake`. The best way to build it is here:
```commandline
mkdir -p build
cd build
cmake ..
cmake --build .
```
To run the program with manual input (it will not stop until the `EOF`) execute this:
```commandline
./bin/firewall 1
```
To run program with default input (lays in the `test/packets.txt`) execute this:
```commandline
./bin/firewall 1 < ../test/packets.txt
```

## Testing
To run tests you will need to execute run_tests.sh. It is automatically building, so you do not have to build it 
manually. Just run this command:
```commandline
./run_tests.sh
```
Also for your convenience there is [GitHub actions](https://github.com/LeftTry/firewall-test-task/actions/workflows/run_tests.yml) 
that do the same job.
