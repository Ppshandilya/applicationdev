#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
    int price;
    char categ[20];
    char proname[20];
    int quantity;
    char pur[20];
    char exp[20];
}p;

int main()
{ int choice,shift,length;           int price,found,quant;
    char categ[20];
    char proname[20];
    int quantity;
    char pur[20];
    char exp[20];

   FILE *fp;


   Label1:

      printf("Enter your choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
       case  1:
       Label2:
       printf("\nEnter product name:");
       scanf("%d",&p.proname);


       scanf("%s",&p.categ)  ;

       scanf("%d",&p.price);
       fp=fopen("Productfile.txt","a+");
       fprintf(fp,"\n%d\t%s\t%s\t%d\t",p.price,p.proname,p.categ,p.quant);
       fclose(fp);

       scanf("%d",&shift);
       if(shift==1)
	goto Label2;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("Exiting.........");
	break;
	}

       case 2:
       Label4:
       printf("\nEnter product name: ");
       scanf("%s",&proname);
       printf("Searching record with proname=%s.\n",proname);
	   found=0;
	   if((fp=fopen("productfile.txt","r"))==NULL)
	{
	    printf(" ! The File is Empty...\n\n");
	}
	else
	{
	    while(!feof(fp)&& found==0)
		{
		fscanf(fp,"\n%d\t%s\t%s\t%d\t",&p.price,p.proname,p.categ,&p.price);
		length = strlen(p.proname);
		if(p.proname[length]==proname[length])
		    found=1;
	    }
	    }
       if(found)
       {
	 printf("\nThe record is found.");
	 printf("\nquantity: %d\nProductName: %s\nProductCategory: %s\nprice: %d \n",p.price,p.proname,p.categ,p.price);
       }
       else
       {
	 printf("Not found...\n");
	 getch();
       }
       Label5:
       printf("\n\n1 -> Wish to search another record");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit  Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label4;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto Label5;
	}
       case 3:
       Label6:
       printf("\nEnter the price ");
       scanf("%d",&price);
       printf("Searching record with price=%d.\n",price);
	   found=0;
	   if((fp=fopen("Productfile.txt","r"))==NULL)
	{
	    printf(" ! The File is Empty...\n\n");
	}
	else
	{
	    while(!feof(fp)&& found==0)
		{
		fscanf(fp,"\n%d\t%s\t%s\t%d\t",&p.price,p.proname,p.categ,&p.quant);
		if(p.proname=proname)
		    found=1;
	    }
	    }
       if(found)
       {
	 printf("\nThe record is found.");
	 printf("\nprice: %d\nProductName: %s\ncategory: %s\nprice: %d \n",p.price,p.proname,p.categ,p.quant);
       }
       else
       {
	 printf("Not found...\n");
	 getch();
       }
       Label7:
       printf("\n\n1 -> Wish to search more..");
       printf("\n2 -> Move to main menu");
       printf("\n3 -> Exit  Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label6;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto Label7;
	}
       case 4: break;
       default :
	  printf(" Enter a proper choice\n");
	  goto Label1;
	}

      getch();
      return 0;
