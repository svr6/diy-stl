#include <stdio.h>
#include <unistd.h>
int main()
{
	if(access("/etc/passwd", R_OK) == 0)
	{
		printf("/etc/passwd can be read \n");
	}

	if(access("/etc/passwd", X_OK) != 0)
	{
		printf("/etc/passwd can not be exec\n");
	}

	if(access("/etc/passwd", R_OK|W_OK|X_OK) == 0)
	{
		printf("/etc/passwd can 777 \n");
	}else
	{
		printf("/etc/passwd can not be 777\n");
	}

	if(access("/etc/shadow", X_OK) == 0)
	{
		printf("/etc/shadow can be exec\n");
	}else
	{
		printf("cat not be read\n");
	}
}
