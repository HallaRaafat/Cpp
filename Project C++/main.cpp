#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

float  mean (int arr [200],int i); // to calculate mean of arrays
float  standev (int arr [200],int i); // To calculate standard deviation
void GPA_PER(string arr[200], int i); // percentage of each grade


class Student {
private :
string col[200];
string cell,line,file,ID[200],lines , name[200],age[200],gender[200],Gmath[200],Gphy[200],Gdraw[200],Gcomp[200],Gchem[200] ;
int math[200],phy [200],draw[200],comp[200],chem [200],i;
float Nmath[200],Nphy [200],Ndraw[200],Ncomp[200],Nchem [200];
float Mm ,Mp,Md,Mc,Mch,Sm,Sp,Sd,Sc,Sch; // M for Mean S for Standard deviation and m=math p= phy ....
public :


      void import_grades () // file name then extract arrays for each column

    {

    cout <<"Enter grade's file name"<< endl ;
    cin >> file ;
    ifstream ifile (file);
    if (ifile.is_open())
    {  getline (ifile,line);
       i=0;
        while (!ifile.eof())
        {
                getline (ifile,line);
                stringstream lines (line) ;
                 int j =0;
            while (!lines.eof() )
                        {
                                              getline (lines,cell,',');
                                              col[j]=cell ;
                                            j++   ;
                        }
        if(!ifile.eof())

       {      ID    [i]=        col [0];
              math  [i]= stoi (col [1]);
               phy  [i]= stoi (col [2]);
               draw [i]= stoi (col [3]);
               comp [i]= stoi (col [4]);
               chem [i]= stoi (col [5]);++i;} }  }
    else cout <<"Unable to find file "<<endl;
    }

      void import_data ()

    {
    cout <<"Enter Data's file name"<< endl ;
    cin >> file ;
    ifstream ifile (file);
    if (ifile.is_open())
    { getline (ifile,line);

        int i=0;
        while (!ifile.eof())
        {getline (ifile,line);
          stringstream lines (line) ;
           int j =0;
            while (!lines.eof() )
                        {                    getline (lines,cell,',');
                                              col[j]=cell ;
                                              j++   ;
                        }
if(!ifile.eof()){ID     [i]= col [0];
              name   [i]= col [1];
              age    [i]= col [2];
             gender  [i]= col [3];i++;}}}
    else cout <<"Unable to find file "<<endl;}

    void normalize ()
    {
      Mm= mean(math,i);
      Sm = standev(math,i);
      for (int x=0;x<i;x++)
    Nmath[x]=((math[x]-Mm)/Sm);


      Mp = mean(phy,i);
      Sp= standev(phy,i);
      for (int x=0;x<i;x++)
    Nphy[x]=((phy[x]-Mp)/Sp);

      Md = mean(draw,i);
      Sd= standev(draw,i);
      for (int x=0;x<i;x++)
    Ndraw[x]=((draw[x]-Md)/Sd);

      Mc = mean(comp,i);
      Sc= standev(comp,i);
      for (int x=0;x<i;x++)
    Ncomp[x]=((comp[x]-Mc)/Sc);

      Mch = mean(chem,i);
      Sch= standev(chem,i);
for (int x=0;x<i;x++)
    Nchem [x]=((chem[x]-Mch)/Sch);
    }

    void export_norm(){

     ofstream ofile ("Normalized_Grades.csv");
    if (ofile.is_open())
    {
           ofile<<"Student Code"<<","<<"Math"<<","<<"Physics"<<","<<"Drawing"<<","<<"Computer"<<","<<"Chemistry"<<endl;
           normalize();
           for (int x = 0 ; x<i;x++)
            ofile<<ID[x]<<","<<Nmath[x]<<","<<Nphy[x]<<","<<Ndraw[x]<<","<<Ncomp[x]<<","<<Nchem[x]<<endl;

        }


    else cout <<"Unable to export file "<<endl;
                   }

