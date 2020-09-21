#include <stdio.h>

int main()
{
    int a[30][30],b[50][3],c[50][50],d[100][3] ,m,n,t,i,j, l1,l2,s,r,l3,e[100][3],f[50][50], e1[100][100],k,g[100][100];
    printf("Enter the rows and coloumns of first matrix: ");
    scanf("%d %d", &m,&n);
    printf("Enter the elements of the first matrix: ");
    k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j] != 0)
            k++;                    
        }
    }
    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = k;                      
    l1 = 1;           
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j] !=0)
            {
                b[l1][0] = i;
                b[l1][1] = j;
                b[l1][2] = a[i][j];
                l1++;         
            }
        }
    }
    printf("The tuple form of the  first matrix is: \n");
    for(i=0;i<l1;i++)
    {
        
        printf(" %d  %d  %d ",b[i][0], b[i][1],b[i][2]);
        printf("\n");
    }
    printf("Enter the rows and coloumns of the second array: ");
    scanf("%d %d", &s,&t);
    printf("Enter the elements of the second matrix: ");
    for(i=0;i<s;i++)
    {
        for(j=0; j<t; j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j] != 0)
            r++;
        }
    }
    d[0][0] = s;
    d[0][1] = t;
    d[0][2] = r;
    l2 = 1;
    for(i=0;i<s;i++)
    {
        for(j=0;j<t;j++)
        {
            if(c[i][j] !=0)
            {
                d[l2][0] = i;
                d[l2][1] = j;
                d[l2][2] = c[i][j];
                l2++;
            }
        }
    }
    printf("The tuple form of the second matrix is: \n");
    for(i=0;i<l2;i++)
    {

        printf(" %d  %d  %d ",d[i][0], d[i][1],d[i][2]);
        printf("\n");
    }
    if(m==s && n==t)
    {
        l1 = 1;
        l2 = 1;
        l3 = 1;
        e[0][0] = b[0][0];
        e[0][1] =  b[0][1];
        while(l1<=k && l2<=r )
        {
            if(b[l1][0]< d[l2][0] )
            {
                e[l3][0] = b[l1][0];
                e[l3][1] = b[l1][1];
                e[l3][2] = b[l1][2];
                l1++;
                l3++;
            }
            else if(d[l2][0]< b[l1][0])
            {
                e[l3][0] = d[l2][0];
                e[l3][1] = d[l2][1];
                e[l3][2] = d[l2][2];
                l2++;
                l3++;
            }
            else if(b[l1][1]< d[l2][1])
            {
                e[l3][0] = b[l1][0];
                e[l3][1] = b[l1][1];
                e[l3][2] = b[l1][2];
                l1++;
                l3++;
            }
            else if(d[l2][1]< b[l1][1])
            {
                e[l3][0] = d[l2][0];
                e[l3][1] = d[l2][1];
                e[l3][2] = d[l2][2];
                l2++;
                l3++;
            }
            else
            {
                e[l3][0] = b[l1][0];
                e[l3][1] = b[l1][1];
                e[l3][2] = b[l1][2] + d[l2][2];
                l1++;
                l2++;
                l3++;
            }
        }
        while(l1<=t)
        {
            e[l3][0] = b[l1][0];
            e[l3][1] = b[l1][1];
            e[l3][2] = b[l1][2];
            l1++;
            l3++;

        }
        while(l2<=r)
        {
                e[l3][0] = d[l2][0];
                e[l3][1] = d[l2][1];
                e[l3][2] = d[l2][2];
                l2++;
                l3++;
        }
        e[0][2] = l3-1;
        printf("\nThe resultant matrix after adition in tuple form is: \n");
       for(i=0;i<l3;i++)
        {
            for(j=0;j<3;j++)
                printf(" %d ", e[i][j]);
             printf("\n");
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            e1[i][j] = a[i][j] + c[i][j];
        }
       
    }
    else
        printf("matrix addition not possible");

    f[0][0] = b[0][1];
    f[0][1] = b[0][0];
    f[0][2] = b[0][2];
    k = 1;
    for(i=0; i< b[0][1]; i++)
    {
        for(j=1; j<= b[0][2] ; j++)
        {
            if(b[j][1] == i)
            {
                f[k][0] = b[j][1];
                f[k][1] = b[j][0];
                f[k][2] = b[j][2];
                k++;
            }
        }
    }
    printf("transpose of the first matrix : \n");
    for(i=0; i< k ; i++)
    {
        printf(" %d  %d  %d", f[i][0] ,f[i][1], f[i][2]);
        printf("\n");
    }
    g[0][0] = d[0][1];
    g[0][1] = d[0][0];
    g[0][2] = d[0][2];
    k = 1;
    for(i=0; i< d[0][1]; i++)
    {
        for(j=1; j<= d[0][2] ; j++)
        {
            if(d[j][1] == i)
            {
                g[k][0] = d[j][1];
                g[k][1] = d[j][0];
                g[k][2] = d[j][2];
                k++;
            }
        }
    }
    printf("transpose of the second matrix : \n");
    for(i=0; i< k ; i++)
    {
        printf(" %d  %d  %d", g[i][0] ,g[i][1], g[i][2]);
        printf("\n");
    }
                                                            
    
}
