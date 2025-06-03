#include <stdio.h>

int main() {
    // printf
    printf("%d", 10);

    // fprintf
    FILE *f = fopen("foo", "w");
    fprintf(f, "%d\n", 10);
    fclose(f);

    // sprintf (do not use this)
    char buf[256] = {0};
    sprintf(buf, "%d, %d", 3, 51);      // Really easy to buffer overflow
    printf("%s\n", buf);

    char buf1[10] = {0};
    // sprintf(buf, "%d, %d, %s", 3, 51, "gsf<ds<dfgdfvbbhatrse");      it runs into overflow
    snprintf(buf, 10,"%d, %d, %s", 3, 51, "gsf<ds<dfgdfvbbhatrse");     // It is safe from overflow

    

    return 0;
}