// dLabPro class CFWTproc (FWTproc)
// - Base class for fast discrete wavelet transformation.
//
// AUTHOR : Soeren Wittenberg
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify fwtproc.def instead.
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
//}}CGEN_END
#include "dlp_fwtproc.h"

// Class CFWTproc

CFWTproc::CFWTproc(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	DEBUGMSG(-1,"CFWTproc::CFWTproc; (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	dlp_strcpy(m_lpClassName,"FWTproc");
	dlp_strcpy(m_lpObsoleteName,"");
	dlp_strcpy(m_lpProjectName,"FWTproc");
	dlp_strcpy(m_version.no,"1.0");
	dlp_strcpy(m_version.date,"");
	m_nClStyle = CS_AUTOACTIVATE;

	if (bCallVirtual)
	{
		DLPASSERT(OK(AutoRegisterWords()));
		Init(TRUE);
	}
}

CFWTproc::~CFWTproc()
{
  //{{CGEN_DONECODE
  DONE;
  //}}CGEN_DONECODE
}

INT16 CFWTproc::AutoRegisterWords()
{
	DEBUGMSG(-1,"CFWTproc::AutoRegisterWords",0,0,0);
	IF_NOK(inherited::AutoRegisterWords()) return NOT_EXEC;

	//{{CGEN_REGISTERWORDS
	REGISTER_METHOD("-analyze","",LPMF(CFWTproc,OnAnalyze),"Run DWT.",0,"<data idSignal> <data idPitch> <data idReal> <data idImag> <FWTproc this>","")
	REGISTER_METHOD("-get_coef","",LPMF(CFWTproc,OnGetCoef),"Get scaling function coefficients of configured wavelet type ({@link wvltype})",0,"<data idCoef> <FWTproc this>","")
	REGISTER_METHOD("-synthesize","",LPMF(CFWTproc,OnSynthesize),"Convert scaling function and wavelet coefficients to signal.",0,"<data idTrans> <data idSignal> <FWTproc this>","")
	REGISTER_FIELD("level","",LPMV(m_nLevel),NULL,"Transformation detail level. (max. level (default) = -1; If defined          level is greater then possible transformation depth, transformation          provides with max. detail level.)",0,2002,1,"short",(INT16)-1)
	REGISTER_FIELD("wvltype","",LPMV(m_lpsWvltype),NULL,"Wavelet type (available values: haar,d2,d4,d6,...,d20)",0,5000,1,"string","d4")
	REGISTER_ERROR("~e8_1_0__1",EL_ERROR,FWT_DIM_ERROR,"Length of frame %d isn't 2^n.")
	//}}CGEN_REGISTERWORDS

	return O_K;
}

INT16 CFWTproc::Init(BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CFWTproc::Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	//{{CGEN_INITCODE
  INIT;
	//}}CGEN_INITCODE

	// If last derivation call reset (do not reset members; already done by Init())
	if (bCallVirtual) return Reset(FALSE);
	else              return O_K;
}

INT16 CFWTproc::Reset(BOOL bResetMembers)
{
	DEBUGMSG(-1,"CFWTproc::Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	//{{CGEN_RESETCODE
  RESET;
	//}}CGEN_RESETCODE

	return O_K;
}

INT16 CFWTproc::ClassProc()
{
	//{{CGEN_CLASSCODE
  return CLASSPROC;
	//}}CGEN_CLASSCODE

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CFWTproc::Serialize(CDN3Stream* lpDest)
{
	//{{CGEN_SAVECODE
  return SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific save code */
#define SAVE  SAVE_XML
INT16 CFWTproc::SerializeXml(CXmlStream* lpDest)
{
	//{{CGEN_SAVECODE
  return SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_XML

#define CODE_DN3 /* check this for dn3 specific restore code */
#define RESTORE  RESTORE_DN3
INT16 CFWTproc::Deserialize(CDN3Stream* lpSrc)
{
	//{{CGEN_RESTORECODE
  return RESTORE;
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific restore code */
#define RESTORE  RESTORE_XML
INT16 CFWTproc::DeserializeXml(CXmlStream* lpSrc)
{
	//{{CGEN_RESTORECODE
  return RESTORE;
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CFWTproc::Copy(CDlpObject* __iSrc)
{
	//{{CGEN_COPYCODE
  return COPY;
	//}}CGEN_COPYCODE

	return O_K;
}

// Runtime class type information and class factory
INT16 CFWTproc::InstallProc(void* lpItp)
{
	//{{CGEN_INSTALLCODE
  return INSTALL;
	//}}CGEN_INSTALLCODE

	return O_K;
}

CFWTproc* CFWTproc::CreateInstance(const char* lpName)
{
	CFWTproc* lpNewInstance;
	ICREATEEX(CFWTproc,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CFWTproc::GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_AUTOACTIVATE;
	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CFWTproc::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CFWTproc::InstallProc;
	lpClassWord->ex.fct.lpProject   = "FWTproc";
	lpClassWord->ex.fct.lpBaseClass = "FBAproc";
	lpClassWord->lpComment          = "Base class for fast discrete wavelet transformation.";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CFWTproc";
	lpClassWord->ex.fct.lpAuthor    = "Soeren Wittenberg";

	dlp_strcpy(lpClassWord->lpName             ,"FWTproc");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"1.0");

	return O_K;
}

INT16 CFWTproc::GetInstanceInfo(SWord* lpClassWord)
{
	return CFWTproc::GetClassInfo(lpClassWord);
}

BOOL CFWTproc::IsKindOf(const char* lpClassName)
{
  if (dlp_strncmp(lpClassName,"FWTproc",L_NAMES) == 0) return TRUE;
  else return inherited::IsKindOf(lpClassName);
}

INT16 CFWTproc::ResetAllOptions(BOOL bInit)
{
	DEBUGMSG(-1,"CFWTproc::ResetAllOptions;",0,0,0);
	//{{CGEN_RESETALLOPTIONS
	//}}CGEN_RESETALLOPTIONS

	return inherited::ResetAllOptions(bInit);
}

// Generated primary method invocation functions

#ifndef __NOITP
//{{CGEN_PMIC
INT16 CFWTproc::OnAnalyze()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	data* idImag = MIC_GET_I_EX(idImag,data,1,1);
	data* idReal = MIC_GET_I_EX(idReal,data,2,2);
	data* idPitch = MIC_GET_I_EX(idPitch,data,3,3);
	data* idSignal = MIC_GET_I_EX(idSignal,data,4,4);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Analyze(idSignal, idPitch, idReal, idImag);
	return __nErr;
}

INT16 CFWTproc::OnGetCoef()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	data* idCoef = MIC_GET_I_EX(idCoef,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = GetCoef(idCoef);
	return __nErr;
}

INT16 CFWTproc::OnSynthesize()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	data* idSignal = MIC_GET_I_EX(idSignal,data,1,1);
	data* idTrans = MIC_GET_I_EX(idTrans,data,2,2);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Synthesize(idTrans, idSignal);
	return __nErr;
}

//}}CGEN_PMIC
#endif /* #ifndef __NOITP */


// Generated secondary method invocation functions

//{{CGEN_SMIC
//}}CGEN_SMIC


// Generated option change callback functions

//{{CGEN_OCCF
//}}CGEN_OCCF


// Generated field change callback functions

//{{CGEN_FCCF
//}}CGEN_FCCF


// EOF
