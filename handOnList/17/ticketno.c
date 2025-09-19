/*
======================================================================================
Name        : ticket_init.c
Author      : Mohit Kumar
Description : Create ticket.txt and store initial ticket number.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    int ticket = 100;

    f = fopen("ticket.txt", "w");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    fprintf(f, "%d\n", ticket);
    fclose(f);

    printf("Ticket file initialized with %d\n", ticket);
    return 0;
}

/*
======================================================================================
output:
======================================================================================

*/

