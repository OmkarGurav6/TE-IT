
/*
Name : Omkar Gurav
Roll No : 8048
TE IT

Write a program to find Maximum and Minimum element in an array using Divide and Conquer strategy.
*/

#include<iostream>

using namespace std;


void getmaxmin(int a[],int low,int high,int &min,int &max)
{

     if(low == high)
     {
        if (max < a[low]) 
			max = a[low];

		if (min > a[high])   		
			min = a[high];

         return;

     } 
     
     if(low == high -1)
     {
         
         if(a[low] < a[high])
         {
         
            if(min > a[low])
             min = a[low];

            if(max < a[high])
              max = a[high];
         
         } else {
            
            if (min > a[high])
				min = a[high];
			
			if (max < a[low])    	
				max = a[low];

         }

         return;

     } 

        int mid = (low + high)/2;

        getmaxmin(a,low,mid,min,max);
        getmaxmin(a,mid + 1,high,min,max);

}


int main()
{ 
    int n,high,low,max=0,min=9999;

    cout << "Enter size of array :";
    cin >> n;

    high = n-1;
    low = 0;

    int a[n];
     
    cout << "\n\nEnter elements of array :";
    for(int i = 0 ; i<n;i++)
    {
        cin >> a[i];
    }

    getmaxmin(a,low,high,min,max);

    cout << "Maximum value in array is " << max << "\n\nMinimum value in array is " << min;

    return 0;
}

//Ouput : 
// Enter size of array :8


// Enter elements of array :12
// 65
// 98
// 34
// 67
// 87
// 24
// 59
// Maximum value in array is 98

// Minimum value in array is 12
