#include <MainView.h>

void MainView::MainMenu()
{
    int choice;
    while (true)
    {
        cout << "Quan ly truong hoc: " << endl;
        cout << "1. Mon hoc." << endl;
        cout << "2. Giao vien." << endl;
        cout << "3. Lop hoc." << endl;
        cout << "4. Hoc sinh." << endl;
        cout << "5. Diem." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            SubjectView::SubjectMenu();
            break;
        case 2:
            TeacherView::TeacherMenu();
            break;
        case 3:
            ClassView::ClassMenu();
            break;
        case 4:
            StudentView::StudentMenu();
            break;
        case 5:
            MarkView::MarkMenu();
            break;
        default:
            break;
        }
    }
}
