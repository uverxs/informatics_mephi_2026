#ifndef ERR_H
#define ERR_H

typedef enum Err {
    ERR_OK,
    ERR_ALLOC,
    ERR_SIZE,
    ERR_EOF,
    ERR_ARGUMENT,
} Err;

#endif