/*simple_managementsystem.c����������Ա����ϵͳ 1.0*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define MAXPER 200

struct staff                      //staff�ṹ��������Ա��Ϣ
{
	char sgroup[MAX];             //���
	char sname[MAX];              //����
	char smage[MAX];              //רҵ�꼶
	char stele[MAX];              //�绰
	char sqq[MAX];                //qq
	char semail[MAX];             //����
	char sno[MAX];                //ѧ��
};
struct staff per[MAXPER];         //MAXPERΪ��������Ա������������ݶ�Ϊ200

struct admin                      //admin�ṹ�������û���¼������
{
	char user[MAX];
	char keys[MAX];
}easy;
struct admin num[MAXPER];         //MAXPERΪ�������û�������������ݶ�Ϊ200

int Number=0;                     //ȫ�ֱ�������ʼ����Ա��Ϣ����Ϊ0
int usernumber;                   //ȫ�ֱ�������ʼ���û�����Ϊ0


void Menu();                      //˵����ʾ��Ϣ������Ա��Ϣ�ĸ��ֲ���

void bc(struct staff*per);       //����
void bcs(struct admin *num) ;

void Back();                     //�������˵�

int dq(struct staff per[]);      //��ȡ
int dqs(struct admin num[]);


void Add();                     //�����µ���Ա��Ϣ�����洢

void Search();                  //��������һ����Ա����Ϣ

void Putm();                    //���ҵġ���֧��������ͨ����������

void Putn();                    //���ҵġ���֧��������ͨ��ѧ�Ų���

void Delete();                  //ɾ����Ա��Ϣ

void delm();                    //ɾ���ġ���֧��������ͨ������ɾ��

void deln();                    //ɾ���ġ���֧��������ͨ��ѧ��ɾ��

void View();                    //���������

void Stsrt();                   //����

void stsrtg();                  //���������

void stsrtn();                  //��ѧ������

void Help();                    //����

void headmenu();                //��ͷ���û���½����

void reg();                     //ע��

void login();                   //��¼


int main(void)
{
	usernumber=dqs(num);

    headmenu();

    int choose=0;
    FILE*fpb=NULL;
    FILE*fp=NULL;

    char yesorno;

    if((fpb=fopen("staff_b.txt","rb"))==NULL)
    {
    	printf("\n��ʾ���ļ������ڣ��Ƿ�Ҫ������(y/n)\n");
    	scanf("%c",&yesorno);
    	if(yesorno=='y'||yesorno=='Y')
    	{
    		fp=fopen("staff.txt","w");
    		fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
			fpb=fopen("staff_b.txt","wb");

    		fclose(fp);
    		fclose(fpb);
		}
		else
		exit(0);
	}
	else
	{
		Number=dq(per);
	}
	system("cls");

	while(1)
	{
		Menu();
		printf("��ѡ��");
		scanf("%d",&choose);
		system("cls");

		switch(choose)
		{
			case 1:
				Add();
				Back();
				break;

			case 2:
				Search();
				Back();
				break;

			case 3:
				Delete();
				Back();
				break;

			case 4:
			    View();
			    Back();
				break;

			case 5:
				Stsrt();
				Back();
				break;

            case 6:
            	Help();
            	Back();
            	break;

			case 0:
				printf("ллʹ�ã�\n");
				printf("���밴������˳�����");
				exit(0);
				break;

			default:
				printf("�����밴Enter�����ء�\n");
				break;
		}
    	fflush(stdin);
    	getchar();
    	fflush(stdin);                                //���ɾ����һ���ַ����������
    	system("cls");
    }
    Menu();
    return 0;
}




void Menu()                                //�˵�������������ʾ�û����в���
{
/*	printf("*******************************************************************\n");
    printf("*******************************************************************\n");
	printf("**************    ��ӭ������Ա��Ϣ����ϵͳ      *******************\n");
	printf("		                                                           \n");
	printf("		                                                           \n");
	printf("		----	    ���˵�:			----                           \n");
	printf("		~~~~		1.  ���		~~~~                           \n");
	printf("		----		2.  ��ѯ		----                           \n");
	printf("		~~~~		3.  ɾ��		~~~~                           \n");
	printf("		----		4.  ���		----                           \n");
	printf("		~~~~		5.  ����		~~~~                           \n");
	printf("        ----        6.  ����        ----                           \n");
	printf("		~~~~		0.  �˳�		~~~~                           \n");
	printf("*******************************************************************\n");     ������  */

	printf("*******************************************************************\n");
    printf("*******************************************************************\n");
	printf("**************    ��ӭ������Ա��Ϣ����ϵͳ      *******************\n");
	printf("		                                                           \n");
	printf("		                                                           \n");
	printf("\t\t----\t ���˵�: \t----\n");
	printf("\t\t~~~~\t 1.  ���\t~~~~\n");
	printf("\t\t----\t 2.  ��ѯ\t----\n");
	printf("\t\t~~~~\t 3.  ɾ��\t~~~~\n");
	printf("\t\t----\t 4.  ���\t----\n");
	printf("\t\t~~~~\t 5.  ����\t~~~~\n");
	printf("\t\t----\t 6.  ����\t----\n");
	printf("\t\t~~~~\t 0.  �˳�\t~~~~\n");
	printf("*******************************************************************\n");

}

