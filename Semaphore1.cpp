#include<pthread.h>
#include<unistd.h>
#include<iostream>
#include<semaphore.h>
using namespace std;
sem_t f1;
sem_t f2;
sem_t f3;
int count=0;
void*foo(void*arg)
{
	sem_wait(&f1);
	cout<<"a";
	count++;
	if(count==3)
	{
		sem_post(&f3);
	}
	pthread_exit(NULL);
}
void*foo1(void*arg)
{
	sem_wait(&f2);
	cout<<"b";
	count++;
	sem_post(&f1);
	sem_post(&f1);
	sem_post(&f1);
	count=0;
	pthread_exit(NULL);
}
void*foo2(void*arg)
{
	sem_wait(&f3);
	cout<<"c";
	count++;
	sem_post(&f2);	
	pthread_exit(NULL);
}
int main()
{
	sem_init(&f1,0,3);
	sem_init(&f2,0,0);
	sem_init(&f3,0,0);
	pthread_t thread1,thread2,thread3,thread4,thread5;
	while(1)
	{
		pthread_create(&thread1,NULL,&foo,NULL);
		pthread_create(&thread2,NULL,&foo,NULL);
		pthread_create(&thread3,NULL,&foo,NULL);
		pthread_create(&thread4,NULL,&foo1,NULL);
		pthread_create(&thread5,NULL,&foo2,NULL);
		
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
		pthread_join(thread3,NULL);
		pthread_join(thread4,NULL);
		pthread_join(thread5,NULL);
	}

	return 0;
}
