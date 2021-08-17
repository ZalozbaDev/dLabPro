// This file is part of dLabPro.
// 
// dLabPro is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
// 
// dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with dLabPro. If not, see <http://www.gnu.org/licenses/>.

#ifndef ALIGNMENT_FIXES_H
#define ALIGNMENT_FIXES_H

#include <string.h>

#include "dlp_base.h"

#include "dlp_cscope.h" /* Indicate C scope */
#include "dlp_fst.h"

inline static FLOAT64 convertINT32FromBuffer(const void* lpBuffer)
{
	char buf[sizeof(INT32)];
	
	memcpy(buf, lpBuffer, sizeof(INT32));
	
	return (FLOAT64) *buf;
}

inline static FLOAT64 convertUINT64FromBuffer(const void* lpBuffer)
{
	char buf[sizeof(UINT64)];
	
	memcpy(buf, lpBuffer, sizeof(UINT64));
	
	return (FLOAT64) *buf;
}

inline static void writeFLOAT64ToBuffer(const FLOAT64 val, void* lpBuffer)
{
	memcpy(lpBuffer, &val, sizeof(FLOAT64));
}

inline static FLOAT64 readFLOAT64ArrayIndexFromBuffer(const void* lpBuffer, INT32 nArrIdx)
{
	char buf[sizeof(FLOAT64)];
	
	memcpy(buf, &(((FLOAT64*) lpBuffer)[nArrIdx]), sizeof(FLOAT64));
	
	return (FLOAT64) *buf;
}

inline static FST_WTYPE readFSTWTYPEFromBuffer(const void* lpBuffer)
{
	char buf[sizeof(FST_WTYPE)];
	
	memcpy(buf, lpBuffer, sizeof(FST_WTYPE));
	
	return (FST_WTYPE) *buf;
}

inline static FST_STYPE readFSTSTYPEFromBuffer(const void* lpBuffer)
{
	char buf[sizeof(FST_STYPE)];
	
	memcpy(buf, lpBuffer, sizeof(FST_STYPE));
	
	return (FST_STYPE) *buf;
}

inline static void writeFSTWTYPEToBuffer(const FST_WTYPE data, void* lpBuffer)
{
	memcpy((FST_WTYPE*) lpBuffer, &data, sizeof(FST_WTYPE));
}

#endif 
