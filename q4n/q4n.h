// linux 
#ifndef Q4n_H
#define Q4n_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <fcntl.h> // flags and mode
#include <errno.h> // errno, perror()
#include <assert.h>

#include <unistd.h>
#include <sys/io.h>
#include <sys/mman.h>
#include <sys/types.h>

#define log(fmt, ...)                                                   \
    do {                                                                       \
        fprintf(stderr, "%s:%d:%s(): " fmt,__FILE__, __LINE__, __func__, ##__VA_ARGS__);   \
    } while (0)

#define pause() \
    do{ \
        fprintf(stderr, "%s:%d:%s(): pause", __FILE__, __LINE__, __func__); \
        getchar(); \
    }while(0)

void die(const char* msg)
{
    perror(msg);
    exit(-1);
}

void hexdump(const char *desc, void *addr, int len) {
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char *)addr;

    // Output description if given.
    if (desc != NULL)
        printf("%s:\n", desc);
    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %i\n", len);
        return;
    }

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).
        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf("  %s\n", buff);
            // Output the offset.
            printf("  %04x ", i);
        }
        // Now the hex code for the specific character.
        printf(" %02x", pc[i]);
        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }
    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf("   ");
        i++;
    }
    // And print the final ASCII bit.
    printf("  %s\n", buff);
}

#endif
