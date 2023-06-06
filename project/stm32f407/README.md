### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

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
dht20 -i

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
dht20 -p

dht20: SCL connected to GPIOB PIN8.
dht20: SDA connected to GPIOB PIN9.
```

```shell
dht20 -t read --times=3

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
dht20: temperature: 29.1C.
dht20: humidity: 26%.
dht20: temperature: 29.1C.
dht20: humidity: 25%.
dht20: temperature: 29.2C.
dht20: humidity: 25%.
dht20: finish read test.
```

```shell
dht20 -e read --times=3

dht20: 1/3.
dht20: temperature is 28.94C.
dht20: humidity is 33%.
dht20: 2/3.
dht20: temperature is 28.93C.
dht20: humidity is 28%.
dht20: 3/3.
dht20: temperature is 28.89C.
dht20: humidity is 26%.
```

```shell
dht20 -h

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

