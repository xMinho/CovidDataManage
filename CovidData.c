#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"


/*******************
 *
 *	 ���ݴ���ģ�� 
 *
 *******************/


/*
 *	����һ������� 
 */
void AddData(illdata *pData, FILE *ill_fp)
{
	/* ��ȡ�Ѵ��������� */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	
	/* ���µ�һ��֮ǰ */
	if (dataAmount < 121)
	{
		fprintf(ill_fp, "%s\n", GetDateStr(dataAmount));
		fprintf(ill_fp, "%s", "ȫ��\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�ӱ�\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "ɽ��\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�㽭\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "ɽ��\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�㶫\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�Ĵ�\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�ຣ\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "���\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�Ϻ�\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "�½�\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "���\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "����\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "̨��\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "������\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n"
							  "���ɹ�\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n");
							  
		if (dataAmount != 0)
		{
			printf("�ɹ���� %s ���������ݣ����Խ�������¼����!\n", GetDateStr(dataAmount));
		}	
					  
		rewind(ill_fp);
	}
	else
	{
		printf("����ϵͳ��Ч��!\n"); 
	}
	
	/* �����ϼ����� */
	if (dataAmount != 0)
	{
		OpenDataMenu(pData, ill_fp);
	}
}

/*
 *	����¼�� 
 *	��������:
 *		0:�ۼ�ȷ��	1:����ȷ��	2:�ۼ����� 	3:�������� 	4:�ۼ�����
 * 		5:��������	6:�������� 	7:���Ʊ仯 	8:������֢ 	9:��֢�仯
 */
void InputData(illdata *pData, FILE *ill_fp)
{
	/* ��ȡ�Ѵ����������Լ�������� */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	int k;
	
	/* �������� */
	char date[11];
	printf("������������������������������������������������������������������\n");
    printf("#           		��������¼��		                 #\n");
   	printf("#                   �Ѹ����� %s                          #\n", GetDateStr(dataAmount - 1));
	printf("������������������������������������������������������������������\n");
	printf("������Ҫ¼�������(��ʽΪyyyy-mm-dd����2021-01-01)\n");
	printf(">");	
	scanf("%s", date);
	
	/* ��ȡ������� */
	int code;
	code = GetDateCode(pData, date, ill_fp);
	
	/* �����������ݴ��� */
	if (code != -1)
	{
		/* ���������ж� */
		int input_flag;
		input_flag = 0;
		
		while (input_flag == 0)
		{
			/* ���������ж� */
			int area_flag;
			area_flag = 0;
			
			printf("����¼�� %s ����������\n", date);
			printf("������������������������������������������������������������������\n");
			printf("# ����: ���������֡��������ӱ���������ɽ�������ա��㽭������     #\n"
				   "#       ������������ɽ�������ϡ����������ϡ��㶫�����ϡ��Ĵ�     #\n"
				   "#       ���ݡ����ϡ����������ࡢ�ຣ������������Ϻ�������     #\n"
				   "#       ���ء����ġ��½�����ۡ����š�̨�塢�����������ɹ�       #\n");
			printf("# �������������������������������������������������������������� #\n");
			printf("# ����: 0:�ۼ�ȷ�� 1:����ȷ�� 2:�ۼ����� 3:�������� 4:�ۼ�����   #\n"
				   "#       5:�������� 6:�������� 7:���Ʊ仯 8:������֢ 9:��֢�仯   #\n");
			printf("������������������������������������������������������������������\n");
			printf("�밴��ʽ����: <����> <0> <1> <2> <3> <4> <5> <6> <7> <8> <9>\n");
			printf(">");
			
			/* ��ȡ�����Ҫ�������� */
			char area[10];
			int type[10];
			scanf("%s", area);
			for (i=0; i<10; i++)
			{
				scanf("%d", &type[i]);
			}
			
			/* Ѱ��Ҫ���ĵĵ�����������һ��ȫ������ */
			for(i=1; i<36; i++) 
			{
				/* ���ҵ����� */
				if (strcmp(area, (pData + code)->m_sArea[i].m_strName) == 0) 
				{
					/* ���������жϸ���Ϊ�ҵ� */
					area_flag = 1;
					
					/* ¼����ֵ�������ṹ�� */
					for (k=0; k<10; k++)
					{
						(pData + code)->m_sArea[i].m_nType[k] = type[k];
					}
					
					/* �������� */
					UpdateData(pData, ill_fp);
					
					/* �ж��Ƿ����¼�� */
					printf("¼��ɹ�������¼������0���ص��ϼ���������1: ");
					scanf("%d", &input_flag);
					system("cls");
				}
			}
			if (area_flag == 0)
			{
				system("cls");
				printf("�����ڵĵ���!\n");
			}
		}
	}
	else
	{
		system("cls");
		printf("������δ��¼���������ݻ����ڸ�ʽ���Ϸ�!\n");
	}
	
	system("cls");
	OpenDataMenu(pData, ill_fp);
}

