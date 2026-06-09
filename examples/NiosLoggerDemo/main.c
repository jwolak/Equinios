/*-
 * BSD 3-Clause License
 *
 * Copyrights 2026, Janusz Wolak
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include "equinios.h"

#include <stdint.h>

static uint32_t g_demo_ticks = 0u;

static uint32_t demo_timestamp_provider(void)
{
  return g_demo_ticks;
}

int main(void)
{
  uint32_t loop = 0u;
  uint32_t dropped;

  log_set_level(LOG_LEVEL_TRACE);
  log_set_process_every_n_calls(1u);
  log_set_timestamp_provider(demo_timestamp_provider);

  LOGI("EquiniosLogger demo started");
  LOGI("Logger flush is called from main loop");

  while (1)
  {
    g_demo_ticks++;

    if ((loop % 1000u) == 0u)
    {
      LOGD("Heartbeat loop=%lu", (unsigned long)loop);
    }

    if ((loop % 5000u) == 0u)
    {
      LOGW("Warning sample loop=%lu", (unsigned long)loop);
    }

    if ((loop % 20000u) == 0u)
    {
      LOGE("Error sample loop=%lu", (unsigned long)loop);
    }

    if ((loop % 10000u) == 0u)
    {
      dropped = log_get_dropped_lines();
      if (dropped > 0u)
      {
        LOGW("Dropped log lines since last check: %lu", (unsigned long)dropped);
        log_reset_dropped_lines();
      }
    }

    log_process();
    loop++;
  }
}
