#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#define  MAX_CMD  1024

char buff[MAX_CMD];

//1.��ȡ����
int get_cmd()
{
	memset(buff, 0x00, MAX_CMD);
	printf("[lee@localhost ~]$ ");
	fflush(stdout);
	//ģ�������� 
	
	fgets(buff, MAX_CMD - 1, stdin);
	buff[strlen(buff) - 1] = '\0';
	return 0;

}

//2.�������� 
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
	//��ȡ���� 

	argv[argc] = NULL;
	return argv;
}

//3.�����滻 
int do_exec(char *buff)
{
	char **argv ={ NULL };

	int pid = fork();
	//���ӽ����н��г����滻 
	if(0 == pid)
	{	
		argv = do_parse(buff);
		
		if(NULL != argv[0])
		{
			execvp(argv[0], argv);
			//�����滻
		}
		else
		{
			exit(-1);
			//�˳����� 
		}
			
	}	
	else
	{
		waitpid(pid, NULL, 0);
		//���̵ȴ�
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
