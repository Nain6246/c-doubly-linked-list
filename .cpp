#include <iostream>
using namespace std;

struct student
{
   string data;
   int roll_no;

   student *next;
   student *pre;
};

class dsa
{
private:
   student *header;
   student *tailer;

public:
   int count = 0;
   dsa()
   {
      header = new student;
      tailer = new student;

      header->next = tailer;
      header->data = "\0";
      header->pre = NULL;
      header->roll_no = 0;

      tailer->next = NULL;
      tailer->pre = header;
      tailer->data = "\0";
      tailer->roll_no = 0;
   }
   ~dsa()
   {

      while (header->next != tailer)
      {
         header->next = header->next->next;
         delete header->next->pre;
         header->next->pre = NULL;
         count--;
      }
      delete header;
      delete tailer;
      header = NULL;
      tailer = NULL;
      count = 0;
   }
   void add_student(student *existing_node, int roll1, string data1)
   {
      student *new_node = new student;
      new_node->roll_no = roll1;
      new_node->data = data1;

      new_node->next = existing_node;
      new_node->pre = existing_node->pre;

      existing_node->pre->next = new_node;
      existing_node->pre = new_node;
   }
   void add_front()
   {
      int no;
      cout << "Enter no :";
      cin >> no;
      count++;
      add_student(header->next, no, "A");
   }
   void add_back()
   {
      int no;
      cout << "Enter no :";
      cin >> no;
      count++;
      add_student(tailer, no, "B");
   }
   void diplay_data()
   {
      student *temp = header->next;
      cout << "\tName \tRoll_no" << endl;
      int no = count;
      for (int i = 0; i < no; i++)
      {

         cout << "\t" << temp->data << "\t" << temp->roll_no << endl;
         temp = temp->next;
      }
      cout << "Total student :" << count << endl;
   }
   student *find_student_by_roll_no(int roll_no_find)
   {

      if (header->next != NULL)
      {
         student *temp = header->next;
         while (temp->roll_no != roll_no_find && temp->next != tailer)
         {
            temp = temp->next;
         }
         if (temp->roll_no == roll_no_find)
            return temp;
      }
      return NULL;
   }
   void insert_before_existing_student(string new_name, int new_roll)
   {
      int roll;
      cout << "Enter roll no for insertion before :";
      cin >> roll;
      student *temp = find_student_by_roll_no(roll);
      if (temp == NULL)
      {
         cout << "Roll no are not exist :" << endl;
         return;
      }
      add_student(temp, new_roll, new_name);
      count++;
   }

   void deletion(student *node_deletion)
   {
      node_deletion->pre->next = node_deletion->next;
      node_deletion->pre = node_deletion->pre->next;
   }
   void deletion_by_roll_no(int roll)
   {
      student *temp = header;
      while (temp != NULL)
      {
         if (temp->roll_no == roll)
         {
            count--;
            deletion(temp);
            return;
         }
         temp = temp->next;
      }
   }
   void del_front()
   {
      count--;
      deletion(header->next);
   }
   void del_back()
   {
      count--;
      deletion(tailer->pre);
   }
};
int main()
{
   dsa obj;
   obj.add_front();
   obj.add_back();
   obj.add_back();
   obj.add_back();
   obj.add_back();
   obj.diplay_data();
   cout << "Delete front " << endl;
   obj.del_front();

   obj.insert_before_existing_student("H", 9);
   obj.diplay_data();
   cout << "Delete back " << endl;
   obj.del_back();
   obj.diplay_data();

   cout << "specific location " << endl;
   obj.deletion_by_roll_no(90);
   obj.diplay_data();
}
