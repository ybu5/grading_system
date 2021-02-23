// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>
#include <string>
#include "CCourse.h"
#include "CStudent.h"
#include <fstream>

void print_menu();

CCourse elex;
int main()
{
   using namespace std;
   print_menu();

   while (1)
   {

   }
}


////////////////////////////////////////////////////////////
// Print menu for Grade System 
////////////////////////////////////////////////////////////
void print_menu()
{
   string input;
   while (1)
   {
      //print menu instuctions 
      cout << "\n***********************\n" << "ELEX4618 Grade System, by Yanming Bu" << "\n***********************\n" << "(A)dd student\n" << "(E)dit student\n" << "(P)rint grades\n" <<"(D)elete student\n"<< "(Q)uit\n";

      //wait for user input and branch to function accordingly 
      while (1)
      {
         getline(cin, input);

         if (input.size() == 1)
         {
            if (input[0] == 'A')
            {
               cout << "\n";
               elex.add_student();

               break;
            }
            else if (input[0] == 'E')
            {
               cout << "\n";
               elex.edit_student();
               break;
            }
            else if (input[0] == 'P')
            {
               cout << "\n";
               elex.print_student();
               break;
            }
            else if (input[0] == 'D')
            {
               cout << "/n";
               elex.delete_student();
               break;
            }
            else if (input[0] == 'S')
            {
               cout << "/n";
               elex.save_file();
               break;
            }
            else if (input[0] == 'L')
            {
               cout << "/n";
               //load file
               break;
            }
            else if (input[0] == 'Q')
               break;
            else
            {
               cout << "invaild input\n";
            }
         }
         else
         {
            cout << "invaild input\n";
         }

      }
      if (input.size() == 1)
      {
         if (input[0] == 'Q')
            break;
      }
      else
         cout << "invaild input\n";
      

   }

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
