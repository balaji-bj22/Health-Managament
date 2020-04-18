#include<iostream>
#include<cstring>
#include<string.h>
#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<dos.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
class health
{
protected:
    float ht,wt,bmi,bmr,intake,met,burnt,time,total;
    int age,activity,level,dd,mm,yy,cd,cm,cy,id;
    char gender[10],elevel[3];
    string name,blood;
public:
    health()
    {
        total=0;
        cd=5;
        cm=5;
        cy=2018;
        id=1000;
    }
    void getdata()
    {
        cout<<"Let me know about you  \n";
        PlaySound(TEXT("Audio/LET ME.wav"),NULL,SND_ASYNC);
        cout<<"Enter your name \n";
        while(name=="\0")
            getline(cin,name);
        transform(name.begin(),name.end(),name.begin(), ::toupper);
        cout<<"Enter your date of birth in dd mm yyyy \n";
        cin>>dd>>mm>>yy;
        if(mm<cm)
            age=cy-yy;
        else if(mm>cm)
            age=cy-yy-1;
        cout<<"Enter the blood group \n";
        cin>>blood;
        cout<<"Enter your gender as MALE or FEMALE \n";
        cin>>gender;
        strcpy(gender,strupr(gender));
        cout<<"Enter your weight in KG \n";
        cin>>wt;
        cout<<"Enter your height in cm \n";
        cin>>ht;
        cout<<"Do you exercise daily? \n Enter YES or NO \n";
        cin>>elevel;
        strcpy(elevel,strupr(elevel));
        if(strcmp(elevel,"YES")==0)
       {
           PlaySound(TEXT("Audio/GOOD HEAR.wav"),NULL,SND_ASYNC);
           Sleep(2000);
           cout<<"Good to hear that you exercise daily. Time for some workout \n";

       }
       else
       {
           PlaySound(TEXT("Audio/TAKE YOUR.wav"),NULL,SND_ASYNC);
           Sleep(2000);
           cout<<"Take your first step in Physical fitness. Time for some workout \n";

       }
    }
    void generate_id()
    {
        fstream f;
        string line;
        f.open("Patient.txt");
         f.seekg(0,ios::beg);
          getline(f,line);
             if(line.c_str()=="/0")
             {
                 id=1000;
             }
             else
             {
                 while(!f.eof())
                 {
                     for(int i=0;i<12&&getline(f,line);i++)
                     {

                     }
                     id=id+1;
                 }
             }
    }
    friend void bmi_calc(health &a);
    void bmr_calc()
    {
        if(strcmp(gender,"MALE")==0)
        {
            bmr=66.47+(13.7*wt)+(5*ht)-(6.8*age);
        }
        else
        {
            bmr=655+(9.6*wt)+(1.8*ht)-(4.7*age);
        }
        if(strcmp(gender,"MALE")==0)
        {
            intake=1.725*bmr;
        }
        else if(strcmp(gender,"FEMALE")==0)
        {
            intake=1.2*bmr;
        }

    }
    void calories()
    {

       cout<<"Choose any one activity listed below \n  1 for Walking\n  2 for WeightLifting\n  3 for Dancing\n  4 for Bicycling\n  5 for Swimming\n  6 for Jogging\n  7 for Running \n";
       cin>>activity;
       cout<<"Enter the level of your activity\n1 for LIGHT\n2 for MODERATE\n3 for VIGOROUS \n";
       cin>>level;
       if(activity==1)
       {
           met=2.5;
       }
       else if(activity==2)
       {
           met=3.5;
       }
       else if(activity==3)
       {
           met=3;
       }
       else if(activity==4)
       {
           met=4;
       }
       else if(activity==5)
       {
           met=5;
       }
       else if(activity==6)
       {
           met=6;
       }
       else if(activity==7)
       {
           met=8;
       }
       if(level==2)
       {
           met=met+2;
       }
       else if(level==3)
       {
           met=met+3.5;
       }

       cout<<"Enter your duration of activity in hr\n";
       cin>>time;
       PlaySound(TEXT("Audio/CONGRATS.wav"),NULL,SND_ASYNC);
       burnt=met*wt*time;
       total=total+burnt;
        Sleep(3000);
       cout<<"Congrats! ";
       Sleep(1000);
       cout<<"You have burnt "<<total<<" calories \n";
    }
    friend ostream &operator<<(ostream &out,health h);

