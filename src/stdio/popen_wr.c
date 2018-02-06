#include <stdio.h>
#include <errno.h>

#define E_SUCCESS    (0)         /* Success */
#define E_FATAL      (-1)        /* Fatal error */
#define E_NOMEM      (ENOMEM)    /* Out of memory */
#define E_INVAL      (EINVAL)    /* Invalid argument */

int
popen_wr (FILE *stream, const char *command, const char *type)
{
    if ((NULL == stream) || (NULL == command) || (NULL == type)) {
        return(E_INVAL);
    }

    errno = 0;
    stream = popen(command, type);
    if (NULL == stream) {
        if(0 == errno) {
            return(E_NOMEM);
        }
        else if(EINVAL == errno) {
            return(E_INVAL);
        }
        else {
            return(E_FATAL);
        }
    }

    return (E_SUCCESS);
}
