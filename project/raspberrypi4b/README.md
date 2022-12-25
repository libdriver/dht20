### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

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

1. Show dht20 chip and driver information.

   ```shell
   dht20 (-i | --information)
   ```

2. Show dht20 help.

   ```shell
   dht20 (-h | --help)
   ```

3. Show dht20 pin connections of the current board.

   ```shell
   dht20 (-p | --port)
   ```

4. Run dht20 read test, num means test times. 

   ```shell
   dht20 (-t read | --test=read) [--times=<num>]
   ```

5. Run dht20 read function, num means test times.

   ```shell
   dht20 (-e read | --example=read) [--times=<num>]
   ```

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
./dht20 -t read --times=3

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
dht20: temperature: 29.4C.
dht20: humidity: 28%.
dht20: temperature: 29.5C.
dht20: humidity: 28%.
dht20: temperature: 29.6C.
dht20: humidity: 27%.
dht20: finish read test.
```

```shell
./dht20 -e read --times=3

dht20: 1/3.
dht20: temperature is 30.00C.
dht20: humidity is 26%.
dht20: 2/3.
dht20: temperature is 29.99C.
dht20: humidity is 26%.
dht20: 3/3.
dht20: temperature is 30.00C.
dht20: humidity is 26%.
```

```shell
./dht20 -h

Usage:
  dht20 (-i | --information)
  dht20 (-h | --help)
  dht20 (-p | --port)
  dht20 (-t read | --test=read) [--times=<num>]
  dht20 (-e read | --example=read) [--times=<num>]

Options:
  -e <read>, --example=<read>    Run the driver example.
  -h, --help                     Show the help.
  -i, --information              Show the chip information.
  -p, --port                     Display the pin connections of the current board.
  -t <read>, --test=<read>       Run the driver test.
      --times=<num>              Set the running times.([default: 3])
```

