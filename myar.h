// free malloced memory
// make sure extra spaces not used for padding where they shouldnt be
// set user and group id
// from assign: permssions subject to umask limitation?
// make sure when writing, i wrote newline instead of seeking forward for uneven
// test append with sym links

/*
 * @file 	myar.h
 *
 * @author 	Rebecca Sagalyn
 */

#ifndef MYAR_H_
#define MYAR_H_

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ar.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <libgen.h>
#include <utime.h>
#include <dirent.h>

#define SARFMAG 2
#define BLKSIZE 4096
#define SARHDR 60   		/* size of ar_hdr */
#define SARFNAM 16
#define SARFDAT 12
#define SARFUID 6
#define SARFGID 6
#define SARFMOD 8
#define SARFSIZ 10
#define SARFMAG 2
#define TMPARCH "tempfile.a"
#define FILE_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) /* default permissions */


/* Quickly append named files to end of archive, and create archive if doesn't exist  */
void 	append(int fd, char**ar_list, int n);

/* Quickly append all regular files in current directory */
void	append_all(int fd, char*ar_name);

/* Delete names files from archive */
void 	delete(int *fd, char*arname, char**filename, int n);

void 	extract(int fd, char *filename);

void 	extract_all(int fd);

/* Print a verbose table of contents of the archive. */
void 	print_verbose(int fd);


void 	print_concise(int fd);

/* Return an ls-style string of permissions mask */
void 	ar_mode_string(mode_t mode, char* mode_string);

/* Returns fd to opened ar file if success
 * Returns -1 if not archive file, or can't open file/filedoesnt exist
 */
int 	open_ar_file(char *path, char key);

/* Prints a shell-style usage message when user makes invalid entry */
void usage();

#endif /* MYAR_H_ */
