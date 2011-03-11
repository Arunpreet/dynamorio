/* *******************************************************************************
 * Copyright (c) 2011 Massachusetts Institute of Technology  All rights reserved.
 * *******************************************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of MIT nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL MIT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

/* Most functions here need to be exported and not inlined no matter the build
 * mode so that we can find their addresses via symbol lookup for
 * instrumentation.
 */
#ifdef WINDOWS
#define EXPORT __declspec(dllexport)
#define NOINLINE __declspec(noinline)
#else
#define EXPORT __attribute__((visibility("default")))
#define NOINLINE __attribute__((noinline))
#endif

EXPORT NOINLINE void empty() {}
EXPORT NOINLINE void inscount() {}
EXPORT NOINLINE void callpic_pop() {}
EXPORT NOINLINE void callpic_mov() {}
EXPORT NOINLINE void cond_br() {}
EXPORT NOINLINE void tls_clobber() {}
EXPORT NOINLINE void nonleaf() {}

int
main(void)
{
    empty();
    inscount();
    callpic_pop();
    callpic_mov();
    cond_br();
    tls_clobber();
    nonleaf();
}
