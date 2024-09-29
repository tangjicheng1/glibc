/* Install given floating-point control modes.  SPARC version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
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

#include <fenv.h>
#include <fenv_private.h>
#include <fpu_control.h>

#define FPU_CONTROL_BITS 0xcfc00000UL

int
fesetmode (const femode_t *modep)
{
  femode_t fsr;

  __fenv_stfsr (fsr);
  fsr &= ~FPU_CONTROL_BITS;
  if (modep == FE_DFL_MODE)
    fsr |= _FPU_DEFAULT;
  else
    fsr |= *modep & FPU_CONTROL_BITS;
  __fenv_ldfsr (fsr);

  return 0;
}
