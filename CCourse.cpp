#include "CCourse.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>
#include <fstream>

bool check_student_number(string str);
bool check_grade(string str);
string removeSpace(string str);

//using namespace std;

//void data(int i);

//int student_num = 0;

CStudent student_info;



////////////////////////////////////////////////////////////
// Add student info
////////////////////////////////////////////////////////////
void CCourse::add_student()
{
   cout << "Adding student\n";
   data();
   v_student.push_back(student_info);
}

////////////////////////////////////////////////////////////
// Print all student info 
////////////////////////////////////////////////////////////
void CCourse::print_student()
{
   ostringstream stream_title;
   stream_title << setfill(' ') << setw(5) << "#" << setw(15) << "student" << setw(10) << "Lab" << setw(10) << "Quiz" << setw(10) << "Midterm" << setw(15) << "Final Exam" << setw(15) << "Final Grade";
   cout << stream_title.str() << endl;
   stream_title.str(" ");
   stream_title.clear();
   
   int i;
   for (i = 0; i < v_student.size(); i++)
   {
      print_one_student(i);
   }

   //cout << CCourse::v_student[i].get_final;
   //cout << CCourse::v_student[1].CStudent::get_final;
}

void CCourse::print_one_student(int i)
{
   ostringstream stream;
   string print_id = CCourse::v_student[i].get_student_id();
   float print_lab = CCourse::v_student[i].get_lab();
   float print_quiz = CCourse::v_student[i].get_quiz();
   float print_midterm = CCourse::v_student[i].get_midterm();
   float print_final = CCourse::v_student[i].get_final();
   float print_final_final = CCourse::v_student[i].get_final_final();

   stream << setfill(' ') << setw(5) << i+1 << setw(15) << print_id << setprecision(3) << setw(10) << print_lab << setw(10) << print_quiz << setw(10) << print_midterm << setw(15) << print_final << setw(15) << setprecision(4) << print_final_final;
   cout << stream.str() << endl;
   stream.str(" ");
   stream.clear();
}

////////////////////////////////////////////////////////////
// Edit student info according to user input 
////////////////////////////////////////////////////////////
void CCourse::edit_student()
{
   int i;
   cout << "Student to edit: ";
   cin >> i;
   data();
   v_student.at(i - 1) = student_info;

}

////////////////////////////////////////////////////////////
// Modify info in the structure 
////////////////////////////////////////////////////////////
void CCourse::data()
{
   string student_ID, lab, quiz, midterm, final;

   cout << "Student Number:";
   
   //from https://stackoverflow.com/questions/10553597/cin-and-getline-skipping-input

   do
   {
      
      getline(cin, student_ID);
      cout << "what" << endl;
      student_ID = removeSpace(student_ID);
   } while (check_student_number(student_ID) == false);
   
   student_info.put_student_ID(student_ID);

   cout << "Lab Grade:";
   do
   {
      getline(cin, lab);
      lab = removeSpace(lab);
   } while (check_grade(lab) == false);

   student_info.put_lab(lab);

   cout << "Quiz Grade:";
   do
   {
      getline(cin, quiz);
      quiz = removeSpace(quiz);
   } while (check_grade(quiz) == false);

   student_info.put_quiz(quiz);

   cout << "Midterm Grade:";
   do
   {
      getline(cin, midterm);
      midterm = removeSpace(midterm);
   } while (check_grade(midterm) == false);

   student_info.put_midterm(midterm);

   cout << "Final Grade:";
   do
   {
      getline(cin, final);
      final = removeSpace(final);
   } while (check_grade(final) == false);

   student_info.put_final(final);

   student_info.put_final_final();
}

void CCourse::delete_student()
{
   string delete_num;
   cout << "Student to be delete: " << endl;
   getline(cin, delete_num);
   v_student.erase(v_student.begin() + (stoi(delete_num) - 1));
}

void CCourse::save_file()
{
   string file_name;
   cout << "Please Enter A FileName:";
   getline(cin, file_name);
   std::ofstream output(file_name);
   //for (int i = 0; i < CCourse::v_student.size(); i++) {
   //   output << CCourse::v_student[i].getid() << " " << CCourse::v_student[i].get_lab() << " " << CCourse::v_student[i].get_quiz() << " " << CCourse::list_of_students[i].get_midterm() << " " << CCourse::list_of_students[i].get_final() << endl;
   //}
   output.close();
   cout << "Student List Saved In File:   " << file_name << endl;
}

bool check_student_number(string str)
{
   regex student_number("(A)([0])([0-1])([0-9]+)");


   if (str.size() == 9)
   {
      if (regex_match(str, student_number))
         return 1;
      else
      {
         cout << "invaild input\n";
         return 0;
      }
   }
   else
   {
      cout << "invaild input\n";
      return 0;
   }
}

bool check_grade(string grade)
{
   regex check_dot("(\\.)");
   regex check_num("([0-9]+)");
   regex check_100("([1])([0])([0])(\\.)([0]+)");
   regex check_less_100("([0]?)([0-9]?)([0-9]?)(\\.)([0-9]+)");

   float final_grade = ::atof(grade.c_str());


   if (regex_search(grade, check_dot))
   {
      if (regex_match(grade, check_100))
         return 1;
      else if (regex_match(grade, check_less_100))
         return 1;
      else
      {
         cout << "invaild input\n";
         return 0;
      }
   }
   else if (regex_match(grade, check_num))
   {
      if (grade.size() <= 2)
         return 1;
      else if (grade.size() == 3 && final_grade == 100)
         return 1;
      else
      {
         cout << "invaild input\n";
         return 0;
      }
   }
   else
   {
      cout << "invaild input\n";
      return 0;
   }
}

//////////////////////////////////////////////////////////////
/////got it from https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
//////////////////////////////////////////////////////////////
string removeSpace(string str)
{
   str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
   return str;
}