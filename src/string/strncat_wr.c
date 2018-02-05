#include <string.h>
#include <errno.h>

#define E_SUCCESS    (0)         /* Success */
#define E_INVAL      (EINVAL)    /* Invalid argument */


int
strncat_wr (char *dest,
            const char *src,
            size_t size)
{
    if ((NULL == dest) || (NULL == src) || (size == 0)) {
        return (E_INVAL);
    }
    strncat(dest, src, (size - strlen(src) - 1));
    return (E_SUCCESS);
}