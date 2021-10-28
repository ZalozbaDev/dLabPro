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

#define LOG_DIRECTORY "vad_logs/"

void vad_logging_init(void)
{
	int result;
	
	printf("VAD logging enabled!\n");
	
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
		}
	}
}

void vad_logging_frame_status(INT64 nFrame, INT16 nVadSfa)
{
	printf("Frame %ld VAD %d.\n", nFrame, nVadSfa);	
}

void vad_logging_exit(void)
{
	printf("VAD logging stopped!\n");
}
