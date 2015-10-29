
//
// buffer.h
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef _GAME_UTILS_BUFFER_H_
#define _GAME_UTILS_BUFFER_H_ 1

#include <sys/types.h>

/*
 * Default buffer size.
 */

#ifndef BUFFER_DEFAULT_SIZE
#define BUFFER_DEFAULT_SIZE 64
#endif

/*
 * Buffer struct.
 */

typedef struct {
    size_t len;
    char *alloc;
    char *data;
} buffer_t;

// prototypes

/**
 *
 * @return [description]
 */
buffer_t *buffer_new();

/**
 *
 * @param  n [description]
 * @return   [description]
 */
buffer_t *buffer_new_with_size(size_t n);

/**
 *
 * @param  str [description]
 * @return     [description]
 */
buffer_t *buffer_new_with_string(char *str);

/**
 *
 * @param  str [description]
 * @param  len [description]
 * @return     [description]
 */
buffer_t *buffer_new_with_string_length(char *str, size_t len);

/**
 *
 * @param  str [description]
 * @return     [description]
 */
buffer_t *buffer_new_with_copy(char *str);

/**
 *
 * @param  self [description]
 * @return      [description]
 */
size_t buffer_size(buffer_t *self);

/**
 *
 * @param  self [description]
 * @return      [description]
 */
size_t buffer_length(buffer_t *self);

/**
 *
 * @param self [description]
 */
void buffer_free(buffer_t *self);

/**
 *
 * @param  self [description]
 * @param  str  [description]
 * @return      [description]
 */
int buffer_prepend(buffer_t *self, char *str);

/**
 *
 * @param  self [description]
 * @param  str  [description]
 * @return      [description]
 */
int buffer_append(buffer_t *self, const char *str);

/**
 *
 */
int buffer_appendf(buffer_t *self, const char *format, ...);

/**
 *
 * @param  self [description]
 * @param  str  [description]
 * @param  len  [description]
 * @return      [description]
 */
int buffer_append_n(buffer_t *self, const char *str, size_t len);

/**
 *
 * @param  self  [description]
 * @param  other [description]
 * @return       [description]
 */
int buffer_equals(buffer_t *self, buffer_t *other);

/**
 *
 * @param  self [description]
 * @param  str  [description]
 * @return      [description]
 */
ssize_t buffer_indexof(buffer_t *self, char *str);

/**
 *
 * @param  self [description]
 * @param  from [description]
 * @param  to   [description]
 * @return      [description]
 */
buffer_t *buffer_slice(buffer_t *self, size_t from, ssize_t to);

/**
 *
 * @param  self [description]
 * @return      [description]
 */
ssize_t buffer_compact(buffer_t *self);

/**
 *
 * @param self [description]
 * @param c    [description]
 */
void buffer_fill(buffer_t *self, int c);

/**
 *
 * @param self [description]
 */
void buffer_clear(buffer_t *self);

/**
 *
 * @param self [description]
 */
void buffer_trim_left(buffer_t *self);

/**
 *
 * @param self [description]
 */
void buffer_trim_right(buffer_t *self);

/**
 *
 * @param self [description]
 */
void buffer_trim(buffer_t *self);

/**
 * @param self [description]
 */
void buffer_print(buffer_t *self);

#define buffer_string(self) (self->data)

#endif
