/* Copyright (C) 2000-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <stdio_ext.h>

#undef __fsetlocking

int
__fsetlocking (FILE *fp, int type)
{
  int result = ((fp->_flags & _IO_USER_LOCK)
		? FSETLOCKING_BYCALLER : FSETLOCKING_INTERNAL);

  if (type != FSETLOCKING_QUERY)
    {
      fp->_flags &= ~_IO_USER_LOCK;
      if (type == FSETLOCKING_BYCALLER)
	 fp->_flags |= _IO_USER_LOCK;
    }

  return result;
}
libc_hidden_def (__fsetlocking)
