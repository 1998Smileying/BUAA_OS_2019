#include "lib.h"



static void user_out2string(void *arg, char *s, int l)
{
    int i;
    int j = 0;
	char * b = (char *)arg;
    // special termination call
    if ((l==1) && (s[0] == '\0')) return;
    
    while (b[j] != '\0')
        j++;
    for (i=0; i< l; i++) {
	    b[j+i]=s[i];
    }
}


int fwritef(int fd, const char *fmt, ...)
{
	char buf[512] = {0};
    user_bzero(buf, sizeof(buf));
	va_list ap;
	va_start(ap, fmt);
	user_lp_Print(user_out2string, buf, fmt, ap);
	va_end(ap);
	return write(fd, buf, strlen(buf));
}

