#include "BigNumber Counter.h"


void InitBigNum(BigNum *s1, char* str)
{
	assert(s1 && str);
	int i, j;
	j = strlen(str);
	for (i = 0; i < j; i++)
	{
		s1->data[i] = 0;
		s1->data[i] = str[i];
	}
	s1->data[i] = '\0';
	s1->length = j;
}

int* reverse(int* arr, int head, int tail)
{
	while (head < tail)
	{
		int temp = arr[head];
		arr[head] = arr[tail];
		arr[tail] = temp;
		head++;
		tail--;
	}
	return arr;
}

void AddBigNum(BigNum* src1, BigNum* src2, BigNum* dst)
{
	int arr1[NUMSIZE], arr2[NUMSIZE], ret[NUMSIZE] = {0};
	char str[NUMSIZE];
	int i, j, k = 0;
	int temp, next = 0;
	int len1 = src1->length, len2 = src2->length;
	k = len1 > len2 ? len2 : len1;

	for (i = 0; i < len1; i++)
	{
		arr1[i] = src1->data[i] - '0';
	}
	reverse(arr1, 0, i - 1);

	for (i = 0; i < len2; i++)
	{
		arr2[i] = src2->data[i] - '0';
	}
	reverse(arr2, 0, i - 1);
	//���ַ�������������

	for(i = 0; i < k; i++)
	{
		temp = arr1[i] + arr2[i] + next;
		next = temp / 10;
		ret[i] = temp % 10;
	}
	//�ȼ�����̳��ȣ��ټ�����������һ����
	while (i < len1)
	{
		temp = arr1[i] + next;
		next = temp / 10;
		ret[i++] = temp % 10;
	}

	while (i < len2)
	{
		temp = arr2[i] + next;
		next = temp / 10;
		ret[i++] = temp % 10;
	}

	if (next > 0)
		ret[i++] = next;

	reverse(ret, 0, i - 1);

	for (j = 0; j < i; j++)
	{
		str[j] = ret[j] + '0';
	}
	str[j] = '\0';

	InitBigNum(dst, str);
}

void MinusBigNum(BigNum* src1, BigNum* src2, BigNum* dst)
{
	int arr1[NUMSIZE], arr2[NUMSIZE], ret[NUMSIZE] = { 0 };
	char str[NUMSIZE];
	int i, j, k = 0;
	int flag, next = 0;
	int len1 = src1->length, len2 = src2->length, big, small;
	

	for (i = 0; i < src1->length; i++)
	{
		arr1[i] = src1->data[i] - '0';
	}
	reverse(arr1, 0, i - 1);

	for (i = 0; i < src2->length; i++)
	{
		arr2[i] = src2->data[i] - '0';
	}
	reverse(arr2, 0, i - 1);

	if (len1 > len2)
	{
		big = len1;
		small = len2;
	}
	else
	{
		big = len2;
		small = len1;
	}
	//�����ȴ�ķŵ�big��̵ĳ��ȷŵ�small

	if (0 == strcmp(src1->data, src2->data))
	{
		InitBigNum(dst, "0");
		return;
	}
	//��������ͬ��ʱ��ֱ�ӳ�ʼ��Ϊ0
	else
	{
		if (strcmp(src1->data, src2->data) >= 0)
			//flagΪ����λ���������ж�����,���ձ����������С����������
		{
			flag = 1;

			for (i = 0; i < len1; i++)
			{
				arr1[i] = src1->data[i] - '0';
			}
			reverse(arr1, 0, i - 1);

			for (i = 0; i < len2; i++)
			{
				arr2[i] = src2->data[i] - '0';
			}
			reverse(arr2, 0, i - 1);
		}
		else
		{
			flag = -1;
			for (i = 0; i < len2; i++)
			{
				arr1[i] = src2->data[i] - '0';
			}
			reverse(arr1, 0, i - 1);

			for (i = 0; i < len1; i++)
			{
				arr2[i] = src1->data[i] - '0';
			}
			reverse(arr2, 0, i - 1);
		}

		for (i = 0; i < small; i++)
		{
			if (arr1[i] >= arr2[i])
			{
				ret[i] = arr1[i] - arr2[i];
			}
			else
			{
				ret[i] = arr1[i] - arr2[i] + 10;
				arr1[i++]--;
			}
		}
		//����϶̳����ǲ��ֵĲ�ֵ,��Ϊ��λ���ǲ��ֳ���ǰ���λ�Ĳ��� �����Ŀ��Բ��ü���

		while (i < big)
		{
			if (arr1[i] >= 0)
			{
				ret[i] = arr1[i];
			}
			else 
			{
				ret[1] = arr1[i] + 10;
				arr1[i + 1]--;
			}
			i++;
		}
		//���㳤�����������ǲ��֣�С����Ľ�β���������ֱ�Ӹ���
	}

	while (0 == ret[i - 1])
		i--;
	reverse(ret, 0, i - 1);
	//ȥ������λ
	j = 0;
	if (flag == -1)
		str[j++] = '-';
	//������λ�ŵ���λ


	while(j < i)
	{
		str[j] = ret[j] + '0';
		j++;
	}
	str[j] = '\0';

	InitBigNum(dst, str);
}


