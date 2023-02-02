#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<time.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
int buffer[100];
sem_t s1;
sem_t s2;
void*producer(void*arg)
{
	int temp;
	srand(time(NULL));
	for(int i=0;i<500;i++)
	{
		sem_wait(&s1);
		buffer[i]=(rand()%500)+1;
		cout<<"Number "<<buffer[i];
		//write(1,&temp,sizeof(temp));	
		cout<<endl;
		sem_post(&s2);
	}
	pthread_exit(NULL);
}
void*consumer(void*arg)
{
	int sum=0;
	for(int i=0;i<100;i++)
	{	
		sem_wait(&s2);
		sum=sum+buffer[i];
		cout<<"Sum "<<sum<<endl;
		//write(1,&sum,sizeof(sum));
		sem_post(&s1);
	}
	pthread_exit(NULL);
}
int main()
{
	sem_init(&s1,0,1);
	sem_init(&s2,0,0);
	pthread_t thread[2];
	pthread_create(&thread[0],NULL,&producer,NULL);
	wait(NULL);
	pthread_create(&thread[1],NULL,&consumer,NULL);
	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);
	return 0;
}
