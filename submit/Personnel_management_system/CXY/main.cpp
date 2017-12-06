//ͨ�������Ա����ϵͳѧϰ��fscanf,fprintf,fopen,feof,EOF����ɵ�½�Ĳ���
//��һ�α�д���Ľ���Ա������������ȫ�ֱ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MenNum 200//��Ա����ϵͳ���ܴ洢��Ա�����ֵ
#define groupLEN 20
#define nameLEN 20
#define majorLEN 20
#define TeleLEN 15
#define mailLEN 40
#define IDLEN 11
#define qqLEN 15

#define LenthUserName 20
#define LenthKeyWord  20
#define UserNum       100

//��½�����õ��ı���
struct  User
{
    char User_name[LenthUserName];
    char Keyword[LenthKeyWord];
};
struct User users[100];
int TempUserNum = 0;


//��Ա����ϵͳ�õ��Ľṹ����
struct Men
{
    char group[groupLEN];
    char name[nameLEN];
    char major[majorLEN];
    char Tele[TeleLEN];
    char QQ[qqLEN];
    char Mail[mailLEN];
    char ID[IDLEN];
};
struct Men member[MenNum];
int TempMemberNum = 0;

//��½����
int Signin();
int Signup();
int LoadInterFace();
void LoadinUser();

//�˵�������
void PrtMenu();
void CleanMenu();

//�˵�ѡ���
void Memberlist();
void Add();
void Finding();
void Change();
void Sort();
//�����ļ��е�����
void ReadMemberFile();
int main()
{
    LoadinUser();
    if( LoadInterFace()==1 )
    {
        int option = 0;
        CleanMenu();
        printf("��½�ɹ���\n");
        PrtMenu();
        ReadMemberFile();

        printf("������ѡ���Լ���:\n");
        scanf("%d", &option );

        switch( option )
        {
            case 1:
                printf("������Ա��Ϣ��\n");
                Memberlist();
                break;
            case 2:
                printf("����µĳ�Ա��\n");
                Add();
                break;
            case 3:
                printf("��ѯ��Ա��Ϣ��\n");
                Finding();
                break;
            case 4:
                printf("��Ա��Ϣ�Ķ���\n");
                Change();
                break;
            case 5:
                printf("��Ա��Ϣ����\n");
                Sort();
                break;
            default:
                CleanMenu();
                printf("��������ȷ��ѡ�\n");
                main();
            break;
        }
    }
    else
    {
        return 0;
    }



    return 0;
}
void PrtMenu()
{
    printf("******************************************************\n");
    printf("*             ��ӭ����Robomaster��Ա����ϵͳ         *\n");
    printf("*                 ѡ��1�����س�Ա��Ϣ                *\n");
    printf("*                 ѡ��2����ӳ�Ա��Ϣ                *\n");
    printf("*                 ѡ��3����ѯ��Ա                    *\n");
    printf("*                 ѡ��4����Ա��Ϣ�Ķ�                *\n");
    printf("*                 ѡ��5�������Ա                    *\n");
    printf("******************************************************\n");
}
void LoadinUser()
{
    int i = 0;
    FILE *loadptr;
    loadptr = fopen("�û�����.txt", "r");
    while( !feof(loadptr) )//
    {

        fscanf(loadptr,"%19s%19s", &users[i].User_name,&users[i].Keyword );
        ++TempUserNum;
        ++i;
    }
    TempUserNum=TempUserNum-1;
    fclose(loadptr);
}
int  LoadInterFace()
{

    int Option_load = 0;
    printf("***********************************************\n");
    printf("*           Robomaster��Ա����ϵͳ            *\n");
    printf("*           ѡ��1����½                       *\n");
    printf("*           ѡ��2��ע���˺�                   *\n");
    printf("*           ѡ��3���˳�ϵͳ                   *\n");
    printf("***********************************************\n");

    scanf("%d",&Option_load);
    if( Option_load == 1 )
    {
        int Signinresult=Signin();
        if( Signinresult==0 )
        {
            printf("�û��������������\n");
            LoadInterFace();

        }
        else if( Signinresult==1 )
        {
            return 1;
        }
    }
    if( Option_load == 2 )
    {
        Signup();
        int Signinresult=Signin();
        if( Signinresult==0 )
        {
            printf("�û��������������\n");
            LoadInterFace();

        }
        else if( Signinresult==1 )
        {
            return 1;
        }
    }
    if( Option_load == 3 )
    {
        return 0;
    }
}
int Signup()
{
    LoadinUser();
    char UserName[LenthUserName];
    char KeyWord[LenthKeyWord];

    printf("�û�ע�᣺\n");
    printf("�û���:");
    scanf("%19s",UserName);
    printf("\n����: ");
    scanf("%19s",KeyWord );

    int i = 0;
    while( i < TempUserNum+1 )
    {
        if( strcmp( users[i].User_name, UserName )==0 )
        {
            printf("�û����ظ�\n����ע��\n");
            Signup();
        }
        ++i;
    }
    printf("ע��ɹ�\n");
    FILE *loadptr;
    loadptr = fopen("�û�����.txt", "a+");
    fprintf(loadptr,"%-s\t%-s\n",UserName,KeyWord);
    LoadinUser();
    fclose(loadptr);

}
int  Signin()
{
    int i = 0;
    char UserName[LenthUserName];
    char KeyWord[LenthKeyWord];
    printf("���������ĵ�½��Ϣ:\n");
    printf("�û���:");
    scanf("%19s", &UserName);
    printf("\n����: ");
    scanf("%19s",&KeyWord);
    while( i<TempUserNum+1 )//TempUserNumΪ��ǰע���û���
    {
        if( strcmp( users[i].User_name, UserName )==0&& strcmp( users[i].Keyword, KeyWord )==0)
        {

            return 1;
        }
        ++i;
    }
    return 0;

}
void CleanMenu()
{
    system("cls");
}