    void to_file()
    {
         fstream f,g;
         f.open("Patient.txt");
         f.seekg(0,ios::end);
         f<<endl<<id<<endl<<name<<endl<<dd<<" "<<mm<<" "<<yy<<endl<<age<<endl<<blood<<endl<<gender<<endl<<wt<<endl<<ht<<endl<<bmi<<endl<<bmr<<endl<<intake<<endl;
         g.open("Calorie.txt");
         g.seekg(0,ios::end);
         g<<endl<<id<<endl<<name<<endl<<total<<endl;
         Sleep(3000);
         cout<<"Your report is saved successfully \n";
         PlaySound(TEXT("Audio/RECORD SAVED.wav"),NULL,SND_ASYNC);
         Sleep(3000);
    }
    void to_file1()
    {
         fstream g;
         g.open("Calorie.txt");
         g.seekg(0,ios::end);
         g<<endl<<id<<endl<<name<<endl<<total<<endl;
         PlaySound(TEXT("Audio/RECORD SAVED.wav"),NULL,SND_ASYNC);
         Sleep(3000);
         cout<<"Your report is saved successfully \n";

    }
    int ofile(int id)
    {
        int f1=0;
        string line;
        fstream f,g;
        int check;
        f.open("Patient.txt");
        f.seekg(0,ios::beg);
        g.open("Calorie.txt");
        g.seekg(0,ios::beg);

            while(!f.eof())
        {
            for(int i=0;getline(f,line);i++)
            {
                sscanf(line.c_str(),"%d",&check);
                if(id==check)
             {
                 f1=1;
                     PlaySound(TEXT("Audio/FOUND RECORD.wav"),NULL,SND_ASYNC);
                     Sleep(2000);
                cout<<"ID : "<<line<<endl;
                getline(f,line);
                cout<<"NAME : "<<line<<endl;
                getline(f,line);
                cout<<"DOB : "<<line<<endl;
                getline(f,line);
                cout<<"AGE : "<<line<<endl;
                getline(f,line);
                cout<<"BLOOD GROUP : "<<line<<endl;
                getline(f,line);
                cout<<"GENDER : "<<line<<endl;
                getline(f,line);
                sscanf(line.c_str(),"%f",&wt);
                cout<<"WEIGHT : "<<wt<<endl;
                getline(f,line);
                cout<<"HEIGHT : "<<line<<endl;
                getline(f,line);
                cout<<"BMI : "<<line<<endl;
                getline(f,line);
                cout<<"BMR : "<<line<<endl;
                getline(f,line);
                cout<<"CALORIE REQUIREMENT : "<<line<<endl;
            }
            }

          }
          while(!g.eof())
          {
              for(int i=0;getline(g,line);i++)
            {

                sscanf(line.c_str(),"%d",&check);
                if(id==check)
                {
                    getline(g,line);
                    getline(g,line);
                    getline(g,line);
                    cout<<"TOTAL CALORIES BURNT : "<<line<<endl;
                    sscanf(line.c_str(),"%f",&total);
                }
            }
          }
          return f1;

        }
        ~health()
        {

        }

};
ostream &operator<<(ostream &out,health h)
{
        out<<"\nNAME :"<<h.name<<"\nID : "<<h.id<<"\nDATE OF BIRTH :"<<h.dd<<" "<<h.mm<<" "<<h.yy<<endl<<"AGE :"<<h.age<<"\nBLOOD GROUP : "<<h.blood;
        out<<"\nGENDER :"<<h.gender<<endl;
        out<<"HEIGHT :"<<h.ht<<" cm \n"<<"WEIGHT :"<<h.wt<<" kg \n";
        if(h.bmi<19)
        {
            PlaySound(TEXT("Audio/UNDERWEIGHT.wav"),NULL,SND_ASYNC);
            Sleep(3000);
            out<<"Your BMI is "<<h.bmi<<". \n";
            out<<"You are severely underweight. Eat well to achieve healthy life \n";

        }
        else if(h.bmi>26)
        {
            PlaySound(TEXT("Audio/OBESE.wav"),NULL,SND_ASYNC);
            Sleep(3000);
            out<<"Your BMI is "<<h.bmi<<". \n";
            Sleep(1000);
            out<<"You are obese. Do regular exercise for healthy life \n";

        }
        else
        {
            PlaySound(TEXT("Audio/HEALTHY.wav"),NULL,SND_ASYNC);
            Sleep(3000);
            out<<"Your BMI is "<<h.bmi<<endl;
            Sleep(1000);
            out<<"You have a healthy weight. \n";

        }
        PlaySound(TEXT("Audio/PROP DIET.wav"),NULL,SND_ASYNC);
        Sleep(3000);
        out<<"Your BMR is "<<h.bmr<<". So your daily calorie requirement is "<<h.intake<<" calories \n";
        out<<"Have a proper diet to meet up your calorie requirement \n";


}
void bmi_calc(health &a)
   {

        a.bmi=a.wt/((a.ht*a.ht)/10000);
    }

