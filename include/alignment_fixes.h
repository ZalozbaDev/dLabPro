/* This file is part of dLabPro.
 * 
 * dLabPro is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with dLabPro. If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef ALIGNMENT_FIXES_H
#define ALIGNMENT_FIXES_H

#include <string.h>

#include "dlp_base.h"

#include "dlp_cscope.h" /* Indicate C scope */
#include "dlp_fst.h"

#if ARCHITECURE == arm

#warning "Applying alignment exception workarounds!"

#endif

__inline__ static FLOAT64 convertINT32FromBuffer(const void* lpBuffer)
{
#if ARCHITECURE == arm
	INT32 tmp;
	
	memcpy(&tmp, lpBuffer, sizeof(INT32));
	
	return (FLOAT64) tmp;
#else
	return (FLOAT64) (*(INT32*)lpBuffer);
#endif
}

__inline__ static FLOAT64 convertUINT64FromBuffer(const void* lpBuffer)
{
#if ARCHITECURE == arm
	UINT64 tmp;
	
	memcpy(&tmp, lpBuffer, sizeof(UINT64));
	
	return (FLOAT64) tmp;
#else
	return (FLOAT64) (*(UINT64)lpBuffer);
#endif
}

__inline__ static void writeFLOAT64ToBuffer(const FLOAT64 val, void* lpBuffer)
{
#if ARCHITECURE == arm
	memcpy(lpBuffer, &val, sizeof(FLOAT64));
#else
	*(FLOAT64*)lpBuffer = val;
#endif
}

__inline__ static FLOAT64 readFLOAT64ArrayIndexFromBuffer(const void* lpBuffer, INT32 nArrIdx)
{
#if ARCHITECURE == arm
	FLOAT64 tmp;
	
	memcpy(&tmp, &(((FLOAT64*) lpBuffer)[nArrIdx]), sizeof(FLOAT64));
	
	return tmp;
#else
	
#endif
}

__inline__ static FST_WTYPE readFSTWTYPEFromBuffer(const void* lpBuffer)
{
#if ARCHITECURE == arm
	FST_WTYPE tmp;
	
	memcpy(&tmp, lpBuffer, sizeof(FST_WTYPE));
	
	return tmp;
#else
	return *(FST_WTYPE*)lpBuffer;
#endif
}

__inline__ static FST_STYPE readFSTSTYPEFromBuffer(const void* lpBuffer)
{
#if ARCHITECURE == arm
	FST_STYPE tmp;
	
	memcpy(&tmp, lpBuffer, sizeof(FST_STYPE));
	
	return tmp;
#else
	eturn *(FST_STYPE*)lpBuffer;
#endif
}

__inline__ static void writeFSTWTYPEToBuffer(const FST_WTYPE data, void* lpBuffer)
{
#if ARCHITECURE == arm
	memcpy((FST_WTYPE*) lpBuffer, &data, sizeof(FST_WTYPE));
#else
	*(FST_WTYPE*)lpBuffer = data;
#endif
}

#endif 
