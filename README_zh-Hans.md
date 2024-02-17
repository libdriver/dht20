[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver DHT20

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/dht20/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

DHT20是DHT11的全新升级产品，配置了专用的ASIC传感器芯片、高性能的半导体硅基电容式湿度传感器和一个标准的片上温度传感器，并使用了标准I²C数据输出信号格式。其性能已经大大提升，并且超过了前一代传感器的可靠性水平。新一代升级产品，经过改进使其在高温高湿环境下的性能更稳定；同时，产品的精度、响应时间、测量范围都得到了大幅的提升。每一个传感器的出厂都经过严格的校准和测试，保障并满足客户的大规模应用。它被应用于暖通空调、除湿器和冰箱等家电产品，测试和检测设备及其他相关温湿度检测控制产品。

LibDriver DHT20是LibDriver推出的DHT20全功能驱动，该驱动提供温度、相对湿度读取的功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver DHT20的源文件。

/interface目录包含了LibDriver DHT20与平台无关的IIC总线模板。

/test目录包含了LibDriver DHT20驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver DHT20编程范例。

/doc目录包含了LibDriver DHT20离线文档。

/datasheet目录包含了DHT20数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC总线模板，完成指定平台的IIC总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_dht20_basic.h"

uint8_t res;
uint8_t i;
float temperature;
uint8_t humidity;

res = dht20_basic_init();
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    dht20_interface_delay_ms(2000);
    res = dht20_basic_read((float *)&temperature, (uint8_t *)&humidity);
    if (res != 0)
    {
        (void)dht20_basic_deinit();

        return 1;
    }
    dht20_interface_debug_print("dht20: temperature is %0.2fC.\n", temperature);
    dht20_interface_debug_print("dht20: humidity is %d%%.\n", humidity); 
    
    ...
        
}

...

(void)dht20_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/dht20/index.html](https://www.libdriver.com/docs/dht20/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。