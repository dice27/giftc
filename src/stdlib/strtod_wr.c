#include <stdlib.h>
#include <errno.h>

#define E_SUCCESS    (0)         /* Success */
#define E_FATAL      (-1)        /* Fatal error */
#define E_RANGE      (ERANGE)    /* Math result not representable */
#define E_BADMSG     (EBADMSG)   /* Not a data message */
#define E_INVAL      (EINVAL)    /* Invalid argument */


int
strtod_wr(const char* nptr,
          char** endptr,
          double* dest)
{
    double tmpval = 0.0;
    char*  tmpend = NULL;

    if ((NULL == nptr) || (NULL == dest)) {
        return (E_INVAL);
    }

    errno = 0;
    tmpval = strtod(nptr, &tmpend);

    if (endptr != NULL) {
        endptr = &tmpend;
    }

    if (0 != errno) {
        if (ERANGE == errno) {
            *dest = tmpval;
            return (E_RANGE);
        }
    }
    else {
        return (E_FATAL);
    }

    if (tmpend == nptr) {
        return (E_BADMSG);
    }

    *dest = tmpval;
    return (E_SUCCESS);
}
