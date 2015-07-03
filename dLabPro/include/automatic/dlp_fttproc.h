// dLabPro class CFTTproc (FTTproc)
// - Header file
//
// AUTHOR : Steffen Kuerbis
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify fttproc.def instead.
// 
// Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
// - Chair of System Theory and Speech Technology, TU Dresden
// - Chair of Communications Engineering, BTU Cottbus
// 
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


//{{CGEN_INCLUDE
#include "dlp_config.h"
#include "dlp_object.h"
#include "dlp_fbaproc.h"
#include "dlp_data.h"
#include "dlp_math.h"
//}}CGEN_END

//{{CGEN_ERRORS
#undef FTT_LEN             
#undef FTT_WINDOW          
#undef FTT_WTYPE           
#define FTT_LEN              -1018
#define FTT_WINDOW           -1019
#define FTT_WTYPE            -1020
//}}CGEN_END

// C/C++ language abstraction layer
#undef fttproc_par
#define fttproc_par CFTTproc

// dLabPro/C++ language abstraction layer
#undef FTTproc
#define FTTproc CFTTproc

//{{CGEN_DEFINE
//}}CGEN_DEFINE

#ifndef __FTTPROC_H
#define __FTTPROC_H

//{{CGEN_HEADERCODE
//}}CGEN_HEADERCODE

// Class CFTTproc

class CFTTproc : public CFBAproc 
{

typedef CFBAproc inherited;
typedef CFTTproc thisclass;

//{{CGEN_FRIENDS
//}}CGEN_FRIENDS
public:
	CFTTproc(const char* lpInstanceName, BOOL bCallVirtual = 1);
	virtual ~CFTTproc();

// Virtual and static function overrides
public:
	virtual INT16 AutoRegisterWords();
	virtual INT16 Init(BOOL bCallVirtual = 0);
	virtual INT16 Reset(BOOL bResetMembers = 1);
	virtual INT16 Serialize(CDN3Stream* lpDest);
	virtual INT16 SerializeXml(CXmlStream* lpDest);
	virtual INT16 Deserialize(CDN3Stream* lpSrc);
	virtual INT16 DeserializeXml(CXmlStream* lpSrc);
	virtual INT16 Copy(CDlpObject* iSrc);
	virtual INT16 ClassProc();
	static  INT16 InstallProc(void* lpItp);
	static  CFTTproc* CreateInstance(const char* lpName);
	static  INT16 GetClassInfo(SWord* lpClassWord);
	virtual INT16 GetInstanceInfo(SWord* lpClassWord);
	virtual BOOL  IsKindOf(const char* lpClassName);
	virtual INT16 ResetAllOptions(BOOL bInit = 0);

// Primary method invocation functions            
// DO NOT CALL THESE FUNCTIONS FROM C SCOPE.      
// THEY MAY INTERFERE WITH THE INTERPRETER SESSION
#ifndef __NOITP
public:
//{{CGEN_PMIC
	INT16 OnAnalyze();
//}}CGEN_PMIC
#endif // #ifndef __NOITP

// Secondary method invocation functions
public:
//{{CGEN_SMIC
	INT16 Analyze(data* dSignal, data* dPitch, data* dReal, data* dImag);
//}}CGEN_SMIC

// Option changed callback functions
public:
//{{CGEN_OCCF
//}}CGEN_OCCF

// Field changed callback functions
public:
//{{CGEN_FCCF
	INT16 OnBandwidthChanged();
	INT16 OnCoeffChanged();
	INT16 OnFincChanged();
	INT16 OnFttTypeChanged();
	INT16 OnLogChanged();
	INT16 OnMaxvalChanged();
	INT16 OnNormCoeffChanged();
	INT16 OnSmCoeffChanged();
	INT16 OnStartfreqChanged();
//}}CGEN_FCCF

// Scanned member functions
//{{CGEN_EXPORT

// Taken from 'ftt_work.cpp'
	public: INT16 AnalyzeFrame();
	public: virtual void PrepareOutput(CData* dResult);
	private: INT16 InitFTT(INT16 noreset);
	protected: INT16 InitBuffers();

// Taken from 'ftt_stat.cpp'
	public: void Status();
//}}CGEN_EXPORT

// Member variables
public:

//{{CGEN_FIELDS
	FLOAT32          m_nBandwidth;
	INT32            m_nCoeff;
	FLOAT32          m_nFinc;
	MLP_FTT_TYPE*    m_lpFtt;
	char             m_lpsFttType[255];
	FLOAT32          m_nLog;
	FLOAT32          m_nMaxval;
	FLOAT32          m_nNormCoeff;
	FLOAT32          m_nSmCoeff;
	FLOAT32          m_nStartfreq;
//}}CGEN_FIELDS

//{{CGEN_OPTIONS
	BOOL m_bNoreset;
//}}CGEN_OPTIONS
}

;

// Scanned C (member) functions
//{{CGEN_CEXPORT

// Taken from 'ftt_work.cpp'

// Taken from 'ftt_stat.cpp'
//}}CGEN_CEXPORT

#endif //#ifndef __FTTPROC_H


// EOF
