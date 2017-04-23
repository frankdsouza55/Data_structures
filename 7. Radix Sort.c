#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,i,j,ne,a[100],k,x;
    printf("\nEnter max no of digits : ");
    scanf("%d",&n);
    printf("\nEnter number of elements : ");
    scanf("%d",&ne);
    printf("\nEnter the elements\n");
    for(i=0;i<ne;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        k=pow(10,i-1);
        for(x=1;x<ne;x++)
            for(j=0;j<ne-x;j++)
                if( (a[j]/k) %10 > (a[j+1]/k) %10 )
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
    }
    printf("\nSorted array\n");
    for(i=0;i<ne;i++)
        printf("%d\t",a[i]);
    return 0;
}

