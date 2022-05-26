#include "Filter.h"

static double filter_taps[FILTER_TAP_NUM] = {
  0.009946748262632829,
  -0.0004420042728980889,
  -0.014953307817692385,
  -0.0054195735588639425,
  0.0047424661108033984,
  -0.008679566512622939,
  -0.007178215505627076,
  0.010453435690882784,
  -0.00243719645110471,
  -0.013837970031658813,
  0.011097708284911507,
  0.008054104024537361,
  -0.020542661796577676,
  0.003983395444191073,
  0.022770620994058178,
  -0.02193472007149754,
  -0.013764958940867407,
  0.039170339995545624,
  -0.010823692014528746,
  -0.04705816597396291,
  0.05339041824490635,
  0.03124051251090246,
  -0.1262128164499602,
  0.06167840235456709,
  0.5171426359462703,
  0.5171426359462703,
  0.06167840235456709,
  -0.1262128164499602,
  0.03124051251090246,
  0.05339041824490635,
  -0.04705816597396291,
  -0.010823692014528746,
  0.039170339995545624,
  -0.013764958940867407,
  -0.02193472007149754,
  0.022770620994058178,
  0.003983395444191073,
  -0.020542661796577676,
  0.008054104024537361,
  0.011097708284911507,
  -0.013837970031658813,
  -0.00243719645110471,
  0.010453435690882784,
  -0.007178215505627076,
  -0.008679566512622939,
  0.0047424661108033984,
  -0.0054195735588639425,
  -0.014953307817692385,
  -0.0004420042728980889,
  0.009946748262632829
};

void Filter_init(Filter* f) {
  int i;
  for(i = 0; i < FILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void Filter_put(Filter* f, double input) {
  f->history[f->last_index++] = input;
  if(f->last_index == FILTER_TAP_NUM)
    f->last_index = 0;
}

double Filter_get(Filter* f) {
  double acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < FILTER_TAP_NUM; ++i) {
    index = index != 0 ? index-1 : FILTER_TAP_NUM-1;
    acc += f->history[index] * filter_taps[i];
  };
  return acc;
}
