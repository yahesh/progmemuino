/*
 * File:    progmemuino.h
 * Author:  Yahe <hello@yahe.sh>
 * Version: 0.4.0
 *
 * Created on 06. May 2013
 *
 * Release 0.1.0 on 06. May 2013
 * initial implementation
 *
 * Release 0.2.0 on 10. May 2013
 * introduced PROGMEM
 * introduced password-check option
 * enhanced chunk API
 *
 * Release 0.3.0 on 12. May 2013
 * changed special char generation from hashInformation to hmacPassword
 *
 * Release 0.4.0 on 18. July 2013
 * hardened against dictionary attacks against hashInformation
 * renamed hashInformation to hmacInformation
 */

/*
 * progmemuino.h contains an implementation of a compatibility layer for PROGMEM.
 *
 * Copyright (C) 2013-2018 Yahe <hello@yahe.sh>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __PROGMEMUINO_H__
#define	__PROGMEMUINO_H__

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef ARDUINO

#include <avr/pgmspace.h>

#define pm_byte(x,y)  ((uint8_t)pgm_read_byte_near(x+y))
#define pm_word(x,y)  ((uint16_t)pgm_read_word_near(x+y))
#define pm_dword(x,y) ((uint32_t)pgm_read_dword_near(x+y))
#define pm_float(x,y) ((float)pgm_read_float_near(x+y))

#else

#define PROGMEM /**/

#define prog_char     int8_t
#define prog_uchar    uint8_t
#define prog_int16_t  int16_t
#define prog_uint16_t uint16_t
#define prog_int32_t  int32_t
#define prog_uint32_t uint32_t

#define pm_byte(x,y)  ((uint8_t)x[y])
#define pm_word(x,y)  ((uint16_t)x[y])
#define pm_dword(x,y) ((uint32_t)x[y])
#define pm_float(x,y) ((float)x[y])

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* __PROGMEMUINO_H__ */
