#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"


/*******************
 *
 *	 ���ݲ�ѯģ�� 
 *
 *******************/
 
/*
 *	ȫ���ܼ����� 
 */
void PrintTotalData(illdata *pData, FILE *ill_fp, int userType)
{
	/* ������ѯ�ж� */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date[11];
		
		printf("��������������������������������������\n");
	   	printf("#           ȫ���ܼ���������         #\n");
	   	if (GetDataAmount(ill_fp) > 0)
	   	{
	   		printf("#          �Ѹ����� %s       #\n", GetDateStr(GetDataAmount(ill_fp) - 1));
		}
		else
		{
			printf("#       �������ݣ���ϵ����Ա¼��     #\n");
		}
		printf("��������������������������������������\n");
		printf("������Ҫ��ѯ������(��ʽ: yyyy-mm-dd)\n");
		printf(">");
		scanf("%s", date);
		
		/* ��ȡ������� */
		int dateCode;
		dateCode = GetDateCode(pData, date, ill_fp);
		
		/* �ж������Ƿ�Ϸ� */
		if (dateCode != -1)
		{
			system("cls");
			printf("��������������������������������������\n");
	   		printf("#           ȫ���ܼ���������         #\n");
			printf("��������������������������������������\n");
			PrintData((pData + dateCode), 0);
			printf("��������������������������������������\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
		else
		{
			printf("\n��������������������������������������\n");
			printf("������δ��¼���������ݻ����ڸ�ʽ���Ϸ�!\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}
 
/*
 *	ȫ����ϸ���� 
 */
void PrintAllData(illdata *pData, FILE *ill_fp, int userType)
{
	/* ������ѯ�ж� */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date[11];
		
		printf("��������������������������������������\n");
	   	printf("#           ȫ����ϸ��������         #\n");
	   	if (GetDataAmount(ill_fp) > 0)
	   	{
	   		printf("#          �Ѹ����� %s       #\n", GetDateStr(GetDataAmount(ill_fp) - 1));
		}
		else
		{
			printf("#       �������ݣ���ϵ����Ա¼��     #\n");
		}
		printf("��������������������������������������\n");
		printf("������Ҫ��ѯ������(��ʽ: yyyy-mm-dd)\n");
		printf(">");
		scanf("%s", date);
		
		/* ��ȡ������� */
		int dateCode = GetDateCode(pData, date, ill_fp);
		
		/* �ж������Ƿ�Ϸ� */
		if (dateCode != -1)
		{
			system("cls");
			printf("��������������������������������������\n");
	   		printf("#            �������ݲ�ѯ            #\n");
			printf("��������������������������������������\n");
			
			int i;
			for (i=0; i<36; i++)
			{
				printf("[%d.]", i);
				PrintData((pData + dateCode), i);
				printf("\n");
			}
			printf("��������������������������������������\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
		else
		{
			printf("\n��������������������������������������\n");
			printf("������δ��¼���������ݻ����ڸ�ʽ���Ϸ�!\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	ʡ�������� 
 */
void PrintAreaData(illdata *pData, FILE *ill_fp, int userType)
{
	/* ������ѯ�ж� */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		char date[11];
		char area[20];
		
		/* �����Ϸ��ж� */
		int area_flag;
		area_flag = 0;
		
		system("cls");
		printf("������������������������������������������������������������������\n");
	    printf("#           		�������ݲ�ѯ		                 #\n");
	   	printf("#                   �Ѹ����� %s                          #\n", GetDateStr(GetDataAmount(ill_fp) - 1));
		printf("������������������������������������������������������������������\n");
		printf("# ����: ���������֡��������ӱ���������ɽ�������ա��㽭������     #\n"
		 	   "#       ������������ɽ�������ϡ����������ϡ��㶫�����ϡ��Ĵ�     #\n"
			   "#       ���ݡ����ϡ����������ࡢ�ຣ������������Ϻ�������     #\n"
			   "#       ���ء����ġ��½�����ۡ����š�̨�塢�����������ɹ�       #\n");
		printf("������������������������������������������������������������������\n");
		printf("������Ҫ��ѯ������(��ʽ: yyyy-mm-dd)\n");
		printf(">");
		scanf("%s", date);
		printf("������Ҫ��ѯ�ĵ���\n");
		printf(">");
		scanf("%s", area);
		
		/* ������� */
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
					printf("��������������������������������������\n");
   			 		printf("#            �������ݲ�ѯ            #\n");
					printf("��������������������������������������\n");
					PrintData((pData + dateCode), i);
					printf("��������������������������������������\n");
					printf("������ѯ����0���ص�����������1��");
					scanf("%d", &query_flag);
				}
			}
			
			if (area_flag == 0)
			{
				printf("\n��������������������������������������\n");
				printf("�����ڵĵ���!\n");
				printf("������ѯ����0���ص�����������1��");
				scanf("%d", &query_flag);
			}
		}
		else
		{
			printf("\n��������������������������������������\n");
			printf("������δ��¼���������ݻ����ڸ�ʽ���Ϸ�!\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	ȫ��ƽ������ 
 */
void PrintAverData(illdata *pData, FILE *ill_fp, int userType) 
{
	/* ������ѯ�ж� */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date_s[11]; //��ʼ���� 
		char date_e[11]; //��ֹ���� 
		
		printf("����������������������������������������\n");
	    printf("#           ƽ�����ݲ�ѯ               #\n");
		printf("����������������������������������������\n");
	    printf(" ��������ʼ����: ");
		scanf("%s", date_s);
		printf(" �������ֹ����: ");
		scanf("%s", date_e);
		
		/* ��ȡ������� */
		int code_s;
		code_s = GetDateCode(pData, date_s, ill_fp); 
		int code_e;
		code_e = GetDateCode(pData, date_e, ill_fp); 
		
		if ((code_s != -1) && (code_e != -1) && (code_s < code_e))
		{
			/* ���ڲ�ֵ */
			int diff;
			diff = code_e - code_s + 1;
			
			/* �洢��ֵ�ܼ� */
			int sum[10] = {0};
			
			int i;
			int j;
			for(i=code_s; i<=code_e; i++) 
			{
				for (j=0; j<10; j++) {
					sum[j] = sum[j] + (pData + i)->m_sArea[0].m_nType[j];
				}
			}
			
			/* ��ӡ���� */
			system("cls");
			printf("��������������������������������������������\n");
		    printf("#               ƽ�����ݲ�ѯ               #\n");
		    printf("#      	  %-10s �� %10s         #\n", date_s, date_e);
			printf("��������������������������������������������\n");
			printf(">  ƽ���ۼ�ȷ��: %-7d", sum[0]/diff);
			printf("  ƽ������ȷ��: %-7d\n", sum[1]/diff);
			printf(">  ƽ���ۼ�����: %-7d", sum[2]/diff);
			printf("  ƽ����������: %-7d\n", sum[3]/diff);
			printf(">  ƽ���ۼ�����: %-7d", sum[4]/diff);
			printf("  ƽ����������: %-7d\n", sum[5]/diff);
			printf(">  ƽ����������: %-7d", sum[6]/diff);
			
			/* �жϱ仯���� */
			if ((sum[7]/diff) < 0) 
			{
				printf("  ƽ����������: %-7d\n", 0-(sum[7]/diff));
			} 
			else 
			{
				printf("  ƽ����������: %-7d\n", sum[7]/diff);
			}
			
			printf(">  ƽ��������֢: %-7d", sum[8]/diff);
			/* �жϱ仯���� */
			if ((sum[9]/diff) < 0) 
			{
				printf("  ƽ��������֢: %-7d\n", 0-(sum[9]/diff));
			} 
			else 
			{
				printf("  ƽ��������֢: %-7d\n", sum[9]/diff);
			}
			
			printf("��������������������������������������������\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
		else if ((code_s >= code_e) && (code_s != -1))
		{
			printf("\n����������������������������������������\n");
			printf("��ʼ���ڲ��ܴ��ڻ���ڽ�ֹ����!\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
		else
		{
			printf("\n����������������������������������������\n");
			printf("���ڸ�ʽ�������!��ȷ��ʽ��: 2021-1-1\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	��ӡ�յ� 
 */
void PrintTurningPoint(illdata *pData, FILE *ill_fp, int userType) 
{	
	/* ��ȡ�Ѵ��������� */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	
	printf("����������������������������������������\n");
    printf("#               �յ�ͳ��               #\n");
	printf("����������������������������������������\n");
	/* ��ǰ����ͺ��������Աȣ��Ѽ�¼����Ӧ����10  */
	if (dataAmount > 10)
	{
		/* �жϹյ㲢��ӡ */
		int i;
		int h;
		for (i=5; i<dataAmount; i++) 
		{
			/* �յ�����ж� */
			int point_flag;
			point_flag = 0;
			
			/* ��ǰ����Ա� */
			for (h=i-1; h>=(i-5); h--) 
			{
				if (((pData + i)->m_sArea[0].m_nType[1]) <= ((pData + h)->m_sArea[0].m_nType[1])) 
				{
					point_flag = 1;
				}
			}
			
			/* �������ǰ���� */
			if (point_flag == 0)
			{
				/* �������Ա� */
				for (h=i+1; h<=(i+5); h++) 
				{
					if (((pData + i)->m_sArea[0].m_nType[1]) <= ((pData + h)->m_sArea[0].m_nType[1])) 
					{
						point_flag = 1;
					}
				}
			}
			
			/* ��ӡ�յ����� */
			if (point_flag == 0) 
			{
				printf(" %10s *\n", (pData + i)->m_strDay); 
			}
		}
		printf("����������������������������������������\n");
	}
	
	printf("���»س�����������...");
	fflush(stdin);
	getchar();
	system("cls");
	OpenMenu(userType);
}

/*
 *	�Զ����������ͼ�� 
 */
void PrintDataGraph(illdata *pData, FILE *ill_fp, int userType) 
{
	/* ������ѯ�ж� */
	int query_flag;
	query_flag = 0;
	
	while (query_flag == 0)
	{
		system("cls");
		char date[11];
		int rate;
		
		printf("��������������������������������������\n");
	   	printf("#           ȫ����������ͼ��         #\n");
		printf("��������������������������������������\n");
		printf("����Ҫ��ѯ������: ");
		scanf("%s", date);
		printf("����ͼ�����(1~1000): 1:");
		scanf("%d", &rate);
		int dateCode;
		dateCode = GetDateCode(pData, date, ill_fp);
		
		if ((rate>0) && (rate<1000))
		{
			if (dateCode != -1)
			{
				system("cls");
				/* ��ӡͼ�� */
				printf("\n");
				printf("%45s %s ��������ͼ��\n", (pData + dateCode)->m_sArea[0].m_strName, (pData + dateCode)->m_strDay);
				printf("\n");
				
				/* ���� */
				int unit;
				unit = ((pData + dateCode)->m_sArea[0].m_nType[0])/rate;
				
				int i;
				for(i=(unit+1); i>0; i--)
				{
					/* ��ӡ��״ͼ */
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
					/* �жϱ仯���� */
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
					/* �жϱ仯���� */
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
				printf("     ������������������������������������������������������������������������������������������������\n");
				
				/* ��ӡ��ֵ */
				printf("%10d%10d%10d%10d%10d%10d%10d", (pData + dateCode)->m_sArea[0].m_nType[0],(pData + dateCode)->m_sArea[0].m_nType[1],(pData + dateCode)->m_sArea[0].m_nType[2],(pData + dateCode)->m_sArea[0].m_nType[3],(pData + dateCode)->m_sArea[0].m_nType[4],(pData + dateCode)->m_sArea[0].m_nType[5],(pData + dateCode)->m_sArea[0].m_nType[6]);
				/* �ж�������������� */
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
				
				/* ��ӡ��Ӧ�������� */
				printf("    �ۼ�ȷ��  ����ȷ��  �ۼ�����  ��������  �ۼ�����  ��������  ��������");
				/* �ж�������������ӡ��Ӧ���� */
				if (((pData + dateCode)->m_sArea[0].m_nType[7]) >= 0) 
				{
					printf("  ��������  ������֢");
				} 
				else 
				{
					printf("  ��������  ������֢");
				}
				if (((pData + dateCode)->m_sArea[0].m_nType[9]) >= 0) 
				{
					printf("  ������֢\n");
				} 
				else 
				{
					printf("  ������֢\n");
				}
				printf("    (����: 1:%d)\n", rate);
				printf("\n");
				printf("��������������������������������������\n");
				printf("������ѯ����0���ص�����������1��");
				scanf("%d", &query_flag);
			}
			else
			{
				printf("\n��������������������������������������\n");
				printf("������δ��¼���������ݻ����ڸ�ʽ���Ϸ�!\n");
				printf("������ѯ����0���ص�����������1��");
				scanf("%d", &query_flag);
			}	
		}
		else
		{
			printf("\n��������������������������������������\n");
			printf("�ñ������Ϸ���������1~1000֮�����ֵ!\n");
			printf("������ѯ����0���ص�����������1��");
			scanf("%d", &query_flag);
		}
	}
	
	system("cls");
	OpenMenu(userType);
}

/*
 *	���ݴ�ӡģ�� 
 */
void PrintData(illdata *pData, int areaCode) 
{
	printf("��%s��(%s)\n", pData->m_sArea[areaCode].m_strName, pData->m_strDay);
	printf(">  �ۼ�ȷ��: %-7d", pData->m_sArea[areaCode].m_nType[0]);
	printf("  ����ȷ��: %-7d\n", pData->m_sArea[areaCode].m_nType[1]);
	printf(">  �ۼ�����: %-7d", pData->m_sArea[areaCode].m_nType[2]);
	printf("  ��������: %-7d\n", pData->m_sArea[areaCode].m_nType[3]);
	printf(">  �ۼ�����: %-7d", pData->m_sArea[areaCode].m_nType[4]);
	printf("  ��������: %-7d\n", pData->m_sArea[areaCode].m_nType[5]);
	printf(">  ��������: %-7d", pData->m_sArea[areaCode].m_nType[6]);
	
	/* �жϱ仯���� */
	if ((pData->m_sArea[areaCode].m_nType[7]) < 0) 
	{
		printf("  ��������: %-7d\n", 0 - pData->m_sArea[areaCode].m_nType[7]);
	} 
	else 
	{
		printf("  ��������: %-7d\n", pData->m_sArea[areaCode].m_nType[7]);
	}
	
	printf(">  ������֢: %-7d", pData->m_sArea[areaCode].m_nType[8]);
	/* �жϱ仯���� */
	if ((pData->m_sArea[areaCode].m_nType[9]) < 0) 
	{
		printf("  ������֢: %-7d\n", 0 - pData->m_sArea[areaCode].m_nType[9]);
	} 
	else 
	{
		printf("  ������֢: %-7d\n", pData->m_sArea[areaCode].m_nType[9]);
	}
}

