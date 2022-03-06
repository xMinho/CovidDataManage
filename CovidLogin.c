#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Covidlib.h"
#include "CovidStruct.h"

/*
	��¼ע��ģ��
	ʵ�ֶԵ�¼ע���ѡ���Լ���¼ע������� 
*/

void LoginMain(FILE *user_fp, FILE *ill_fp)
{
	char flag; //�����ж��û��Ĳ���
	
	/* ��ʾ��¼ϵͳ�������� */
	printf("����������������������������������������\n");
    printf("#         �¹��������ݹ���ϵͳ         #\n");
    printf("#            ���201 ������            #\n"); 
    printf("����������������������������������������\n");
    printf("# �����˺ţ�ֱ�ӵ�¼������: L/l        #\n");
    printf("# û���˺ţ�����ע�������룺R/r        #\n");
    printf("����������������������������������������\n");
    printf(">");
    scanf("%c", &flag);
    
    /* �ж��ǵ�¼��ע�� */
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
		printf("δ֪ѡ�����������ѡ��\n");
		LoginMain(user_fp, ill_fp);
	}
}

void Login(FILE *user_fp, FILE *ill_fp)
{
	user userLog;
	
	printf("����������������������������������������\n");
    printf("#               �˺ŵ�¼               #\n");
    printf("����������������������������������������\n");
    printf("�������˺ţ�");
    scanf("%s", userLog.m_strID);
    printf("���������룺");
    scanf("%s", userLog.m_strPassword);
    
    int type = GetUserType(userLog.m_strID, userLog.m_strPassword, user_fp);
    
    /* ��¼ */
    if (type == 1 || type == 2)
    {
    	system("cls");
    	OpenMenu(type, ill_fp);
	}
	else
	{
		system("cls");
		printf("�˺Ų����ڻ�������������µ�¼\n");
		Login(user_fp, ill_fp); 
	}
}

void Register(FILE *user_fp, FILE *ill_fp)
{
	user userReg; //�����û��ṹ����� 
	
	printf("����������������������������������������\n");
    printf("#               �˺�ע��               #\n");
    printf("����������������������������������������\n");
    printf("������Ҫע����˺ţ�");
    scanf("%s", userReg.m_strID);
    printf("������Ҫע������룺");
    scanf("%s", userReg.m_strPassword);
    
    int type = GetUserType(userReg.m_strID, userReg.m_strPassword, user_fp);
    
    /* ͨ���жϽ�������¼�� */
    if (type == 0)
    {
    	fprintf(user_fp, "\n%s\t", userReg.m_strID);
    	fprintf(user_fp, "%s\t", userReg.m_strPassword);
    	fprintf(user_fp, "user");
    	rewind(user_fp);
    	
    	system("cls");
    	printf("ע��ɹ������¼\n");
    	Login(user_fp, ill_fp);
	}
	else
	{
		system("cls");
		printf("���˺��Ѿ����ڣ�������ע�ᣡ\n");
		Register(user_fp, ill_fp);
	}
}
