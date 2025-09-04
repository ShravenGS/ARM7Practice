#include<LPC21XX.h>
#include"i2c_driver.h"
void I2C_EEPROM_WRITE(unsigned char slaveAddr,unsigned char wBuffAddr,unsigned char dat)
{
  I2C_START();	
  I2C_WRITE(slaveAddr<<1); //slaveAddr + w
  I2C_WRITE(wBuffAddr);    //wBuffAddr
  I2C_WRITE(dat);          //data
  I2C_STOP();
  delay(10);
}


unsigned char I2C_EEPROM_READ(unsigned char slaveAddr,unsigned char rBuffAddr)
{
	unsigned char dat;
	I2C_START();	
  	I2C_WRITE(slaveAddr<<1); //slaveAddr + w
	I2C_WRITE(rBuffAddr);    //wBuffAddr
	I2C_RESTART();	
	I2C_WRITE(slaveAddr<<1|1); //slaveAddr + r  
  	dat=I2C_NACK();	
	I2C_STOP();
	return dat;

}
