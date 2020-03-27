#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#define  MAX_CMD  1024

char buff[MAX_CMD];

//1.获取命令
int get_cmd()
{
	memset(buff, 0x00, MAX_CMD);
	printf("[lee@localhost ~]$ ");
	fflush(stdout);
	//模拟命令行 
	
	fgets(buff, MAX_CMD - 1, stdin);
	buff[strlen(buff) - 1] = '\0';
	return 0;

}

//2.解析命令 
char **do_parse(char *buff)
{
	char *ptr = buff;
	int argc = 0;
	static char *argv[32];
	
	while('\0' != *ptr)
	{
		if(' ' != *ptr)
		{
			argv[argc++] = ptr;
			while('\0' != *ptr && ' ' != *ptr)
			{
				ptr++;
			}
			*ptr = '\0';
		}
		ptr++;
	}
	//提取命令 

	argv[argc] = NULL;
	return argv;
}

//3.程序替换 
int do_exec(char *buff)
{
	char **argv ={ NULL };

	int pid = fork();
	//在子进程中进行程序替换 
	if(0 == pid)
	{	
		argv = do_parse(buff);
		
		if(NULL != argv[0])
		{
			execvp(argv[0], argv);
			//程序替换
		}
		else
		{
			exit(-1);
			//退出进程 
		}
			
	}	
	else
	{
		waitpid(pid, NULL, 0);
		//进程等待
	}
	
	return 0;
}

int main(int argc, char*argv[])
{
	while(1)
	{
		if(!get_cmd())
			do_exec(buff);
	}

	return 0;
}