void Add()
{
    int numberTemp=0;
	int i=0,j=0,count=0;
	struct staff temp;
	printf("������Ҫ��ӵ���Ա��Ϣ������");
	scanf("%d",&numberTemp);

	for(i=0;i<numberTemp;i++)
	{
		printf("�������%d����Ա��Ϣ:\n",i+1);
		printf("���");
		scanf("%s",temp.sgroup);
		printf("������");
		scanf("%s",temp.sname);
		printf("רҵ�꼶��");
		scanf("%s",temp.smage);
		printf("�绰��");
		scanf("%s",temp.stele);
		printf("qq��");
		scanf("%s",temp.sqq);
		printf("���䣺");
		scanf("%s",temp.semail);
		printf("ѧ�ţ�");
		scanf("%s",temp.sno);

		for(j=0;j<Number;j++)
		{
			if(strcmp(temp.sno,per[j].sno)==0)
			{
				count++;
			}
		}
		if(count==0)
		{
			per[Number++]=temp;
		    bc(&temp);
			printf("��ӳɹ�\n");
		}
		else
		printf("���ʧ�ܣ���ѧ���Ѵ��ڣ�\n");
	}

}

void bc(struct staff*per)//����
{
	FILE*fpb=NULL;
	fpb=fopen("staff_b.txt","ab+");
	fwrite(per,sizeof(struct staff),1,fpb);
	fclose(fpb);

	FILE*fp=NULL;
	fp=fopen("staff.txt","a+");
	fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",per->sgroup, per->sname, per->smage, per->stele, per->sqq, per->semail, per->sno);
	fclose(fp);
}

void Back()//��ʾ����
{
	printf("��Enter���������˵�\n");
}

int dq(struct staff per[])//��ȡ
{
	FILE*fpb=NULL;
	int i=0;
	fpb=fopen("staff_b.txt","rb");
	while(fread(&per[i],sizeof(struct staff),1,fpb))
	i++;
	fclose(fpb);
	return i;
}


void Search()//���˵�����֮��������ѯ
{
	int n;
	printf("��ѯ��ʽ���£�\n");
	printf("1-����\n");
	printf("2-ѧ��\n");
	printf("3-����\n");
	printf("��������Ҫ��ѯ�ķ�ʽ��");
	scanf("%d",&n);

	system("cls");

	switch(n)
	{
		case 1:
			Putm();
			break;
		case 2:
			Putn();
			break;
		case 3:
			break;
		default:
			system("cls");
			printf("�������������롣\n");
			Search();
	}
}

