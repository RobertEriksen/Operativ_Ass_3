#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

FILE *pFile;
FILE *outputFile;

char* args1 = "./Thread1.txt";
char* args2 = "./Thread2.txt";
char* args3 = "./Thread3.txt";

void *Read(void* file) {
	int display;
	pFile = fopen(file, "r");
	
	/*
	outputFile = fopen(file, "a");
	fclose(outputFile);
	*/
	return NULL;
}

int main(void) {
	pthread_t mythread_1;
	if ( pthread_create( &mythread_1, NULL, Read, args1) ) {
		printf("error creating thread.");
		abort();
	}

	pthread_t mythread_2;
	if ( pthread_create( &mythread_2, NULL, Read, args2) ) {
		printf("error creating thread.");
		abort();
	}

	pthread_t mythread_3;
	if ( pthread_create( &mythread_3, NULL, Read, args3) ) {
		printf("error creating thread.");
		abort();
	}
	
	
	if ( pthread_join ( mythread_1, NULL ) ) {
		printf("error joining thread.");
		abort();
	}

	if ( pthread_join ( mythread_2, NULL ) ) {
		printf("error joining thread.");
		abort();
	}

	if ( pthread_join ( mythread_3, NULL ) ) {
		printf("error joining thread.");
		abort();
	}
	


	
	exit(0);
}
