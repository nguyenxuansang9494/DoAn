#include <StudentView.h>

void StudentView::StudentMenu()
{
    int choice;
    while (true)
    {
        cout << "Quan ly hoc sinh: " << endl;
        cout << "1. Hien thi tat ca hoc sinh." << endl;
        cout << "2. Tim hoc sinh theo id." << endl;
        cout << "3. Tao hoc sinh." << endl;
        cout << "4. Chinh sua hoc sinh." << endl;
        cout << "5. Xoa hoc sinh." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            StudentView::ShowAllStudent();
            break;
        case 2:
            StudentView::ShowAStudent();
            break;
        case 3:
            StudentView::CreateStudent();
            break;
        case 4:
            StudentView::UpdateStudent();
            break;
        case 5:
            StudentView::RemoveStudent();
            break;
        default:
            break;
        }
    }
}


void StudentView::ShowAllStudent(){}
void StudentView::ShowAStudent(){}
void StudentView::CreateStudent(){}
void StudentView::RemoveStudent(){}
void StudentView::UpdateStudent(){}