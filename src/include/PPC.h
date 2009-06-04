#if !defined (_PPC_H_)
#define _PPC_H_

/* Copyright 1996 by Abacus Research and Development, Inc.
 * All rights reserved.
 *
 * $Id: PPC.h 63 2004-12-24 18:19:43Z ctm $
 */

typedef int16 PPCPortKinds;
typedef int16 PPCLocationKind;

typedef struct EntityName
{
  /* #### bogus */
} EntityName;

typedef struct LocationNameRec
{
  PPCLocationKind locationKindSelector	PACKED;
  
  union
    {
      EntityName npbEntity		LPACKED;
      Str32 npbType			LPACKED;
    } u					LPACKED;
} LocationNameRec;

typedef struct PPCPortRec
{
  ScriptCode nameScript			PACKED;
  Str32 name				LPACKED;
  
  PPCPortKinds portKindsSelector	PACKED;
  
  union
    {
      Str32 portTypeStr			LPACKED;
      struct
        {
	  OSType creator		PACKED;
	  OSType type			PACKED;
        } port				LPACKED;
    } u					LPACKED;
} PPCPortRec, *PPCPortPtr;

#endif /* !_PPC_H_ */
