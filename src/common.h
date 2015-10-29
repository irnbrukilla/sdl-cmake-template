#ifndef _GAME_COMMON_H_
#define _GAME_COMMON_H_ 1

#define TRUE  1
#define FALSE 0

#define implies(x, y) (!(x) || (y))

#define compare(x, y) (((x) > (y)) - ((x) < (y)))
#define sign(x) compare(x, 0)

#define size_of_array(a) (sizeof(a) / sizeof(*a))

#define swap(x, y, T) do { T tmp = (x); (x) = (y); (y) = tmp; } while(0)
#define sort2(a, b, T) do { if ((a) > (b)) swap((a), (b), T); } while (0)

#define set_of(d, n, v) do{ size_t i_, n_; for (n_ = (n), i_ = 0; n_ > 0; --n_, ++i_) (d)[i_] = (v); } while(0)
#define zero_set(d, n) SET(d, n, 0)

#endif
