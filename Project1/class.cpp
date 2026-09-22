#include <iostream>
#include <windows.h>
using namespace std;
#define Max 1000
void Menu()
{
    cout << "*******************" << endl;
    cout << "** 1. 添加联系人 **" << endl;
    cout << "** 2. 显示联系人 **" << endl;
    cout << "** 3. 删除联系人 **" << endl;
    cout << "** 4. 查找联系人 **" << endl;
    cout << "** 5. 修改联系人 **" << endl;
    cout << "** 6. 清空联系人 **" << endl;
    cout << "** 0. 退出通讯录 **" << endl;
    cout << "*******************" << endl;
}
struct person {
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;

};
struct Addessbooks {
    struct person personarray[Max];
	int m_Size;
};
void addperson(Addessbooks* abs) {
    if (abs->m_Size == Max) {
		cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
		abs->personarray[abs->m_Size].m_Name = name;
		cout << "请输入性别" << endl;
		cout << "1 --- 男   2 --- 女" << endl;
		int sex = 0;
        while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
                abs->personarray[abs->m_Size].m_Sex = sex;
                break;
            }
            else {
                cout << "输入有误，请重新输入" << endl;
            }
        }
		cout << "请输入年龄" << endl;
        int age = 0;
		cin >> age;
		abs->personarray[abs->m_Size].m_Age = age;
        cout << "请输入电话" << endl;
        string numble;
        cin >> numble;
        abs->personarray[abs->m_Size].m_Phone = numble;
        cout << "请输入地址" << endl;
        string address;
        cin >> address;
        abs->personarray[abs->m_Size].m_Addr = address;
    }
	abs->m_Size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}
void showperson(Addessbooks* abs) {
    if (abs->m_Size == 0) {
        cout << "通讯录为空" << endl;
    }
    else {
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "姓名：" << abs->personarray[i].m_Name << "\t";
            cout << "性别：" << (abs->personarray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personarray[i].m_Age << "\t";
            cout << "电话：" << abs->personarray[i].m_Phone << "\t";
            cout << "地址：" << abs->personarray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}
int isExit(Addessbooks*abs,string name) {
    for (int i = 0;i < abs->m_Size;i++) {
        if (abs->personarray[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}
void Delet(Addessbooks* abs, string name) {
    int ret = 0;
    ret = isExit(abs,name);
    if (ret != -1) {
        for (int i = ret;i < abs->m_Size;i++) {
            abs->personarray[i] = abs->personarray[i + 1];
        }
		abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	Addessbooks abs;
	abs.m_Size = 0;
    int select = 0;
    while (true)
    {
        Menu();
        cin >> select;
        switch (select) {
        case 1:
			addperson(&abs);
            break;
        case 2:
            showperson(&abs);
            break;
        case 3:
        {
            cout << "请输入删除姓名" << endl;
            string name;
            cin >> name;
            Delet(&abs, name);
        }
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        }
    }
    return 0;
}