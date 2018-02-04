#include <stdlib.h>
#include <errno.h>

#define E_SUCCESS    (0)         /* Success */
#define E_FATAL      (-1)        /* Fatal error */
#define E_RANGE      (ERANGE)    /* Math result not representable */
#define E_INVAL      (EINVAL)    /* Invalid argument */

int
strtod_wr(const char* nptr,
          char** endptr,
          double* dest)
{
    double tmpval = 0.0;
    char*  tmpend = NULL;

    if ((NULL == nptr) || (NULL == dest)) {
        return E_INVAL;
    }

    errno = 0;
    tmpval = strtod(nptr, &tmpend);

    if (ERANGE == errno) {
        *dest = tmpval;
        return E_RANGE;
    }

    if (endptr != NULL) {
        endptr = &tmpend;
    }

    if (nptr == tmpend) {
        return E_INVAL;
    }

    *dest = tmpval;
    return E_SUCCESS;
}