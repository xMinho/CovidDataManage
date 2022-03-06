#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Covidlib.h"
#include "CovidStruct.h"

int main()
{
	/* �û������ļ�����/���� */
	FILE *user_fp;
	if((user_fp=fopen("user_data.txt", "a+")) == NULL) 
	{
    	exit(0);
    }

	/* �����û���������ͷ��� */
	user_list *header = NULL;
	header = (user_list *)malloc(sizeof(user_list));
	if (header == NULL)
	{
		printf("�����ڴ�ʧ�ܡ�");
		exit(0);
	}
	memset(header, 0, sizeof(user_list));
    
    /* ���û���¼���� */
    UserMain(user_fp, header);
    
    /* �ͷ����� */
    FreeNode(header);
    
	return 0;
}
