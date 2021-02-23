#pragma once

#include <vector>
#include "CStudent.h"
using namespace std;


class CCourse
{
public:
   void add_student();
   void print_student();
   void edit_student();
   void delete_student();
   void print_one_student(int i);
   void save_file();
   
private:
   vector<CStudent> v_student;
   void data();

};


