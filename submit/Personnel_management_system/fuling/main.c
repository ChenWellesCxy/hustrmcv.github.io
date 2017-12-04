#include <stdio.h>
#include <string.h>
#include "stddef.h"
#include <stdlib.h>

struct Friends_List
{
    char group[10];
    char name[10];
    char major[16];
    char telephone[13];
    char email[20];
    char QQ[13];
    char ID[16];
    struct Friends_List*next;
};

struct Friends_List*Create_Friends_List( struct Friends_List*p )
{
    if( p != NULL )
    {
        printf( "ͨѶ¼�Ѿ����ڡ�\n" );
    }

    else
    {
        p = ( struct Friends_List* ) malloc( sizeof( struct Friends_List ) );

        if ( p == NULL )
        {
            printf( "����ͨѶ¼ʧ�ܣ����´�����\n" );

            return p;
        }

        p->next = NULL;
    }

    return p;
}

//���һλ����ϵ�˵���Ϣ
void Insert_Friends_List( struct Friends_List*p )
{
    struct Friends_List*q;
    char c;

    if ( p == NULL )
    {
        printf( "ͨѶ¼�����ڣ����ȴ�����\n" );
    }

    else while(1)
    {
        q = ( struct Friends_List* ) malloc( sizeof( struct Friends_List ) );

        if(q == NULL)
        {
            continue;
        }

        printf("����������ϵ�˵���� ");
        scanf("%s", q->group);
        printf("����������ϵ�˵������� ");
        scanf("%s", q->name);
        printf("����������ϵ�˵İ༶���ƣ� ");
        scanf("%s", q->major);
        printf("����������ϵ�˵ĵ绰���룺 ");
        scanf("%s", q->telephone);
        printf("����������ϵ�˵������ַ�� ");
        scanf("%s", q->email);
        printf("����������ϵ�˵�QQ����:  ");
        scanf("%s", q->QQ);
        printf("����������ϵ�˵�ѧ�ţ� ");
        scanf("%s", q->ID);

        q->next=NULL;
        q->next=p->next;
        p->next=q;

        printf("��q�˳�����������������\n");
        fflush(stdin);
        scanf("%c", &c);

        if(c == 'q')
        {
            break;
        }
    }
}

//ͨ�����ִ�ӡ����ϵ����Ϣ���ӡ��ȫ����ϵ�˵���Ϣ
void Display_Friend_List( struct Friends_List*p, char name[10], int i )
{
    struct Friends_List*q;
    int j;
    q = p->next;

    if ( i == 1 )
    {
        j = 1;

        while ( q != NULL )
        {
            if ( strcmp( name, q->name )==0 )
            {
                printf( "\n************����Ϊ%s�ĵ�%d����ϵ��*************\n", q->name, j );
                printf("���\t����\tרҵ�༶\t�绰����\t�����ַ\tQQ����\t  ѧ��\n");
                printf("%-8s%-8s%-16s%-16s%-16s%-12s%-12s\n", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);
                j++;
            }
            q=q->next;
        }
        if( j==1 )
        {
            printf("ͨѶ¼��û������Ϊ: %s����ϵ�ˡ�\n", name);
        }
    }

    else
    {
        j = 1;

        while( q != NULL )
        {
            printf( "\n************��%d����ϵ��*************\n", j );
            printf("���\t����\tרҵ�༶\t�绰����\t�����ַ\tQQ����\t  ѧ��\n");
            printf("%-8s%-8s%-16s%-16s%-16s%-12s%-12s\n", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);

            q = q->next;
            j++;
        }

        if( j==1 )
        {
            printf( "ͨѶ¼��û�м�¼��\n" );
        }
    }
}

//ͨ��ѧ�Ŵ�ӡ����ϵ����Ϣ
void Display_Friend_List_ID( struct Friends_List*p, char ID[10], int i )
{
    struct Friends_List*q;
    int j = 1;
    q = p->next;

    while ( q != NULL )
    {
        if ( strcmp( ID, q->ID ) == 0 )
        {
            printf( "\n************ѧ��Ϊ%s�ĵ�%d����ϵ��*************\n", q->ID, j );
            printf("���\t����\tרҵ�༶\t�绰����\t�����ַ\tQQ����\t  ѧ��\n");
            printf("%-8s%-8s%-16s%-16s%-16s%-12s%-12s\n", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);

            j++;
        }

        q=q->next;
    }

    if(j==1)
    {
        printf("ͨѶ¼��û��ѧ��Ϊ: %s����ϵ�ˡ�\n", ID);
    }
}

