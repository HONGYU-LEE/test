bool isnum(const char* str)
{
    if(*str == '-' && strlen(str) == 1)
        return false;

    if(*str == '*' || *str == '/' || *str == '+')
        return false;

    return true;
}

int getnum(const char* str)
{
    int i = 0;
    int ret = 0, flag = 1;
    if(str[i] == '-')
    {
        i++;
        flag = 0;
    }

    for(; i < strlen(str); i++)
    {
        ret = ret * 10 + str[i] - '0';
    }

    return flag ? ret : - ret;
}

int evalRPN(char ** tokens, int tokensSize){
    int count, num1, num2, j = 0;
    int *stack = (int*)malloc(sizeof(int) * tokensSize);

    for(int i = 0; i < tokensSize; i++)
    {
        if (isnum(tokens[i]))
        {
            stack[j++] = getnum(tokens[i]);
        }
        else
        {
            switch(*tokens[i])
            {
                case '+': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    stack[j++] = num2 + num1;
                    break;

                case '-': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    stack[j++] = num2 - num1;
                    break;    

                case '*': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    stack[j++] = num2 * num1;
                    break;          

                case '/': 
                    num1 = stack[--j];
                    num2 = stack[--j];
                    if(!num1)
                        break;
                    stack[j++] = num2 / num1;
                    break;
            }
        }
    }
    
    count = stack[j - 1];
    return count;
}
