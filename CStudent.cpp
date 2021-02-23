#include "CStudent.h"

//using namespace std;
void CStudent::put_student_ID(string student_id)
{
   student_ID = student_id;
}

string CStudent::get_student_id(void)
{
   return student_ID;
}


void CStudent::put_lab(string lab_mark)
{
   lab = ::atof(lab_mark.c_str());
}

float CStudent::get_lab(void)
{
   return lab;
}


void CStudent::put_midterm(string midterm_mark)
{
   midterm = ::atof(midterm_mark.c_str());
}

float CStudent::get_midterm(void)
{
   return midterm;
}


void CStudent::put_quiz(string quiz_mark)
{
   quiz = ::atof(quiz_mark.c_str());
}

float CStudent::get_quiz(void)
{
   return quiz;
}


void CStudent::put_final(string final_mark)
{
   final = ::atof(final_mark.c_str());
}

float CStudent::get_final(void)
{
   return final;

}


void CStudent::put_final_final()
{
   final_grade = 0.4 * lab + 0.1 * quiz + 0.2 * midterm + 0.3 * final;
}

float CStudent::get_final_final(void)
{
   return final_grade;
   //s_array[i].final_grade = 0.4 * s_array[i].lab + 0.1 * s_array[i].quiz + 0.2 * s_array[i].midterm + 0.3 * s_array[i].final;
}