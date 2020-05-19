#include<stdio.h>
#include<stdlib.h>

//字符数统计
//题目要求：空格，水平制表符，换行符均算字符
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
//题目要求：由空格或
