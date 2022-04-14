#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE          (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("bir dosya ismi vermelisiniz.");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY, FILE_MODE);
	if(fd<0)
	{
		printf("dosya okuma hatasi.\n");
		exit(-2);
	}
	int fd2 = open(argv[2] = "metin_sesli_harfsiz.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE );
	if(fd2<0)
	{
		printf("txt olusturma hatasi.\n");
		exit(-3);
	}
	int n = 1;
	char buf[1];
	while (n!=0)
	{
		n = read(fd,buf,1);
		if(buf[0] !='a' && buf[0] !='e' && buf[0] !='i' &&                        buf[0] !='I' && buf[0] !='u' && buf[0] !='o' &&                        buf[0] !='A' && buf[0] !='U' && buf[0] !='O' &&                        buf[0] !='E')
		{
		write(fd2,buf,1);
		}
	}
	close(fd);
	close(fd2);
return 0;
}