void DivideBigNum(BigNum* src1, BigNum* src2, BigNum* dst)
{
	char result_tmp[NUMSIZE];
	char final[NUMSIZE];
	int i, j, k;
	int len1 = src1->length, len2 = src2->length;
	char* result;
	k = 0;
	while (1)
	{                        //��ѭ��ֻ�е�len1��len2���ʱ����ѭ������Ϊ�᲻�ϵ���src2->data����ǰ��0���Ը�����ĳ��ȣ�                                          //�᲻�ϵı仯���������ʱ˵���Ѿ��޷�����������
		result_tmp[k] = 0;
		while (strcmp(src1->data, src2->data) >= 0)
		{ 
			int i = 0, j;                  //������������ƶ�һλһ�����ֲ������������غ��Ժ�����������ݡ�
			while (1)
			{
				if (src1->data[i] == '0')
					i++;//ȥ��src1->data��λǰ���0
				else
				{
					j = i;              //ȥ��src2->data��λ����0
					break;
				}
			}
			for (; i < len2; i++)            //������
				src1->data[i] = src1->data[i] - src2->data[i] + '0';
			for (i = len2 - 1; i > j; i--)       //ÿ��һ��������������飬��������������ǰ��ƪ�ж���ʹ�á�
				if (src1->data[i] < '0')
				{              //���������ﲻ���������������src1->data���飬��������ڣ������в�������
					src1->data[i] += 10;;
					src1->data[i - 1]--;
				}
			result_tmp[k]++;
		}
		k++;
		if (len1 == len2)
			break;
		for (i = len2 - 1; i >= 0; i--)   //��src2->data�е�Ԫ���Ⱥ���λ��ͬʱ����src2->data���Ȳ�����src2->dataǰ�˲�һλ0��
			src2->data[i + 1] = src2->data[i];
		src2->data[0] = '0';               //���������������src2->data[0]ÿ���ƶ���Ϊ�գ�����ÿ����0���롣
		len2++;
		src2->data[len2] = '\0';           //�ڽ�β�����ַ����Ľ�����ǡ�
	}
	i = 0;j = 0;
	while (result_tmp[i] == 0)
		i++;
	for (; i < k; i++)
	{
		final[j++] = result_tmp[i] + '0';

	}
	final[j] = '\0';
	result = final;
	InitBigNum(dst, result);
	
}
//void DivideBigNum1(BigNum* src1, BigNum* src2, BigNum* dst)
//{
//	char t[100] = { 0 };
//	char b[2] = "0";
//	BigNum* d1 = (BigNum*)malloc(sizeof(BigNum));
//	if (strcmp(src1->data, src2->data) == 0) 
//	{
//		InitBigNum(d1, "0");
//		InitBigNum(dst, "1");
//	}
//	else if (strcmp(src1->data, src2->data) < 0) 
//	{
//		InitBigNum(d1, src1->data);
//		InitBigNum(dst, "0");
//	}
//	else 
//	{
//		BigNum* aa;
//		aa = (BigNum*)malloc(sizeof(BigNum));
//		InitBigNum(aa, src1->data);
//		while (strcmp(aa->data, src2->data) >= 0) 
//		{
//			MinusBigNum(aa, src2, dst);
//			InitBigNum(aa, dst->data);
//			one(t);
//		}
//		InitBigNum(dst, t);
//		InitBigNum(d1, aa->data);
//	}
//}
//
//

void MuliplyBigNum(BigNum* src1, BigNum* src2, BigNum* dst)
{
	int arr1[NUMSIZE], arr2[NUMSIZE], ret[NUMSIZE] = { 0 };
	int i, j, k;
	int temp, next = 0;
	int len1 = src1->length, len2 = src2->length;


	InitBigNum(dst, "0");

	for (i = 0; i < len1; i++)
	{
		arr1[i] = src1->data[i] - '0';
	}
	reverse(arr1, 0, i - 1);

	for (i = 0; i < len2; i++)
	{
		arr2[i] = src2->data[i] - '0';
	}
	reverse(arr2, 0, i - 1);

	for (i = 0; i < len2; i++)
	{
		next = 0;
		for (j = 0;j < len1;j++) {
			temp = arr1[j] * arr2[i] + next;
			ret[j] = temp % 10;
			next = temp / 10;
		}

		if (next > 0)
		{
			ret[j++] = next;
		}

		while (0 == ret[j - 1])
			j--;

		char str[NUMSIZE];

		reverse(ret, 0, j - 1);

		for (k = 0;k < j;k++)
			str[k] = ret[k] + '0';

		for (j = 0;j < i;j++)
			str[k++] = '0';

		str[k] = '\0';

		BigNum* t;
		t = (BigNum*)malloc(sizeof(BigNum));
		InitBigNum(t, str);
		AddBigNum(dst, t, dst);
	}
}