main()
{
    PlaySound(TEXT("Audio/HI.wav"),NULL,SND_ASYNC);
    health a;
    int id,q;
    char wish[10];
    string name1;
    cout<<"Hi! I am Jarvis..." ;
    Sleep(3000);
    cout<<"Your Personal health manager \n";
    cout<<"Enter 1 to CREATE an new record\n      2 to OPEN an existing record \n";
    cin>>q;

    if(q==1)
    {
        a.getdata();
        a.generate_id();
        bmi_calc(a);
        a.bmr_calc();
        a.calories();
        PlaySound(TEXT("Audio/NOW TIME.wav"),NULL,SND_ASYNC);
        Sleep(2500);
        cout<<"\nNow the time for your result \n";
        cout<<a;
        PlaySound(TEXT("Audio/ENTER SAVE.wav"),NULL,SND_ASYNC);
        Sleep(2000);
        cout<<"Enter SAVE to save your record \n";
        cin>>wish;
        if(strcmp(strupr(wish),"SAVE")==0)
        {
            a.to_file();
        }
        while(1)
        {
            cout<<"Want to burn a few more calories?? \nEnter YES or NO \n";
           Sleep(2000);
           PlaySound(TEXT("Audio/BURN FEW.wav"),NULL,SND_ASYNC);
           cin>>wish;
            if(strcmp(strupr(wish),"NO")==0)
                {
                    break;
                }
                a.calories();
           cout<<"Enter SAVE to save your record or NO to EXIT\n";
           cin>>wish;
           if(strcmp(strupr(wish),"SAVE")==0)
           {
            a.to_file1();
           }
           if(strcmp(strupr(wish),"NO")==0)
           {
               break;
           }
        }

    }
    else if(q==2)
    {
       cout<<"Enter your name and id to search \n";
           PlaySound(TEXT("Audio/HAVE U BACK.wav"),NULL,SND_ASYNC);
       while(name1=="\0")
        getline(cin,name1);
        cin>>id;
       if(a.ofile(id))
       {
           cout<<"Want to burn a few more calories?? \nEnter YES or NO \n";
           Sleep(2000);
       PlaySound(TEXT("Audio/BURN FEW.wav"),NULL,SND_ASYNC);
       cin>>wish;
       while(strcmp(strupr(wish),"YES")==0)
       {
           a.calories();
           cout<<"Enter SAVE to save your record \n";
            PlaySound(TEXT("Audio/ENTER SAVE.wav"),NULL,SND_ASYNC);
           cin>>wish;
        if(strcmp(strupr(wish),"SAVE")==0)
        {
            a.to_file1();
        }
        cout<<"Want to burn a few more calories?? \nEnter YES or NO \n";
        Sleep(1000);
        PlaySound(TEXT("Audio/BURN FEW.wav"),NULL,SND_ASYNC);
        cin>>wish;
        if(strcmp(strupr(wish),"NO")==0)
        {
            PlaySound(TEXT("Audio/BYE.wav"),NULL,SND_ASYNC);
            Sleep(3000);
            cout<<"BYE \n";
        }
      }

}
}
 else
{
        PlaySound(TEXT("Audio/BYE.wav"),NULL,SND_ASYNC);
    cout<<"Sorry..Wrong input..Try again"<<endl;

}
}


