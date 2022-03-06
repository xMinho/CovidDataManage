#ifndef COVID_LIB_H
#define COVID_LIB_H
#include "CovidStruct.h"
#define AMOUNT 121

/* 
 *	用户系统模块函数声明
 *	包括 10 个函数 
 */
void UserMain(FILE *user_fp, user_list *header); //用户系统主函数 
void UserLogin(user_list *header, FILE *user_fp); //登录函数 
void UserRegister(user_list *header, FILE *user_fp); //注册函数 
void UserPswChange(user_list *header, FILE *user_fp); //更改密码函数 
void UserAdd(user_list *header, user_list *newUser); //增加用户函数 
void UserRead(user_list *header, FILE *user_fp); //用户数据文件读取函数 
void UserSave(user_list *header, FILE *user_fp); //用户数据文件更新函数 
void FreeNode(user_list *header);//链表释放
int GetUserType(user_list *header, char userID[], char userPassword[]);//获取用户类型 
user_list *CreateNode(char userID[], char userPassword[], char userType[]); //创建链表结点 

/* 
 *	菜单系统模块函数声明 
 *	包括 4 个函数 
 */
void PrintMenu(int userType); //打印主界面菜单
void PrintDataMenu(); //打印数据管理界面菜单 
void OpenMenu(int userType); //打开主界面菜单 
void OpenDataMenu(illdata *pData, FILE *ill_fp); //打开疫情数据管理界面

/*
 *	数据处理模块函数声明 
 *	包括 9 个函数 
 */ 
void AddData(illdata *pData, FILE *ill_fp); //新增一个日期 
void ChangeData(illdata *pData, FILE *ill_fp); //更改数据 
void HandleData(illdata *pData, FILE *ill_fp);  //数据处理函数 
void InputData(illdata *pData, FILE *ill_fp); //录入数据 
void UpdateData(illdata *pDat, FILE *ill_fp); //更新数据
int GetFileLines(FILE *fp); //获取文件行数 
int GetDataAmount(FILE *ill_fp);//获取已存疫情数据数量
int GetDateCode(illdata *pData, char date[], FILE *ill_fp); //得到日期字符串对应的序号
char *GetDateStr(int code); //得到日期序号对应的日期字符串

/*
 *	数据查询模块函数声明 
 *	包括 7 个函数 
 */ 
void PrintData(illdata *pData, int areaCode); //打印数据
void PrintTurningPoint(illdata *pData, FILE *ill_fp, int userType); //拐点统计 
void PrintAverData(illdata *pData, FILE *ill_fp, int userType); //打印平均数据
void PrintAreaData(illdata *pData, FILE *ill_fp, int userType);//全国/某省区市的数据打印 
void PrintAllData(illdata *pData, FILE *ill_fp, int userType); //打印全国总计的详细数据 
void PrintTotalData(illdata *pData, FILE *ill_fp, int userType); //打印全国总计数据 
void PrintDataGraph(illdata *pData, FILE *ill_fp, int userType); //打印图表 

#endif
