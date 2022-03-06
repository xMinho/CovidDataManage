#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"


/*******************
 *
 *	 数据处理模块 
 *
 *******************/


/*
 *	增加一天的数据 
 */
void AddData(illdata *pData, FILE *ill_fp)
{
	/* 获取已存数据数量 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	
	/* 五月第一天之前 */
	if (dataAmount < 121)
	{
		fprintf(ill_fp, "%s\n", GetDateStr(dataAmount));
		fprintf(ill_fp, "%s", "全国\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "吉林\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "辽宁\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "河北\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "陕西\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "山西\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "江苏\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "浙江\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "安徽\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "福建\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "江西\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "山东\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "河南\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "湖北\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "湖南\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "广东\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "海南\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "四川\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "贵州\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "云南\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "陕西\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "甘肃\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "青海\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "北京\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "天津\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "上海\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "重庆\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "广西\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "西藏\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "宁夏\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "新疆\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "香港\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "澳门\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "台湾\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "黑龙江\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "内蒙古\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n");
							  
		if (dataAmount != 0)
		{
			printf("成功添加 %s 的疫情数据，可以进行数据录入了!\n", GetDateStr(dataAmount));
		}	
					  
		rewind(ill_fp);
	}
	else
	{
		printf("超过系统有效期!\n"); 
	}
	
	/* 返回上级界面 */
	if (dataAmount != 0)
	{
		OpenDataMenu(pData, ill_fp);
	}
}

/*
 *	数据录入 
 *	数据类型:
 *		0:累计确诊	1:新增确诊	2:累计治愈 	3:新增治愈 	4:累计死亡
 * 		5:新增死亡	6:现有疑似 	7:疑似变化 	8:现有重症 	9:重症变化
 */
void InputData(illdata *pData, FILE *ill_fp)
{
	/* 获取已存数据数量以及定义变量 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	int k;
	
	/* 输入日期 */
	char date[11];
	printf("—————————————————————————————————\n");
    printf("#           		疫情数据录入		                 #\n");
   	printf("#                   已更新至 %s                          #\n", GetDateStr(dataAmount - 1));
	printf("—————————————————————————————————\n");
	printf("请输入要录入的日期(格式为yyyy-mm-dd，如2021-01-01)\n");
	printf(">");	
	scanf("%s", date);
	
	/* 获取日期序号 */
	int code;
	code = GetDateCode(pData, date, ill_fp);
	
	/* 若该日期数据存在 */
	if (code != -1)
	{
		/* 持续输入判断 */
		int input_flag;
		input_flag = 0;
		
		while (input_flag == 0)
		{
			/* 地区查找判断 */
			int area_flag;
			area_flag = 0;
			
			printf("正在录入 %s 的疫情数据\n", date);
			printf("—————————————————————————————————\n");
			printf("# 地区: 广西、吉林、辽宁、河北、陕西、山西、江苏、浙江、安徽     #\n"
				   "#       福建、江西、山东、河南、湖北、湖南、广东、海南、四川     #\n"
				   "#       贵州、云南、陕西、甘肃、青海、北京、天津、上海、重庆     #\n"
				   "#       西藏、宁夏、新疆、香港、澳门、台湾、黑龙江、内蒙古       #\n");
			printf("# ——————————————————————————————— #\n");
			printf("# 类型: 0:累计确诊 1:新增确诊 2:累计治愈 3:新增治愈 4:累计死亡   #\n"
				   "#       5:新增死亡 6:现有疑似 7:疑似变化 8:现有重症 9:重症变化   #\n");
			printf("—————————————————————————————————\n");
			printf("请按格式输入: <地区> <0> <1> <2> <3> <4> <5> <6> <7> <8> <9>\n");
			printf(">");
			
			/* 获取输入的要更改数据 */
			char area[10];
			int type[10];
			scanf("%s", area);
			for (i=0; i<10; i++)
			{
				scanf("%d", &type[i]);
			}
			
			/* 寻找要更改的地区，跳过第一个全国数据 */
			for(i=1; i<36; i++) 
			{
				/* 若找到地区 */
				if (strcmp(area, (pData + code)->m_sArea[i].m_strName) == 0) 
				{
					/* 地区查找判断更改为找到 */
					area_flag = 1;
					
					/* 录入数值数据至结构体 */
					for (k=0; k<10; k++)
					{
						(pData + code)->m_sArea[i].m_nType[k] = type[k];
					}
					
					/* 更新数据 */
					UpdateData(pData, ill_fp);
					
					/* 判断是否继续录入 */
					printf("录入成功，继续录入输入0，回到上级界面输入1: ");
					scanf("%d", &input_flag);
					system("cls");
				}
			}
			if (area_flag == 0)
			{
				system("cls");
				printf("不存在的地区!\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("该日期未记录有疫情数据或日期格式不合法!\n");
	}
	
	system("cls");
	OpenDataMenu(pData, ill_fp);
}

/* 
 *	更改数据
 *	数据类型:
 *		0:累计确诊	1:新增确诊	2:累计治愈 	3:新增治愈 	4:累计死亡
 *		5:新增死亡	6:现有疑似 	7:疑似变化 	8:现有重症 	9:重症变化
*/
void ChangeData(illdata *pData, FILE *ill_fp) 
{	
	/* 获取疫情数据数量并定义循环变量 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	
	/* 输入日期 */
	char date[11];
	printf("—————————————————————————————————\n");
    printf("#           		疫情数据修改		                 #\n");
   	printf("#                   已更新至 %s                          #\n", GetDateStr(dataAmount - 1));
	printf("—————————————————————————————————\n");
	printf("请输入要修改的日期(格式为yyyy-mm-dd，如2021-01-01)\n");
	printf(">");
	scanf("%s", date);
	
	/* 获取日期序号 */
	int code;
	code = GetDateCode(pData, date, ill_fp);
	
	/* 判断日期是否存在 */
	if (code != -1)
	{
		/* 持续更改判断 */
		int change_flag;
		change_flag = 0;
		
		while (change_flag == 0)
		{
			/* 地区合法性判断 */
			int area_flag;
			area_flag = 0;
			
			/* 数据类型合法性判断 */ 
			int type_flag;
			type_flag = 0;
			
			/* 要修改的数据 */
			char area[20];
			int value;
			int type;
						
			printf("正在修改 %s 的疫情数据\n", date);
			printf("————————————————————————————————\n");
			printf("# 地区: 广西、吉林、辽宁、河北、陕西、山西、江苏、浙江、安徽     #\n"
				   "#       福建、江西、山东、河南、湖北、湖南、广东、海南、四川     #\n"
				   "#       贵州、云南、陕西、甘肃、青海、北京、天津、上海、重庆     #\n"
				   "#       西藏、宁夏、新疆、香港、澳门、台湾、黑龙江、内蒙古       #\n");
			printf("# ——————————————————————————————— #\n");
			printf("# 类型: 0:累计确诊 1:新增确诊 2:累计治愈 3:新增治愈 4:累计死亡   #\n"
				   "#       5:新增死亡 6:现有疑似 7:疑似变化 8:现有重症 9:重症变化   #\n");
			printf("—————————————————————————————————\n");
			printf("请按格式输入: <地区> <类型> <数值>\n");
			printf(">");
			scanf("%s%d%d", area, &type, &value);
			
			/* 寻找省区市 ，跳过全国数据 */
			for(i=1; i<36; i++)
			{
				if (strcmp(area, (pData+code)->m_sArea[i].m_strName) == 0) 
				{
					/* 地区更改为合法 */
					area_flag = 1;
					
					if ((type >= 0) && (type < 10))
					{
						/* 数据类型更改为合法 */
						type_flag = 1;
						(pData+code)->m_sArea[i].m_nType[type] = value;
					}
				}
			}
			if (area_flag == 0)
			{
				printf("不存在的地区!\n");
			}
			if (type_flag == 0)
			{
				printf("不存在的数据类型!\n");
			}
			
			/* 地区、数据类型合法则更新数据 */
			if ((area_flag == 1) && (type_flag == 1))
			{
				UpdateData(pData, ill_fp);
				
				printf("修改成功，继续修改输入0，回到上级界面输入1: ");
				scanf("%d", &change_flag);
				system("cls");
			}
		}
	}
	else
	{
		system("cls");
		printf("该日期未记录有疫情数据或日期格式不合法!\n");
		ChangeData(pData, ill_fp);
	}

	system("cls");
	OpenDataMenu(pData, ill_fp);
}

/*
 *	更新数据 
 */
void UpdateData(illdata *pData, FILE *ill_fp)
{
	/* 获取疫情数据数量并定义循环变量 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	int j;
	int k;
	
	/* 计算全国总计数据 */
	for (i=0; i<dataAmount; i++)
	{
		/* 数据初始化 */ 
		for (j=0; j<10; j++)
		{
			(pData+i)->m_sArea[0].m_nType[j] = 0;	
		}
		
		/* 计算累计数据 */
		for (j=1; j<36; j++)
		{
			for (k=0; k<10; k++)
			{
				(pData+i)->m_sArea[0].m_nType[k] = (pData+i)->m_sArea[0].m_nType[k] + (pData+i)->m_sArea[j].m_nType[k];
			}
		}
	}
	
	/* 对各省市数据进行排序 (根据累计确诊进行排序) */
	for (i=0; i<dataAmount; i++)
	{
		/* 定义中间变量并初始化 */
		struct Area temp;
		memset(&temp, 0, sizeof(struct Area));
		
		/* 冒泡法排序地区数据 */
		for (j=1; j<36; j++)
		{
			for (k=j+1; k<36; k++)
			{
				if (((pData+i)->m_sArea[j].m_nType[0]) < ((pData+i)->m_sArea[k].m_nType[0])) 
				{
					memcpy(&temp, &((pData+i)->m_sArea[j]), sizeof(struct Area));
					memcpy(&((pData+i)->m_sArea[j]), &((pData+i)->m_sArea[k]), sizeof(struct Area));
					memcpy(&((pData+i)->m_sArea[k]), &temp, sizeof(struct Area));
				}
			}
		}
	}
	
	/* 清空文件以写入数据 */
	ill_fp = fopen("ill_data.txt", "w+"); 
	
	/* 更新数据至文件 */
	for(i=0; i<dataAmount; i++) 
	{
		/* 写入日期 */
		fprintf(ill_fp, "%s\n", (pData+i)->m_strDay);
		
		/* 写入地区数据 */
		for (j=0; j<36; j++) 
		{
			fprintf(ill_fp,"%s\t", (pData+i)->m_sArea[j].m_strName);
			 /* 最后一个数据单独，故k<9 */
			for (k=0; k<9; k++)
			{
				fprintf(ill_fp,"%d\t", (pData+i)->m_sArea[j].m_nType[k]);
			}
			/* 每行的最后一个数据加换行符 */
			fprintf(ill_fp, "%d\n", (pData+i)->m_sArea[j].m_nType[9]);
		}
	}
	
	rewind(ill_fp);
}

/*
 * 数据处理，将文件数据导入至结构体 
 */
void HandleData(illdata *pData, FILE *ill_fp) 
{
	/* 获取疫情数据数量并定义循环变量 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	int k;
	int j;
	
	/* 获取文件数据至结构体 */ 
	for(i=0; i<dataAmount; i++) 
	{
		/* 导入日期 */
    	char date[11];
    	fscanf(ill_fp, "%s", date);
    	strcpy((pData+i)->m_strDay, date);  
    	
    	/* 导入地区数据 */
		for (k=0; k<36; k++) 
		{
			fscanf(ill_fp, "%s", (pData+i)->m_sArea[k].m_strName);
			
			for (j=0; j<10; j++) 
			{
				fscanf(ill_fp, "%d", &((pData+i)->m_sArea[k].m_nType[j]));
			}
		}
	}
	
	rewind(ill_fp);
}


/*
 * 获取日期序号 
 */
int GetDateCode(illdata *pData, char date[], FILE *ill_fp)
{
	/* 初始化返回值 */
	int code;
	code = -1;
	
	/* 获取已存数据数量 */
	int amount;
	amount = GetDataAmount(ill_fp);
	
	/* 寻找日期，找到时赋值给code */
	int i;
	for(i=0; i<amount; i++) 
	{
		if (strcmp(date, (pData+i)->m_strDay) == 0) 
		{
			code = i;
		}
	}
	
	return code;
}


/*
 *	获取日期字符串 
 *	输入序号参数应为0为基准的序号 
 *	日期格式为：yyyy-mm-dd 
 */ 
char *GetDateStr(int code)
{
	/* 矫正误差 */
	code++;
	
	/* 月份，日 */
	int month;
	int day;
	
	/* 判断是否找到所属月份 */
	int flag;
	flag = 0;
	
	/* 存储1.1-5.1日期累计值 */
	int days[5] = {120, 90, 59, 31, 0};
	
	/* 初始化返回的日期字符串 */
	char *date;
	date = (char *)malloc(11);
	memset(date, 0 ,10);
	
	/* 判断序号属于1-5哪个月 */
	int i;
	for (i=0; (i<5) && (flag==0); i++)
	{
		if ((code - days[i]) > 0)
		{
			month = 5 - i;
			day = code - days[i];
			flag = 1;
		}
	}

	/* 根据日号单双位矫正格式 */
	if (day < 10)
	{
		sprintf(date, "2021-0%d-0%d\0", month, day);
	}
	else
	{
		sprintf(date, "2021-0%d-%d\0", month, day);
	}
	
	return date;
}


/*
 *	获取已存疫情数据数量 
 */
int GetDataAmount(FILE *ill_fp)
{
	/* 疫情数据每37行为一个单位 */
	int amount;
	amount = GetFileLines(ill_fp)/37;;
	
	return amount;
}


/*
 *	获取文件行数 
 */
int GetFileLines(FILE *fp) 
{
	/* 初始化文件行数变量 */
	int lines;
	lines = 0; 
	
	/* 每换行一次行数加一 */
	while(!feof(fp)) 
	{
    	if(fgetc(fp) == '\n')  
		{ 
        	lines++;
    	}
	}
	
	rewind(fp);
	
	return lines;
}
