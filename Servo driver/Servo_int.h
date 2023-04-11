/*
 * Servo_int.h
 *
 *  Created on: 17 Sep 2019
 *      Author: coder
 */

#ifndef SERVO_INT_H_
#define SERVO_INT_H_

#define SERVO_u8SERVO_1 0
#define SERVO_u8SERVO_2 1

void Servo_vidInit(u8 Servo_ID);
void Servo_vidWriteDeg(u8 Servo_ID,u16 Servo_Degree);
//u16 Servo_u16ReadDeg(u8 Servo_ID);

#endif /* SERVO_INT_H_ */
