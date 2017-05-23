#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void new_free(int count)
{
	char * a = new char(100);
	std::cout << "for loop :"<< count << std::endl;
	
	if(a)
	{
		memset(a,1,count);
		printf("before %p\n",a);
		free(a);
		printf("after %p\n",a);
	}

}

int main()
{
#define MAX 100
	int i = 0;
	for(i=0; i < MAX ; i++)
	{
		new_free(i);
	}
}