//ѯ���Ժ��ַ�ʽ��ѯ
void Query_Friends_List( struct Friends_List*p )
{
    int choice;
    char name[10];
    char ID[16];

    if( p == NULL )
    {
        printf( "ͨѶ¼�����ڣ����ȴ�����\n" );

        return;
    }

    while(1)
    {
        printf( "��ѯѡ� 1����������ѯ��ϵ�� 2: ��ѧ�Ų�ѯ��ϵ�� 3����ѯ������ϵ�� 0���˳�\n" );
        printf( "��ѡ���ܣ�" );  scanf( "%d", &choice );

        if ( choice == 1 )
        {
            printf( "��������ϵ�˵�������" );
            scanf( "%s", name );
            Display_Friend_List( p, name, 1 );
        }

        if ( choice == 2 )
        {
            printf( "��������ϵ�˵�ѧ�ţ�" );
            scanf( "%s", ID );
            Display_Friend_List_ID( p, ID, 1 );
        }

        else if( choice == 3 )
        {
            Display_Friend_List( p, name, 2 );
        }

        else if( choice == 0 )
        {
            break;
        }
    }
}

//ɾ��ĳ����ϵ�˵���Ϣ
int Delete_Friends_List( struct Friends_List*p )
{
    char name[10];
    struct Friends_List*q,*r;
    int j = 1;

    if ( p == NULL )
    {
        printf( "ͨѶ¼�����ڣ� ���ȴ�����\n" );

        return 1;
    }

    printf( "������Ҫɾ������ϵ�˵�������" );
    scanf( "%s", name );

    r = p;
    q = p->next;

    while( q != NULL )
    {
        if( strcmp( name, q->name ) == 0 )
        {
            r->next = q->next;
            free(q);
            q = r->next;
            j++;
        }

        else
        {
            r = q;
            q = q->next;
        }
    }

    if ( j == 0 )
    {
        printf("ͨѶ¼��û������Ϊ��%s����ϵ�ˡ�\n", name);
    }

    else
    {
        printf("ͨѶ¼�й�ɾ��������Ϊ��%s��%d����¼��\n", name, j);
    }

    return 0;
}

//���ļ��е���Ϣ��ȡ����������
struct Friends_List *createlink()
{
    char c;
    struct Friends_List*p;
    p =(struct Friends_List*)malloc(sizeof(struct Friends_List));
    struct Friends_List *r;
    struct Friends_List *q;

    r=q=p;
    FILE * fp= fopen("information.txt","r");

    if( fp == NULL )
    {
        printf("���ļ�ʧ��!");

        return NULL;
    }

    while( (c = fgetc(fp))!=EOF )
    {
       q= (struct Friends_List*)malloc(sizeof(struct Friends_List));
       fscanf(fp,"%10s%10s%16s%13s%20s%13s%16s", \
              q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);
       //Display_Friend_List( p, c, 0 );

       r->next = q;
       r = q;
    }

    r->next=NULL;
    printf("��ȡ�ɹ���");

    return p;
}

//���������е���Ϣ���浽�ļ���
void outlink(struct Friends_List*p)
{
   struct Friends_List *q=p->next;

   FILE *fp =fopen("information.txt","w");

   if(fp == NULL)
   {
       printf("���ļ�ʧ��!");
       return;
   }

   while(q)
   {
       //�������ڵ����ݵ��ļ�information.txt
       fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s ", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);
       q=q->next;
   }
   printf("\n");
   fprintf(fp,"\n");
   fclose(fp);
   printf("����ɹ���");

   return;
}

//������
int main( void )
{
    int choice;
    struct Friends_List*p = NULL;

    do
    {
        printf( "\nͨѶ¼������ѡ��:\n1:�½� 2:���� 3:��ѯ 4:ɾ�� 5:���� 6:���� 0:�˳�\n" );
        printf( "��ѡ����:" );
        scanf( "%d", &choice );

        switch( choice )
        {
            case 1:
                p = Create_Friends_List(p);
                break;

            case 2:
                Insert_Friends_List(p);
                break;

            case 3:
                Query_Friends_List(p);
                break;

            case 4:
                Delete_Friends_List(p);
                break;

            case 5:
                outlink(p);
                break;

            case 6:
                p=createlink();
                break;

            case 0:
                break;

            default:
                printf( "ѡ����� ����ѡ��" );
        }
    }while( choice != 0 );


    printf("ллʹ��ͨѶ¼��������ټ���\n");

    return 0;
}
