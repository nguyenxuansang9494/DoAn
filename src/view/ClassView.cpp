#include <ClassView.h>

void ClassView::ClassMenu()
{
    int choice;
    while (true)
    {
        cout << "Quan ly lop hoc: " << endl;
        cout << "1. Hien thi tat ca lop hoc." << endl;
        cout << "2. Tim lop hoc theo id." << endl;
        cout << "3. Tao lop hoc." << endl;
        cout << "4. Chinh sua lop hoc." << endl;
        cout << "5. Xoa lop hoc." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            ClassView::ShowAllClass();
            break;
        case 2:
            ClassView::ShowAClass();
            break;
        case 3:
            ClassView::CreateClass();
            break;
        case 4:
            ClassView::UpdateClass();
            break;
        case 5:
            ClassView::RemoveClass();
            break;
        default:
            break;
        }
    }
}

void ClassView::ShowAllClass(){}
void ClassView::ShowAClass(){}
void ClassView::CreateClass(){}
void ClassView::RemoveClass(){}
void ClassView::UpdateClass(){}