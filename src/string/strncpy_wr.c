#include <string.h>
#include <errno.h>

#define E_SUCCESS    (0)         /* Success */
#define E_INVAL      (EINVAL)    /* Invalid argument */


int
strncpy_wr (char *dest,
            const char *src,
            size_t size)
{
    if ((NULL == dest) || (NULL == src)) {
        return (E_INVAL);
    }

    /* In case of size 0, this function don't anything */
    if (0 == size)) {
        return (E_INVAL);
    }

    /* The end must be NULL. size is -1. */
    strncpy(dest, src, size - 1);

    /* Always set to size-1 NULL. */
    /* Prevents NULL termination from occurring when copying character string longer than dest. */
    dest[size - 1] = '\0';
}