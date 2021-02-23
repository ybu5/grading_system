#pragma once

#include <string>

using namespace std;

class CStudent
{
public:
   void put_student_ID(string student_id);
   void put_lab(string lab_mark);
   void put_quiz(string quiz_mark);
   void put_midterm(string midterm_mark);
   void put_final(string final_mark);
   void put_final_final();

   string get_student_id(void);
   float get_lab(void);
   float get_quiz(void);
   float get_midterm(void);
   float get_final(void);
   float get_final_final(void);
private:
   string student_ID;
   float lab;
   float quiz;
   float midterm;
   float final;
   float final_grade;
   
};
