#ifndef COVID_STRUCT_H
#define COVID_STRUCT_H

/*
 *	�������ݽṹ��
 */
struct Area
{
	char m_strName[20]; //������ 
	int m_nType[10]; //ʮ����ֵ���� 
};


/*
 *	�����������ṹ��
 */
typedef struct illData
{
	char m_strDay[11]; //���� 
	struct Area m_sArea[36]; //�����ṹ�� 
} illdata;


/*
 *	�û����ݽṹ�� 
 */
typedef struct UserList{
	char m_strID[30]; //�˺� 
	char m_strPassword[50]; //���� 
	char m_strType[10]; //�û����� admin:����Ա user:��ͨ�û�  
	struct UserList *next;
} user_list;

#endif
