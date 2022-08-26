#include <iostream>
// Halla Raafat mahmoud ibrahim 1806328 section 1

using namespace std;
void  input_matrix2 (float arr [2][2]);
void  input_matrix3 (float arr [3][3]);
void print_matrix2   (float arr [2][2]);
void print_matrix3   (float arr [3][3]);
void add_matrix2 (float arr1 [2][2],float arr2 [2][2]);
void add_matrix3 (float arr1 [3][3],float arr2 [3][3]);
void subt_matrix2 (float arr1 [2][2],float arr2 [2][2]);
void subt_matrix3 (float arr1 [3][3],float arr2 [3][3]);
void prd_matrix2 (float arr1 [2][2],float arr2 [2][2]);
void prd_matrix3 (float arr1 [3][3],float arr2 [3][3]);
float det_matrix2(float arr [2][2]);
float det_matrix3 (float arr [3][3]);
void inv_matrix2 (float arr [2][2]);
void inv_matrix3 (float arr [3][3]);

int main()
{
    float matrix21 [2][2], matrix22 [2][2], matrix31 [3][3],matrix32 [3][3],new2[2][2],new3 [3][3];
    int x,y;
    cout<<"Choose the matrix ? *2* for 2 x 2 or *3* for 3 x 3 : "<<endl;
    cin>>x;
while ((x != 2 )&&(x != 3 ))
        { cout<<" Enter 2 or 3 only "<<endl;
    cin >>x;}
    cout << "Choose number of matrices *1* or *2*  " <<endl;
    cin>>y;
while ((y != 1 )&&(y != 2 ))
        { cout<<" Enter 1 or 2 only "<<endl;
    cin >>y;}
    cout<<endl;
         if ((x==2)&&(y==1))
        {cout<<"ENTER DATA OF THE MATRIX "<<1<<endl;
        input_matrix2 (matrix21);}


        else if ((x==2)&&(y==2))

        {cout<<"ENTER DATA OF THE MATRIX "<<1<<endl;
        input_matrix2(matrix21);
        cout<<"ENTER DATA OF THE MATRIX "<<2<<endl;
        input_matrix2(matrix22);}

        else if ((x==3)&&(y==1))

        {cout<<"ENTER DATA OF THE MATRIX "<<1<<endl;
        input_matrix3 (matrix31);}

            else {cout<<"ENTER DATA OF THE MATRIX "<<1<<endl;
        input_matrix3 (matrix31);
        cout<<"ENTER DATA OF THE MATRIX "<<2<<endl;
        input_matrix3 (matrix32);}
        char z;
    while (z!= 'q') {
    cout <<"\n Choose operator : \n + for addition \n - for subtraction \n * for Multiplication \n d for determinant \n i for inverse \n q for quit"<<endl;
    cin>>z;
  while ((z != '+')&&(z != '-')&&(z != '*')&&(z != 'd')&&(z != 'i')&&(z != 'q'))
   {
        cout << "PLEASE ENTER THE SIGN OF THE OPERATOR";
       cin>>z;
    }
    switch (z)
    {case 'q' :
        break;
    case '+' :
        {if (x==2)
{add_matrix2 (matrix21, matrix22 );

}
else
{add_matrix3 (matrix31,matrix32);
}
}
        break;
    case '-' :
        {
if (x==2)
subt_matrix2 (matrix21, matrix22 );
else
subt_matrix3 (matrix31,matrix32);
        }
         break;

     case '*' :
        {
if (x==2)
prd_matrix2 (matrix21, matrix22 );
else
prd_matrix3 (matrix31,matrix32);
        }
         break;
     case 'd' :
        {
            int f;
            cout <<"FIRST (1) OR SECOND (2) MATRIX ? ";
            cin>>f;
            if ((f==1)&&(x==2))
                cout<<"\n DETERMINANT EQUALS TO"<<det_matrix2 (matrix21)<<endl;
            else if ((f==2)&&(x==2))
                cout<<"\n DETERMINANT EQUALS TO"<<det_matrix2 (matrix22)<<endl;

         else if ((f==1)&&(x==3))
                cout<<"\n DETERMINANT EQUALS TO"<<det_matrix3 (matrix31)<<endl ;
        else cout<<"\n DETERMINANT EQUALS TO"<<det_matrix3 (matrix32)<<endl;

        }
         break;
     case 'i' :
        {
            int f;
            cout <<"FIRST (1) OR SECOND (2) MATRIX ? ";
            cin>>f;
            if ((f==1)&&(x==2))
               inv_matrix2 (matrix21);
            else if ((f==2)&&(x==2))
               inv_matrix2 (matrix22);

         else if ((f==1)&&(x==3))
                inv_matrix3 (matrix31) ;
        else inv_matrix3 (matrix32);
        }
}
    }
}
void print_matrix2   (float arr [2][2])
{ cout<<endl;
    for (int i=0;i<2;i++)
   {for (int j=0;j<2;j++)
    {cout<< arr[i][j]<<"\t";}
    cout<<endl;}}

