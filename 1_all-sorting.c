#include<stdio.h>
#include<stdlib.h>
#define n 10

void merge_Sort(int a[], int i, int j);
void merge(int a[], int i1, int j1, int i2, int j2);

void printArray(int a[])
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
}
void bubble_sort(int a[])
{
    int i,j,key;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                key=a[j];
                a[j]=a[j+1];
                a[j+1]=key;
            }
        }
        // printArray(a);
    }
}
int binnary_search(int a[])
{
    int val,lb=0,ub=9,mid;
    
    // bubble_sort(a);
    
    printf("\n Enter element : ");
    scanf("%d",&val);
    
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        
        if(a[mid]==val)
        {
            return mid;
            printf("\n element position : %d",mid);
        }
        else if(a[mid]>val)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    return -1;
}
void selection_sort(int a[])
{
    int i,j,key;
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                key=a[i];
                a[i]=a[j];
                a[j]=key;
            }
        }
        // printArray(a);
    }
}
void insertion_sort(int a[],int size)
{
    for(int step=1;step<=size;step++)
    {
        int key=a[step];
        int j=step-1;

        while(key<a[j] && j>=0)
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }
}
void quick_sort(int a[],int first,int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        // printf("\n inside quick");
        // printArray(a);

        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(a[i]<=a[pivot] && i<last)
                i++;

            while (a[j]>a[pivot])
                j--;
            
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;

        quick_sort(a,first,j-1);
        quick_sort(a,j+1,last);
    }
}
void merge_Sort(int a[], int i, int j)
{
    int mid;
    if (i < j)
    {
        mid = (i + j) / 2;
        merge_Sort(a, i, mid);
        merge_Sort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
    }
}
void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[50];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;
    
    // printf("\n  %d, %d   ",a[i],a[j]);
    // printf("\n %d, %d, %d, %d, ", i1, j1, i2, j2);
    while (i <= j1 && j <= j2)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while (i <= j1)
        temp[k++] = a[i++];
    while (j <= j2)
        temp[k++] = a[j++];

    for (i = i1, j = 0; i <= j2; i++, j++)

        a[i] = temp[j];
}
int main()
{
    int a[20],min=11,max=101,val,ch,bin,i;
    
    for(i=0;i<n;i++)
    {
        a[i]=(rand() % (max-min+1)+min);
    }
    printArray(a);
    
    do
    {
        printf("\n\n 1. bubble sorting");
        printf("\n 2. binnary search");
        printf("\n 3. selection sorting");
        printf("\n 4. quick sorting");
        printf("\n 5. insertion sorting");
        printf("\n 6. mrege sorting");
        printf("\n 7. exit");
        
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                bubble_sort(a);
                printArray(a);
                break;
                
            case 2:
                bin=binnary_search(a);
                
                if(bin==-1)
                {
                    printf("\n This element is not found");
                }
                else
                {
                    printf("\n element position : %d",bin);
                }
                break;
                
            case 3:
                selection_sort(a);
                printArray(a);
                break;
                
            case 4:
                quick_sort(a,0,n-1);
                printArray(a);
                break;
                
            case 5:
                insertion_sort(a,n-1);
                printArray(a);
                break;

            case 6:
                merge_Sort(a,0,n-1);
                printArray(a);
                break;

            default:
                printf("\n your choice is envlide \n");
                break;
        }
    }while(ch!=7);
    
    return 0;
}