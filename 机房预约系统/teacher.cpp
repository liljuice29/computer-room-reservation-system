#include"teacher.h"

//默认构造
teacher::teacher()
{

}
//有参构造
teacher::teacher(int emipd, string name, string pwd)
{
	this->empid = empid;
	this->name = name;
	this->pwd = pwd;
}
//菜单界面
void teacher::opermenu()
{
	cout << "------------------  欢迎老师登录  ------------------ " << endl;
	cout << "\t\t -------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               1.查看所有预约       |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               2.审核预约           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|               0.注销登录           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t -------------------------------------\n";
	cout << "请输入你的选择;" << endl;
 }

//查看所有预约
void teacher::showallorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << ",";
		cout << "预约如期：周" << of.orderdata[i]["date"] << "  ";
		cout << "时间段：" << (of.orderdata[i]["interval"] == "1" ? "上午" : "下午") << "  ";
		cout << "学号：" << of.orderdata[i]["stuid"] << "  ";
		cout << "姓名：" << of.orderdata[i]["stuname"] << "  ";
		cout << "机房号：" << of.orderdata[i]["roomid"] << "  ";
		string status = "状态";
		//1审核中 2已预约 -1预约失败 0取消预约
		if (of.orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}

		else if (of.orderdata[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;


	}

	system("pause");
	system("cls");

}
//审核预约
void teacher::validorder()
{
	orderfile of;
	if (of.size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核预约记录如下" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.orderdata[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << ", ";
			cout << "预约如期：周" << of.orderdata[i]["date"] << "  ";
			cout << "时间段：" << (of.orderdata[i]["interval"] == "1" ? "上午" : "下午") << "  ";
			cout << "学号：" << of.orderdata[i]["stuid"] << "  ";
			cout << "姓名：" << of.orderdata[i]["stuname"] << "  ";
			cout << "机房号：" << of.orderdata[i]["roomid"] << "  ";
			cout << "状态：审核中" << endl;
		}


	}

	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约结果记录
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1,通过 2，不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.orderdata[v[select - 1]]["status"] = "-1";
				}
				of.updateorder();
				cout << "审核完毕" << endl;
				break;
			}



		}
		cout << "输入有误，请重新输入" << endl;

	}

	system("pause");
	system("cls");

}