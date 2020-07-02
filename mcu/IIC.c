/*
 * IIC: AT24C02
 */
#include <stdint.h>
/*
   Device Address
   | A6 A5 A4 A3   A2 A1 A0 | R/~W
   | 1  0  1  0    x  x  x  | 0/1
*/
#define IIC_DEV_ADDR   (0xA0)
/* we assume addr should shift, some chips may not shift, USE AT YOUR OWN DISCRETION! */
#define IIC_WRITE_ADDR (I2C_DEV_ADDR << 1)
#define IIC_READ_ADDR  ((I2C_DEV_ADDR << 1) + 1)

#define SDA (MCU_PIN_1)
#define SCL (MCU_PIN_2)

extern char iic_ack_flag; // store ack signal error

static inline void delay()
{
    int i, j;
    for(i = 0; i < 50 ; i+=1)
        for(j = 0; j < 1000; j+=1);
}

void IIC_start(void)
{
    SDA=1;
    SCL=1;    // bus initial, unlock

    SDA=0;    // trigger start signal
    delay();

    SCL=0;    // lock
    delay();
}

void IIC_stop(void)
{
    SCL=0;   // lock
    delay();

    SDA=0;   // ready for stop
    delay();

    SCL=1;   // unlock
    delay();

    SDA=1;   // trigger stop signal
    delay();
}

void IIC_ack(void)
{
    uint8_t timeout=9;
    SCL=1;
    delay();
    while(SDA && timeout){
        delay();
        timeout--;
    }
    iic_ack_flag = !timeout ? 1 : 0; // wait ack timeout!?
    SCL=0;
    return;
}

void IIC_write(const uint8_t wbyte)
{
    uint8_t bitmask,i;
    for(i = 0; i < 8; i+=1){
        SCL=0;                            // lock
        SDA=( bitmask & wbyte ) ? 1 : 0;  // set SDA to next bit
        bitmask>>=1;                      // clear bitmask
        delay();

        SCL=1;                            // unlock
        delay();                          // writting ...
    }
    IIC_ack();
}

uint8_t IIC_read(void)
{
    uint8_t i, rbyte = 0x00;
    for( i = 0; i < 8 ; i+=1){
        SCL=0;             // lock
        SDA=0;             // ready for read
        delay();

        SCL=1;             // unlock
        delay();

        byte=(byte<<1)|SDA // read from SDA (MSB->LSB)
        delay();           // reading...
    }
    IIC_ack();
    return byte;
}


void IIC_write_8Bit(uint8_t addr, uint8_t data)
{
    IIC_start();
    IIC_write(IIC_WRITE_ADDR); // 7+W --> use this addr to find slave dev
    IIC_write(addr);           // 8   --> store data at slave's addr
    IIC_write(data);           // 8   --> to store data
    IIC_stop();
}

uint8_t IIC_read_8Bit(uint8_t addr)
{
    uint8_t data;
    IIC_start();
    IIC_write(IIC_WRITE_ADDR);  // 7+W --> use this addr to find slave dev
    IIC_write(addr);            // 8   --> send master's addr

    IIC_start();
    IIC_write(IIC_READ_ADDR);   // 7+R --> slave ready to be read
    data=IIC_read();            // 8   --> recevie data
    IIC_stop();
    return data;
}
