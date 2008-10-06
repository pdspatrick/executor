
#if !defined (_MACTYPES_H_)
#define _MACTYPES_H_

/*
 * Copyright 1986, 1989, 1990, 1995 by Abacus Research and Development, Inc.
 * All rights reserved.
 *
 * $Id: MacTypes.h 86 2005-05-25 00:47:12Z ctm $
 */


#define a5	(EM_A5)

typedef int8 SignedByte;
typedef uint8 Byte;
typedef int8 *Ptr;

typedef struct { Ptr p PACKED_P; } HIDDEN_Ptr;
typedef HIDDEN_Ptr *Handle;
typedef struct { Handle p PACKED_P; } HIDDEN_Handle;

typedef BOOLEAN Boolean;

typedef Byte Str15[16];
typedef Byte Str31[32];
typedef Byte Str32[33];
typedef Byte Str63[64];
typedef Byte Str255[256];
typedef Byte *StringPtr;

typedef struct { StringPtr p PACKED_P; } HIDDEN_StringPtr;
typedef HIDDEN_StringPtr *StringHandle;

typedef int (*ProcPtr)();
typedef struct { ProcPtr p PACKED_P; } HIDDEN_ProcPtr;

typedef LONGINT Fixed, Fract;

/* SmallFract represnts values between 0 and 65535 */
typedef unsigned short SmallFract;

#define MaxSmallFract 0xFFFF

typedef double Extended;

typedef LONGINT Size;

typedef INTEGER OSErr;
typedef LONGINT OSType;
typedef	LONGINT ResType;

typedef	LONGINT	OSErrRET;	/* for smashing d0 just like the Mac */
typedef	LONGINT	INTEGERRET;
typedef	LONGINT	BOOLEANRET;
typedef	LONGINT	SignedByteRET;

typedef struct {
    INTEGER qFlags	PACKED;
    union __qe *qHead	PACKED_P;	/* actually QElemPtr */
    union __qe *qTail	PACKED_P;	/* actually QElemPtr */
} QHdr;
typedef QHdr *QHdrPtr;
typedef union __qe *QElemPtr;

typedef struct { QElemPtr p PACKED_P; } HIDDEN_QElemPtr;

#define noErr	0

/* from Quickdraw.h */
typedef struct Point
{
  INTEGER v	PACKED;
  INTEGER h	PACKED;
} Point;

#define NULL_POINTP ((Point *) NULL)

#define ZEROPOINT(p) (p.v = CWC (0), p.h = CWC (0))

typedef struct Rect
{
  INTEGER top		PACKED;
  INTEGER left		PACKED;
  INTEGER bottom	PACKED;
  INTEGER right		PACKED;
} Rect;

typedef Rect *RectPtr;

#define RECT_WIDTH(r)				\
({						\
  const Rect *__r = (r);			\
  CW (__r->right) - CW (__r->left);		\
})
#define RECT_HEIGHT(r)				\
({						\
  const Rect *__r = (r);			\
  CW (__r->bottom) - CW (__r->top);		\
})

#define NULL_RECTP	((Rect *) NULL)

#define RECT_ZERO(r)				\
do						\
  memset (r, 0, sizeof (Rect));			\
while (FALSE)

#define RECT_EQUAL_P(r1, r2)			\
({						\
  const uint32 *__p1 = (const uint32 *) (r1);	\
  const uint32 *__p2 = (const uint32 *) (r2);	\
  __p1[0] == __p2[0] && __p1[1] == __p2[1];	\
})

/* from IntlUtil.h */
typedef INTEGER ScriptCode;
typedef INTEGER LangCode;

/* DO NOT DELETE THIS LINE */
extern INTEGER 	ROM85;
extern INTEGER 	DSErrCode;
#endif /* _MACTYPES_H_ */