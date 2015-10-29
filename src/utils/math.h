#ifndef _GAME_UTILS_MATH_H_
#define _GAME_UTILS_MATH_H_ 1

#define compare_floats(a,b,epsilon) (fabs(a - b) <= epsilon * fabs(a))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#endif
