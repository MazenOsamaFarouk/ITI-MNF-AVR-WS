/*
 * SPI_private.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mazen
 */

#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

#define SPIF    7


#define SPDR   *((volatile u8*)(0x2F))
#define SPSR   *((volatile u8*)(0x2E))
#define SPCR   *((volatile u8*)(0x2D))





#endif /* SPI_SPI_PRIVATE_H_ */
