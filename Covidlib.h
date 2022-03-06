#ifndef COVID_LIB_H
#define COVID_LIB_H
#include "CovidStruct.h"
#define AMOUNT 121

/* 
 *	�û�ϵͳģ�麯������
 *	���� 10 ������ 
 */
void UserMain(FILE *user_fp, user_list *header); //�û�ϵͳ������ 
void UserLogin(user_list *header, FILE *user_fp); //��¼���� 
void UserRegister(user_list *header, FILE *user_fp); //ע�ắ�� 
void UserPswChange(user_list *header, FILE *user_fp); //�������뺯�� 
void UserAdd(user_list *header, user_list *newUser); //�����û����� 
void UserRead(user_list *header, FILE *user_fp); //�û������ļ���ȡ���� 
void UserSave(user_list *header, FILE *user_fp); //�û������ļ����º��� 
void FreeNode(user_list *header);//�����ͷ�
int GetUserType(user_list *header, char userID[], char userPassword[]);//��ȡ�û����� 
user_list *CreateNode(char userID[], char userPassword[], char userType[]); //���������� 

/* 
 *	�˵�ϵͳģ�麯������ 
 *	���� 4 ������ 
 */
void PrintMenu(int userType); //��ӡ������˵�
void PrintDataMenu(); //��ӡ���ݹ������˵� 
void OpenMenu(int userType); //��������˵� 
void OpenDataMenu(illdata *pData, FILE *ill_fp); //���������ݹ������

/*
 *	���ݴ���ģ�麯������ 
 *	���� 9 ������ 
 */ 
void AddData(illdata *pData, FILE *ill_fp); //����һ������ 
void ChangeData(illdata *pData, FILE *ill_fp); //�������� 
void HandleData(illdata *pData, FILE *ill_fp);  //���ݴ����� 
void InputData(illdata *pData, FILE *ill_fp); //¼������ 
void UpdateData(illdata *pDat, FILE *ill_fp); //��������
int GetFileLines(FILE *fp); //��ȡ�ļ����� 
int GetDataAmount(FILE *ill_fp);//��ȡ�Ѵ�������������
int GetDateCode(illdata *pData, char date[], FILE *ill_fp); //�õ������ַ�����Ӧ�����
char *GetDateStr(int code); //�õ�������Ŷ�Ӧ�������ַ���

/*
 *	���ݲ�ѯģ�麯������ 
 *	���� 7 ������ 
 */ 
void PrintData(illdata *pData, int areaCode); //��ӡ����
void PrintTurningPoint(illdata *pData, FILE *ill_fp, int userType); //�յ�ͳ�� 
void PrintAverData(illdata *pData, FILE *ill_fp, int userType); //��ӡƽ������
void PrintAreaData(illdata *pData, FILE *ill_fp, int userType);//ȫ��/ĳʡ���е����ݴ�ӡ 
void PrintAllData(illdata *pData, FILE *ill_fp, int userType); //��ӡȫ���ܼƵ���ϸ���� 
void PrintTotalData(illdata *pData, FILE *ill_fp, int userType); //��ӡȫ���ܼ����� 
void PrintDataGraph(illdata *pData, FILE *ill_fp, int userType); //��ӡͼ�� 

#endif
