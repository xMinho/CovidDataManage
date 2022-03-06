#ifndef COVID_STRUCT_H
#define COVID_STRUCT_H

/*
 *	地区数据结构体
 */
struct Area
{
	char m_strName[20]; //地区名 
	int m_nType[10]; //十个数值数据 
};


/*
 *	疫情数据主结构体
 */
typedef struct illData
{
	char m_strDay[11]; //日期 
	struct Area m_sArea[36]; //地区结构体 
} illdata;


/*
 *	用户数据结构体 
 */
typedef struct UserList{
	char m_strID[30]; //账号 
	char m_strPassword[50]; //密码 
	char m_strType[10]; //用户类型 admin:管理员 user:普通用户  
	struct UserList *next;
} user_list;

#endif
