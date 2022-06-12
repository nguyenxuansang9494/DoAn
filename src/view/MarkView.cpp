#include <MarkView.h>

void MarkView::MarkMenu()
{
    int choice;
    while (true)
    {
        cout << "Quan ly diem: " << endl;
        cout << "1. Hien thi tat ca diem." << endl;
        cout << "2. Tim diem theo id hoc sinh." << endl;
        cout << "3. Tim diem theo id hoc sinh va id mon hoc." << endl;
        cout << "4. Tim diem theo id hoc sinh va id mon hoc va id lop hoc." << endl;
        cout << "5. Tao diem." << endl;
        cout << "6. Chinh sua diem." << endl;
        cout << "7. Xoa diem." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            MarkView::ShowAllMark();
            break;
        case 2:
            MarkView::ShowAllStudentMark();
            break;
        case 3:
            MarkView::ShowAllStudentSubjectMark();
            break;
        case 4:
            MarkView::ShowAStudentSubjectClassMark();
            break;
        case 5:
            MarkView::CreateMark();
            break;
        case 6:
            MarkView::UpdateMark();
            break;
        case 7:
            MarkView::RemoveMark();
            break;
        default:
            break;
        }
    }
}


void MarkView::ShowAllMark(){}
void MarkView::ShowAllStudentMark(){}
void MarkView::ShowAllStudentSubjectMark(){}
void MarkView::ShowAStudentSubjectClassMark(){}
void MarkView::CreateMark(){}
void MarkView::RemoveMark(){}
void MarkView::UpdateMark(){}