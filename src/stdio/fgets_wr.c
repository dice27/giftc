#include <stdio.h>
#include <errno.h>

#define E_SUCCESS    (0)         /* Success */
#define E_INVAL      (EINVAL)    /* Invalid argument */
#define E_BADMSG     (EBADMSG)   /* Not a data message */


int
fgets_wr (char *s,
          int size,
          FILE *stream)
{
    char* ret = NULL;
    size_t len = 0;

    if ((NULL == s) || (NULL == stream) || (NULL == dest)) {
        return (E_INVAL);
    }

    if (0 == size) {
        return(E_INVAL);
    }

    memset(s, 0, size);
    ret = fgets(s, size, stream);
    if (ret == NULL) {
        return (E_BADMSG);
    }

    /* Replace trailing newline with NULL termination */
    len = strlen(s);
    if (len > 0) {
        --len;
        if (s[len] == '\n') {
            s[len] = '\0';
        }
    }

  return (E_SUCCESS);
}