/* 
 *	��������
 *	��������:
 *		0:�ۼ�ȷ��	1:����ȷ��	2:�ۼ����� 	3:�������� 	4:�ۼ�����
 *		5:��������	6:�������� 	7:���Ʊ仯 	8:������֢ 	9:��֢�仯
*/
void ChangeData(illdata *pData, FILE *ill_fp) 
{	
	/* ��ȡ������������������ѭ������ */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	
	/* �������� */
	char date[11];
	printf("������������������������������������������������������������������\n");
    printf("#           		���������޸�		                 #\n");
   	printf("#                   �Ѹ����� %s                          #\n", GetDateStr(dataAmount - 1));
	printf("������������������������������������������������������������������\n");
	printf("������Ҫ�޸ĵ�����(��ʽΪyyyy-mm-dd����2021-01-01)\n");
	printf(">");
	scanf("%s", date);
	
	/* ��ȡ������� */
	int code;
	code = GetDateCode(pData, date, ill_fp);
	
	/* �ж������Ƿ���� */
	if (code != -1)
	{
		/* ���������ж� */
		int change_flag;
		change_flag = 0;
		
		while (change_flag == 0)
		{
			/* �����Ϸ����ж� */
			int area_flag;
			area_flag = 0;
			
			/* �������ͺϷ����ж� */ 
			int type_flag;
			type_flag = 0;
			
			/* Ҫ�޸ĵ����� */
			char area[20];
			int value;
			int type;
						
			printf("�����޸� %s ����������\n", date);
			printf("����������������������������������������������������������������\n");
			printf("# ����: ���������֡��������ӱ���������ɽ�������ա��㽭������     #\n"
				   "#       ������������ɽ�������ϡ����������ϡ��㶫�����ϡ��Ĵ�     #\n"
				   "#       ���ݡ����ϡ����������ࡢ�ຣ������������Ϻ�������     #\n"
				   "#       ���ء����ġ��½�����ۡ����š�̨�塢�����������ɹ�       #\n");
			printf("# �������������������������������������������������������������� #\n");
			printf("# ����: 0:�ۼ�ȷ�� 1:����ȷ�� 2:�ۼ����� 3:�������� 4:�ۼ�����   #\n"
				   "#       5:�������� 6:�������� 7:���Ʊ仯 8:������֢ 9:��֢�仯   #\n");
			printf("������������������������������������������������������������������\n");
			printf("�밴��ʽ����: <����> <����> <��ֵ>\n");
			printf(">");
			scanf("%s%d%d", area, &type, &value);
			
			/* Ѱ��ʡ���� ������ȫ������ */
			for(i=1; i<36; i++)
			{
				if (strcmp(area, (pData+code)->m_sArea[i].m_strName) == 0) 
				{
					/* ��������Ϊ�Ϸ� */
					area_flag = 1;
					
					if ((type >= 0) && (type < 10))
					{
						/* �������͸���Ϊ�Ϸ� */
						type_flag = 1;
						(pData+code)->m_sArea[i].m_nType[type] = value;
					}
				}
			}
			if (area_flag == 0)
			{
				printf("�����ڵĵ���!\n");
			}
			if (type_flag == 0)
			{
				printf("�����ڵ���������!\n");
			}
			
			/* �������������ͺϷ���������� */
			if ((area_flag == 1) && (type_flag == 1))
			{
				UpdateData(pData, ill_fp);
				
				printf("�޸ĳɹ��������޸�����0���ص��ϼ���������1: ");
				scanf("%d", &change_flag);
				system("cls");
			}
		}
	}
	else
	{
		system("cls");
		printf("������δ��¼���������ݻ����ڸ�ʽ���Ϸ�!\n");
		ChangeData(pData, ill_fp);
	}

	system("cls");
	OpenDataMenu(pData, ill_fp);
}

