// dLabPro class CDgen (DGen)
// - Header file
//
// AUTHOR : Matthias Wolff
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify dgen.def instead.
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
#include "dlp_data.h"
#include "dlp_fst.h"
//}}CGEN_END

//{{CGEN_ERRORS
#undef DG_TOOFEWCOMPS      
#undef DG_NOTSYMBCOMPTYPE  
#undef DG_TOOLONG          
#undef DG_TOOLONG2         
#undef DG_HERESCRIPT       
#undef DG_STREXCEEDSLINE   
#undef DG_PARSER           
#undef DG_OPCODE           
#undef DG_SYNTAX           
#undef DG_SYNTAX2          
#undef DG_EXPECT           
#undef DG_AWOB             
#undef DG_JVD              
#define DG_TOOFEWCOMPS       -1001
#define DG_NOTSYMBCOMPTYPE   -1002
#define DG_TOOLONG           -1003
#define DG_TOOLONG2          -1004
#define DG_HERESCRIPT        -1005
#define DG_STREXCEEDSLINE    -1006
#define DG_PARSER            -1007
#define DG_OPCODE            -1008
#define DG_SYNTAX            -1009
#define DG_SYNTAX2           -1010
#define DG_EXPECT            -1011
#define DG_AWOB              -1012
#define DG_JVD               -1013
//}}CGEN_END

// C/C++ language abstraction layer
#undef dgen_par
#define dgen_par CDgen

// dLabPro/C++ language abstraction layer
#undef DGen
#define DGen CDgen

//{{CGEN_DEFINE
#define TT_LCMT       "cl"
#define TT_BCMT       "cb"
#define TT_DCMT       "cd"
#define TT_DRCT       "cv"
#define TT_STR        "ss"
#define TT_CHR        "sc"
#define TT_DEL        "d"
#define TT_UNK        "?"
#define TT_WSPC       "w"
#define TT_ELIN       "e"
#define TT_FORM       "fm"
#define TT_LAB        "?L"
#define DL_NONE        0
#define DL_SIGN        1
#define DL_INSIGN      2
#define OF_LINE        0
#define OF_TTYP        1
#define OF_TOK         2
#define OF_BLV0        3
#define OF_BLV1        4
#define OF_BLV2        5
#define OF_IDEL        6
#define OF_SRCID       7
#define CDM_OF_DOBT    0
#define CDM_OF_DSPC    1
#define CDM_OF_NAME    2
#define CDM_OF_EXT1    3
#define CDM_OF_EXT2    4
#define CDM_OF_FTOK    5
#define CDM_OF_LTOK    6
#define CDM_OF_FTOKD   7
#define CDM_OF_LTOKD   8
#define CDM_OT_FHEAD   0
#define CDM_OT_FFARG   1
#define UDM_OF_DOBT    0
#define UDM_OF_NAME    1
#define UDM_OF_TYPE    2
#define UDM_OF_EXT1    3
#define UDM_OF_FTOK    4
#define UDM_OF_LTOK    5
#define UDM_OF_FJVD    6
#define UDM_OF_NJVD    7
#define UDM_OT_CLARG   0
#define UDM_OT_FHEAD   1
#define UDM_OT_FRETV   2
#define UDM_OT_FFARG   3
#define UDM_OT_FGLOB   4
#define UDM_OT_FSEE    5
#define __TTYP_IS_EX(THIS,A,B) (dlp_strcmp((char*)THIS->XAddr(A,OF_TTYP),B)==0)
#define __TOK_IS_EX(THIS,A,B)  (dlp_strcmp((char*)THIS->XAddr(A,OF_TOK ),B)==0)
#define __TTYP_EX(THIS,A)      ( (char* )THIS->XAddr(A,OF_TTYP  ))
#define __TOK_EX(THIS,A)       ( (char* )THIS->XAddr(A,OF_TOK   ))
#define __LINE_EX(THIS,A)      (*(INT32* )THIS->XAddr(A,OF_LINE  ))
#define __BLV_EX(THIS,A,B)     (*(INT16*)THIS->XAddr(A,OF_BLV0+B))
#define __IDEL_EX(THIS,A)      ( (char* )THIS->XAddr(A,OF_IDEL  ))
#define __TTYP_IS(A,B)         __TTYP_IS_EX(m_idTsq,A,B)
#define __TOK_IS(A,B)          __TOK_IS_EX(m_idTsq,A,B)
#define __TTYP(A)              __TTYP_EX(m_idTsq,A)
#define __TOK(A)               __TOK_EX(m_idTsq,A)
#define __LINE(A)              __LINE_EX(m_idTsq,A)
#define __BLV(A,B)             __BLV_EX(m_idTsq,A,B)
#define __IDEL(A)              __IDEL_EX(m_idTsq,A)
//}}CGEN_DEFINE

#ifndef __DGEN_H
#define __DGEN_H

//{{CGEN_HEADERCODE
//}}CGEN_HEADERCODE

// Class CDgen

