#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"

/*******************
 *
 *	 �û�ϵͳģ�� 
 *
 *******************/

/*
 *	�û�ϵͳ������ 
 */
void UserMain(FILE *user_fp, user_list *header)
{
	/* ��λͷ��� */
	user_list *p = header;
	int lines = GetFileLines(user_fp);
	
	/* ����û��ļ��ǿյģ�������һ��Ĭ�Ϲ���Ա�˺� */
	if (lines == 0)
	{
		fprintf(user_fp, "admin\tadmin\tadmin\n");
		rewind(user_fp);
	}
	
	/* ��ȡ�ļ����������� */
	UserRead(p, user_fp);
	
	/* ��ʾ��¼ϵͳ�������� */
	char flag;
	printf("����������������������������������������\n");
    printf("#         �¹��������ݹ���ϵͳ         #\n");
    printf("#            ���201 ������            #\n"); 
    printf("����������������������������������������\n");
    printf("# ֱ�ӵ�¼������: L/l                  #\n");
    printf("# ע���˺������룺R/r                  #\n");
    printf("# �������������룺C/c                  #\n");
    printf("����������������������������������������\n");
    printf(">");
    scanf("%c", &flag);
    
    /* �ж��ǵ�¼��ע�������� */
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
		printf("δ֪ѡ�����������ѡ��\n");
		UserMain(user_fp, header);
	}
}

/*
 *	��¼���� 
 */
void UserLogin(user_list *header, FILE *user_fp)
{
	/* �����˺�������� */
	char userID[20];
	char userPassword[50];
	printf("����������������������������������������\n");
    printf("#               �˺ŵ�¼               #\n");
    printf("����������������������������������������\n");
    printf("�������˺ţ�");
    scanf("%s", userID);
    printf("���������룺");
    scanf("%s", userPassword);
    
    /* ��ȡ�û����� 
		0���û������� 1����ͨ�û� 2������Ա�û� 3���������	 */
    int type;
	type = GetUserType(header, userID, userPassword);
    
    /* �����жϷ��ص����ʹ򿪶�Ӧ�Ĳ˵�������ʾ���� */
    if (type == 1 || type == 2)
    {
    	system("cls");
    	OpenMenu(type);
	}
	else if (type == 3)
	{
		system("cls");
		printf("������������µ�¼\n");
		
		fflush(stdin); 
		UserMain(user_fp, header);
	}
	else
	{
		system("cls");
		printf("�˺Ų����ڣ������µ�¼\n");
		
		fflush(stdin); 
		UserMain(user_fp, header);	
	}
}

/*
 *	ע����� 
 */
void UserRegister(user_list *header, FILE *user_fp) 
{
	/* �˺������������ */
	char userID[20];
	char userPassword[50];
	printf("����������������������������������������\n");
    printf("#               �˺�ע��               #\n");
    printf("����������������������������������������\n");
    printf("������Ҫע����˺ţ�");
    scanf("%s", userID);
    printf("������Ҫע������룺");
    scanf("%s", userPassword);
    
    /* ��ȡ�û����� 
		0���û������� 1����ͨ�û� 2������Ա�û� 3���������	 */
    int type;
	type = GetUserType(header, userID, userPassword);
    
    /* ���˺Ų�����,���û���ӵ��������������ļ����򿪵�¼���� */
    if (type == 0)
    {
    	UserAdd(header, CreateNode(userID, userPassword, "user")); 
    	UserSave(header, user_fp); 
    	
    	system("cls");
    	printf("ע��ɹ������¼\n");
    	UserLogin(header, user_fp);
	}
	/* ���˺��Ѿ����ڣ���ʾ���󲢷����ϼ����� */
	else
	{
		system("cls");
		printf("���˺��Ѿ����ڣ���ֱ�ӵ�¼������ע�ᣡ\n");
		
		fflush(stdin); 
		UserMain(user_fp, header);
	}
}

/*
 *	��������� 
 */