void Memberlist()
{
    int i=0;
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "���","����","רҵ���","�绰","QQ", "����","ѧ��");
    printf("\n");
    while( i<TempMemberNum )
    {
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);

        ++i;
    }
}
void Add()
{
    FILE *MLptr;
    MLptr = fopen( "��Ա��Ϣ.txt ", "a+" );
    printf("���������һ����Ա��Ϣ .\n");
    int i = TempMemberNum+1;
    printf("�������Ա����� ����·����е���Ӿ���Ƕ����Ӫ��.\n");
            scanf("%19s", &member[i].group );
            //fprintf(Ptr,"\n%-2s\t",member[i].group );

            printf("�������Ա������\n ");
            scanf("%19s", &member[i].name );
            //fprintf(Ptr,"%-6s\t",member[i].name );

            printf("�������Ա��רҵ��� ��eg:���1701��ͨ��1501�� .\n ");
            scanf("%19s", &member[i].major );
            //fprintf(Ptr,"%-8s\t",member[i].major );

            printf("�������Ա�ĵ绰\n ");
            scanf("%14s", &member[i].Tele );
            //fprintf(Ptr,"%-11s\t",member[i].Tele );

            printf("�������Ա��QQ .\n ");
            scanf("%14s", &member[i].QQ );
            //fprintf(Ptr,"%-11s\t",member[i].QQ );

            printf("�������Ա������\n ");
            scanf("%39s", &member[i].Mail );
            //fprintf(Ptr,"%-20s\t",member[i].Mail );

            printf("�������Ա��ѧ��\n ");
            scanf("%10s", &member[i].ID );
            //fprintf(Ptr,"%-11s\t",member[i].ID );



                fprintf(MLptr,"\n%-2s\t",member[i].group );
                fprintf(MLptr,"%-6s\t",member[i].name );
                fprintf(MLptr,"%-8s\t",member[i].major );
                fprintf(MLptr,"%-11s\t",member[i].Tele );
                fprintf(MLptr,"%-11s\t",member[i].QQ );
                fprintf(MLptr,"%-20s\t",member[i].Mail );
                fprintf(MLptr,"%-11s\t",member[i].ID );


    fclose( MLptr );
    printf("����������Ҫ��ӵĳ�Ա��Ϣ\n");
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);

    printf("��ӳɹ�!\n");
    system("pause");
    printf("�㻹Ҫ����ʲô������\n");
    CleanMenu();
    main();
    //չʾ������Ϣ�ĳɹ�
}
void Finding()
{
    int choice;
    printf("******************************************************\n");
    printf("*              ѡ��1:����������                      *\n");
    printf("*              ѡ��2:��������                      *\n");
    printf("*              ѡ��3:��ѧ�Ų���                      *\n");
    printf("******************************************************\n");

    scanf("%d", &choice);

    if( choice == 1)
    {
        int i = 0,jug=0;//�����jug����ȥ�ж��Ƿ����if
        char F_name[10];
        printf("��������ҵ�����");
        scanf("%9s", &F_name);
        while( i<TempMemberNum+1 )
        {

            if( !strcmp( member[i].name, F_name))
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;
        }
        if ( jug == 0 )
        {
            printf("û���ҵ�ƥ�������\n");
        }

    }
    if( choice == 2)
    {
        printf("������𣬴�����ĳ�Ա\n");
        printf("��'�Ӿ�','��·','��е','Ƕ��','��Ӫ'\n");
        char GN[10];
        scanf("%9s", GN);
        int i=0,jug=0;//�����jug����ȥ�ж��Ƿ����if
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
        while( i<TempMemberNum+1 )
        {

            if( !strcmp( member[i].group,GN) )
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;

        }
        if ( jug == 0 )
        {
            printf("û���ҵ������\n");
        }
    }
    if( choice == 3)
    {
        printf("��������Ҫ���ҵ�ѧ��\n");
        printf("���磺U201715487\n");
        char IdE[12];
        scanf("%d", IdE);
        int i=0, jug=0;//�����jug����ȥ�ж��Ƿ����if
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
        while( i<TempMemberNum+1)//�ж��Ƿ����ļ���β
        {

            if( strcmp( member[i].ID,IdE)==0 )
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;

        }
        if ( jug == 0 )
        {
            printf("û���ҵ���ѧ��ƥ��ĳ�Ա\n");
        }

    }
}
void Change()
{
    int option;
    printf("******************************************************\n");
    printf("*              ѡ��1:ɾ����Ա��Ϣ                    *\n");
    printf("*              ѡ��2:��Ա��Ϣ�Ķ�                    *\n");
    printf("******************************************************\n");

    scanf("%d" , &option );
    if( option == 1 )
    {
        FILE *Ptr;
        char Del_name[20];
        int InJug=0;
        printf("������Ҫɾ���ĳ�Ա����\n");
        scanf("%19s", Del_name );
        int i=-1;
        while(1)
        {
            ++i;
            if( strcmp( member[i].name, Del_name ) == 0 )
            {
                int j=i;
                InJug = 1;
                for ( j=i; j<TempMemberNum+1; ++j)
                {
                    strcpy( member[j].group, member[j+1].group );
                    strcpy( member[j].name, member[j+1].name );
                    strcpy( member[j].major, member[j+1].major );
                    strcpy( member[j].Tele, member[j+1].Tele );
                    strcpy( member[j].QQ, member[j+1].QQ );
                    strcpy( member[j].Mail, member[j+1].Mail );
                    strcpy( member[j].ID, member[j+1].ID );
                }
                break;
            }

        }
        if( InJug == 0)
        {
            printf("û���ҵ���Ҫɾ������Ա");
        }
        int g=0;
        Ptr = fopen("��Ա��Ϣ.txt", "w");
        while( g<TempMemberNum && !feof(Ptr) )
        {
            fprintf(Ptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            ++g;

        }
        fclose(Ptr);

    }
    if( option == 2)
    {
        int Change_option = 0;
        char Change_name [10];
        printf("******************************************************\n");
        printf("*              ѡ��1:���ĳ�Ա���                    *\n");
        printf("*              ѡ��2:���ĳ�Ա����                    *\n");
        printf("*              ѡ��3:���ĳ�Աרҵ���                *\n");
        printf("*              ѡ��4:���ĳ�Ա�绰                    *\n");
        printf("*              ѡ��5:���ĳ�ԱQQ                      *\n");
        printf("*              ѡ��6:���ĳ�Ա����                    *\n");
        printf("*              ѡ��7:���ĳ�Աѧ��                    *\n");
        printf("******************************************************\n");
        scanf("%d", &Change_option);
        if( Change_option == 1 )
        {
            int j=0;
            printf("�������! \n ��������Ҫ�������ĳ�Ա������!\n");
            scanf( "%9s", Change_name);
            while( j < TempMemberNum)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("��������ĺ�����!����·����е���Ӿ���Ƕ����Ӫ��\n");
                    scanf("%19s",&member[j].group);
                }
                ++j;
            }
        }
        else if( Change_option == 2 )
        {
            int j=0;
            printf("��������! \n ������֮ǰ������ !\n");
            scanf( "%9s", Change_name );
            while( j< TempMemberNum)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("��������ĺ������!\n");
                    scanf( "%19s",&member[j].name );
                }

                ++j;
            }
        }
        else if( Change_option == 3 )
        {
            int j=0;
            printf("����רҵ! \n ��������Ҫ���ĺ��רҵ��Ա����!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("��������ĺ������!\n");
                    scanf("%19s",&member[j].major);
                }
                ++j;
            }
        }
        else if( Change_option == 4 )
        {
            int j=0;
            printf("�ı�绰����! \n ��������Ҫ�ı�绰����ĳ�Ա����!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("��������ĺ�ĵ绰����!\n");
                    scanf("%19s",&member[j].Tele);
                }
                ++j;
            }
        }
        else if( Change_option == 5 )
        {
            int j=0;
            printf("�޸�QQ��! \n ��������Ҫ�޸�QQ�ŵĳ�Ա����!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("�������µ�QQ��!\n");
                    scanf("%19s",&member[j].QQ);
                }
                ++j;
            }
        }
        else if( Change_option == 6 )
        {
            int j=0;
            printf("��������! \n ��������Ҫ��������ĳ�Ա��Ϣ !\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("��������ĺ������!\n");
                    scanf("%19s",&member[j].Mail);
                }
                ++j;
            }
        }
        else if ( option == 7)
        {
            int j=0;
            printf("�ı�ѧ��! \n ��������Ҫ����ѧ�ŵĳ�Ա��Ϣ!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("��������ĺ��ѧ��!\n");
                    scanf("%19s",&member[j].ID);
                }
                ++j;
            }
        }
        else
        {
            printf("������1-7�е�����\n���¸��ĳ�Ա��Ϣ");
            Change();
        }
        FILE *Ptr;
        int g=0;
        Ptr = fopen("��Ա��Ϣ.txt", "w");
        while( g<TempMemberNum && !feof(Ptr) )
        {

            fprintf(Ptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            ++g;
        }
        fclose(Ptr);
    }

}
void Sort()
{
    int Sort_option = 0;
    printf("******************************************************\n");
    printf("*              ѡ��1:����ѧ������                    *\n");
    printf("*              ѡ��2:����������                    *\n");
    printf("******************************************************\n");
    scanf("%d", &Sort_option );
    if( Sort_option == 1 )
    {
        int i = 0 , j = 0;
        int cmp = 0;
        struct Men TempMember;
        for( i = 0; i < TempMemberNum-1; ++i )
        {
            for( j = 0; j< TempMemberNum-i-1; ++j)
            {
                cmp = strcmp( member[j].ID, member[j+1].ID );//ע��ð������Խ��
                if( cmp>0 )
                {
                    TempMember = member[j+1];
                    member[j+1] = member[j];
                    member[j] = TempMember;
                }
            }
        }

        FILE * Sortptr;
        if( (Sortptr=fopen("��ѧ������.txt","w") )== NULL )
        {
            printf("�����ļ�ʧ�ܣ�\n");
        }
        else
        {
            int k = 0;
            for( k = 0; k<TempMemberNum+1; ++k )
            {
                fprintf(Sortptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[k].group,member[k].name,member[k].major,member[k].Tele,member[k].QQ,member[k].Mail,member[k].ID );
            }
        }
        fclose(Sortptr);
        printf("ѧ�Ŵ�С���������ĳ�Ա�б�Ϊ��\n");
        Memberlist();

    }
    if( Sort_option == 2 )
    {
        FILE *fptr1;
        fptr1=fopen("���Ӿ������.txt","w");
        int g= 0;
        printf("�Ӿ����С��飺\n");
        printf("\n");
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"�Ӿ�")==0 )
            {
                fprintf(fptr1,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr1);


        FILE *fptr2;
        fptr2=fopen("����е�����.txt","w");
        g= 0;
        printf("��е���С��飺\n");
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"��е")==0 )
            {
                fprintf(fptr2,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr2);

        FILE *fptr3;
        fptr3=fopen("����·�����.txt","w");
        printf("��·���С��飺\n");
        g= 0;
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"��·")==0 )
            {
                fprintf(fptr3,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr3);

        FILE *fptr4;
        fptr4=fopen("��Ƕ�������.txt","w");
        printf("Ƕ�����С��飺\n");
        g= 0;
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"Ƕ��")==0 )
            {
                fprintf(fptr4,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr4);

        FILE *fptr5;
        fptr5=fopen("����Ӫ�����.txt","w");
        printf("��Ӫ���С��飺\n");
        g= 0;
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"��Ӫ")==0 )
            {
                fprintf(fptr5,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }

            ++g;
        }
        printf("\n\n");
        fclose(fptr5);
    }

}
void ReadMemberFile()
{
    FILE * MLptr ;

    if((MLptr=fopen( "��Ա��Ϣ.txt", "r" )) == NULL )
    {
        printf("�޷��򿪣�\n");
    }
    else
    {
        int i = 0;
        while( !feof(MLptr) )
        {
            fscanf(MLptr,"%19s%19s%19s%14s%14s%39s%10s",&member[i].group, &member[i].name, &member[i].major, &member[i].Tele, &member[i].QQ, &member[i].Mail, &member[i].ID);
            ++i;
            ++TempMemberNum;
        }
        TempMemberNum = TempMemberNum-1;//�������õ��ܳ�Ա��
        fclose( MLptr );

    }
}
