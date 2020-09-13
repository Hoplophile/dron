#include "imu.h"
#include "i2c.h"

union imu_data_union{
    int16_t data;
    struct{
        uint8_t data_l;
        uint8_t data_h;
    };
};

void IMU_InitAcc(void){
    HAL_StatusTypeDef result;
    uint8_t settings = ACC_100HZ | ACC_ENABLE;

    result = HAL_I2C_Mem_Write(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_CTRL_REG1, 1, &settings, 1, 50);
}

int16_t IMU_ReadAccXRaw(void){
    union imu_data_union read_data;
    HAL_StatusTypeDef result;

    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_X_H, 1, &read_data.data_h, 1, 50);
    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_X_L, 1, &read_data.data_l, 1, 50);

    return read_data.data;
}

int16_t IMU_ReadAccYRaw(void){
    union imu_data_union read_data;
    HAL_StatusTypeDef result;

    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_Y_H, 1, &read_data.data_h, 1, 50);
    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_Y_L, 1, &read_data.data_l, 1, 50);

    return read_data.data;
}

int16_t IMU_ReadAccZRaw(void){
    union imu_data_union read_data;
    HAL_StatusTypeDef result;

    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_Z_H, 1, &read_data.data_h, 1, 50);
    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_ACC<<1), ADDR_ACC_Z_L, 1, &read_data.data_l, 1, 50);

    return read_data.data;
}

void IMU_InitMag(void){
    HAL_StatusTypeDef result;
    uint8_t settings = 0;

    result = HAL_I2C_Mem_Write(&hi2c2, (ADDR_MAG<<1), MR_REG_M, 1, &settings, 1, 50);
}

int16_t IMU_ReadMagXRaw(void){
    union imu_data_union read_data;
    HAL_StatusTypeDef result;

    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_MAG<<1), ADDR_MAG_X_H, 1, &read_data.data_h, 1, 50);
    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_MAG<<1), ADDR_MAG_X_L, 1, &read_data.data_l, 1, 50);

    return read_data.data;
}

int16_t IMU_ReadMagYRaw(void){
    union imu_data_union read_data;
    HAL_StatusTypeDef result;

    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_MAG<<1), ADDR_MAG_Y_H, 1, &read_data.data_h, 1, 50);
    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_MAG<<1), ADDR_MAG_Y_L, 1, &read_data.data_l, 1, 50);

    return read_data.data;
}

int16_t IMU_ReadMagZRaw(void){
    union imu_data_union read_data;
    HAL_StatusTypeDef result;

    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_MAG<<1), ADDR_MAG_Z_H, 1, &read_data.data_h, 1, 50);
    result = HAL_I2C_Mem_Read(&hi2c2, (ADDR_MAG<<1), ADDR_MAG_Z_L, 1, &read_data.data_l, 1, 50);

    return read_data.data;
}