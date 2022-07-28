/* dLabPro program recognizer (dLabPro recognizer)
 * - Header file
 *
 * AUTHOR : Frank Duckhorn
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
#ifndef _RECOGNIZER_VOSK_WRAPPER_H
#define _RECOGNIZER_VOSK_WRAPPER_H

// should create an error if different, otherwise warning only?
#define PABUF_SIZE    160

#ifdef __cplusplus
extern "C" {
#endif

int recognizer_main(int argc, char** argv);

void recognizer_exit(void);

int recognizer_get_idle_counter(void);

int recognizer_get_busy_counter(void);

int recognizer_get_vad_status(void);

char* recognizer_partial_result(void);

char* recognizer_final_result(void);

#ifdef __cplusplus
}
#endif

#endif

