#include <ClassView.h>

ClassDao *CLASS_DAO = ClassDao::Getinstance();

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

void ClassView::ShowAllClass()
{
    cout << "Id"
         << "\t"
         << "Lop"
         << "\t"
         << "Ten lop"
         << "\t"
         << "Nam"
         << "\t"
         << "Id giao vien chu nhiem" << endl;
    ArrayList<Class> clazzs = CLASS_DAO->GetAll();
    for (int i = 0; i < clazzs.length(); i++)
    {
        cout << clazzs.get(i).Getid() << "\t" << clazzs.get(i).Getlevel() << "\t" << clazzs.get(i).Getname()<< "\t" << clazzs.get(i).Getyear()<< "\t" << clazzs.get(i).Getteacher().Getid() << endl;
    }
}

void ClassView::ShowAClass()
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
        Class *clazz = CLASS_DAO->GetById(id);
        if (clazz == nullptr)
            continue;
        cout << "Id: " << clazz->Getid() << endl;
        cout << "Lop: " << clazz->Getlevel() << endl;
        cout << "Ten lop: " << clazz->Getname() << endl;
        cout << "Nam: " << clazz->Getyear() << endl;
        cout << "Id giao vien chu nhiem: " << clazz->Getteacher().Getid() << endl;
    }
}

void ClassView::CreateClass()
{
    int choice;
    int level;
    string name;
    int year;
    int teacher_id;
    while (true)
    {
        cout << "Nhap lop : ";
        cin >> level;
        cout << "Nhap nam : ";
        cin >> year;
        cout << "Nhap id giao vien chu nhiem: ";
        cin >> teacher_id;
        cin.ignore();
        cout << "Nhap ten lop: ";
        getline(cin, name);
        CLASS_DAO->CreateOne(Class(level, name, year, Teacher(teacher_id, "x", "x", Date(1,JANUARY,1), "x", "x", Subject("x",1))));
        cout << "Ban co muon tao them mon hoc khong(nhap 0 de quay ve menu truoc): ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
    }
}

void ClassView::RemoveClass()
{
    int id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id lop: ";
        cin >> id;
        if (id == 0)
            break;
        CLASS_DAO->RemoveById(id);
    }
}

void ClassView::UpdateClass()
{
    int id;
    int level;
    string name;
    int year;
    int teacher_id;
    cout << "Nhap 0 de quay ve menu truoc." << endl;
    while (true)
    {
        cout << "Nhap id lop: ";
        cin >> id;
        cin.ignore();
        if (id == 0)
            break;
        Class *clazz = CLASS_DAO->GetById(id);
        if (clazz == nullptr)
            continue;
        cout << "Nhap lop : ";
        cin >> level;
        cout << "Nhap nam : ";
        cin >> year;
        cout << "Nhap id giao vien chu nhiem: ";
        cin >> teacher_id;
        cin.ignore();
        cout << "Nhap ten lop: ";
        getline(cin, name);
        CLASS_DAO->UpdateById(id, Class(level, name, year, Teacher(teacher_id, "x", "x", Date(1,JANUARY,1), "x", "x", Subject("x",1))));
    }
}
