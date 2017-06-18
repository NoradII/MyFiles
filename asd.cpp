#include <iostream>
#include <stdlib.h> // ǥ�� ���̺귯�� - ���ڿ� ��ȯ, ���� �޸� ���� ���� �Լ����� �����Ѵ�.

using namespace std;

FILE *fp = NULL; // using FILE structure pointer(file pointer)
FILE *fq = NULL; // using FILE structure pointer(file pointer)
FILE *fr = NULL; // using FILE structure pointer(file pointer)

struct book { // definition of structure
	int id;
	char name[30];
};

book books[10]; // declaration of structure array

struct member { // definition of structure
	int id;
	char name[30];
};

member members[5]; // declaration of structure array

void quit() { // function declaration
	exit(0); // �Լ� ȣ�� �������� ��� ���μ����� �����ϴ� ǥ���Լ�
}

void book_show() { // function declaration
	for (int i = 1; i < 11; i++) { // for��
		cout << i << "�� å�� ID = " << books[i].id << endl; // 1~10��° å�� id ���
		cout << i << "�� å�� Name = " << books[i].name << endl; // 1~10��° å�� name ���
	}
}

void book_change() { // function declaration
	fp = fopen("books.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	int k; // int type variable k
	cout << "������ å�� ��ȣ�� �Է��ϼ���" << endl; // ���
	cin >> k; // �Է�
	for (int i = 1; i < 11; i++) { // for��
		if (i == k) { // if��
			cout << "change your data" << endl;// ���
			cin >> books[i].id >> books[i].name; // 1~10��° å�� id�� å�� name �Է�
			for (int j = 1; j < 11; j++) // for��
			{
				fprintf(fp, "å ID : %d å �̸� : %s\n", books[j].id, books[j].name); // file output-å�� id�� name
			}
		}
	}
	fclose(fp); // file close
}

void book_remove() { // function declaration
	fp = fopen("books.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	int k; // int type variable k
	cout << "������ å�� ��ȣ�� �Է��ϼ���" << endl; // ���
	cin >> k; // �Է�
	if (books[k].id == 0) { // if��(book�� id�� 0�̸�)
		cout << "���̻� ���Ÿ� �� �� �����ϴ�." << endl; // ���
	}
	for (int i = 1; i < 11; i++) { // for��
		if (i == k) { // if��
			books[i].id = 0; // å�� id �ʱ�ȭ
			memset(books[i].name, 0, 30 * sizeof(char)); // ����ڰ� ���� �޸� ũ�� ��ŭ �޸� ������ Ư���� ������ ä��� �Լ�
			for (int j = 1; j < 11; j++) // for��
			{
				fprintf(fp, "å ID : %d å �̸� : %s\n", books[j].id, books[j].name); // file output
			}
		}
	}
	fclose(fp); // file close
}

void book_insert() { // function declaration
	fp = fopen("books.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	int k; // int type variable k
	cout << "�߰��� å�� ��ȣ�� �Է��ϼ���" << endl; // ���
	cin >> k; // �Է�
	if (books[k].id != 0) // if��(book�� id�� 0�� �ƴ϶��)
	{
		cout << "���� å���ִ� index�Դϴ�." << endl;  // ���
		return;
	}
	for (int i = 1; i < 11; i++) { // for��
		if (i == k) { // if��
			cout << "insert your data" << endl; // ���
			cin >> books[i].id >> books[i].name; // 1~10��° book�� id�� name �Է�
			for (int j = 1; j < 11; j++) // for��
			{
				fprintf(fp, "å ID : %d å �̸� : %s\n", books[j].id, books[j].name); // file output-å�� id�� name
			}
		}
	}
	fclose(fp); // file close
}

void member_show() { // function declaration
	for (int i = 1; i < 6; i++) { // for��
		cout << i << "��° ����� ID: " << members[i].id << endl; // 1~5��° ����� id ���
		cout << i << "��° ����� �̸�: " << members[i].name << endl; // 1~5��° ����� name ���
	}
}

void member_change() { // function declaration
	fq = fopen("members.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	int k; // int type variable k
	cout << "������ ����� ��ȣ�� �Է��ϼ���" << endl; // ���
	cin >> k; // �Է�
	for (int i = 1; i < 6; i++) { // for��
		if (i == k) { // if��
			cout << "enter your data" << endl; // ���
			cin >> members[i].id >> members[i].name; // 1~5��° ����� id�� name �Է�
			for (int j = 1; j < 6; j++)  // for��
			{
				fprintf(fq, "��� ID : %d ��� �̸� : %s\n", members[j].id, members[j].name); // file output-member�� id�� name
			}
		}
	}
	fclose(fq); // file close
}

void member_remove() { // function declaration
	fq = fopen("members.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	int k; // int type variable k
	cout << "������ ����� ��ȣ�� �Է��ϼ���" << endl; // ���
	cin >> k; // �Է�
	if (members[k].id == 0) { // if��(����� id�� 0�̸�)
		cout << "���̻� ���Ÿ� �� �� �����ϴ�." << endl; // ���
	}
	for (int i = 1; i < 6; i++) { // for��
		if (i == k) { // if��
			members[i].id = 0; // ����� id �ʱ�ȭ
			memset(members[i].name, 0, 30 * sizeof(char)); // ����ڰ� ���� �޸� ũ�� ��ŭ �޸� ������ Ư���� ������ ä��� �Լ�
			for (int j = 1; j < 6; j++) // for��
			{
				fprintf(fq, "��� ID : %d ��� �̸� : %s\n", members[j].id, members[j].name); // file output-member�� id�� name
			}
		}
	}
	fclose(fq); // file close
}

void member_insert() { // fuction declaration
	fq = fopen("members.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	int k; // int type variable k
	cout << "�߰��� ����� ��ȣ�� �Է��ϼ���" << endl; // ���
	cin >> k; // �Է�
	if (members[k].id != 0) // if��(����� id�� 0�� �ƴ϶��)
	{
		cout << "���� ����� �ִ� index�Դϴ�." << endl; // ���
		return;
	}
	for (int i = 1; i < 6; i++) { // for��
		if (i == k) { // if��
			cout << "insert your data" << endl; // ���
			cin >> members[i].id >> members[i].name; // 1~5��° ����� id�� name �Է�
			for (int j = 1; j < 6; j++) // for��
			{
				fprintf(fq, "��� ID : %d ��� �̸� : %s\n", members[j].id, members[j].name); // file output-member�� id�� name
			}
		}
	}
	fclose(fq); // file close
}

void borrow_b() { // function declaration
	fr = fopen("manage.txt", "a+"); // file open, �߰� ���� ������ ����. ������ ������ ���ο� ������ �����, �Ȱ��� �̸��� ������ ������ ������ �����Ͱ� ������ ���� �߰��ȴ�.
	int memin, bookin; // int type variables
	int b; // int type variable b
	int x; // int type variable x
	int y; // int type variable y
	int z; // int type variable z
	cout << "1. å�� ���� 2. å�� ������ ����" << endl; // ���
	cin >> b; // �Է�
	if (b == 1) { // if��
		cout << "å�� ����" << endl; // ���
		cout << "���� å�� ���ȴ°�?" << endl; // ���
		member_show(); //function call
		cout << "Member�� ��ȣ�� �Է��ϼ���(1~5)" << endl; // ���
		cin >> memin; // �Է�
		cout << "� å�� ���ȴ°�?" << endl; // ���
		book_show(); // function call
		cout << "Book�� ��ȣ�� �Է��ϼ���(1~10)" << endl; // ���
		cin >> bookin; // �Է�

		cout << "���� å�� ���ȴ°�?" << endl; // ���
		cout << "�⵵�� �Է��ϼ��� : " << endl; // ���
		cin >> x; // �Է�
		cout << "���� �Է��ϼ��� : " << endl; // ���
		cin >> y; // �Է�
		cout << "��¥�� �Է��ϼ��� : " << endl; // ���
		cin >> z; // �Է�
		cout << "year: " << x << "month: " << y << "date: " << z << endl; // ���
		fprintf(fr, "å�� ����\n"); // file output
		fprintf(fr, "å ���� ��� �̸� : %s å ���� ��� ID: %d\n", members[memin].name, members[memin].id); // file output-����� name�� id
		fprintf(fr, "���� å �̸�: %s ���� å ID: %d\n", books[bookin].name, books[bookin].id); // file output-book�� name�� id
		fprintf(fr, "year: %d     month: %d     date: %d\n", x, y, z); // file output-x,y,z
		fclose(fr); // file close
	}
	else if (b == 2) {
		cout << "å�� ������ ����" << endl; // ���
		fprintf(fr, "å�� ������ ����\n");
		fclose(fr); // file close
	}
	//fclose(fr); // file close

}

void return_b() { // function declaration
	fr = fopen("manage.txt", "a+"); // file open, �߰� ���� ������ ����. ������ ������ ���ο� ������ �����, �Ȱ��� �̸��� ������ ������ ������ �����Ͱ� ������ ���� �߰��ȴ�.
	int memid, bookid; // int type variables
	int r; // int type variable r
	int x; // int type variable x
	int y; // int type variable y
	int z; // int type variable z
	cout << "1. å�� �ݳ��� 2. å�� �ݳ����� ����" << endl; // ���
	cin >> r; // �Է�
	if (r == 1) { // if��
		cout << "å�� �ݳ���" << endl; // ���
		cout << "���� å�� �ݳ��Ͽ��°�?" << endl; // ���
		member_show(); // function call
		cout << "Member�� ��ȣ�� �Է��ϼ���(1~5)" << endl; // ���
		cin >> memid; // �Է�
		cout << "� å�� �ݳ��Ͽ��°�" << endl; // ���
		book_show(); // function call
		cout << "Book�� ��ȣ�� �Է��ϼ���(1~10)" << endl; // ���
		cin >> bookid; // �Է�
		cout << "���� å�� �ݳ��Ͽ��°�?" << endl; // ���
		cout << "�⵵�� �Է��ϼ��� : " << endl; // ���
		cin >> x; // �Է�
		cout << "���� �Է��ϼ��� : " << endl; // ���
		cin >> y; // �Է�
		cout << "��¥�� �Է��ϼ��� : " << endl; // ���
		cin >> z; // �Է�
		cout << "year: " << x << "month: " << y << "date: " << z << endl; // ���
		fprintf(fr, "å�� �ݳ���\n"); // file output
		fprintf(fr, "å ���� ��� �̸�: %s å ���� ��� ID: %d\n", members[memid].name, members[memid].id); // file output-member�� name�� id
		fprintf(fr, "���� å �̸�: %s ���� å ID: %d\n", books[bookid].name, books[bookid].id); // file output-book�� name�� id
		fprintf(fr, "year: %d     month: %d     date: %d\n", x, y, z); // file output-x,y,z
	}
	else if (r == 2) {
		cout << "�ݳ����� ����" << endl; // ���
		fprintf(fr, "å�� �ݳ����� ����\n");
	}
	fclose(fr); // file close
}

int main(void) { // main �Լ�
	fr = fopen("manage.txt", "w"); // file open, ���� ���� ������ �����Ѵ�. ������ �������� ������ ������ �����ǰ�, ������ �̹� �����ϸ� ������ ������ ��������.
	while (1) { // ���ѷ���
		cout << "MENU" << endl; // ���
		cout << "1. quit 2. book show 3. book change 4. book remove 5. book insert " << endl; // ���
		cout << "6. member show 7. member change 8. member remove 9. member insert " << endl; // ���
		cout << "10. borrow 11.return " << endl; // ���
		int k; // int type variable k
		cout << "���Ͻô� �޴��� �����ϼ���" << endl; // ���
		cin >> k; // �Է�
		switch (k) { // switch��
		case 1:
			quit(); // function call
			break;
		case 2:
			book_show(); // function call
			break;
		case 3:
			book_change(); // function call
			break;
		case 4:
			book_remove(); // function call
			break;
		case 5:
			book_insert(); // function call
			break;
		case 6:
			member_show(); // function call
			break;
		case 7:
			member_change(); // function call
			break;
		case 8:
			member_remove(); // function call
			break;
		case 9:
			member_insert(); // funciton call
			break;
		case 10:
			borrow_b(); // function call
			break;
		case 11:
			return_b(); // function call
			break;

		}
	}
	return 0;
	fclose(fr); // file close
}