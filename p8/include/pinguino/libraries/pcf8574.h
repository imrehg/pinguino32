/*	----------------------------------------------------------------------------
	FILE:				pcf8574.h
	PROJECT:			pinguino - http://www.pinguino.cc/
	PURPOSE:			driving pcf8574 i/o expander
	PROGRAMER:		regis blanchot <rblanchot@gmail.com>
	FIRST RELEASE:	29 jul. 2008
	LAST RELEASE:	06 apr. 2011
	----------------------------------------------------------------------------
	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
	--------------------------------------------------------------------------*/

/*	----------------------------------------------------------------------------
	---------- PCF8574P
	----------------------------------------------------------------------------

	+5V		A0		-|o|-		VDD	+5V
	+5V		A1		-|	|-		SDA	pull-up 1K8 au +5V
	+5V		A2		-|	|-		SCL 	pull-up 1K8 au +5V
	LCD_BL	P0		-|	|-		INT
	LCD_RS	P1		-|	|-		P7		LCD_D7
	LCD_RW	P2		-|	|-		P6		LCD_D6
	LCD_EN	P3		-|	|-		P5		LCD_D5
	GRND		VSS	-|	|-		P4		LCD_D4

	SYMBOL 	PIN	DESCRIPTION						NB
	A0			1		address input 0				adress = 0 1 0 0 A2 A1 A0 0
	A1			2		address input 1				A0, A1 et A2 relies au +5V
	A2			3		address input 2				donc adress = 01001110 = 0x4E
	P0			4		quasi-bidirectional I/O 0	LCD_BL
	P1			5		quasi-bidirectional I/O 1	LCD_RS
	P2			6		quasi-bidirectional I/O 2	LCD_RW
	P3			7		quasi-bidirectional I/O 3	LCD_EN
	VSS		8		supply ground
	P4			9		quasi-bidirectional I/O 4	LCD_D4
	P5			10		quasi-bidirectional I/O 5	LCD_D5
	P6			11		quasi-bidirectional I/O 6	LCD_D6
	P7			12		quasi-bidirectional I/O 7	LCD_D7
	INT		13		interrupt output (active LOW)
	SCL		14		serial clock line				uC_SCL
	SDA		15		serial data line				uC_SDA
	VDD		16		supply voltage
	--------------------------------------------------------------------------*/

#ifndef __PCF8574_H
	#define __PCF8574_H

	typedef union
	{
		u8 val;
		struct
		{
			unsigned bit0 :1;
			unsigned bit1 :1;
			unsigned bit2 :1;
			unsigned bit3 :1;
			unsigned bit4 :1;
			unsigned bit5 :1;
			unsigned bit6 :1;
			unsigned bit7 :1;
		} bits;
	} Byte;							// nom du type

	// Byte toto;
	// toto.val = 255;			// si on veut utiliser la variable complète
	// toto.bits.bit5 = 1;		// si on veut utiliser un bit

	extern Byte PCF8574_data;	// les registres du PCF8574
	extern u8 PCF8574_address;

#endif

