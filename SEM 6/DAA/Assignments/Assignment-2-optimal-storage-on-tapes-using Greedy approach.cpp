
/*
Name : Omkar Gurav
TE IT S3 Batch
Roll No : 8048

Write a program to solve optimal storage on tapes problem using Greedy approach. 
*/

#include<iostream>

using namespace std;


class greedy{
 
   public: 

   int n,l[100],t,tape[100][30],l1=0,r1,itempertapecount[20];
   float mrt[20];
   
   void getdata();
   void mergesort(int a[],int L,int r,int n);
   void merge(int a[],int L,int m,int r,int n);
   void arrangeintapes();
   void displaytape();
   void calculatemrt();
   void totalmrt();
};


void greedy::getdata()
{
    cout << "\nEnter number of programs : ";
    cin >> n;

    r1 = n-1;

    for(int i=0; i<n; i++)
    {
        cout << "\nEnter length of program " << i+1 << ": ";
        cin >> l[i];
    }

    cout << "\nEnter number of tapes : ";
    cin >> t;

    for(int i=0 ; i<t; i++)
    {
      for(int j=0 ; i<30; i++)
       {
          tape[i][j] = 0;
       }
    }

}


void greedy::merge(int a[],int L,int m,int r,int n)
{
   int s1=m-L+1,s2=r-m,i,j,k;
   int L1[s1],R[s2];
   static int c;

      for(i=0;i<s1;i++)
      {
        L1[i]=a[L+i];
      }

      for(j=0;j<s2;j++)
      {
        R[j]=a[m+1+j];
      }

      i=0;j=0;k=L;
      
      while(i<s1 && j<s2)
      { 
        if(L1[i]<=R[j])
        {
          a[k]=L1[i];
          i++;
        }
        else
        {
          a[k]=R[j];
          j++;
        }
         k++;
      }

      
      while(i<s1)
      { 
        a[k]=L1[i];
        i++;
        k++;
      }

      while(j<s2)
      {
        a[k]=R[j];
        j++;
        k++;
      }

}


void greedy::mergesort(int a[],int L,int r,int n)
{
        if(L<r)
        {
          int m=(L+r)/2;

          mergesort(a,L,m,n);
          mergesort(a,m+1,r,n);
          merge(a,L,m,r,n);
        }
        else
            return;
}


void greedy::arrangeintapes()
{
    int count=0,col=0;

    for(int j=0; j<20; j++)
       itempertapecount[j] = 0;

    for(int k=0; k<n; k++)
    {
       tape[count][col] = l[k];

       itempertapecount[count]++;

       if(count == t-1)
       {
           col++;
           count = 0;
       }
       else 
           count++;

    }  
}


void greedy::displaytape()
{
   int col=0;

   for(int i=0; i<t; i++)
   {
       cout << "\nTape " << i+1;

       while(tape[i][col] != 0)
       {
           cout << "\t" << tape[i][col];
           col++;
       }

       cout << "\n";

       col = 0;
   }

}


void greedy::calculatemrt()
{
    int col=0,i,j=0,k;

    float sum[t]; 

    for(int i=0; i<t; i++) 
       sum[i]=0;


    for(i=0; i<t; i++)
    {
        for(j=0; j<itempertapecount[i]; j++)
        {
           for(k=0; k<=j; k++)
           {
              sum[i] = sum[i]+tape[i][k];
           }

           col++;
        
        }

      col = 0;

      mrt[i] = sum[i]/itempertapecount[i];

      cout << "\n\nMRT of tape " << i+1 << " is " << mrt[i];

    }

}


void greedy::totalmrt()
{
    float totalmrt=0;

    for(int i=0; i<t; i++)
     totalmrt = totalmrt + mrt[i];

    cout << "\n\nFinal MRT is " << totalmrt/t;

}


int main()
{
   greedy g;

   g.getdata();
   g.mergesort(g.l,g.l1,g.r1,g.n);

//    for(int i=0; i<g.n; i++)
//      cout << "\n" << g.l[i] << "\n";

   g.arrangeintapes();
   g.displaytape();

//    for(int i=0; i<20; i++)
//      cout << "\n" << g.itempertapecount[i] << "\n";   

   g.calculatemrt();
   g.totalmrt();

   return 0;
}


/*
Output :

Enter number of programs : 5

Enter length of program 1: 24

Enter length of program 2: 78

Enter length of program 3: 101

Enter length of program 4: 85

Enter length of program 5: 56

Enter number of tapes : 2

Tape 1  24      78      101

Tape 2  56      85


MRT of tape 1 is 109.667   

MRT of tape 2 is 98.5      

Final MRT is 104.083    

*/
