/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_dht20_basic.c
 * @brief     driver dht20 basic source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2022-10-31
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2022/10/31  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_dht20_basic.h"

static dht20_handle_t gs_handle;        /**< dht20 handle */

/**
 * @brief  basic example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t dht20_basic_init(void)
{
    uint8_t res;
    
    /* link interface function */
    DRIVER_DHT20_LINK_INIT(&gs_handle, dht20_handle_t);
    DRIVER_DHT20_LINK_IIC_INIT(&gs_handle, dht20_interface_iic_init);
    DRIVER_DHT20_LINK_IIC_DEINIT(&gs_handle, dht20_interface_iic_deinit);
    DRIVER_DHT20_LINK_IIC_READ_CMD(&gs_handle, dht20_interface_iic_read_cmd);
    DRIVER_DHT20_LINK_IIC_WRITE_CMD(&gs_handle, dht20_interface_iic_write_cmd);
    DRIVER_DHT20_LINK_DELAY_MS(&gs_handle, dht20_interface_delay_ms);
    DRIVER_DHT20_LINK_DEBUG_PRINT(&gs_handle, dht20_interface_debug_print);
    
    /* dht20 init */
    res = dht20_init(&gs_handle);
    if (res != 0)
    {
        dht20_interface_debug_print("dht20: init failed.\n");
        
        return 1;
    }
    
    return 0;
}

/**
 * @brief      basic example read
 * @param[out] *temperature points to a converted temperature buffer
 * @param[out] *humidity points to a converted humidity buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t dht20_basic_read(float *temperature, uint8_t *humidity)
{
    uint32_t temperature_raw;
    uint32_t humidity_raw;
    
    /* read temperature and humidity */
    if (dht20_read_temperature_humidity(&gs_handle, (uint32_t *)&temperature_raw, temperature, 
                                       (uint32_t *)&humidity_raw, humidity) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t dht20_basic_deinit(void)
{
    /* deinit dht20 and close bus */
    if (dht20_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
