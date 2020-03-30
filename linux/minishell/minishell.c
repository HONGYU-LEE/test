#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#define  MAX_CMD  1024

char buff[MAX_CMD];

//1.获取命令
int get_cmd()
{
	memset(buff, 0x00, MAX_CMD);
	printf("[lee@localhost ~]$ ");
	fflush(stdout);
	//模拟终端显示
	
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
	//去掉空格，提取命令

	argv[argc] = NULL;
	return argv;
}

void do_redirect(char *buff)
{
	int redirect_flag = 0;
	char *redirect_file = NULL;
	char *ptr = buff;

	while(*ptr != '\0')
	{
		if(*ptr == '>')
		{
			*ptr++ = '\0';
			++redirect_flag;

			if(*ptr == '>')
			{
				++redirect_flag;
				ptr++;
			}
			
			while(*ptr == ' ' && *ptr != '\0')
			{
				ptr++;
			}

			redirect_file = ptr;

			while(*ptr != ' ' && *ptr != '\0')
			{
				ptr++;
			}
				
			*ptr = '\0';
		}
		ptr++;
	}

	if(redirect_flag == 1)
	{
		int fd = open(redirect_file, O_WRONLY|O_CREAT|O_TRUNC, 0664);
		dup2(fd, 1);
	}
	else if(redirect_flag == 2)
	{
		int fd = open(redirect_file, O_WRONLY|O_CREAT|O_APPEND, 0664);
		dup2(fd, 1);
	}
}

//4.程序替换
int do_exec(char *buff)
{
	char **argv ={ NULL };

	int pid = fork();
	//创建子进程， 在子进程中进行程序替换
	if(0 == pid)
	{	
		do_redirect(buff);
		argv = do_parse(buff);
		
		if(NULL != argv[0])
		{
			execvp(argv[0], argv);
			//替换进程
		}
		else
		{
			exit(-1);
			//输入命令错误则退出进程
		}
			
	}	
	else
	{
		waitpid(pid, NULL, 0);
		//等待子进程退出
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
