#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"


/*******************
 *
 *	 �˵�ϵͳģ�� 
 *
 *******************/


/*
 * ��������
 */
void OpenMenu(int userType)
{
	/* ���������ļ����� */
	FILE *ill_fp;
	
	if((ill_fp=fopen("ill_data.txt", "a+")) == NULL) 
	{
    	exit(0);
    }
    
    
    /* ����ṹ�岢��� */
    illdata Data[AMOUNT];
	memset(Data, 0, sizeof(illdata)*AMOUNT);
	
	/* ��������ļ�Ϊ��������һ������ */
	int dataAmount;
	dataAmount = GetDataAmount(ill_fp);
	
	if (dataAmount == 0)
	{
		AddData(Data, ill_fp);
	}
	
	/* ���ݴ����������ṹ�� */
	HandleData(Data, ill_fp);
    
	/* ��ӡ�����ܲ˵����沢��ȡ�����ѡ�� */
	int flag;
	PrintMenu(userType);
	scanf("%d", &flag);
	
	/* ���ݻ�ȡ��ѡ��ִ�ж�Ӧ���� */
	switch (flag)
	{
		/* ȫ���ܼ����� */
		case 0:
			system("cls");
			PrintTotalData(Data, ill_fp, userType);
			break;
		/* 	ȫ����ϸ���� */ 
		case 1:
			system("cls");
			PrintAllData(Data, ill_fp, userType);
			break;
		/* ʡ�������� */
		case 2:
			system("cls");
			PrintAreaData(Data, ill_fp, userType);
			break;
		/* ȫ��ƽ������ */
		case 3:
			system("cls");
			PrintAverData(Data, ill_fp, userType);
			break;
		/* ��ӡ�յ� */ 
		case 4:
			system("cls");
			PrintTurningPoint(Data, ill_fp, userType);
			break;
		/* ����ͼ�� */
		case 5:
			system("cls");
			PrintDataGraph(Data, ill_fp, userType);
			break;
		/* �˳����� */
		case 6:
			break;
		/* ����Ա�������ݹ��� */
		case 7:
			system("cls");
			if (userType == 2)
			{
				OpenDataMenu(Data, ill_fp);
			}
			else
			{
				printf("�ǹ���Ա�޷�ʹ�øù��ܡ�\n");
				OpenMenu(userType);
			}
			break;
		/* ���������ص������� */
		default:
			system("cls");
			OpenMenu(userType);
			break;
	}
}

/*
 *	�����ݹ��������� 
 */
void OpenDataMenu(illdata *pData, FILE *ill_fp)
{
	/* ��ӡ���ݹ���˵����沢��ȡ�����ѡ�� */
	int flag;
	PrintDataMenu();
	scanf("%d", &flag);
	
	/* ���ݻ�ȡ��ѡ��ִ�ж�Ӧ���� */
	switch (flag)
	{
		/* ����¼�� */
		case 0:
			system("cls");
			InputData(pData, ill_fp);
			break;
		/* �����޸� */
		case 1:
			system("cls");
			ChangeData(pData, ill_fp);
			break;
		/* �������� */
		case 2:
			system("cls");
			AddData(pData, ill_fp);
			break;
		/* ���������ص�����Ա������ */
		default:
			system("cls");
			OpenMenu(2);
			break;
	}
}

/*
 *	��ӡ������ 
 */
void PrintMenu(int userType)
{
	printf("����������������������������������������\n");
    printf("#         �¹��������ݲ�ѯϵͳ         #\n");
    if (userType == 2)
	{
		printf("#               <����Ա>               #\n");	
	} 
    printf("# ������������������������������������ #\n");
	printf("# 0.�鿴ȫ���ܼ���������	       #\n");
	printf("# 1.��ѯȫ����ϸ��������	       #\n");
	printf("# 2.�鿴ĳʡ������������	       #\n");
	printf("# 3.�鿴ȫ������ƽ������	       #\n");
	printf("# 4.�鿴ȫ������յ�ͳ��	       #\n");
	printf("# 5.�鿴ȫ����������ͼ��	       #\n");
	printf("# 6.�˳�����	                       #\n");
	if (userType == 2) 
	{
		printf("# ������������������������������������ #\n");
		printf("# 7.������������¼�빤��	       #\n");
	}
	printf("����������������������������������������\n");
	printf("���������ʹ�ö�Ӧ���ܣ�");
}

/*
 *	��ӡ���ݹ��������� 
 */
void PrintDataMenu()
{
	printf("����������������������������������������\n");
    printf("#         �¹��������ݹ���ϵͳ         #\n");
	printf("#               <����Ա>               #\n");	
    printf("# ������������������������������������ #\n");
	printf("# 0.ʡ��������¼��	               #\n");
	printf("# 1.ʡ���������޸�	               #\n");
	printf("# 2.����һ�����������	               #\n");
	printf("# 3.����������      	               #\n");
	printf("����������������������������������������\n");
	printf("���������ʹ�ö�Ӧ���ܣ�");
}
