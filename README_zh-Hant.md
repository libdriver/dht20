[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver DHT20

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/dht20/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

DHT20是DHT11的全新陞級產品，配寘了專用的ASIC感測器晶片、高性能的電晶體矽基電容式濕度感測器和一個標準的片上溫度感測器，並使用了標準I ² C數據輸出信號格式。 其效能已經大大提升，並且超過了前一代感測器的可靠性水准。 新一代陞級產品，經過改進使其在高溫高濕環境下的效能更穩定； 同時，產品的精度、回應時間、測量範圍都得到了大幅的提升。 每一個感測器的出廠都經過嚴格的校準和測試，保障並滿足客戶的大規模應用。 它被應用於暖通空調、除濕器和冰柜等家電產品，測試和檢測設備及其他相關溫濕度檢測控制產品。

LibDriver DHT20是LibDriver推出的DHT20全功能驅動，該驅動提供溫度、相對濕度讀取的功能並且它符合MISRA標準。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver DHT20的源文件。

/interface目錄包含了LibDriver DHT20與平台無關的IIC總線模板。

/test目錄包含了LibDriver DHT20驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver DHT20編程範例。

/doc目錄包含了LibDriver DHT20離線文檔。

/datasheet目錄包含了DHT20數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的IIC總線模板，完成指定平台的IIC總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

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

### 文檔

在線文檔: [https://www.libdriver.com/docs/dht20/index.html](https://www.libdriver.com/docs/dht20/index.html)。

離線文檔: /doc/html/index.html。

### 貢獻

請參攷CONTRIBUTING.md。

### 版權

版權 (c) 2015 - 現在 LibDriver 版權所有

MIT 許可證（MIT）

特此免費授予任何獲得本軟件副本和相關文檔文件（下稱“軟件”）的人不受限制地處置該軟件的權利，包括不受限制地使用、複製、修改、合併、發布、分發、轉授許可和/或出售該軟件副本，以及再授權被配發了本軟件的人如上的權利，須在下列條件下：

上述版權聲明和本許可聲明應包含在該軟件的所有副本或實質成分中。

本軟件是“如此”提供的，沒有任何形式的明示或暗示的保證，包括但不限於對適銷性、特定用途的適用性和不侵權的保證。在任何情況下，作者或版權持有人都不對任何索賠、損害或其他責任負責，無論這些追責來自合同、侵權或其它行為中，還是產生於、源於或有關於本軟件以及本軟件的使用或其它處置。

### 聯繫我們

請聯繫lishifenging@outlook.com。