void print_matrix3   (float arr [3][3])
{cout<<endl;
    for (int i=0;i<3;i++)
    {for (int j=0;j<3;j++)
    cout<< arr[i][j]<<"\t";
    cout<<endl;}}
void  input_matrix2 (float arr [2][2])
{{for (int i=0;i<2;i++)
    for (int j=0;j<2;j++)
    {cout<< i<<"i "<<j<<"j"<<endl;
cin>> arr[i][j];}}
print_matrix2 ( arr);}



void  input_matrix3 (float arr [3][3])
{{for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
    {cout<< i<<"i "<<j<<"j"<<endl;
cin>> arr[i][j];}}
print_matrix3 (arr);}

void add_matrix2 (float arr1 [2][2],float arr2 [2][2])
{
float add [2][2]={0} ;
{for (int i=0;i<2;i++)
   for (int j=0;j<2;j++)
    add [i][j]= arr1[i][j]+ arr2 [i][j];}
 print_matrix2 (add);
}
void add_matrix3 (float arr1 [3][3],float arr2 [3][3])
{
float add [3][3]={0} ;
{for (int i=0;i<3;i++)
   for (int j=0;j<3;j++)
    add [i][j]= arr1[i][j]+ arr2 [i][j];}
  print_matrix3 (add);
}
void subt_matrix2 (float arr1 [2][2],float arr2 [2][2])
{
float subt [2][2] ;
{for (int i=0;i<2;i++)
   for (int j=0;j<2;j++)
    subt [i][j]= arr1[i][j]- arr2 [i][j];}
    print_matrix2 (subt);
}
void subt_matrix3 (float arr1 [3][3],float arr2 [3][3])
{
float subt [3][3] ;
{for (int i=0;i<3;i++)
   for (int j=0;j<3;j++)
    subt [i][j]= arr1[i][j]- arr2 [i][j];}
    print_matrix3 (subt);
}
void prd_matrix2 (float arr1 [2][2],float arr2 [2][2])
{
    float prd[2][2]= {0};
{for (int i=0;i<2;i++)
   for (int j=0;j<2;j++)
    for (int k=0; k<2;k++)
        prd [i][j]+= arr1[i][k]*arr2[k][j];
    }
    print_matrix2 (prd);
}
void prd_matrix3 (float arr1 [3][3],float arr2 [3][3])
{
    float prd[3][3]= {0};
{for (int i=0;i<3;i++)
   for (int j=0;j<3;j++)
    for (int k=0; k<3;k++)
        prd [i][j]+= arr1[i][k]*arr2[k][j];
    }
   print_matrix3 (prd);
}
float det_matrix3 (float arr [3][3]){
   float det =0.0;
{for (int i=0;i<3;i++)
    det +=( arr[0][i]*((arr[1][(i+1)%3]*arr[2][(i+2)%3])-(arr[1][(i+2)%3]*arr[2][(i+1)%3])));
}
return  det;
}
float det_matrix2(float arr [2][2])
{
   float det = arr [0][0]*arr [1][1]-arr[0][1]*arr [1][0];

    return det;
}
void inv_matrix3 (float arr [3][3])
{
    if (det_matrix3 (arr )==0)
        cout<<"NO INVERSE FOR THIS MATRIX";
        else
   {

    float inv [3][3] = {0};
     for (int i=0;i<3;i++)
   for (int j=0;j<3;j++)
       inv [i][j]= ((arr[(j+1)%3][(i+1)%3]*arr[(j+2)%3][(i+2)%3])-(arr[(j+1)%3][(i+2)%3]*arr[(j+2)%3][(i+1)%3]))/ (det_matrix3 (arr ));
       print_matrix3 (inv);
   }
}
void inv_matrix2 (float arr [2][2])
{ if (det_matrix2 (arr )==0)
        cout<<"NO INVERSE FOR THIS MATRIX";
        else {
    float inv[2][2];
    inv [0][0]= arr[1][1]/det_matrix2 (arr);
    inv [0][1]= - arr[0][1]/det_matrix2 (arr);
    inv [1][1]= arr[0][0]/det_matrix2 (arr);
    inv [1][0]= - arr[1][0]/det_matrix2 (arr);
    print_matrix2 (inv);}}





