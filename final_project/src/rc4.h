#ifndef DSIFFORD_RC4_H
#define DSIFFORD_RC4_H

#define RC4_HASH_KEY "this assignment is a giant waste of time"
#define RC4_KEY_LEN (sizeof(RC4_HASH_KEY) - 1)

int transform_rc4(int fd);

#endif

