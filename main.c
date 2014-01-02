#include "myar.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <libgen.h>


int main(int argc, char **argv)  {
	int fd;
    char c;
    char key;
    char *ar_name = NULL;


    // Process command line option arguments
    while ((c = getopt (argc, argv, "qxtvdAw")) != -1)
        switch (c) {
            case 'q':
                key = 'q';
                break;
            case 'x':
                key = 'x';
                break;
            case 't':
                key = 't';
                break;
            case 'v':
                key = 'v';
                break;
            case 'd':
                key = 'd';
                break;
            case 'A':
                key = 'A';
                break;
            case 'w':
                key = 'w';
                break;
            default:
                usage();
                exit(EXIT_FAILURE);
                break;
        }

    // Make sure an option was entered
    if (!key){
    	printf("No option given\n");
    	usage();
    	exit(-1);
    }

    // Get archive path
    if (optind < argc) {
        ar_name = (char*)malloc(sizeof(char) * (strlen(argv[optind]) + 1));
        assert(ar_name != NULL);
        strcpy(ar_name, argv[optind]);
        optind = optind + 1;
    }else { // Error - no archive file
        printf("no archive file given.\n");
        usage();
    }

    // Open archive fle
    fd = open_ar_file(ar_name, key);

    // Check key and call function
    do {
        switch(key) {
            case 'q':
                if (argv[optind] == NULL) {
                    printf("no file given to append.\n");
                	usage();
                	exit(EXIT_FAILURE);
                }
            	append(fd, &(argv[optind]), (argc-optind));
            	optind = argc;
                break;
            case 't':
                print_concise(fd);
                break;
            case 'v':
                print_verbose(fd);
                break;
            case 'x':
                extract(fd, argv[optind] ? argv[optind] : NULL);
                break;
            case 'd':
                if (argv[optind] == NULL) {
                    printf("no file given to delete.\n");
                	usage();
                	exit(EXIT_FAILURE);
                }
            	delete(&fd, ar_name, &(argv[optind]), (argc-optind));
            	optind = argc;
                break;
            case 'A':
                append_all(fd, ar_name);
                break;
            case 'w':
                break;
        }
        optind++;
    } while (optind < argc);

    // Close file
    if (close(fd) == -1)
        printf("ERROR: %s\n", strerror(errno));
    return(0);
}