void Putm()
{
	char name[MAX];
	int i=0;
	int count=0;
	printf("������Ҫ���ҵ���Ա����:");
	scanf("%s",name);

	system("cls");

	for(i=0;i<Number;i++)
	{
		if(strcmp(name,per[i].sname)==0)
		{
			printf("%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
			printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
			count++;
		}
	}
	if(count==0)
	printf("�Բ��𣬸���Ա�����ڣ�\n");
}

void Putn()
{
	char no[MAX];
	int i=0;
	int count=0;
	printf("������Ҫ���ҵ���Աѧ��:");
	scanf("%s",no);

	system("cls");

	for(i=0;i<Number;i++)
	{
		if(strcmp(no,per[i].sno)==0)
		{
			printf("%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
			printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
			count++;
		}
    }
	if(count==0)
	printf("�Բ��𣬸���Ա�����ڣ�\n");
}

void Delete()//���˵��Ĺ���֮������ɾ��
{
	int n=0;
	printf("ɾ����ʽ���£�\n");
	printf("1-����\n");
	printf("2-ѧ��\n");
	printf("3-����\n");
	printf("��������Ҫɾ���ķ�ʽ��");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
			delm();
			break;
		case 2:
			deln();
			break;
		case 3:
			break;
		default:
			system("cls");
			printf("�������������롣\n");
			Delete();
	}
}

void delm()//ɾ���ġ���֧��������ͨ������ɾ��
{
	FILE*fp=NULL;
	FILE*fpb=NULL;
	char name[MAX];
	int i=0;
	int j=0;
	int count=0;
	printf("������Ҫɾ������Ա��������");
	scanf("%s",name);

/*	for(i=0;i<Number;i++)
	{
		if(strcmp(name,per[i].sname)==0)
		{
			printf("��ţ�%d  ",i);
			printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
		}
	}                       ����ͬ��ͬ����������������   */

	for(i=0;i<Number;i++)
	{
		if(strcmp(name,per[i].sname)==0)
		{
			for(j=i;j<Number-1;j++)
	    	{
	   		    per[j]=per[j+1];
		   	}
		   	Number--;
			count++;
		}
	}
	if(count>0)
	{
		fpb=fopen("staff_b.txt","wb");
	    fp=fopen("staff.txt","w");
    	for(i=0;i<Number;i++)
    	{
    		fwrite(&per[i],sizeof(struct staff),1,fpb);
    		fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
    	}
    	fclose(fpb);
    	fclose(fp);
    	printf("ɾ���ɹ�\n");
	}
	else
	printf("�Բ��𣬸���Ա�����ڣ�\n");

}

void deln()//ɾ���ġ���֧��������ͨ��ѧ��ɾ��
{
	FILE*fp=NULL;
	FILE*fpb=NULL;
	char no[MAX];
	int i=0;
	int j=0;
	int count=0;
	printf("������Ҫɾ������Ա��ѧ�ţ�");
	scanf("%s",no);

	for(i=0;i<Number;i++)
	{
		if(strcmp(no,per[i].sno)==0)
		{
			for(j=i;j<Number-1;j++)
			{
				per[j]=per[j+1];
			}
			Number--;
			count++;
		}
	}
	if(count>0)
	{
		fpb=fopen("staff.txt","wb");
		fp=fopen("staff.txt","w");
    	for(i=0;i<Number;i++)
    	{
    		fwrite(&per[i],sizeof(struct staff),1,fpb);
    		fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
    	}
    	fclose(fpb);
    	fclose(fp);
    	printf("ɾ���ɹ�\n");
	}
	else
	printf("�Բ��𣬸���Ա�����ڣ�\n");
}

void View()//���˵�����֮�ġ������������
{
	int i=0;

	printf("������ȫ����Ա��Ϣ��\n");
	printf("%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
	for(i=0;i<Number;i++)
	{
		printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
	}
}
void Stsrt()//���˵�����֮�塪������
{
	int n=0;
	printf("���з�ʽ���£�\n");
	printf("1-���\n");
	printf("2-ѧ��\n");
	printf("3-����\n");
	printf("��������Ҫ���еķ�ʽ��");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
			stsrtg();//���������
			break;
		case 2:
			stsrtn();//��ѧ������
			break;
		case 3:
			break;
		default:
			system("cls");
			printf("�������������롣\n");
			Stsrt();
	}
}

void stsrtg()//����ġ���֧����������������� //Ŀǰ�������⡣����
{
	int i,k;
	int top,seek;
	char *ptstr[MAXPER];
	char *temp;
	struct staff *eptstr[MAXPER];
	struct staff *etemp;

//	char atemp[]="100";
//	char btemp[]="101";
//	char ctemp[]="102";
//	char dtemp[]="103";

	FILE*fp=NULL;
	fp=fopen("sortg.txt","w");

	for(i=0;i<Number;i++)
	{
	   /* if(strcmp((per[i].sgroup),"��·")==0)
		{
		//	printf("%d",i);
		    ptstr[i]=atemp;
		  //  printf("%d",i);
		    eptstr[i]=&per[i];
		 //   printf("%d",i);
		}
	    if(strcmp((per[i].sgroup),"��е")==0)
		{
	   	    ptstr[i]=btemp;
	        eptstr[i]=&per[i];
		}
	    if(strcmp((per[i].sgroup),"Ƕ��")==0)
		{
	   	    ptstr[i]=ctemp;
	        eptstr[i]=&per[i];
		}

		if(strcmp((per[i].sgroup),"�Ӿ�")==0)
		{
			ptstr[i]=dtemp;
	    	eptstr[i]=&per[i];
		} */
		ptstr[i]=per[i].sgroup;
		eptstr[i]=&per[i];

	}

	//for(i=0;i<Number;i++)
	//printf("%s",ptstr[i]);

	for(top=0;top<Number-1;top++)
	   for(seek=top+1;seek<Number;seek++)
	      if(strcmp(ptstr[top],ptstr[seek])>0)
	      {
		    temp=ptstr[top];
            ptstr[top]=ptstr[seek];
            ptstr[seek]=temp;

	      	etemp=eptstr[top];
	      	eptstr[top]=eptstr[seek];
	      	eptstr[seek]=etemp;

		  }

	fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
	printf("%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");

    for(k=0;k<Number;k++)
    {
    	printf("%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
    	fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
	}
	fclose(fp);
}

void stsrtn()//����ġ���֧����������ѧ������
{
	int i,k;
	int top,seek;
	char *ptstr[MAXPER];
	char *temp;
	struct staff *eptstr[MAXPER];
	struct staff *etemp;

	FILE*fp=NULL;
	fp=fopen("sortn.txt","w");

	printf("%d",Number);

	for(i=0;i<Number;i++)
	{
		ptstr[i]=per[i].sno;
		eptstr[i]=&per[i];
	}
	for(top=0;top<Number-1;top++)
	   for(seek=top+1;seek<Number;seek++)
	      if(strcmp(ptstr[top],ptstr[seek])>0)//����
	      {
            temp=ptstr[top];
            ptstr[top]=ptstr[seek];
            ptstr[seek]=temp;

	      	etemp=eptstr[top];
	      	eptstr[top]=eptstr[seek];
	      	eptstr[seek]=etemp;
		  }

	fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");
    printf("%s   %s    %s  %s           %s           %s                %s\n","���","����","רҵ�꼶","�绰","qq","����","ѧ��");

    for(k=0;k<Number;k++)
    {
    	printf("%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
    	fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
	}
	fclose(fp);

}



void Help()//���˵�����֮����������
{
	printf("ע��\n");
	printf("1.ѡ��������ż��ɣ�\n");
	printf("2.����ӡ��������Ա����ĳ��������Ա��Ϣ¼�룻\n");
	printf("3.����ѯ����������Ա��Ϣ��\n");
	printf("4.��ɾ������ɾ��ĳ����Ա��Ϣ��\n");
	printf("5.����������������ȫ����Ա��Ϣ��\n");
	printf("6.�����򡱼���ȫ����Ա��Ϣ��һ��˳����ʾ��\n");
}

void headmenu()
{
	int join;
	printf("��ӭ������Ա����ϵͳ��¼ҳ��\n\n");
	printf("1-ע�᣻\n2-��¼��\n3-�˳�\n");
	scanf("%d",&join);
	system("cls");


	switch(join)
	{
		case 1:
			reg();
			break;
		case 2:
			login();
			break;
		case 3:
			printf("ллʹ�ã�\n");
			exit(0);
		default:
			printf("�������������롣\n");
			headmenu();
	}
	fflush(stdin);

}

void reg()//ע�� //ȱ�㣺���ڳ�������
{
	int i=0;
	int count=0;

	printf("[Register...]\n");
	printf("��ע���û��������볤�Ⱦ����ó���20���ַ���\n\n");
	printf("�û�����");
	scanf("%s",easy.user);
	printf("���룺");
	scanf("%s",easy.keys);

	for(i=0;i<usernumber;i++)
	{
		if(strcmp(easy.user,num[i].user)==0)
		count++;
	}
	if(count==0)
	{
		num[usernumber++]=easy;
	    bcs(&easy);

		system("cls");
		printf("ע��ɹ�\n\n");
		headmenu();
	}
	else
	{
		system("cls");
		printf("�û���\"%s\"�Ѵ��ڣ�������ע��!\n\n",easy.user);
		reg();
	}
}

int dqs(struct admin num[])//��ȡ
{
	FILE*fpb=NULL;
	int i=0;
	fpb=fopen("user_b.txt","a+b");
	while(fread(&num[i],sizeof(struct admin),1,fpb))
	i++;
	fclose(fpb);
	return i;
}

void bcs(struct admin*num)//����
{
	FILE*fpb=NULL;
	fpb=fopen("user_b.txt","a+b");
	fwrite(num,sizeof(struct admin),1,fpb);
	fclose(fpb);

	FILE*fp=NULL;
	fp=fopen("user.txt","a+");
	fprintf(fp,"%s   %s  \n",num->user, num->keys);
	fclose(fp);
}

void login()//��¼ //ȱ�㣺�������ⷵ�أ������ڳ�������
{
	char userp[MAX];
	char keysp[MAX];
	int count=0;
	int i;
    printf("[Login...]\n\n");
	while(1)
	{
	    printf("�û�����");
	    scanf("%s",userp);
     	printf("���룺");
    	scanf("%s",keysp);

		for(i=0;i<usernumber;i++)
		{
			if(strcmp(num[i].user,userp)==0&&strcmp(num[i].keys,keysp)==0)
			count++;
		}
		if(count==1)
		break;
		else
		printf("�û���������������������룺\n");
	}

}

