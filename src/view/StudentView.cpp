#include <StudentView.h>

StudentDao *STUDENT_DAO = StudentDao::Getinstance();

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

void StudentView::ShowAllStudent()
{
    cout << "Id"
         << "\t"
         << "Ho"
         << "\t"
         << "Ten"
         << "\t"
         << "Ngay sinh"
         << "\t"
         << "Email"
         << "\t"
         << "Sodt"
         << "\t"
         << "Id lop hoc" << endl;
    ArrayList<Student> students = STUDENT_DAO->GetAll();
    for (int i = 0; i < students.length(); i++)
    {
        Student student = students.get(i);
        cout << student.Getid() << '\t' << student.Getlast_name() << '\t' << student.Getfirst_name() << '\t' << student.Getdob().tostring() << '\t' << student.Getemail() << '\t' << student.Getphone_number() << '\t' << student.Getstudentclass().Getid() << endl;
    }
}

void StudentView::ShowAStudent()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Student *student = STUDENT_DAO->GetById(id);
        if (student == nullptr)
            continue;
        delete student;
        cout << "Id: " << student->Getid() << endl;
        cout << "Ho: " << student->Getlast_name() << endl;
        cout << "Ten: " << student->Getfirst_name() << endl;
        cout << "Ngay sinh: " << student->Getdob().tostring() << endl;
        cout << "Email: " << student->Getemail() << endl;
        cout << "Sodt: " << student->Getphone_number() << endl;
        cout << "Id lop hoc: " << student->Getstudentclass().Getid() << endl;
    }
}

void StudentView::CreateStudent()
{
    int choice;
    string first_name;
    string last_name;
    string dob;
    string email;
    string sdt;
    int clazz_id;
    while (true)
    {
        cout << "Nhap ho : ";
        getline(cin, last_name);
        cout << "Nhap ten : ";
        getline(cin, first_name);
        cout << "Nhap ngay sinh : ";
        getline(cin, dob);
        cout << "Nhap email : ";
        getline(cin, email);
        cout << "Nhap sdt : ";
        getline(cin, sdt);
        cout << "Nhap id lop hoc : ";
        cin >> clazz_id;
        Class clazz;
        clazz.Setid(clazz_id);
        STUDENT_DAO->CreateOne(Student(first_name, last_name, Date(dob), email, sdt, clazz));
        cout << "Ban co muon tao them hoc sinh khong(nhap 0 de quay ve menu truoc): ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
    }
}

void StudentView::RemoveStudent()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> id;
        if (id == 0)
            break;
        STUDENT_DAO->RemoveById(id);
    }
}

void StudentView::UpdateStudent()
{
    int id;
    string first_name;
    string last_name;
    string dob;
    string email;
    string sdt;
    int clazz_id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id hoc sinh: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Student *student = STUDENT_DAO->GetById(id);
        if (student == nullptr)
            continue;
        delete student;
        cout << "Nhap ho : ";
        getline(cin, last_name);
        cout << "Nhap ten : ";
        getline(cin, first_name);
        cout << "Nhap ngay sinh : ";
        getline(cin, dob);
        cout << "Nhap email : ";
        getline(cin, email);
        cout << "Nhap sdt : ";
        getline(cin, sdt);
        cout << "Nhap id lop hoc : ";
        cin >> clazz_id;
        cin.ignore();
        Class clazz;
        clazz.Setid(clazz_id);
        STUDENT_DAO->UpdateById(id, Student(first_name, last_name, Date(dob), email, sdt, clazz));
    }
}
