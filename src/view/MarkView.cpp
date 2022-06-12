#include <MarkView.h>

MarkDao *MARK_DAO = MarkDao::Getinstance();

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

void MarkView::ShowAllMark()
{
    cout << "Id"
         << "\t"
         << "Id hoc sinh"
         << "\t"
         << "Id lop"
         << "\t"
         << "Id mon"
         << "\t"
         << "Diem" << endl;
    ArrayList<Mark> marks = MARK_DAO->GetAll();
    for (int i = 0; i < marks.length(); i++)
    {
        cout << marks.get(i).Getid() << "\t" << marks.get(i).Getstudent().Getid() << "\t" << marks.get(i).Getclazz().Getid() << "\t" << marks.get(i).Getsubject().Getid() << marks.get(i).Getvalue() << endl;
    }
}

void MarkView::ShowAllStudentMark()
{
    int id;
    cout << "Nhap 0 de ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        cout << "Id"
             << "\t"
             << "Id hoc sinh"
             << "\t"
             << "Id lop"
             << "\t"
             << "Id mon"
             << "\t"
             << "Diem" << endl;
        ArrayList<Mark> marks = MARK_DAO->GetAllByStudentId(id);
        for (int i = 0; i < marks.length(); i++)
        {
            cout << marks.get(i).Getid() << "\t" << marks.get(i).Getstudent().Getid() << "\t" << marks.get(i).Getclazz().Getid() << "\t" << marks.get(i).Getsubject().Getid() << marks.get(i).Getvalue() << endl;
        }
    }
}

void MarkView::ShowAllStudentSubjectMark()
{
    int student_id;
    int subject_id;
    cout << "Nhap 0 de ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> student_id;
        cout << "Nhap id mon hoc: ";
        cin >> subject_id;
        cin.ignore();
        if (student_id * subject_id == 0)
            break;
        cout << "Id"
             << "\t"
             << "Id hoc sinh"
             << "\t"
             << "Id lop"
             << "\t"
             << "Id mon"
             << "\t"
             << "Diem" << endl;
        ArrayList<Mark> marks = MARK_DAO->GetAllByStudentAndSubjectId(student_id, subject_id);
        for (int i = 0; i < marks.length(); i++)
        {
            cout << marks.get(i).Getid() << "\t" << marks.get(i).Getstudent().Getid() << "\t" << marks.get(i).Getclazz().Getid() << "\t" << marks.get(i).Getsubject().Getid() << marks.get(i).Getvalue() << endl;
        }
    }
}

void MarkView::ShowAStudentSubjectClassMark()
{
    int student_id;
    int subject_id;
    int class_id;
    cout << "Nhap 0 de ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> student_id;
        cout << "Nhap id mon hoc: ";
        cin >> subject_id;
        cout << "Nhap id lop hoc: ";
        cin >> class_id;
        cin.ignore();
        if (student_id * subject_id * class_id== 0)
            break;
        Mark *rs = MARK_DAO->GetByStudentAndSubjectIdAndClassId(student_id, subject_id, class_id);
        if (rs == nullptr)
            continue;
        delete rs;
        cout << "Id: " << rs->Getid() << endl; 
        cout << "Id hoc sinh: " << rs->Getstudent().Getid() << endl; 
        cout << "Id mon hoc: " << rs->Getsubject().Getid() << endl; 
        cout << "Id lop hoc: " << rs->Getclazz().Getid() << endl; 
        cout << "Diem: " << rs->Getvalue() << endl; 
    }
}

void MarkView::CreateMark()
{
    int choice;
    int student_id;
    int subject_id;
    int class_id;
    int value;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> student_id;
        cout << "Nhap id mon hoc: ";
        cin >> subject_id;
        cout << "Nhap id lop hoc: ";
        cin >> class_id;
        cout << "Nhap diem: ";
        cin >> value;
        cin.ignore();
        Student student;
        Subject subject;
        Class clazz;
        student.Setid(student_id);
        subject.Setid(subject_id);
        clazz.Setid(class_id);
        MARK_DAO->CreateOne(Mark(student, clazz, subject, value));
        cout << "Ban co muon tao them mon hoc khong(nhap 0 de quay ve menu truoc): ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
    }
}

void MarkView::RemoveMark()
{
    int student_id;
    int subject_id;
    int class_id;
    cout << "Nhap 0 de ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> student_id;
        cout << "Nhap id mon hoc: ";
        cin >> subject_id;
        cout << "Nhap id lop hoc: ";
        cin >> class_id;
        cin.ignore();
        if (student_id * subject_id * class_id== 0)
            break;
        MARK_DAO->RemoveByStudentAndSubjectIdAndClassId(student_id, subject_id, class_id);
    }
}

void MarkView::UpdateMark()
{
    int student_id;
    int subject_id;
    int class_id;
    int value;
    cout << "Nhap 0 de ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> student_id;
        cout << "Nhap id mon hoc: ";
        cin >> subject_id;
        cout << "Nhap id lop hoc: ";
        cin >> class_id;
        cin.ignore();
        if (student_id * subject_id * class_id== 0)
            break;
        Mark *rs = MARK_DAO->GetByStudentAndSubjectIdAndClassId(student_id, subject_id, class_id);
        if (rs == nullptr)
            continue;
        delete rs;
        cout << "Nhap diem: ";
        cin >> value;
        MARK_DAO->UpdateByStudentAndSubjectIdAndClassId(student_id, subject_id, class_id, value);
    }
}