/*
 *	�������� 
 */
void UpdateData(illdata *pData, FILE *ill_fp)
{
	/* ��ȡ������������������ѭ������ */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	int j;
	int k;
	
	/* ����ȫ���ܼ����� */
	for (i=0; i<dataAmount; i++)
	{
		/* ���ݳ�ʼ�� */ 
		for (j=0; j<10; j++)
		{
			(pData+i)->m_sArea[0].m_nType[j] = 0;	
		}
		
		/* �����ۼ����� */
		for (j=1; j<36; j++)
		{
			for (k=0; k<10; k++)
			{
				(pData+i)->m_sArea[0].m_nType[k] = (pData+i)->m_sArea[0].m_nType[k] + (pData+i)->m_sArea[j].m_nType[k];
			}
		}
	}
	
	/* �Ը�ʡ�����ݽ������� (�����ۼ�ȷ���������) */
	for (i=0; i<dataAmount; i++)
	{
		/* �����м��������ʼ�� */
		struct Area temp;
		memset(&temp, 0, sizeof(struct Area));
		
		/* ð�ݷ������������ */
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
	
	/* ����ļ���д������ */
	ill_fp = fopen("ill_data.txt", "w+"); 
	
	/* �����������ļ� */
	for(i=0; i<dataAmount; i++) 
	{
		/* д������ */
		fprintf(ill_fp, "%s\n", (pData+i)->m_strDay);
		
		/* д��������� */
		for (j=0; j<36; j++) 
		{
			fprintf(ill_fp,"%s\t", (pData+i)->m_sArea[j].m_strName);
			 /* ���һ�����ݵ�������k<9 */
			for (k=0; k<9; k++)
			{
				fprintf(ill_fp,"%d\t", (pData+i)->m_sArea[j].m_nType[k]);
			}
			/* ÿ�е����һ�����ݼӻ��з� */
			fprintf(ill_fp, "%d\n", (pData+i)->m_sArea[j].m_nType[9]);
		}
	}
	
	rewind(ill_fp);
}

/*
 * ���ݴ������ļ����ݵ������ṹ�� 
 */
void HandleData(illdata *pData, FILE *ill_fp) 
{
	/* ��ȡ������������������ѭ������ */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	int i;
	int k;
	int j;
	
	/* ��ȡ�ļ��������ṹ�� */ 
	for(i=0; i<dataAmount; i++) 
	{
		/* �������� */
    	char date[11];
    	fscanf(ill_fp, "%s", date);
    	strcpy((pData+i)->m_strDay, date);  
    	
    	/* ����������� */
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
 * ��ȡ������� 
 */
int GetDateCode(illdata *pData, char date[], FILE *ill_fp)
{
	/* ��ʼ������ֵ */
	int code;
	code = -1;
	
	/* ��ȡ�Ѵ��������� */
	int amount;
	amount = GetDataAmount(ill_fp);
	
	/* Ѱ�����ڣ��ҵ�ʱ��ֵ��code */
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
 *	��ȡ�����ַ��� 
 *	������Ų���ӦΪ0Ϊ��׼����� 
 *	���ڸ�ʽΪ��yyyy-mm-dd 
 */ 
char *GetDateStr(int code)
{
	/* ������� */
	code++;
	
	/* �·ݣ��� */
	int month;
	int day;
	
	/* �ж��Ƿ��ҵ������·� */
	int flag;
	flag = 0;
	
	/* �洢1.1-5.1�����ۼ�ֵ */
	int days[5] = {120, 90, 59, 31, 0};
	
	/* ��ʼ�����ص������ַ��� */
	char *date;
	date = (char *)malloc(11);
	memset(date, 0 ,10);
	
	/* �ж��������1-5�ĸ��� */
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

	/* �����պŵ�˫λ������ʽ */
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
 *	��ȡ�Ѵ������������� 
 */
int GetDataAmount(FILE *ill_fp)
{
	/* ��������ÿ37��Ϊһ����λ */
	int amount;
	amount = GetFileLines(ill_fp)/37;;
	
	return amount;
}


/*
 *	��ȡ�ļ����� 
 */
int GetFileLines(FILE *fp) 
{
	/* ��ʼ���ļ��������� */
	int lines;
	lines = 0; 
	
	/* ÿ����һ��������һ */
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
