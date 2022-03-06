#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Covidlib.h"
#include "CovidStruct.h"

int main()
{
	/* 用户数据文件创建/导入 */
	FILE *user_fp;
	if((user_fp=fopen("user_data.txt", "a+")) == NULL) 
	{
    	exit(0);
    }

	/* 创建用户数据链表头结点 */
	user_list *header = NULL;
	header = (user_list *)malloc(sizeof(user_list));
	if (header == NULL)
	{
		printf("申请内存失败。");
		exit(0);
	}
	memset(header, 0, sizeof(user_list));
    
    /* 打开用户登录界面 */
    UserMain(user_fp, header);
    
    /* 释放链表 */
    FreeNode(header);
    
	return 0;
}
