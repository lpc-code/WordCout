#include<stdio.h>
#include<stdlib.h>

//�ַ���ͳ��
//��ĿҪ�󣺿ո�ˮƽ�Ʊ�������з������ַ�
int CharacterCount(char *filename)
{
	FILE *fp;
	int count = 0;
	char ch;
	if ((fp = fopen(filename, "r")) == NULL)  //���򿪲����Ƿ��д�
	{
		printf("cannot open this file!");
		exit(0);
	}
	ch = fgetc(fp);  			//���ļ��ж���һ���ַ�
	while (ch != EOF)			//�ļ�������־
	{
		count++;			//�ַ�������һ
		ch = fgetc(fp);		//��ȡ��һ���ַ�
	}
	fclose(fp);				//�ر��ļ�
	printf("character number is :%d", count);
	return 0;
}

//������ͳ��
//��ĿҪ���ɿո�򶺺ŷָ�Ķ���Ϊ����
int WordCount(char *filename)
{
	FILE *fp;
	int count = 0;
	char ch;
	if ((fp = fopen(filename, "r")) == NULL)	 //���򿪲����Ƿ��д�
	{
		printf("cannot open this file!");
		exit(0);
	}
	ch = fgetc(fp);			//���ļ��ж���һ���ַ�
	while(ch != EOF)			
	{
		
		if(ch == ','||ch == ' ')	//�����Կո�򶺺ŷָ�
		{
			count ++;
		}
		ch = fgetc(fp);		//��ȡ��һ���ַ�
	}
	count +=1;			//�����Կո�򶺺ŷָ�����������Ϊ�ո�Ͷ�������+1
	fclose(fp);
	printf("Word count is :%d",count);
	return 0;
}
int main(int argc, char *argv[])
{
	
	int num = 0;
	if (strcmp(argv[1], "-c") == 0)		//ͳ���ַ���
	{
		CharacterCount(argv[2]);
	}
	if (strcmp(argv[1], "-w") == 0)	//ͳ�Ƶ�����
	{
		WordCount(argv[2]);	
	}
}