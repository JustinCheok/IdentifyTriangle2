//
//  main.cpp
//  HW2
//
//  Created by Justin Cheok on 9/27/20.
//  Copyright Â© 2020 Justin Cheok. All rights reserved.
//

#include <cstdlib>-
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
//Declaration
void triangle (int a, int b, int c);
void triangle (double a, double b, double c);
void sort (int *num1, int *num2);
void sort(double *num1, double *num2);


int main(int argc, char *argv[]){
//    int a = 0, b = 0, c = 0;
    string userChoice;
    string integer = "-i";
    string doub = "-d";
    cout << "If you want to work with integers type (-i), or doubles type (-d): ";
    cin >> userChoice;

/*USERCHOICE IF THEY -I*/
    if(userChoice == integer){
//        cout << "In integer if statement\n";
            int a = 0, b = 0, c = 0;
        if(argc==1){
            cout<<"Enter 3 Sides of the triangle\n";
            cout <<"a: ";
            cin>>a;
            if(a <= 0){
                cerr << "Must be greater than 0.\n";
                exit(1);
            }
            cout <<"b: ";
            cin>>b;
            if(b <= 0){
                cerr << "Must be greater than 0.\n";
                exit(1);
            }
            cout <<"c: ";
            cin>>c;
            if(c <= 0){
                cerr << "Must be greater than 0.\n";
                exit(1);
            }
        }
    //Checks to see arguments. Error if more or less than 3
   else if( argc<=2 || argc >4 ){
       cerr<<"Invalid Argument Count "<< argc - 1;
       cerr<<"\nEnter 3 Values only" << endl;
       return 1;
   }
        if(argc==4){
            a=atoi(argv[1]);
            b=atoi(argv[2]);
            c=atoi(argv[3]);
        }
            if(a > b){
                sort(&a, &b);
            }
            if(a > c){
                sort(&a, &c);
            }
            if(b > c){
                sort(&b, &c);
            }
        triangle(a,b,c);
    }
    
/* USERCHOICE IF THEY -D */
    else if(userChoice == doub){
        double a = 0.00000, b = 0.0, c = 0.0;

        if(argc==1){
                   cout<<"Enter 3 Sides of the triangle\n";
                   cout <<"a: ";
                   cin >> a;
                   if(a <= 0){
                       cerr << "Must be greater than 0.\n";
                       exit(1);
                   }
                   cout <<"b: ";
                   cin >> b;
                   if(b <= 0){
                       cerr << "Must be greater than 0.\n";
                       exit(1);
                   }
                   cout <<"c: ";
                   cin >> c;
             cout << fixed << setprecision(5);
                   if(c <= 0){
                       cerr << "Must be greater than 0.\n";
                       exit(1);
                   }
               }
           //Checks to see arguments. Error if more or less than 3
          else if( argc<=2 || argc >4 ){
              cerr<<"Invalid Argument Count "<< argc - 1;
              cerr<<"\nEnter 3 Values only" << endl;
              return 1;
          }
               if(argc==4){
                   a=atof(argv[1]);
                   b=atof(argv[2]);
                   c=atof(argv[3]);
               }
                   if(a > b){
                       sort(&a, &b);
                   }
                   if(a > c){
                       sort(&a, &c);
                   }
                   if(b > c){
                       sort(&b, &c);
                   }
               triangle(a,b,c);
        
    }
    else{
        cout << "In else when userChoice nothing was entered\n";
        cout << "In integer if statement\n";
                 int a = 0, b = 0, c = 0;
             if(argc==1){
                 cout<<"Enter 3 Sides of the triangle\n";
                 cout <<"a: ";
                 if(a <= 0){
                     cerr << "Must be greater than 0.\n";
                     exit(1);
                 }
                 cout <<"b: ";
                 cin>>b;
                 if(b <= 0){
                     cerr << "Must be greater than 0.\n";
                     exit(1);
                 }
                 cout <<"c: ";
                 cin>>c;
                 if(c <= 0){
                     cerr << "Must be greater than 0.\n";
                     exit(1);
                 }
             }
         //Checks to see arguments. Error if more or less than 3
        else if( argc<=2 || argc >4 ){
            cerr<<"Invalid Argument Count "<< argc - 1;
            cerr<<"\nEnter 3 Values only" << endl;
            return 1;
        }
             if(argc==4){
                 a=atoi(argv[1]);
                 b=atoi(argv[2]);
                 c=atoi(argv[3]);
             }
                 if(a > b){
                     sort(&a, &b);
                 }
                 if(a > c){
                     sort(&a, &c);
                 }
                 if(b > c){
                     sort(&b, &c);
                 }
             triangle(a,b,c);
         }
return 0;
}


//Sort from smallest to largest integer
void sort(int *num1, int *num2){
    
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//Sort from smallest to largest Double
void sort(double *num1, double *num2){
    
    double temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//Triangle function for Integer
void triangle (int a, int b, int c) {
    cout << a << " " << b << " " << c << " ";
   //CHECK TRIANGLE OR NOT
   if(a+b<c){
       cout<<" Not a Triangle\n" << endl;
       return;
   }
   //Right?
   if(a*a + b*b == c*c)
       cout<<" Right";
   //What triangle
   if(a==b && a==c){
       cout<<" Equilateral Triangle\n" << endl;
   }
   else if(a==b || b==c || c==a){
       cout<<" Isosceles Triangle\n" << endl;
   }
   else if(a!=b && b!=c && c!=a){
       cout<<" Scalene Triangle\n" << endl;
   }
  
}

//Traingle function for double
void triangle (double a, double b, double c) {
    const double EPSILON = 0.001;
    cout << fixed << setprecision(5) << a << " " << b << " " << c << " ";
   //CHECK TRIANGLE OR NOT
   if(a+b<c){
       cout<<" Not a Triangle\n" << endl;
       return;
   }
   if (fabs(a - b) < EPSILON && fabs(b - c) < EPSILON){
               cout << "Equilateral triangle\n";
               return;
    }

    else if (fabs((a * a) - (b * b + c * c)) < EPSILON || fabs((b * b) - (c * c + a * a)) < EPSILON ||fabs((c * c) - (a * a + b * b)) < EPSILON){
               cout << "Right ";
           }
           if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(a - c) < EPSILON){
               cout << "Isosceles triangle\n";
           }
           else{
               cout << "Scalene triangle\n";
           }
}
