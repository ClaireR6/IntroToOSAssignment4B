#include <stdio.h>
#include <pthread.h>

int n = 10;
int cnt = 0;
int count = 0;
pthread_cond_t f, d;
pthread_mutex_t m;

void print(){ // Part B method for printing 1 - N within the thread process.
	for(int lcv=1;lcv<=n;lcv++){
		printf("%d ", lcv);
	}
    printf("\n");
	count++;
}


void *process(void *arg){
	pthread_mutex_lock(&m);
	while(count == 1){
		pthread_cond_wait(&f, &m);
	}
	print(); 
	pthread_cond_signal(&d);
	pthread_mutex_unlock(&m);
}



int main(void) {
	for(int lcv=0;lcv<n;lcv++){
		pthread_t p;
		pthread_create(&p, NULL, process, NULL);
		pthread_mutex_lock(&m);
		while(count == 0){
			pthread_cond_wait(&d, &m);
		}
		count--;
		pthread_cond_signal(&f);
		pthread_mutex_unlock(&m);
	}
	return 0;
}