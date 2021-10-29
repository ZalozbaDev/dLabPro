/* dLabPro program recognizer (dLabPro recognizer)
 * - standalone recognizer
 *
 * AUTHOR : Gunntram Strecha
 * PACKAGE: dLabPro/programs
 * 
 * Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
 * - Chair of System Theory and Speech Technology, TU Dresden
 * - Chair of Communications Engineering, BTU Cottbus
 * 
 * This file is part of dLabPro.
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

#include "vadlogger.h"

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <assert.h>

#define LOG_DIRECTORY "vad_logs/"

// should be 10s
#define MAX_NR_FRAMES_BUFFER 1000

static INT32 frame_delay;

static FLOAT32* buf1;
static FLOAT32* buf2;

// 1 or 2
static UINT32 activeBuf;

// data written to buffer
static INT64 activeBufPtrEnd;

// which frame counter does the buffer begin with
static INT64 activeBufFrameCtrStart;
// which frame counter did VAD start
static INT64 activeBufFrameCtrVadOffset;

// status of VAD
static INT16 vadStatus;

void vad_logging_init(INT32 nDelay)
{
	int result;
	
	printf("VAD logging enabled, frame delay=%d!\n", nDelay);
	
	frame_delay = nDelay;
	
	result = mkdir(LOG_DIRECTORY, 0777);
	if (result != 0)
	{
		if (errno == EEXIST)
		{
			printf("Directory %s already exists and might have old files in it.\n", LOG_DIRECTORY);	
		}
		else
		{
			printf("Directory create error %d.\n", errno);	
			assert(0);
		}
	}
	
	buf1 = (FLOAT32*) malloc(160 * sizeof(FLOAT32) * MAX_NR_FRAMES_BUFFER);
	assert(buf1 != NULL);
	buf2 = (FLOAT32*) malloc(160 * sizeof(FLOAT32) * MAX_NR_FRAMES_BUFFER);
	assert(buf2 != NULL);
	
	activeBuf = 1;
	activeBufPtrEnd = 0;
	
	activeBufFrameCtrStart = 0;
	activeBufFrameCtrVadOffset = 0;

	// start with VAD inactive
	vadStatus = 0;
}

void vad_logging_add_frame(INT64 nFrame, FLOAT32 *buffer, UINT32 length)
{
	FLOAT32* currBuf;
	FLOAT32* altBuf;
	
	// printf("Frm: %ld Buf=%d Ptr=%ld\n", nFrame, activeBuf, activeBufPtrEnd);
	
	if (activeBuf == 1)
	{
		currBuf = buf1;
		altBuf  = buf2;
	}
	else
	{
		currBuf = buf2;
		altBuf  = buf1;
	}
	
	assert(activeBufPtrEnd < (MAX_NR_FRAMES_BUFFER - 1));
	
	// remember start frame if starting to fill new buffer
	if (activeBufPtrEnd == 0)
	{
		activeBufFrameCtrStart = nFrame;
	}
	
	// copy this frame to current buffer
	memcpy(currBuf + (activeBufPtrEnd * 160), buffer, length);
	
	// not active yet, check if data needs to be duplicated
	//  0..20 = write to active buffer
	// 21..40 = write to active buffer AND write to inactive buffer at pos 0
	//     41 = switch buffers
	if (vadStatus == 0)
	{
		if ((activeBufPtrEnd > frame_delay) && (activeBufPtrEnd <= (frame_delay * 2)))
		{
			memcpy(altBuf + ((activeBufPtrEnd - frame_delay) * 160), buffer, length);
		}
		else
		{
			// switch active buffer if history in alternative buffer is sufficient
			if (activeBufPtrEnd > (2 * frame_delay))
			{
				if (activeBuf == 1)
				{
					activeBuf = 2;
				}
				else
				{
					activeBuf = 1;
				}
				activeBufPtrEnd -= frame_delay;
				
				activeBufFrameCtrStart += frame_delay;
			}
		}
	}
	
	activeBufPtrEnd++;
}

void vad_logging_frame_status(INT64 nFrame, INT16 currVADStatus)
{
	// printf("Frame %ld VAD %d.\n", nFrame, currVADStatus);
	
	if (currVADStatus == 1)
	{
		// VAD start, remember start frame and record continuously
		activeBufFrameCtrVadOffset = nFrame;
	}
	else
	{
		// ignore VAD off at program start
		if (nFrame > 0)
		{
			// VAD end, write file
			char fullfilename[200];
			char filenamepart[100];
			FILE* outfd;
			FLOAT32* currBuf;
			
			printf("VAD buffer: active=%d start=%ld vadstart=%ld size=%ld\n", activeBuf, activeBufFrameCtrStart, activeBufFrameCtrVadOffset, activeBufPtrEnd);
			
			assert(activeBufFrameCtrVadOffset > activeBufFrameCtrStart);
			
			filenamepart[0] = 0;
			snprintf(filenamepart, 100, "%08u-%08u", activeBufFrameCtrVadOffset, activeBufFrameCtrStart + activeBufPtrEnd);
			
			fullfilename[0] = 0;
			snprintf(fullfilename, 200, "%s%s.raw", LOG_DIRECTORY, filenamepart);
			
			printf("File name to open for writing: '%s'.\n", fullfilename);
			
			outfd = fopen(fullfilename, "w");
			if (outfd != NULL)
			{
				UINT32 writeBufOffset;
				UINT32 writeBufSize;
				size_t currWritten;
				
				if (activeBuf == 1)
				{
					currBuf = buf1;
				}
				else
				{
					currBuf = buf2;
				}
				
				writeBufOffset = 160 * (activeBufFrameCtrVadOffset - activeBufFrameCtrStart);
				writeBufSize = 160 * (activeBufPtrEnd - (activeBufFrameCtrVadOffset - activeBufFrameCtrStart));
				
				currWritten = fwrite(currBuf + writeBufOffset, sizeof(FLOAT32), writeBufSize, outfd);
				
				assert(currWritten == writeBufSize);
				
				fclose(outfd);
			}
			else
			{
				printf("File open error: %d\n", errno);	
			}

			// restart capture from beginning
			activeBuf = 1;
			activeBufPtrEnd = 0;
			
			activeBufFrameCtrStart = 0;
			activeBufFrameCtrVadOffset = 0;
		}
	}
	
	vadStatus = currVADStatus;
}

void vad_logging_exit(void)
{
	printf("VAD logging stopped!\n");
	
	free(buf2);
	free(buf1);
}
