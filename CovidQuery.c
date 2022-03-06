#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"


/*******************
 *
 *	 数据查询模块 
 *
 *******************/
 
/*
 *	全国总计数据 
 */
void PrintTotalData(illdata *pData, FILE *ill_fp, int userType)
{
	/* 持续查询判断 */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date[11];
		
		printf("———————————————————\n");
	   	printf("#           全国总计疫情数据         #\n");
	   	if (GetDataAmount(ill_fp) > 0)
	   	{
	   		printf("#          已更新至 %s       #\n", GetDateStr(GetDataAmount(ill_fp) - 1));
		}
		else
		{
			printf("#       暂无数据，联系管理员录入     #\n");
		}
		printf("———————————————————\n");
		printf("请输入要查询的日期(格式: yyyy-mm-dd)\n");
		printf(">");
		scanf("%s", date);
		
		/* 获取日期序号 */
		int dateCode;
		dateCode = GetDateCode(pData, date, ill_fp);
		
		/* 判断日期是否合法 */
		if (dateCode != -1)
		{
			system("cls");
			printf("———————————————————\n");
	   		printf("#           全国总计疫情数据         #\n");
			printf("———————————————————\n");
			PrintData((pData + dateCode), 0);
			printf("———————————————————\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
		else
		{
			printf("\n———————————————————\n");
			printf("该日期未记录有疫情数据或日期格式不合法!\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}
 
/*
 *	全国详细数据 
 */
void PrintAllData(illdata *pData, FILE *ill_fp, int userType)
{
	/* 持续查询判断 */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date[11];
		
		printf("———————————————————\n");
	   	printf("#           全国详细疫情数据         #\n");
	   	if (GetDataAmount(ill_fp) > 0)
	   	{
	   		printf("#          已更新至 %s       #\n", GetDateStr(GetDataAmount(ill_fp) - 1));
		}
		else
		{
			printf("#       暂无数据，联系管理员录入     #\n");
		}
		printf("———————————————————\n");
		printf("请输入要查询的日期(格式: yyyy-mm-dd)\n");
		printf(">");
		scanf("%s", date);
		
		/* 获取日期序号 */
		int dateCode = GetDateCode(pData, date, ill_fp);
		
		/* 判断日期是否合法 */
		if (dateCode != -1)
		{
			system("cls");
			printf("———————————————————\n");
	   		printf("#            疫情数据查询            #\n");
			printf("———————————————————\n");
			
			int i;
			for (i=0; i<36; i++)
			{
				printf("[%d.]", i);
				PrintData((pData + dateCode), i);
				printf("\n");
			}
			printf("———————————————————\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
		else
		{
			printf("\n———————————————————\n");
			printf("该日期未记录有疫情数据或日期格式不合法!\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	省区市数据 
 */
void PrintAreaData(illdata *pData, FILE *ill_fp, int userType)
{
	/* 持续查询判断 */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		char date[11];
		char area[20];
		
		/* 地区合法判断 */
		int area_flag;
		area_flag = 0;
		
		system("cls");
		printf("—————————————————————————————————\n");
	    printf("#           		疫情数据查询		                 #\n");
	   	printf("#                   已更新至 %s                          #\n", GetDateStr(GetDataAmount(ill_fp) - 1));
		printf("—————————————————————————————————\n");
		printf("# 地区: 广西、吉林、辽宁、河北、陕西、山西、江苏、浙江、安徽     #\n"
		 	   "#       福建、江西、山东、河南、湖北、湖南、广东、海南、四川     #\n"
			   "#       贵州、云南、陕西、甘肃、青海、北京、天津、上海、重庆     #\n"
			   "#       西藏、宁夏、新疆、香港、澳门、台湾、黑龙江、内蒙古       #\n");
		printf("—————————————————————————————————\n");
		printf("请输入要查询的日期(格式: yyyy-mm-dd)\n");
		printf(">");
		scanf("%s", date);
		printf("请输入要查询的地区\n");
		printf(">");
		scanf("%s", area);
		
		/* 日期序号 */
		int dateCode;
		dateCode = GetDateCode(pData, date, ill_fp);
		
		if (dateCode != -1)
		{
			int i;
			for(i=0; i<36; i++)
			{
				if (strcmp(area, (pData + dateCode)->m_sArea[i].m_strName) == 0) 
				{
					area_flag = 1;
					
					system("cls");
					printf("———————————————————\n");
   			 		printf("#            疫情数据查询            #\n");
					printf("———————————————————\n");
					PrintData((pData + dateCode), i);
					printf("———————————————————\n");
					printf("继续查询输入0，回到主界面输入1：");
					scanf("%d", &query_flag);
				}
			}
			
			if (area_flag == 0)
			{
				printf("\n———————————————————\n");
				printf("不存在的地区!\n");
				printf("继续查询输入0，回到主界面输入1：");
				scanf("%d", &query_flag);
			}
		}
		else
		{
			printf("\n———————————————————\n");
			printf("该日期未记录有疫情数据或日期格式不合法!\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	全国平均数据 
 */
void PrintAverData(illdata *pData, FILE *ill_fp, int userType) 
{
	/* 持续查询判断 */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date_s[11]; //起始日期 
		char date_e[11]; //截止日期 
		
		printf("————————————————————\n");
	    printf("#           平均数据查询               #\n");
		printf("————————————————————\n");
	    printf(" 请输入起始日期: ");
		scanf("%s", date_s);
		printf(" 请输入截止日期: ");
		scanf("%s", date_e);
		
		/* 获取日期序号 */
		int code_s;
		code_s = GetDateCode(pData, date_s, ill_fp); 
		int code_e;
		code_e = GetDateCode(pData, date_e, ill_fp); 
		
		if ((code_s != -1) && (code_e != -1) && (code_s < code_e))
		{
			/* 日期差值 */
			int diff;
			diff = code_e - code_s + 1;
			
			/* 存储数值总计 */
			int sum[10] = {0};
			
			int i;
			int j;
			for(i=code_s; i<=code_e; i++) 
			{
				for (j=0; j<10; j++) {
					sum[j] = sum[j] + (pData + i)->m_sArea[0].m_nType[j];
				}
			}
			
			/* 打印数据 */
			system("cls");
			printf("——————————————————————\n");
		    printf("#               平均数据查询               #\n");
		    printf("#      	  %-10s 至 %10s         #\n", date_s, date_e);
			printf("——————————————————————\n");
			printf(">  平均累计确诊: %-7d", sum[0]/diff);
			printf("  平均新增确诊: %-7d\n", sum[1]/diff);
			printf(">  平均累计治愈: %-7d", sum[2]/diff);
			printf("  平均新增治愈: %-7d\n", sum[3]/diff);
			printf(">  平均累计死亡: %-7d", sum[4]/diff);
			printf("  平均新增死亡: %-7d\n", sum[5]/diff);
			printf(">  平均现有疑似: %-7d", sum[6]/diff);
			
			/* 判断变化数据 */
			if ((sum[7]/diff) < 0) 
			{
				printf("  平均减少疑似: %-7d\n", 0-(sum[7]/diff));
			} 
			else 
			{
				printf("  平均新增疑似: %-7d\n", sum[7]/diff);
			}
			
			printf(">  平均现有重症: %-7d", sum[8]/diff);
			/* 判断变化数据 */
			if ((sum[9]/diff) < 0) 
			{
				printf("  平均减少重症: %-7d\n", 0-(sum[9]/diff));
			} 
			else 
			{
				printf("  平均新增重症: %-7d\n", sum[9]/diff);
			}
			
			printf("——————————————————————\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
		else if ((code_s >= code_e) && (code_s != -1))
		{
			printf("\n————————————————————\n");
			printf("起始日期不能大于或等于截止日期!\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
		else
		{
			printf("\n————————————————————\n");
			printf("日期格式输入错误!正确格式如: 2021-1-1\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	打印拐点 
 */
void PrintTurningPoint(illdata *pData, FILE *ill_fp, int userType) 
{	
	/* 获取已存日期数量 */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	
	printf("————————————————————\n");
    printf("#               拐点统计               #\n");
	printf("————————————————————\n");
	/* 与前五天和后五天做对比，已记录天数应大于10  */
	if (dataAmount > 10)
	{
		/* 判断拐点并打印 */
		int i;
		int h;
		for (i=5; i<dataAmount; i++) 
		{
			/* 拐点查找判断 */
			int point_flag;
			point_flag = 0;
			
			/* 与前五天对比 */
			for (h=i-1; h>=(i-5); h--) 
			{
				if (((pData + i)->m_sArea[0].m_nType[1]) <= ((pData + h)->m_sArea[0].m_nType[1])) 
				{
					point_flag = 1;
				}
			}
			
			/* 如果高于前五天 */
			if (point_flag == 0)
			{
				/* 与后五天对比 */
				for (h=i+1; h<=(i+5); h++) 
				{
					if (((pData + i)->m_sArea[0].m_nType[1]) <= ((pData + h)->m_sArea[0].m_nType[1])) 
					{
						point_flag = 1;
					}
				}
			}
			
			/* 打印拐点日期 */
			if (point_flag == 0) 
			{
				printf(" %10s *\n", (pData + i)->m_strDay); 
			}
		}
		printf("————————————————————\n");
	}
	
	printf("按下回车返回主界面...");
	fflush(stdin);
	getchar();
	system("cls");
	OpenMenu(userType);
}

/*
 *	自定义比例数据图表 
 */
void PrintDataGraph(illdata *pData, FILE *ill_fp, int userType) 
{
	/* 持续查询判断 */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date[11];
		int rate;
		
		printf("———————————————————\n");
	   	printf("#           全国疫情数据图表         #\n");
		printf("———————————————————\n");
		printf("输入要查询的日期: ");
		scanf("%s", date);
		printf("输入图表比例(1~1000): 1:");
		scanf("%d", &rate);
		int dateCode;
		dateCode = GetDateCode(pData, date, ill_fp);
		
		if ((rate>0) && (rate<1000))
		{
			if (dateCode != -1)
			{
				system("cls");
				/* 打印图表 */
				printf("\n");
				printf("%45s %s 疫情数据图表\n", (pData + dateCode)->m_sArea[0].m_strName, (pData + dateCode)->m_strDay);
				printf("\n");
				
				/* 比例 */
				int unit;
				unit = ((pData + dateCode)->m_sArea[0].m_nType[0])/rate;
				
				int i;
				for(i=(unit+1); i>0; i--)
				{
					/* 打印柱状图 */
					printf("%10s", "####");
					
					if ((((pData + dateCode)->m_sArea[0].m_nType[1])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					if ((((pData + dateCode)->m_sArea[0].m_nType[2])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					if ((((pData + dateCode)->m_sArea[0].m_nType[3])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					if ((((pData + dateCode)->m_sArea[0].m_nType[4])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					if ((((pData + dateCode)->m_sArea[0].m_nType[5])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					if ((((pData + dateCode)->m_sArea[0].m_nType[6])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					/* 判断变化数据 */
					if (((((pData + dateCode)->m_sArea[0].m_nType[7])/rate) >= i) || (((0-(pData + dateCode)->m_sArea[0].m_nType[7])/rate) >= i)) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					if ((((pData + dateCode)->m_sArea[0].m_nType[8])/rate) >= i) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					/* 判断变化数据 */
					if (((((pData + dateCode)->m_sArea[0].m_nType[9])/rate) >= i) || (((0-(pData + dateCode)->m_sArea[0].m_nType[9]/rate) >= i))) 
					{
						printf("%10s", "####");
					} 
					else 
					{
						printf("%10s", "    ");
					}
					printf("\n");
				}
				printf("     ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
				
				/* 打印数值 */
				printf("%10d%10d%10d%10d%10d%10d%10d", (pData + dateCode)->m_sArea[0].m_nType[0],(pData + dateCode)->m_sArea[0].m_nType[1],(pData + dateCode)->m_sArea[0].m_nType[2],(pData + dateCode)->m_sArea[0].m_nType[3],(pData + dateCode)->m_sArea[0].m_nType[4],(pData + dateCode)->m_sArea[0].m_nType[5],(pData + dateCode)->m_sArea[0].m_nType[6]);
				/* 判断数据增加与减少 */
				if (((pData + dateCode)->m_sArea[0].m_nType[7]) < 0) 
				{
					printf("%10d", 0-(pData + dateCode)->m_sArea[0].m_nType[7]);
				} 
				else 
				{
					printf("%10d", (pData + dateCode)->m_sArea[0].m_nType[7]);
				}
				printf("%10d",(pData + dateCode)->m_sArea[0].m_nType[8]);
				if (((pData + dateCode)->m_sArea[0].m_nType[9]) < 0) 
				{
					printf("%10d\n", 0-(pData + dateCode)->m_sArea[0].m_nType[9]);
				} 
				else 
				{
					printf("%10d\n", (pData + dateCode)->m_sArea[0].m_nType[9]);
				}
				
				/* 打印相应数据名称 */
				printf("    累计确诊  新增确诊  累计治愈  新增治愈  累计死亡  新增死亡  现有疑似");
				/* 判断数据正负，打印相应名称 */
				if (((pData + dateCode)->m_sArea[0].m_nType[7]) >= 0) 
				{
					printf("  新增疑似  现有重症");
				} 
				else 
				{
					printf("  减少疑似  现有重症");
				}
				if (((pData + dateCode)->m_sArea[0].m_nType[9]) >= 0) 
				{
					printf("  新增重症\n");
				} 
				else 
				{
					printf("  减少重症\n");
				}
				printf("    (比例: 1:%d)\n", rate);
				printf("\n");
				printf("———————————————————\n");
				printf("继续查询输入0，回到主界面输入1：");
				scanf("%d", &query_flag);
			}
			else
			{
				printf("\n———————————————————\n");
				printf("该日期未记录有疫情数据或日期格式不合法!\n");
				printf("继续查询输入0，回到主界面输入1：");
				scanf("%d", &query_flag);
			}	
		}
		else
		{
			printf("\n———————————————————\n");
			printf("该比例不合法，请输入1~1000之间的数值!\n");
			printf("继续查询输入0，回到主界面输入1：");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	数据打印模板 
 */
void PrintData(illdata *pData, int areaCode) 
{
	printf("【%s】(%s)\n", pData->m_sArea[areaCode].m_strName, pData->m_strDay);
	printf(">  累计确诊: %-7d", pData->m_sArea[areaCode].m_nType[0]);
	printf("  新增确诊: %-7d\n", pData->m_sArea[areaCode].m_nType[1]);
	printf(">  累计治愈: %-7d", pData->m_sArea[areaCode].m_nType[2]);
	printf("  新增治愈: %-7d\n", pData->m_sArea[areaCode].m_nType[3]);
	printf(">  累计死亡: %-7d", pData->m_sArea[areaCode].m_nType[4]);
	printf("  新增死亡: %-7d\n", pData->m_sArea[areaCode].m_nType[5]);
	printf(">  现有疑似: %-7d", pData->m_sArea[areaCode].m_nType[6]);
	
	/* 判断变化数据 */
	if ((pData->m_sArea[areaCode].m_nType[7]) < 0) 
	{
		printf("  减少疑似: %-7d\n", 0 - pData->m_sArea[areaCode].m_nType[7]);
	} 
	else 
	{
		printf("  新增疑似: %-7d\n", pData->m_sArea[areaCode].m_nType[7]);
	}
	
	printf(">  现有重症: %-7d", pData->m_sArea[areaCode].m_nType[8]);
	/* 判断变化数据 */
	if ((pData->m_sArea[areaCode].m_nType[9]) < 0) 
	{
		printf("  减少重症: %-7d\n", 0 - pData->m_sArea[areaCode].m_nType[9]);
	} 
	else 
	{
		printf("  新增重症: %-7d\n", pData->m_sArea[areaCode].m_nType[9]);
	}
}

