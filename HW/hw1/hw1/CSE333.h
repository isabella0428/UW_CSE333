/*
 * Copyright 2012 Steven Gribble
 *
 *  This file is part of the UW CSE333 project sequence (333proj).
 *
 *  333proj is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or (at your option) any later version.
 *
 *  333proj is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 333proj. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HW1_CSE333_H_
#define _HW1_CSE333_H_

#include <stdint.h>  // for uint32_t, etc.

// We abstract the idea of some quantities into user defined types
//  so  that we could, in theory, easily change between uint32_t and
// uint64_t realizations, say.

typedef uint32_t HWSize_t;   // for sizes of containers and indices into containers

// A wrapper for assert that permits side-effects within the
// Verify333() statement.  Borrowed from:
//
//   http://www.acm.uiuc.edu/sigops/roll_your_own/2.a.html

void VerificationFailure(const char *exp, const char *file,
                         const char *basefile, int line);

#define Verify333(exp) if (exp) ; \
  else VerificationFailure(#exp, __FILE__, __BASE_FILE__, __LINE__)

#endif  // _HW1_CSE333_H_
