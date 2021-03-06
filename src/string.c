/* Copyright 1995 by Abacus Research and
 * Development, Inc.  All rights reserved.
 */

#if !defined (OMIT_RCSID_STRINGS)
char ROMlib_rcsid_string[] =
		"$Id: string.c 88 2005-05-25 03:59:37Z ctm $";
#endif

#include "rsys/common.h"
#include "rsys/string.h"

#include "MemoryMgr.h"

void
str255_from_c_string (Str255 str255, const char *c_stringp)
{
  int len;

  len = strlen (c_stringp);
  if (len > 255)
    len = 255;
  str255[0] = len;
  memcpy (str255 + 1, c_stringp, len);
}


char *
pstr_index_after (StringPtr p, char c, int i)
{
  StringPtr ep;

  if (p)
    {
      for (ep = p + (unsigned char) p[0] + 1, p += 1 + i;
	   p < ep && *p != c;
	   p++)
	;
      return (p == ep) ? NULL : (char *) p;
    }
  else
    return NULL;
}

PRIVATE void strNassign (Str63 new, const StringPtr old, int n)
{
  int old_length, new_length;

  old_length = U (old[0]);
  if (old_length <= n)
    new_length = old_length;
  else
    {
      warning_unexpected ("Truncating string that's too long for a Str%d:  "
			  "\"%.*s\"",
			  n, old_length, old + 1);
      new_length = n;
    }

  new[0] = new_length;
  memcpy (new + 1, old + 1, new_length);
}

void
str63assign (Str63 new, const StringPtr old)
{
  strNassign (new, old, 63);
}

void
str31assign (Str63 new, const StringPtr old)
{
  strNassign (new, old, 31);
}

PUBLIC StringHandle
stringhandle_from_c_string (const char *c_stringp)
{
  int len;
  StringHandle retval;

  len = strlen (c_stringp) + 1;
  retval = (StringHandle) NewHandle (len);
  str255_from_c_string (STARH (retval), c_stringp);
  return retval;
}
