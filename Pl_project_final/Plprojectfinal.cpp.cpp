#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void append();
void list();
void search();
void modify();
void del();

struct student
{
	int rollno,fee,marks,attendance;
	char name[20];
};

int main()
{
	int a,b,c;
	char ch,cm,ck,cl,cs; 
	
	
		printf("      STUDENT DATABASE  ");
		printf("\n");
		printf ( "              |              ");printf("\n");
		printf (  "              |               ");printf("\n");
		printf (   "              |               " );printf("\n");
		printf  ( "______________|_________________ ");printf("\n");
		printf	("|                                | ");printf("\n");
		printf ("V                                V   "); printf("\n");  
do{	    
		 printf("1.STUDENT                2.ADMINISTRATIONS\n");
		scanf("%d",&a);
	switch(a)
	{
		
	case 1:
	{
		printf("1.List student record\n2.Search student record\n Enter choice:");
		scanf("%d",&b);
		switch(b)
		{
			case 1:
			list();
			break;
		    case 2:
			search();
			break;
			default:
			printf("Invalid choice!");		
		}}
		break;
		case 2:
		{
			puts("enter your password here\n\n\n");
			cm=getch();
			printf("*");
			ck=getch();
			printf("*");
			cl=getch();
			printf("*");
			cs=getch();
			printf("*");


if(cm=='r' && ck=='j' && cl=='m' && cs=='m')
{
			
			printf("\n1.Append Student Record\n2.List Student Record\n3.Modify Student Record\n4.Delete Student Record\n5.Search Student Record");
			scanf("%d",&c);
			switch(c)
			{
				case 1:
				append();
				break;
				case 2:
				list();
			  break;
		     	case 3:
			   modify();
				break;
				case 4:
				del();
				break;
				case 5:
				search();
				break;
				default:
				printf("Invalid choice!");
			}}
			else
			{
				printf("\nInvalid try");
			}
			}
			break;
			default:
			printf("Invalid choice");
			
			}printf("\n More actions? (Y/N):");
		    fflush(stdin);
		    scanf("%c",&ch);
	        }while(ch=='y'|| ch=='Y');
			}
			
     // Append function//
	 
	 void append()
	 {
	 	int i,n; char ch;
	 	struct student e;
	 	FILE *fp;
	 	fp=fopen("project.txt","ab");
	 	if(fp==NULL)
	 	{
	 		printf("File Creation Failed !");
	 	}
	 	//do
//		 {
	 	printf("\nEnter the roll no of student:");
	 	scanf("%d",&e.rollno);
	 	printf("\n Enter student name:");
        fflush(stdin);
		gets(e.name);	
		printf("\n Enter marks of student:");
		scanf("%d",&e.marks);
		printf("\n Enter paid fees of the year:");
		scanf("%d",&e.fee);
		printf("\n Enter attendence of the student in %:");
		scanf("%d",&e.attendance);
		printf("\n\n");
		fwrite(&e,sizeof(e),1,fp);
//		printf(" want to enter data for another student (Y/N)");
		//} //while (ch=='y' || ch=='Y');
	 fclose(fp);
}
void list()
{ 
int nofrec=0;//number of records//
struct student e;
FILE *fp;
fp=fopen("project.txt", "rb");
if(fp==NULL)
{
printf("\n\tFile doesn’t exist!!!\nTRY AGAIN");
exit(1);
}
while((fread(&e, sizeof(e), 1, fp))==1)
{ 
nofrec++;
printf("\nStudent's Roll Number : %d", e.rollno);
printf("\nStudent's Name : %s",e.name);
printf("\n\n");
}
printf("Total number of records present are : %d", nofrec);
fclose(fp);
}
void search()
{
int s,recno,per;    //per=percentage//
int total_fee_for_one_semester=18000;
char sname[20];
struct student e;
FILE *fp;
fp=fopen("project.txt", "rb");
printf("\n1.Search by Name\n2.Search by student No.\n Enter choice : ");
scanf("%d", &s);
switch(s)
{
case 1:
printf("Enter the student Name to Search : ");
fflush(stdin);
gets(sname);
while((fread(&e, sizeof(e), 1, fp))==1)
{
if(strcmp(sname,e.name)==0)
{
printf("\nStudent's Roll Number : %d", e.rollno);
printf("\nStudent's Full Name : %s",e.name);
printf("\nStudent's attendance in percentage : %d",e.attendance);//out of 100%//
printf("\n\nSTUDENT'S DUES VERIFICATION !!");
printf("\nStudent's monthly paid fee : %d",e.fee); //FROM 3000//
if((e.fee*6)==total_fee_for_one_semester)
printf("\n  DUES ARE VERIFIED AND CLEAR!");
else
printf("\n  DUES NOT VERIFIED OR NOT PAID");
printf("\nStudent's Total Marks of sessionals in 5 Courses : %d",e.marks);
// marks out of 200//
//passing sessional marks in each course is 10 out of 40//

if((e.attendance>=75)&&(e.marks>=50)&&((e.fee*6)==total_fee_for_one_semester))
printf("\n\n  Student is liable to appear in Final Examinations!");
else
printf("\n\n  Student cannot appear in Final Examination!");
printf("\n");
}
}
break;
case 2:
printf("Enter the student Number to Search : ");
scanf("%d", &recno);
while((fread(&e, sizeof(e), 1, fp))==1)
{
if(e.rollno==recno)
{
printf("\nStudent's Roll Number : %d", e.rollno);
printf("\nStudent's Full Name : %s",e.name);
printf("\nStudent's attendance in percentage : %d",e.attendance);//out of 100%//
printf("\n\nSTUDENT'S DUES VERIFICATION !!");
printf("\nStudent's monthly paid fee : %d",e.fee); //FROM 3000//
if((e.fee*6)==total_fee_for_one_semester)
printf("\n  DUES ARE VERIFIED AND CLEAR!");
else
printf("\n  DUES NOT VERIFIED OR NOT PAID");
printf("\nStudent's Total Marks of sessionals in 5 Courses : %d",e.marks);
// marks out of 200//
//passing sessional marks in each course is 10 out of 40//

if((e.attendance>=75)&&(e.marks>=50)&&((e.fee*6)==total_fee_for_one_semester))
printf("\n\n  Student is liable to appear in Final Examinations!");
else
printf("\n\n  Student cannot appear in Final Examination!");
printf("\n");
}
}
break;
}
}



