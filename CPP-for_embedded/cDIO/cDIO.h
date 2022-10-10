/*
 * cDIO.h
 *
 *  Created on: Oct 8, 2022
 *      Author: mazen
 */

#ifndef CDIO_CDIO_H_
#define CDIO_CDIO_H_

#include "../DIO/DIO_interface.h"


class cDIO
{

public:
	void	setPinDir(u8 port, u8 pin, u8 dir);
	void 	setPinVal(u8 port, u8 pin, u8 val);
};



#endif /* CDIO_CDIO_H_ */
