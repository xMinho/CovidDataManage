#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"


/*******************
 *
 *	 菜单系统模块 
 *
 *******************/


/*
 * 打开主界面
 */
void OpenMenu(int userType)
{
	/* 疫情数据文件导入 */
	FILE *ill_fp;
	
	if((ill_fp=fopen("ill_data.txt", "a+")) == NULL) 
	{
    	exit(0);
    }
    
    
    /* 定义结构体并清空 */
    illdata Data[AMOUNT];
	memset(Data, 0, sizeof(illdata)*AMOUNT);
	
	/* 如果数据文件为空则新增一个数据 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	
	if (dataAmount == 0)
	{
		AddData(Data, ill_fp);
	}
	
	/* 数据处理，导入至结构体 */
	HandleData(Data, ill_fp);
    
	/* 打印主功能菜单界面并获取输入的选择 */
	int flag;
	PrintMenu(userType);
	scanf("%d", &flag);
	
	/* 根据获取的选项执行对应功能 */
	switch (flag)
	{
		/* 全国总计数据 */
		case 0:
			system("cls");
			PrintTotalData(Data, ill_fp, userType);
			break;
		/* 	全国详细数据 */ 
		case 1:
			system("cls");
			PrintAllData(Data, ill_fp, userType);
			break;
		/* 省区市数据 */
		case 2:
			system("cls");
			PrintAreaData(Data, ill_fp, userType);
			break;
		/* 全国平均数据 */
		case 3:
			system("cls");
			PrintAverData(Data, ill_fp, userType);
			break;
		/* 打印拐点 */ 
		case 4:
			system("cls");
			PrintTurningPoint(Data, ill_fp, userType);
			break;
		/* 疫情图表 */
		case 5:
			system("cls");
			PrintDataGraph(Data, ill_fp, userType);
			break;
		/* 退出程序 */
		case 6:
			break;
		/* 管理员疫情数据管理 */
		case 7:
			system("cls");
			if (userType == 2)
			{
				OpenDataMenu(Data, ill_fp);
			}
			else
			{
				printf("非管理员无法使用该功能。\n");
				OpenMenu(userType);
			}
			break;
		/* 输入其他回到主界面 */
		default:
			system("cls");
			OpenMenu(userType);
			break;
	}
}

/*
 *	打开数据管理主界面 
 */
void OpenDataMenu(illdata *pData, FILE *ill_fp)
{
	/* 打印数据管理菜单界面并获取输入的选择 */
	int flag;
	PrintDataMenu();
	scanf("%d", &flag);
	
	/* 根据获取的选项执行对应功能 */
	switch (flag)
	{
		/* 数据录入 */
		case 0:
			system("cls");
			InputData(pData, ill_fp);
			break;
		/* 数据修改 */
		case 1:
			system("cls");
			ChangeData(pData, ill_fp);
			break;
		/* 新增数据 */
		case 2:
			system("cls");
			AddData(pData, ill_fp);
			break;
		/* 输入其他回到管理员主界面 */
		default:
			system("cls");
			OpenMenu(2);
			break;
	}
}

/*
 *	打印主界面 
 */
void PrintMenu(int userType)
{
	printf("————————————————————\n");
    printf("#         新冠疫情数据查询系统         #\n");
    if (userType == 2)
	{
		printf("#               <管理员>               #\n");	
	} 
    printf("# —————————————————— #\n");
	printf("# 0.查看全国总计疫情数据	       #\n");
	printf("# 1.查询全国详细疫情数据	       #\n");
	printf("# 2.查看某省区市疫情数据	       #\n");
	printf("# 3.查看全国疫情平均数据	       #\n");
	printf("# 4.查看全国疫情拐点统计	       #\n");
	printf("# 5.查看全国疫情数据图表	       #\n");
	printf("# 6.退出程序	                       #\n");
	if (userType == 2) 
	{
		printf("# —————————————————— #\n");
		printf("# 7.进行疫情数据录入工作	       #\n");
	}
	printf("————————————————————\n");
	printf("请输入序号使用对应功能：");
}

/*
 *	打印数据管理主界面 
 */
void PrintDataMenu()
{
	printf("————————————————————\n");
    printf("#         新冠疫情数据管理系统         #\n");
	printf("#               <管理员>               #\n");	
    printf("# —————————————————— #\n");
	printf("# 0.省区市数据录入	               #\n");
	printf("# 1.省区市数据修改	               #\n");
	printf("# 2.新增一天的疫情数据	               #\n");
	printf("# 3.返回主界面      	               #\n");
	printf("————————————————————\n");
	printf("请输入序号使用对应功能：");
}