class CDgen : public CDlpObject 
{

typedef CDlpObject inherited;
typedef CDgen thisclass;

//{{CGEN_FRIENDS
	friend class CCgen;
	friend class CFunction;
//}}CGEN_FRIENDS
public:
	CDgen(const char* lpInstanceName, BOOL bCallVirtual = 1);
	virtual ~CDgen();

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
	static  CDgen* CreateInstance(const char* lpName);
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
	INT16 OnEditSection();
	INT16 OnLoad();
	INT16 OnParse();
	INT16 OnScan();
	INT16 OnSetup();
	INT16 OnTable();
	INT16 OnTokenize();
	INT16 OnWrite();
	INT16 OnAddText();
//}}CGEN_PMIC
#endif // #ifndef __NOITP

// Secondary method invocation functions
public:
//{{CGEN_SMIC
//}}CGEN_SMIC

// Option changed callback functions
public:
//{{CGEN_OCCF
//}}CGEN_OCCF

// Field changed callback functions
public:
//{{CGEN_FCCF
	INT16 OnIdelChanged();
	INT16 OnSdelChanged();
//}}CGEN_FCCF

// Scanned member functions
//{{CGEN_EXPORT

// Taken from 'dg_iam.cpp'
	public: INT16 Setup(const char* lpsParser);
	public: INT16 Scan(const char* lpsFilename, const char* lpsParser, CFst* itDeps);
	public: INT16 Parse(const char* lpsParser, CFst* itDeps, INT32 nFtok, INT32 nLtok);

// Taken from 'dg_cpp.cpp'
	protected: void CppMoveAsterisk(char* lpsDst, char* lpsSrc);
	protected: INT16 CppParseArg(INT32 nFtokA, INT32 nLtokA, BOOL bLastA);
	protected: INT32 CppParseArgl(INT32 nFtokL, INT32 nLtokL);
	protected: void CppParser(INT32 nFtok, INT32 nLtok);

// Taken from 'dg_dlp.cpp'
	protected: void DlpTokenize2(BOOL bFragment);
	protected: void DlpParser(CFst* itDeps, INT32 nFtok, INT32 nLtok);

// Taken from 'dg_gen.cpp'
	protected: INT16 AddText(const char* lpsText, const char* lpsDel = "");
	public: INT16 HereScript();
	public: INT16 Table(CData* idTab, char* sPre, char* sDel, char* sSuf);
	public: INT16 Load(char* sFilename);
	public: INT16 EditSection(char* lpMarkOn, char* lpMarkOff, CData* idText, char* lpOpname);
	public: INT16 Write(char* sFilename);

// Taken from 'dg_scan.cpp'
	protected: const char* ScanKey(const char* lpsBuffer, const char* lpsKey);
	protected: INT32 StoreProperty(const char* lpsKey, const char* lpsValue, INT32 nPos = -1);
	protected: INT32 TxtStore(const char* lpsTxt, INT32* lpnFrec = 0);

// Taken from 'dg_tok.cpp'
	public: static void TsqInit(CData* idTsq);
	protected: void TsqPrint(INT32 nFtok, INT32 nLtok);
	protected: char* TsqGlue(INT32 nFtok, INT32 nLtok, BOOL bNorm);
	protected: void TsqTrim(INT32* lpFtok, INT32* lpLtok);
	protected: INT16 TsqIsDelimiter(char nChar);
	protected: void TsqStore(const char* lpsToken, INT32 nLen, const char* lpsFile, INT32 nLine, const char* lpsTtype, const INT16 lpBlv[ 3 ]);
	protected: void TsqStoreIdel(const char* lpsIdel, INT32 nLen, const char* lpsFile, INT32 nLine);
	public: INT16 TokenizeString(const char* lpsLine, INT32 nLine = -1, BOOL* lpbInCmt = NULL, BOOL* lpbInDcmt = NULL, INT16* lpanBlv = NULL);
	public: INT16 Tokenize(const char* lpsFilename);
	protected: INT16 Tokenize2(const char* lpsParser, BOOL bFragment = FALSE);

// Taken from 'dg_uasr.cpp'
	protected: void UasrJavaDoc(INT32 nDomItm, INT32 nFtok, INT32 nLtok, bool nParamExists);
	protected: void UasrParser(CFst* itDeps, INT32 nFtok, INT32 nLtok);

// Taken from 'dg_fml.cpp'
	protected: INT16 FmlTokenize2();
	protected: void FmlParser(INT32 nFtok, INT32 nLtok);

// Taken from 'dg_perl.cpp'
	protected: void PerlParser(INT32 nFtok, INT32 nLtok);
	protected: void PerlTokenize2(BOOL bFragment);
//}}CGEN_EXPORT

// Member variables
public:

//{{CGEN_FIELDS
	char             m_lpsBcmtoff[8];
	char             m_lpsBcmton[8];
	INT16            m_bChrs;
	char             m_lpsDcmt[8];
	CData*           m_idDom;
	char             m_lpsDrct[8];
	char             m_lpsFilename[255];
	CData*           m_idGen;
	INT32            m_nGrany;
	char             m_lpsIdel[64];
	char             m_lpsLcmt[8];
	char             m_lpsSdel[64];
	CData*           m_idSpl;
	INT16            m_bStrs;
	CData*           m_idTsq;
	CData*           m_idTxt;
//}}CGEN_FIELDS

//{{CGEN_OPTIONS
	BOOL m_bBare;
//}}CGEN_OPTIONS
}

;

// Scanned C (member) functions
//{{CGEN_CEXPORT

// Taken from 'dg_iam.cpp'

// Taken from 'dg_cpp.cpp'

// Taken from 'dg_dlp.cpp'

// Taken from 'dg_gen.cpp'

// Taken from 'dg_scan.cpp'

// Taken from 'dg_tok.cpp'

// Taken from 'dg_uasr.cpp'

// Taken from 'dg_fml.cpp'

// Taken from 'dg_perl.cpp'
//}}CGEN_CEXPORT

#endif //#ifndef __DGEN_H


// EOF
