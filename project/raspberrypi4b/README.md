### 1. Chip

#### 1.1 Chip Info

chip name : Raspberry Pi 4B.

iic pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(dht20 REQUIRED)
```

### 3. DHT20

#### 3.1 Command Instruction

​           dht20 is a basic command which can test all dht20 driver function:

​           -h        show dht20 help 

​           -i         show dht20 chip and driver information.

​           -p       show dht20 pin connections of the current board.

​           -t read <times>        run dht20 read test. times means test times. 

​           -c read <times>        run dht20 read function. times means test times.

#### 3.2 Command Example

```shell
./dht20 -i

dht20: chip is ASAIR DHT20.
dht20: manufacturer is ASAIR.
dht20: interface is IIC.
dht20: driver version is 1.0.
dht20: min supply voltage is 2.2V.
dht20: max supply voltage is 5.5V.
dht20: max current is 0.98mA.
dht20: max temperature is 85.0C.
dht20: min temperature is -40.0C.
```

```shell
./dht20 -p

dht20: SCL connected to GPIO3(BCM).
dht20: SDA connected to GPIO2(BCM).
```

```shell
./dht20 -t read 3

dht20: chip is ASAIR DHT20.
dht20: manufacturer is ASAIR.
dht20: interface is IIC.
dht20: driver version is 1.0.
dht20: min supply voltage is 2.2V.
dht20: max supply voltage is 5.5V.
dht20: max current is 0.98mA.
dht20: max temperature is 85.0C.
dht20: min temperature is -40.0C.
dht20: start read test.
dht20: temperature: 26.9C.
dht20: humidity: 42%.0
dht20: temperature: 26.9C.
dht20: humidity: 42%.0
dht20: temperature: 26.9C.
dht20: humidity: 42%.0
dht20: finish read test.
```

```shell
./dht20 -c read 3

dht20: 1/3.
dht20: temperature is 26.66C.
dht20: humidity is 42%.0
dht20: 2/3.
dht20: temperature is 26.64C.
dht20: humidity is 42%.0
dht20: 3/3.
dht20: temperature is 26.62C.
dht20: humidity is 42%.0
```

```shell
./dht20 -h

dht20 -h
	show dht20 help.
dht20 -i
	show dht20 chip and driver information.
dht20 -p
	show dht20 pin connections of the current board.
dht20 -t read <times>
	run dht20 read test.times means test times.
dht20 -c read <times>
	run dht20 read function.times means test times.
```

