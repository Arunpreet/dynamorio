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

/* Export instrumented functions so we can easily find them in client.  */
#ifdef WINDOWS
# define EXPORT __declspec(dllexport)
#else /* LINUX */
# define EXPORT __attribute__((visibility("default")))
#endif

/* List of instrumented functions. */
#define FUNCTIONS() \
        FUNCTION(empty) \
        FUNCTION(empty_push) \
        FUNCTION(enterleave) \
        FUNCTION(entermovpop) \
        FUNCTION(scheduled_prologue) \
        FUNCTION(inscount) \
        FUNCTION(callpic_pop) \
        FUNCTION(callpic_mov) \
        FUNCTION(callpic_out) \
        FUNCTION(nonleaf) \
        FUNCTION(cond_br) \
        FUNCTION(tls_clobber) \
        FUNCTION(aflags_clobber) \
        FUNCTION(decode_past_ret) \
        FUNCTION(decode_loop) \
        FUNCTION(partial_global) \
        FUNCTION(optimize_flags) \
        LAST_FUNCTION()

/* Definitions for every function. */
#define FUNCTION(FUNCNAME) EXPORT void FUNCNAME(void) { }
#define LAST_FUNCTION()
FUNCTIONS()
#undef FUNCTION
#undef LAST_FUNCTION

int
main(void)
{
    /* Calls to every function. */
#define FUNCTION(FUNCNAME) FUNCNAME();
#define LAST_FUNCTION()
    FUNCTIONS()
#undef FUNCTION
#undef LAST_FUNCTION
}