void UserPswChange(user_list *header, FILE *user_fp)
{
	/* ��λͷ��� */
	user_list *p;
	p = header;
	
	/* �˺������������ */
	char userID[20];
	char userPassword[50];
	char changedPassword[50];
	printf("����������������������������������������\n");
    printf("#               �������               #\n");
    printf("����������������������������������������\n");
    printf("��������ĵ��˺ţ�");
    scanf("%s", userID);
    printf("������ԭ�������룺");
    scanf("%s", userPassword);
    
    /* ��ȡ�û����� 
		0���û������� 1����ͨ�û� 2������Ա�û� 3���������	 */
    int type;
	type = GetUserType(header, userID, userPassword);
    
    /* ���˺�������ȷ����и������룬������ʾ���󷵻��ϼ��˵� */
    if (type == 1 || type == 2)
    {
    	printf("��������ĺ�����룺");
    	scanf("%s", changedPassword);
    	
    	while (p->next != NULL)
    	{
    		p = p->next;
    		if (strcmp(p->m_strID, userID) == 0)
    		{
    			/* �������벢�������� */
    			memcpy(&(p->m_strPassword), &changedPassword, sizeof(p->m_strPassword));
    			UserSave(header, user_fp);
    			
    			system("cls");
    			printf("�ɹ��޸�����!\n");
    			
    			fflush(stdin);
    			UserMain(user_fp, header); 
			}
		}
	}
	else if (type == 3)
	{
		system("cls");
		printf("ԭ�������\n");
		
		fflush(stdin);
		UserMain(user_fp, header);
	}
	else
	{
		system("cls");
		printf("�˺Ų����ڣ�\n");
		
		fflush(stdin);
		UserMain(user_fp, header);
	}
}

/*
 *	��ȡ�û����� 
 *	0���û������� 1����ͨ�û� 2������Ա�û� 3���������	 
 */
int GetUserType(user_list *header, char userID[], char userPassword[]) 
{
	/* ��λͷ��� */
	user_list *p = header;
	
	/* ��ʼ������ֵ�Լ�����Ա�ַ����� */
	int flag;
	flag = 0;
	char admin[] = "admin";
	
	/* �������� */
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->m_strID, userID) == 0)
		{
			if (strcmp(p->m_strPassword, userPassword) == 0)
			{
				/* �˺�������ȷ������Ա�˺� */ 
				if (strcmp(p->m_strType, admin) == 0) 
				{
					flag = 2;
				}
				/* �˺�������ȷ����ͨ�û� */ 
				else
				{
					flag = 1;
				}
			}
			/* ������� */
			else 
			{
				flag = 3;
			}
		}
	}
	/* �����û����� */
	return flag;
}

/*
 *	��ȡ�ļ����������� 
 */
void UserRead(user_list *header, FILE *user_fp)
{
	/* ��ȡ�Ѵ洢�û����� */
	int userAmount;
	userAmount = GetFileLines(user_fp); 
	
	/* ��ȡ���������� */
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
 *	����һ���û���� 
 */
void UserAdd(user_list *header, user_list *newUser)
{
	/* ��λͷ��� */
	user_list *p;
	p = header;
	
	/* Ѱ������β��� */
	while (p->next != NULL)
	{
		p = p->next;	
	}
	
	/* �νӽ�� */
	p->next = newUser;
}

/*
 *	�����������ļ� 
 */
void UserSave(user_list *header, FILE *user_fp)
{
	/* ��λͷ��� */
	user_list *p = header;
	
	/* ����ļ���д������ */
	user_fp = fopen("user_data.txt", "w+");
	
	/* ����������ʽ�����������ļ� */
	while (p->next != NULL)
	{
		p = p->next;
		fprintf(user_fp, "%s\t%s\t%s\n", p->m_strID, p->m_strPassword, p->m_strType);
	}
	
	rewind(user_fp);
}

/*
 *	������� 
 */
user_list *CreateNode(char userID[], char userPassword[], char userType[])
{
	/* ����һ����� */
	user_list *p = NULL;
	p = (user_list *)malloc(sizeof(user_list));
	
	if (p == NULL)
	{
		printf("�����ڴ�ʧ�ܡ�");
		exit(0);
	}
	
	/* ��ʼ�������Լ�ָ�� */
	memcpy(p->m_strID, userID, sizeof(p->m_strID));
	memcpy(p->m_strPassword, userPassword, sizeof(p->m_strPassword));
	memcpy(p->m_strType, userType, sizeof(p->m_strType));
	p->next = NULL;
}

/*
 *	�ͷ����� 
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
