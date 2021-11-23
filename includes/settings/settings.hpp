#pragma once

#define VSYNC_ENABLED false // turn to false for a free seizure! (fixed)
#define ANTI_ALIASING_SAMPLES 16 // 0 for no anti-aliasing
#define COLOR_CYCLE_FREQUENCY 4
#define COLOR_CYCLE_EXPONENTIAL_SEIZURE false // overrides COLOR_CYCLE_FREQUENCY
#define PASS_COLOR_CYCLE_TO_GPU_AS_TIME true // overrides COLOR_CYCLE_EXPONENTIAL_SEIZURE and COLOR_CYCLE_FREQUENCY