    string GPA (int x ){
  if (x<60)
    return  "F";
  else if (x<65 )
     return "D";
      else if (x<70 )
     return "D+";
        else if (x<75 )
     return "C";
      else if (x<80 )
     return "C+";
      else if (x<85 )
     return "B";
      else if (x<90 )
     return "B+";
      else if (x<=100 )
     return "A";
     else cout<<"ERROR";
    }
    void export_GPA ()
    {

          ofstream ofile ("GPA_Grades.csv");
    if (ofile.is_open())
    {
           ofile<<"Student's Code "<<","<<"Math"<<","<<"Physics"<<","<<"Drawing"<<","<<"Computer"<<","<<"Chemistry"<<endl;

           for (int x = 0 ; x<i;x++)
         {

         Gmath[x]=GPA(math[x]);
             Gphy[x]=GPA(phy[x]);
              Gdraw[x]=GPA(draw[x]);
               Gcomp[x]=GPA(comp[x]);
                Gchem[x]=GPA(chem[x]);
            ofile<<ID[x]<<","<< Gmath[x]<<","<<Gphy[x]<<","<<Gdraw[x]<<","<< Gcomp[x]<<","<< Gchem[x]<<endl;
         }
        }


    else cout <<"Unable to export file "<<endl;

    }
    void CODE ()
    {
        string code;
        normalize();
          export_GPA();

        cout<<"Enter student's code : "<<endl;
        cin>> code;

int x;
        for( x=0;x<i;x++)
     {
         if (code.compare(ID[x])==0)
         {
        cout << "Student Code              : " << ID[x]<<endl ;
        cout << "Student Name              : " << name[x]<<endl ;
        cout << "Student Age               : " << age[x]<<endl ;
        cout << "Student Gender            : " << gender[x]<<endl ;
        cout << "Student's Math Score      : " << math[x]<<" ,GPA : "<< Gmath[x]<<" Normalized : "<<Nmath[x]<<endl ;
        cout << "Student's Physics Score   : " << phy[x]<< " ,GPA : "<<Gphy[x] <<" Normalized : "<<Nphy[x]<<endl ;
        cout << "Student's Drawing Score   : " << draw[x]<<" ,GPA : "<<Gdraw[x]<<" Normalized : "<<Ndraw[x]<<endl ;
        cout << "Student's Computer Score  : " << comp[x]<<" ,GPA : "<<Gcomp[x]<<" Normalized : "<<Ncomp[x]<<endl ;
        cout << "Student's Chemistry Score : " << chem[x]<<" ,GPA : "<<Gchem[x]<<" Normalized : "<<Nchem[x]<<endl ;

    break;
         }

     }

       if(x>i) cout<<endl<<"Wrong Code"<<endl;
         }
    void GPA_stat (){
    export_GPA();
    cout<<endl<<"Statistics of Math : " << endl;
     GPA_PER(Gmath,i);
    cout<<endl<<"Statistics of Physics : " << endl;
     GPA_PER(Gphy,i);
    cout<<endl<<"Statistics of Drawing : " << endl;
     GPA_PER(Gdraw,i);
      cout<<endl<<"Statistics of Computer : " << endl;
     GPA_PER(Gcomp,i);
      cout<<endl<<"Statistics of Chemistry : " << endl;
     GPA_PER(Gchem,i);

    }

    }  ;

int main()
{
Student s1;
int no=0;

s1.import_data();
s1.import_grades();
while (no!=5) {
cout<<endl << endl << "( 1 ) Export The Normalized Grades " <<
endl<<"( 2 ) Export The GPA of each grade" <<
endl << "( 3 ) Each course Statistics" <<endl << "( 4 ) Enter student code to get data and grades" <<endl<<"( 5 ) Quit "<<endl
<<endl<<"Please Enter the number of your choice : " <<endl;
cin>> no;
switch (no){

case 5 :
    break;
case 1 :
    s1.export_norm();
    break;
case 2 :
    s1.export_GPA();
     break;
case 3 :
    s1.GPA_stat();
     break;
case 4 :
    s1.CODE();
     break;
default :
    cout<<endl<<"Wrong number please run again  " <<endl;

}
}
    return 0;
}
float  mean (int arr [200],int i)
{


       float sum=0;
       for (int x =0 ; x< i ; x++)
           sum+= arr [x];
           float M=(sum/(i));
       return M ;
}
float  standev (int arr[200],int i)
       {
       float sum=0,M,var;
       M=mean(arr,i);

        for(int x=0;x<i ; x++)
        {
          sum+= pow ((arr[x]-M),2);
        }
        var = (sum / (i));
        return sqrt(var);
    }

void GPA_PER(string arr[200],int i ){
    float A =0  , B =0, BP=0 , C=0 , CP=0 , D=0 , DP=0 , F=0 ,PA,PBP,PB,PC,PCP,PDP,PD,PF;
    for (int x  = 0 ; x< i ; x++)
    {
        if ( arr [x].compare("A")==0)
           {A++; goto eol;}
        else if (arr [x].compare("B+")==0)
           {BP++; goto eol;}
        else if (arr [x].compare("B")==0)
            {B++; goto eol; }
        else if (arr [x].compare("C+")==0)
            {CP++; goto eol; }
         else if (arr [x].compare("C")==0)
            {C++; goto eol; }
         else if (arr [x].compare("D+")==0)
            {DP++; goto eol; }
         else if (arr [x].compare("D")==0)
            {D++; goto eol; }
         else if (arr [x].compare("F")==0)
            {F++; goto eol; }
            else cout << "ERROR"<<endl;
            eol : ;
                }

PA=(A/i)*100;
cout<<"Percentage A = "<<PA << "%"<<endl;
PBP=(BP/i)*100;
cout<<"Percentage B+ = "<<PBP << "%"<<endl;
PB=(B/i)*100;
cout<<"Percentage B = "<<PB << "%"<<endl;
PCP=(CP/i)*100;
cout<<"Percentage C+ = "<<PCP << "%"<<endl;

PC=(C/i)*100;
cout<<"Percentage C = "<<PC << "%"<<endl;
PDP=(DP/i)*100;
cout<<"Percentage D+ = "<<PDP << "%"<<endl;
PD=(D/i)*100;
cout<<"Percentage D = "<<PD << "%"<<endl;
PF=(F/i)*100;
cout<<"Percentage F = "<<PF << "%"<<endl;
    }
