#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"

/*******************
 *
 *	 用户系统模块 
 *
 *******************/

/*
 *	用户系统主函数 
 */
void UserMain(FILE *user_fp, user_list *header)
{
	/* 定位头结点 */
	user_list *p = header;
	int lines = GetFileLines(user_fp);
	
	/* 如果用户文件是空的，就增加一个默认管理员账号 */
	if (lines == 0)
	{
		fprintf(user_fp, "admin\tadmin\tadmin\n");
		rewind(user_fp);
	}
	
	/* 读取文件数据至链表 */
	UserRead(p, user_fp);
	
	/* 显示登录系统的主界面 */
	char flag;
	printf("————————————————————\n");
    printf("#         新冠疫情数据管理系统         #\n");
    printf("#            软件201 许敏浩            #\n"); 
    printf("————————————————————\n");
    printf("# 直接登录请输入: L/l                  #\n");
    printf("# 注册账号请输入：R/r                  #\n");
    printf("# 更改密码请输入：C/c                  #\n");
    printf("————————————————————\n");
    printf(">");
    scanf("%c", &flag);
    
    /* 判断是登录或注册或改密码 */
    if (flag == 'L' || flag == 'l')
    {
    	system("cls");
    	UserLogin(p, user_fp);
	}
	else if (flag == 'R' || flag == 'r')
	{
		system("cls");
		UserRegister(p, user_fp);
	}
	else if (flag == 'C' || flag == 'c')
	{
		system("cls");
		UserPswChange(p, user_fp);
	}
	else
	{
		system("cls");
		printf("未知选项，请重新输入选择。\n");
		UserMain(user_fp, header);
	}
}

/*
 *	登录界面 
 */
void UserLogin(user_list *header, FILE *user_fp)
{
	/* 输入账号密码界面 */
	char userID[20];
	char userPassword[50];
	printf("————————————————————\n");
    printf("#               账号登录               #\n");
    printf("————————————————————\n");
    printf("请输入账号：");
    scanf("%s", userID);
    printf("请输入密码：");
    scanf("%s", userPassword);
    
    /* 获取用户类型 
		0：用户不存在 1：普通用户 2：管理员用户 3：密码错误	 */
    int type;
	type = GetUserType(header, userID, userPassword);
    
    /* 根据判断返回的类型打开对应的菜单或者提示错误 */
    if (type == 1 || type == 2)
    {
    	system("cls");
    	OpenMenu(type);
	}
	else if (type == 3)
	{
		system("cls");
		printf("密码错误，请重新登录\n");
		
		fflush(stdin); 
		UserMain(user_fp, header);
	}
	else
	{
		system("cls");
		printf("账号不存在，请重新登录\n");
		
		fflush(stdin); 
		UserMain(user_fp, header);	
	}
}

/*
 *	注册界面 
 */
void UserRegister(user_list *header, FILE *user_fp) 
{
	/* 账号密码输入界面 */
	char userID[20];
	char userPassword[50];
	printf("————————————————————\n");
    printf("#               账号注册               #\n");
    printf("————————————————————\n");
    printf("请输入要注册的账号：");
    scanf("%s", userID);
    printf("请输入要注册的密码：");
    scanf("%s", userPassword);
    
    /* 获取用户类型 
		0：用户不存在 1：普通用户 2：管理员用户 3：密码错误	 */
    int type;
	type = GetUserType(header, userID, userPassword);
    
    /* 若账号不存在,将用户添加到链表、更新数据文件并打开登录界面 */
    if (type == 0)
    {
    	UserAdd(header, CreateNode(userID, userPassword, "user")); 
    	UserSave(header, user_fp); 
    	
    	system("cls");
    	printf("注册成功，请登录\n");
    	UserLogin(header, user_fp);
	}
	/* 若账号已经存在，提示错误并返回上级界面 */
	else
	{
		system("cls");
		printf("该账号已经存在，请直接登录或重新注册！\n");
		
		fflush(stdin); 
		UserMain(user_fp, header);
	}
}

/*
 *	改密码界面 
 */
