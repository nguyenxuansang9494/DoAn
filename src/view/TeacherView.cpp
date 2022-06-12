#include <TeacherView.h>

TeacherDao *TEACHER_DAO = TeacherDao::Getinstance();

void TeacherView::TeacherMenu()
{
    int choice;
    while (true)
    {
        cout << "Quan ly giao vien: " << endl;
        cout << "1. Hien thi tat ca giao vien." << endl;
        cout << "2. Tim giao vien theo id." << endl;
        cout << "3. Tao giao vien." << endl;
        cout << "4. Chinh sua giao vien." << endl;
        cout << "5. Xoa giao vien." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            TeacherView::ShowAllTeacher();
            break;
        case 2:
            TeacherView::ShowATeacher();
            break;
        case 3:
            TeacherView::CreateTeacher();
            break;
        case 4:
            TeacherView::UpdateTeacher();
            break;
        case 5:
            TeacherView::RemoveTeacher();
            break;
        default:
            break;
        }
    }
}

void TeacherView::ShowAllTeacher()
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
         << "Id mon hoc" << endl;
    ArrayList<Teacher> teachers = TEACHER_DAO->GetAll();
    for (int i = 0; i < teachers.length(); i++)
    {
        Teacher teacher = teachers.get(i);
        cout << teacher.Getid() << '\t' << teacher.Getlast_name() << '\t' << teacher.Getfirst_name() << '\t' << teacher.Getdob().tostring() << '\t' << teacher.Getemail() << '\t' << teacher.Getphone_number() << '\t' << teacher.Getsubject().Getid() << endl;
    }
}

void TeacherView::ShowATeacher()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id giao vien: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Teacher *teacher = TEACHER_DAO->GetById(id);
        if (teacher == nullptr)
            continue;
        cout << "Id: " << teacher->Getid() << endl;
        cout << "Ho: " << teacher->Getlast_name() << endl;
        cout << "Ten: " << teacher->Getfirst_name() << endl;
        cout << "Ngay sinh: " << teacher->Getdob().tostring() << endl;
        cout << "Email: " << teacher->Getemail() << endl;
        cout << "Sodt: " << teacher->Getphone_number() << endl;
        cout << "Id mon hoc: " << teacher->Getsubject().Getid() << endl;
    }
}

void TeacherView::CreateTeacher()
{
    int choice;
    string first_name;
    string last_name;
    string dob;
    string email;
    string sdt;
    int subject_id;
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
        cout << "Nhap id mon hoc : ";
        cin >> subject_id;
        TEACHER_DAO->CreateOne(Teacher(first_name, last_name, Date(dob), email, sdt, Subject(subject_id, "x", 0)));
        cout << "Ban co muon tao them mon hoc khong(nhap 0 de quay ve menu truoc): ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
    }
}

void TeacherView::RemoveTeacher()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id giao vien: ";
        cin >> id;
        if (id == 0)
            break;
        TEACHER_DAO->RemoveById(id);
    }
}

void TeacherView::UpdateTeacher()
{
    int id;
    string first_name;
    string last_name;
    string dob;
    string email;
    string sdt;
    int subject_id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id giao vien: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Teacher *teacher = TEACHER_DAO->GetById(id);
        if (teacher == nullptr)
            continue;
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
        cout << "Nhap id mon hoc : ";
        cin >> subject_id;
        cin.ignore();
        TEACHER_DAO->UpdateById(id, Teacher(first_name, last_name, Date(dob), email, sdt, Subject(subject_id, "x", 0)));
    }
}
