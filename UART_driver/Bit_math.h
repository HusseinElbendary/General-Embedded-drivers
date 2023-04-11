/*
 * Bit_math.h
 *
 *  Created on: Aug 17, 2019
 *      Author: yomna
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)  (reg |= (1<<bit))
#define CLEAR_BIT(reg,bit)   (reg &=(~(1<<bit)))
#define GET_BIT(reg,bit)     ((reg>>bit) & 0x01)

#define TOGGLE_BIT(Reg, Bit)       (Reg^=(1<<Bit))


#endif /* BIT_MATH_H_ */