void UserPswChange(user_list *header, FILE *user_fp)
{
	/* 定位头结点 */
	user_list *p;
	p = header;
	
	/* 账号密码输入界面 */
	char userID[20];
	char userPassword[50];
	char changedPassword[50];
	printf("————————————————————\n");
    printf("#               密码更改               #\n");
    printf("————————————————————\n");
    printf("请输入更改的账号：");
    scanf("%s", userID);
    printf("请输入原来的密码：");
    scanf("%s", userPassword);
    
    /* 获取用户类型 
		0：用户不存在 1：普通用户 2：管理员用户 3：密码错误	 */
    int type;
	type = GetUserType(header, userID, userPassword);
    
    /* 若账号密码正确则进行更改密码，否则提示错误返回上级菜单 */
    if (type == 1 || type == 2)
    {
    	printf("请输入更改后的密码：");
    	scanf("%s", changedPassword);
    	
    	while (p->next != NULL)
    	{
    		p = p->next;
    		if (strcmp(p->m_strID, userID) == 0)
    		{
    			/* 更新密码并保存数据 */
    			memcpy(&(p->m_strPassword), &changedPassword, sizeof(p->m_strPassword));
    			UserSave(header, user_fp);
    			
    			system("cls");
    			printf("成功修改密码!\n");
    			
    			fflush(stdin);
    			UserMain(user_fp, header); 
			}
		}
	}
	else if (type == 3)
	{
		system("cls");
		printf("原密码错误！\n");
		
		fflush(stdin);
		UserMain(user_fp, header);
	}
	else
	{
		system("cls");
		printf("账号不存在！\n");
		
		fflush(stdin);
		UserMain(user_fp, header);
	}
}

/*
 *	获取用户类型 
 *	0：用户不存在 1：普通用户 2：管理员用户 3：密码错误	 
 */
int GetUserType(user_list *header, char userID[], char userPassword[]) 
{
	/* 定位头结点 */
	user_list *p = header;
	
	/* 初始化返回值以及管理员字符数组 */
	int flag;
	flag = 0;
	char admin[] = "admin";
	
	/* 遍历链表 */
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->m_strID, userID) == 0)
		{
			if (strcmp(p->m_strPassword, userPassword) == 0)
			{
				/* 账号密码正确，管理员账号 */ 
				if (strcmp(p->m_strType, admin) == 0) 
				{
					flag = 2;
				}
				/* 账号密码正确，普通用户 */ 
				else
				{
					flag = 1;
				}
			}
			/* 密码错误 */
			else 
			{
				flag = 3;
			}
		}
	}
	/* 返回用户类型 */
	return flag;
}

/*
 *	读取文件数据至链表 
 */
void UserRead(user_list *header, FILE *user_fp)
{
	/* 获取已存储用户数量 */
	int userAmount;
	userAmount = GetFileLines(user_fp); 
	
	/* 读取数据至链表 */
	int i;
	for (i=0; i<userAmount; i++)
	{
		char fileID[20];
		char filePassword[50];
		char fileType[10];
		fscanf(user_fp, "%s", fileID);
		fscanf(user_fp, "%s", filePassword);
		fscanf(user_fp, "%s", fileType);
		UserAdd(header, CreateNode(fileID, filePassword, fileType));
	}
	
	rewind(user_fp);
}

/*
 *	增加一个用户结点 
 */
void UserAdd(user_list *header, user_list *newUser)
{
	/* 定位头结点 */
	user_list *p;
	p = header;
	
	/* 寻找链表尾结点 */
	while (p->next != NULL)
	{
		p = p->next;	
	}
	
	/* 衔接结点 */
	p->next = newUser;
}

/*
 *	保存数据至文件 
 */
void UserSave(user_list *header, FILE *user_fp)
{
	/* 定位头结点 */
	user_list *p = header;
	
	/* 清空文件以写入数据 */
	user_fp = fopen("user_data.txt", "w+");
	
	/* 遍历链表按格式导出数据至文件 */
	while (p->next != NULL)
	{
		p = p->next;
		fprintf(user_fp, "%s\t%s\t%s\n", p->m_strID, p->m_strPassword, p->m_strType);
	}
	
	rewind(user_fp);
}

/*
 *	创建结点 
 */
user_list *CreateNode(char userID[], char userPassword[], char userType[])
{
	/* 创建一个结点 */
	user_list *p = NULL;
	p = (user_list *)malloc(sizeof(user_list));
	
	if (p == NULL)
	{
		printf("分配内存失败。");
		exit(0);
	}
	
	/* 初始化数据以及指针 */
	memcpy(p->m_strID, userID, sizeof(p->m_strID));
	memcpy(p->m_strPassword, userPassword, sizeof(p->m_strPassword));
	memcpy(p->m_strType, userType, sizeof(p->m_strType));
	p->next = NULL;
}

/*
 *	释放链表 
 */
void FreeNode(user_list *header)
{
	user_list *node;
	
    while (header != NULL){
        node = header;
        header = header->next;
        free(node);
    }
    
    free(header);
}
