#include <SubjectView.h>

SubjectDao *SUBJECT_DAO = SubjectDao::Getinstance();

void SubjectView::SubjectMenu()
{
    int choice;
    while (true)
    {
        cout << "Quan ly mon hoc: " << endl;
        cout << "1. Hien thi tat ca mon hoc." << endl;
        cout << "2. Tim mon hoc theo id." << endl;
        cout << "3. Tao mon hoc." << endl;
        cout << "4. Chinh sua mon hoc." << endl;
        cout << "5. Xoa mon hoc." << endl;
        cout << "0. Thoat." << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            SubjectView::ShowAllSubject();
            break;
        case 2:
            SubjectView::ShowASubject();
            break;
        case 3:
            SubjectView::CreateSubject();
            break;
        case 4:
            SubjectView::UpdateSubject();
            break;
        case 5:
            SubjectView::RemoveSubject();
            break;
        default:
            break;
        }
    }
}

void SubjectView::ShowAllSubject()
{
    cout << "Id"
         << "\t"
         << "Ten Mon"
         << "\t"
         << "Lop" << endl;
    ArrayList<Subject> subjects = SUBJECT_DAO->GetAll();
    for (int i = 0; i < subjects.length(); i++)
    {
        cout << subjects.get(i).Getid() << "\t" << subjects.get(i).Getname() << "\t" << subjects.get(i).Getgrade() << endl;
    }
}

void SubjectView::ShowASubject()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id mon hoc: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Subject *subject = SUBJECT_DAO->GetById(id);
        if (subject == nullptr)
            continue;
        delete subject;
        cout << "Id: " << subject->Getid() << endl;
        cout << "Ten mon: " << subject->Getname() << endl;
        cout << "Lop: " << subject->Getgrade() << endl;
    }
}

void SubjectView::CreateSubject()
{
    int choice;
    string name;
    int grade;
    while (true)
    {
        cout << "Nhap ten mon hoc : ";
        getline(cin, name);
        cout << "Nhap lop cua mon hoc: ";
        cin >> grade;
        SUBJECT_DAO->CreateOne(Subject(name, grade));
        cout << "Ban co muon tao them mon hoc khong(nhap 0 de quay ve menu truoc): ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
    }
}

void SubjectView::RemoveSubject()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id mon hoc: ";
        cin >> id;
        if (id == 0)
            break;
        SUBJECT_DAO->RemoveById(id);
    }
}

void SubjectView::UpdateSubject()
{
    int id;
    string name;
    int grade;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id mon hoc: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Subject *subject = SUBJECT_DAO->GetById(id);
        if (subject == nullptr)
            continue;
        delete subject;
        cout << "Nhap ten mon hoc: ";
        getline(cin, name);
        cout << "Nhap lop mon hoc: ";
        cin >> grade;
        cin.ignore();
        SUBJECT_DAO->UpdateById(id, Subject(name, grade));
    }
}