void del()
  {
     int recno;
     char ch;
     struct student e;
     FILE *fp,*ft;
     fp=fopen("project.txt", "rb+"); ft=fopen("replica.txt", "wb+"); 

      printf("Enter the student Number to delete : ");
     scanf("%d", &recno);
     while((fread(&e, sizeof(e), 1, fp))==1)
        {
            if(e.rollno==recno)
               {
                  printf("\nstudent Number : %d", e.rollno);
                  printf("\nstudent Name : %s",e.name);
                  printf("\nStudent fees : %d",e.fee);
                  printf("\nstudent marks: %d",e.marks);
                  printf("\n");
                  printf("Do you want to delete this record : ? (Y/N)");
                  fflush(stdin);
                  scanf("%c", &ch);
				  }
		}
               
        
                 if(ch=='y'||ch=='Y')
                   {
                   rewind(fp);
                  while((fread(&e, sizeof(e), 1, fp))==1)
                        {
                           if(recno!=e.rollno)
                            {
                               fwrite(&e,sizeof(e),1,ft);
                            }
                        }
                   }
              
        else if(ch=='n'||ch=='N')
		{	
		printf("No Record was deleted");
		}
        fclose(fp);
        fclose(ft);
		remove("project.txt");
		rename("replica.txt","project.txt");

}
//MODIFY//

void modify()
{
char name[20];
int recno, nofrec=0;
char ch;
struct student e;
FILE *fp,*ft;
fp=fopen("project.txt", "rb+"); ft=fopen("replica.txt", "wb+");
printf("Enter the student Number to modify : ");
scanf("%d", &recno);
while((fread(&e,sizeof(e),1,fp))==1)
{
if(e.rollno==recno)
{
printf("\nstudent Number : %d", e.rollno);
printf("\nstudent Name : %s",e.name);
printf("\nStudent fees : %d",e.fee);
printf("\nstudent marks: %d",e.marks);
printf("\n");
printf("Do you want to modify this record : ? (Y/N)");
fflush(stdin);
scanf("%c", &ch);
}
}
if(ch=='Y'|| ch=='y')
{
printf("Enter student Name : ");
scanf("%s",&e.name);
fflush(stdin);
printf("Enter the student No : ");
scanf("%d",&e.rollno);
printf("\nStudent fees :");
scanf("%d",&e.fee);
printf("\nstudent marks:");
scanf("%d",&e.marks);
fflush(stdin);
fwrite(&e, sizeof(e),1,ft);
printf("Record Modified");
}
else if(ch=='n'|| ch=='N')
{
printf("No modifications were made");
}
fclose(fp);
fclose(ft);
remove("project.txt");
rename("replica.txt","project.txt");
}
