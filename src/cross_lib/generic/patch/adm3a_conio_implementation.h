/*****************************************************************************/
/*                                                                           */
/*                                		                                     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2017      Fabrizio Caruso                                  		     */
/*                					                                         */
/*              				                                             */
/* EMail:        Fabrizio_Caruso@hotmail.com                                 */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

#ifndef _ADM3A_CONIO_IMPLEMENTATION
#define _ADM3A_CONIO_IMPLEMENTATION
	#include <stdio.h>

	#define gotoxy(x,y) printf("\033=%c%c",y+32,x+32);

	#define clrscr() printf("\032")

	#define cprintf printf
	
	#if defined(Z88DK)
		#define cputc(c) fputc_cons(c)
		#define cgetc() getk()
	#else
		#define cputc(c) putchar()
		#define cgetc() getch()		
	#endif

	#if defined(NO_COLOR)
		#define textcolor 
	#endif
	
#endif // ADM3A_CONIO_IMPLEMENTATION

