#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/*
 * You will write an application in C (sig_demo.c) that installs 3 different functions as 
 * signal handlers. Your C code will handle the following signals: SIGUSR1, SIGUSR2, and SIGINT. 
 * It may be tempting to use a single signal handler for all 3 signals, but don’t. Create a separate 
 * single handler function for each signal.
 * 
 * Once your application has installed the 3 signal handlers, it should send the signals to itself, 
 * in this order: SIGUSR1, SIGUSR2, SIGINT. The getpid() system call can be your friend here.
 */
 
// The SIGINT (“program interrupt”) signal is sent when the user types the INTR character 
// (normally C-c). See Special Characters, for information about terminal driver support for C-c.
// The SIGUSR1 and SIGUSR2 signals are set aside for you to use any way you want. 
// They're useful for simple interprocess communication, if you write a signal handler for them in the 
// program that receives the signal. The default action is to terminate the process.

void usr1_handler (int sig){
	printf("Caught SIGUSR1\n");
}

void usr2_handler (int sig){
	printf("Caught SIGUSR2\n");
}

void int_handler (int sig){
	printf("Caught SIGINT, exiting\n");
	//exit
	exit(0);
	
	pid_t x = getpid();
	printf("%d", x);
	printf("\n");

	char c[20];
	char d[5]; 
	sprintf(d, "%d", x);	
	strcpy(c, "ps -p ");
	strcat(c, d);
	printf("%s\n", c);
	
	int res;
	res = system(c);
}

int main(int argc, char **argv) 
{
	// Establish handler for SIGUSR1 signals
	signal(SIGUSR1, usr1_handler);	
	// Establish handler for SIGUSR2 signals
	signal(SIGUSR2, usr2_handler);
	// Establish handler for SIGINT signals
	signal(SIGINT, int_handler);

	raise(SIGUSR1);
	raise(SIGUSR2);
	raise(SIGINT);
	sleep(5);
	return 0;
}



