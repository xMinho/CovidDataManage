#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"

/*
	登录注册模块
	实现对登录注册的选择，以及登录注册操作。 
*/

void LoginMain(FILE *user_fp, FILE *ill_fp)
{
	char flag; //用于判断用户的操作
	
	/* 显示登录系统的主界面 */
	printf("————————————————————\n");
    printf("#         新冠疫情数据管理系统         #\n");
    printf("————————————————————\n");
    printf("# 已有账号，直接登录请输入: L/l        #\n");
    printf("# 没有账号，进行注册请输入：R/r        #\n");
    printf("————————————————————\n");
    printf(">");
    scanf("%c", &flag);
    
    /* 判断是登录或注册 */
    if (flag == 'L' || flag == 'l')
    {
    	system("cls");
    	Login(user_fp, ill_fp);
	}
	else if (flag == 'R' || flag == 'r')
	{
		system("cls");
		Register(user_fp, ill_fp);
	}
	else
	{
		system("cls");
		printf("未知选项，请重新输入选择。\n");
		LoginMain(user_fp, ill_fp);
	}
}

void Login(FILE *user_fp, FILE *ill_fp)
{
	user userLog;
	
	printf("————————————————————\n");
    printf("#               账号登录               #\n");
    printf("————————————————————\n");
    printf("请输入账号：");
    scanf("%s", userLog.m_strID);
    printf("请输入密码：");
    scanf("%s", userLog.m_strPassword);
    
    int type = GetUserType(userLog.m_strID, userLog.m_strPassword, user_fp);
    
    /* 登录 */
    if (type == 1 || type == 2)
    {
    	system("cls");
    	OpenMenu(type, ill_fp);
	}
	else
	{
		system("cls");
		printf("账号不存在或密码错误，请重新登录\n");
		Login(user_fp, ill_fp); 
	}
}

void Register(FILE *user_fp, FILE *ill_fp)
{
	user userReg; //定义用户结构体变量 
	
	printf("————————————————————\n");
    printf("#               账号注册               #\n");
    printf("————————————————————\n");
    printf("请输入要注册的账号：");
    scanf("%s", userReg.m_strID);
    printf("请输入要注册的密码：");
    scanf("%s", userReg.m_strPassword);
    
    int type = GetUserType(userReg.m_strID, userReg.m_strPassword, user_fp);
    
    /* 通过判断进行数据录入 */
    if (type == 0)
    {
    	fprintf(user_fp, "\n%s\t", userReg.m_strID);
    	fprintf(user_fp, "%s\t", userReg.m_strPassword);
    	fprintf(user_fp, "user");
    	rewind(user_fp);
    	
    	system("cls");
    	printf("注册成功，请登录\n");
    	Login(user_fp, ill_fp);
	}
	else
	{
		system("cls");
		printf("该账号已经存在，请重新注册！\n");
		Register(user_fp, ill_fp);
	}
}
