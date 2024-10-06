#ifndef __MPU6050_H__
#define __MPU6050_H__

#include "stm32f1xx_hal.h"
#include "main.h"
#include "i2c.h"

#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19
#define CONFIG 0x1A
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MEMT_1_REG 0x6B
#define PWR_MEMT_2_REG 0x6C
#define WHO_AM_I_REG 0x75

void MPU6050_Init(void);
void MPU6050_Read_Accel(void);
void MPU6050_Read_Gyro(void);

extern float Ax, Ay, Az, Gx, Gy, Gz;

#endif // !__MPU6050__H_