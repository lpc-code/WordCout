#include<stdio.h>
#include<stdlib.h>

//字符数统计
int CharacterCount(char *filename)
{
	FILE *fp;
	int count = 0;
	char ch;
	if ((fp = fopen(filename, "r")) == NULL)  //检测打开操作是否有错
	{
		printf("cannot open this file!");
		exit(0);
	}
	ch = fgetc(fp);  			//从文件中读入一个字符
	while (ch != EOF)			//文件结束标志
	{
		count++;			//字符数量加一
		ch = fgetc(fp);		//读取下一个字符
	}
	fclose(fp);				//关闭文件
	printf("character number is :%d", count);
	return 0;
}

//单词数统计
//题目要求：由空格或逗号分割开的都视为单词
int WordCount(char *filename)
{
	FILE *fp;
	int count = 0;
	char ch;
	if ((fp = fopen(filename, "r")) == NULL)	 //检测打开操作是否有错
	{
		printf("cannot open this file!");
		exit(0);
	}
	ch = fgetc(fp);			//从文件中读入一个字符
	while(ch != EOF)			
	{
		
		if(ch == ','||ch == ' ')	//单词以空格或逗号分隔
		{
			count ++;
		}
		ch = fgetc(fp);		//读取下一个字符
	}
	count +=1;			//单词以空格或逗号分隔，即单词数为空格和逗号数量+1
	fclose(fp);
	printf("Word count is :%d",count);
	return 0;
}
int main(int argc, char *argv[])
{
	
	int num = 0;
	if (strcmp(argv[1], "-c") == 0)		//统计字符数
	{
		CharacterCount(argv[2]);
	}
	if (strcmp(argv[1], "-w") == 0)	//统计单词数
	{
		WordCount(argv[2]);	
	}
}
