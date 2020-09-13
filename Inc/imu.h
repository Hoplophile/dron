#ifndef IMU_H
#define IMU_H

#include "main.h"

/* IMU ADDRESSES */
#define ADDR_ACC 0x19
#define ADDR_MAG 0x1E
#define ADDR_GYR 0x6B
#define ADDR_BAR 0x77

/* ACC REGISTERS */
#define ADDR_ACC_X_H    0x29
#define ADDR_ACC_X_L    0x28
#define ADDR_ACC_Y_H    0x2B
#define ADDR_ACC_Y_L    0x2A
#define ADDR_ACC_Z_H    0x2D
#define ADDR_ACC_Z_L    0x2C

#define ADDR_ACC_CTRL_REG1  0x20

/* MAG CONFIG BITS */
#define ACC_100HZ       0x50 //100Hz
#define ACC_ENABLE      0x07 //enable X,Y,Z

/* MAG REGISTERS */
#define ADDR_MAG_X_H    0x03
#define ADDR_MAG_X_L    0x04
#define ADDR_MAG_Y_H    0x07
#define ADDR_MAG_Y_L    0x08
#define ADDR_MAG_Z_H    0x05
#define ADDR_MAG_Z_L    0x06

#define MR_REG_M        0x02

/* MAG CONFIG BITS */


/* FUNCTIONS */
void IMU_InitAcc(void);
int16_t IMU_ReadAccXRaw(void);
int16_t IMU_ReadAccYRaw(void);
int16_t IMU_ReadAccZRaw(void);

void IMU_InitMag(void);
int16_t IMU_ReadMagXRaw(void);
int16_t IMU_ReadMagYRaw(void);
int16_t IMU_ReadMagZRaw(void);

#endif 