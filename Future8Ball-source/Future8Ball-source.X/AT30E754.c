// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AT30E754
// This code is designed to work with the AT30E754_I2CS I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Temperature?sku=AT30E754_I2CS#tabs-0-product_tabset-2

#include "mcc_generated_files/mcc.h"

#define AT30E754_IIC_ADDRESS			0x48

float cTemp = 0;
float fTemp = 0;
// Writes one byte to the register indicated by reg_address of the I2C slave

uint8_t AT30E754_I2C2_config(void) {
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    uint8_t write_buffer[2];
    write_buffer[0] = 0x01;
    write_buffer[1] = 0x60;
    I2C2_MasterWrite(&write_buffer, 2, AT30E754_IIC_ADDRESS, &status); // pointer la valoarea wr_data
    while (status == I2C2_MESSAGE_PENDING);
    return (status == I2C2_MESSAGE_COMPLETE);
}


// Reads one byte from the register indicated by reg_address of the I2C slave

uint8_t AT30E754_I2C2_read_temp(uint8_t *pData) {
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    static I2C2_TRANSACTION_REQUEST_BLOCK trb[2];
    uint8_t reg_address = 0x00;
    // Checks if there is any more space in TRB queue
    while (I2C2_MasterQueueIsFull() == true); // blocking
    I2C2_MasterWriteTRBBuild(&trb[0], &reg_address, 1, AT30E754_IIC_ADDRESS);
    // Checks if there is any more space in TRB queue
    while (I2C2_MasterQueueIsFull() == true); // blocking    
    //read 2 bytes for temperature
    I2C2_MasterReadTRBBuild(&trb[1], pData, 2, AT30E754_IIC_ADDRESS);
    I2C2_MasterTRBInsert(2, &trb[0], &status);
    while (status == I2C2_MESSAGE_PENDING); // blocking
    return (status == I2C2_MESSAGE_COMPLETE);
}

int16_t get_AT30E754_temperature(uint8_t c_or_f) {
    char data[2] = {0};
    AT30E754_I2C2_read_temp(data);
    int temp = (data[0] * 256 + (data[1] & 0xF0)) / 16;
    if (temp > 2047) {
        temp -= 4096;
    }
    cTemp = (temp * 0.0625);
    fTemp = ((cTemp * 1.8) + 32);
    if (c_or_f) {
        return (int16_t) (cTemp * 10);
    } else {
        return (int16_t) (fTemp * 10);
    }
}

