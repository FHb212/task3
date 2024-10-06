#include "mpu6050.h"
#include <stdint.h>
int16_t Accel_X_RAW = 0;
int16_t Accel_Y_RAW = 0;
int16_t Accel_Z_RAW = 0;

int16_t Gyro_X_RAW = 0;
int16_t Gyro_Y_RAW = 0;
int16_t Gyro_Z_RAW = 0;

float Ax, Ay, Az, Gx, Gy, Gz;

void MPU6050_Init(void)
{
    uint8_t check;
    uint8_t Data;
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, 1000);

    if (check == 0x68)
    {
        Data = 0x01;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MEMT_1_REG, 1, &Data, 1, 1000);

        Data = 0x00;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MEMT_2_REG, 1, &Data, 1, 1000);

        Data = 0x06;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, CONFIG, 1, &Data, 1, 1000);

        Data = 0x09;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &Data, 1, 1000);

        Data = 0x18;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &Data, 1, 1000);

        Data = 0x18;
        HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &Data, 1, 1000);
    }
}
void MPU6050_Read_Accel(void)
{
    uint8_t Rec_Data[6];
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, Rec_Data, 6, 1000);
    Accel_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data[1]);
    Accel_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data[3]);
    Accel_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data[5]);
    Ax = Accel_X_RAW / 2048.0;
    Ay = Accel_Y_RAW / 2048.0;
    Az = Accel_Z_RAW / 2048.0;
}

void MPU6050_Read_Gyro(void)
{
    uint8_t Rec_Data[6];
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, GYRO_XOUT_H_REG, 1, Rec_Data, 6, 1000);
    Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data[1]);
    Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data[3]);
    Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data[5]);
    Gx = Gyro_X_RAW / 16.4 + 1; // 除16.4打出来为-1
    Gy = Gyro_Y_RAW / 16.4 + 1;
    Gz = Gyro_Z_RAW / 16.4 + 1;
}