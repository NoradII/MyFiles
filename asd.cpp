#include <iostream>
#include <stdlib.h> // 표준 라이브러리 - 문자열 반환, 동적 메모리 관리 등의 함수들을 포함한다.

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
	exit(0); // 함수 호출 시점에서 즉시 프로세스를 종료하는 표준함수
}

void book_show() { // function declaration
	for (int i = 1; i < 11; i++) { // for문
		cout << i << "번 책의 ID = " << books[i].id << endl; // 1~10번째 책의 id 출력
		cout << i << "번 책의 Name = " << books[i].name << endl; // 1~10번째 책의 name 출력
	}
}

void book_change() { // function declaration
	fp = fopen("books.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	int k; // int type variable k
	cout << "변경할 책의 번호를 입력하세요" << endl; // 출력
	cin >> k; // 입력
	for (int i = 1; i < 11; i++) { // for문
		if (i == k) { // if문
			cout << "change your data" << endl;// 출력
			cin >> books[i].id >> books[i].name; // 1~10번째 책의 id와 책의 name 입력
			for (int j = 1; j < 11; j++) // for문
			{
				fprintf(fp, "책 ID : %d 책 이름 : %s\n", books[j].id, books[j].name); // file output-책의 id와 name
			}
		}
	}
	fclose(fp); // file close
}

void book_remove() { // function declaration
	fp = fopen("books.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	int k; // int type variable k
	cout << "삭제할 책의 번호를 입력하세요" << endl; // 출력
	cin >> k; // 입력
	if (books[k].id == 0) { // if문(book의 id가 0이면)
		cout << "더이상 제거를 할 수 없습니다." << endl; // 출력
	}
	for (int i = 1; i < 11; i++) { // for문
		if (i == k) { // if문
			books[i].id = 0; // 책의 id 초기화
			memset(books[i].name, 0, 30 * sizeof(char)); // 사용자가 정한 메모리 크기 만큼 메모리 영역을 특정한 값으로 채우는 함수
			for (int j = 1; j < 11; j++) // for문
			{
				fprintf(fp, "책 ID : %d 책 이름 : %s\n", books[j].id, books[j].name); // file output
			}
		}
	}
	fclose(fp); // file close
}

void book_insert() { // function declaration
	fp = fopen("books.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	int k; // int type variable k
	cout << "추가할 책의 번호를 입력하세요" << endl; // 출력
	cin >> k; // 입력
	if (books[k].id != 0) // if문(book의 id가 0이 아니라면)
	{
		cout << "현재 책이있는 index입니다." << endl;  // 출력
		return;
	}
	for (int i = 1; i < 11; i++) { // for문
		if (i == k) { // if문
			cout << "insert your data" << endl; // 출력
			cin >> books[i].id >> books[i].name; // 1~10번째 book의 id와 name 입력
			for (int j = 1; j < 11; j++) // for문
			{
				fprintf(fp, "책 ID : %d 책 이름 : %s\n", books[j].id, books[j].name); // file output-책의 id와 name
			}
		}
	}
	fclose(fp); // file close
}

void member_show() { // function declaration
	for (int i = 1; i < 6; i++) { // for문
		cout << i << "번째 멤버의 ID: " << members[i].id << endl; // 1~5번째 멤버의 id 출력
		cout << i << "번째 멤버의 이름: " << members[i].name << endl; // 1~5번째 멤버의 name 출력
	}
}

void member_change() { // function declaration
	fq = fopen("members.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	int k; // int type variable k
	cout << "변경할 멤버의 번호를 입력하세요" << endl; // 출력
	cin >> k; // 입력
	for (int i = 1; i < 6; i++) { // for문
		if (i == k) { // if문
			cout << "enter your data" << endl; // 출력
			cin >> members[i].id >> members[i].name; // 1~5번째 멤버의 id와 name 입력
			for (int j = 1; j < 6; j++)  // for문
			{
				fprintf(fq, "멤버 ID : %d 멤버 이름 : %s\n", members[j].id, members[j].name); // file output-member의 id와 name
			}
		}
	}
	fclose(fq); // file close
}

void member_remove() { // function declaration
	fq = fopen("members.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	int k; // int type variable k
	cout << "삭제할 멤버의 번호를 입력하세요" << endl; // 출력
	cin >> k; // 입력
	if (members[k].id == 0) { // if문(멤버의 id가 0이면)
		cout << "더이상 제거를 할 수 없습니다." << endl; // 출력
	}
	for (int i = 1; i < 6; i++) { // for문
		if (i == k) { // if문
			members[i].id = 0; // 멤버의 id 초기화
			memset(members[i].name, 0, 30 * sizeof(char)); // 사용자가 정한 메모리 크기 만큼 메모리 영역을 특정한 값으로 채우는 함수
			for (int j = 1; j < 6; j++) // for문
			{
				fprintf(fq, "멤버 ID : %d 멤버 이름 : %s\n", members[j].id, members[j].name); // file output-member의 id와 name
			}
		}
	}
	fclose(fq); // file close
}

void member_insert() { // fuction declaration
	fq = fopen("members.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	int k; // int type variable k
	cout << "추가할 멤버의 번호를 입력하세요" << endl; // 출력
	cin >> k; // 입력
	if (members[k].id != 0) // if문(멤버의 id가 0이 아니라면)
	{
		cout << "현재 멤버가 있는 index입니다." << endl; // 출력
		return;
	}
	for (int i = 1; i < 6; i++) { // for문
		if (i == k) { // if문
			cout << "insert your data" << endl; // 출력
			cin >> members[i].id >> members[i].name; // 1~5번째 멤버의 id와 name 입력
			for (int j = 1; j < 6; j++) // for문
			{
				fprintf(fq, "멤버 ID : %d 멤버 이름 : %s\n", members[j].id, members[j].name); // file output-member의 id와 name
			}
		}
	}
	fclose(fq); // file close
}

void borrow_b() { // function declaration
	fr = fopen("manage.txt", "a+"); // file open, 추가 모드로 파일을 연다. 파일이 없으면 새로운 파일을 만들고, 똑같은 이름의 기존의 파일이 있으면 데이터가 파일의 끝에 추가된다.
	int memin, bookin; // int type variables
	int b; // int type variable b
	int x; // int type variable x
	int y; // int type variable y
	int z; // int type variable z
	cout << "1. 책을 빌림 2. 책을 빌리지 않음" << endl; // 출력
	cin >> b; // 입력
	if (b == 1) { // if문
		cout << "책을 빌림" << endl; // 출력
		cout << "누가 책을 빌렸는가?" << endl; // 출력
		member_show(); //function call
		cout << "Member의 번호를 입력하세요(1~5)" << endl; // 출력
		cin >> memin; // 입력
		cout << "어떤 책을 빌렸는가?" << endl; // 출력
		book_show(); // function call
		cout << "Book의 번호를 입력하세요(1~10)" << endl; // 출력
		cin >> bookin; // 입력

		cout << "언제 책을 빌렸는가?" << endl; // 출력
		cout << "년도를 입력하세요 : " << endl; // 출력
		cin >> x; // 입력
		cout << "월을 입력하세요 : " << endl; // 출력
		cin >> y; // 입력
		cout << "날짜를 입력하세요 : " << endl; // 출력
		cin >> z; // 입력
		cout << "year: " << x << "month: " << y << "date: " << z << endl; // 출력
		fprintf(fr, "책을 빌림\n"); // file output
		fprintf(fr, "책 빌린 사람 이름 : %s 책 빌린 사람 ID: %d\n", members[memin].name, members[memin].id); // file output-멤버의 name과 id
		fprintf(fr, "빌린 책 이름: %s 빌린 책 ID: %d\n", books[bookin].name, books[bookin].id); // file output-book의 name과 id
		fprintf(fr, "year: %d     month: %d     date: %d\n", x, y, z); // file output-x,y,z
		fclose(fr); // file close
	}
	else if (b == 2) {
		cout << "책을 빌리지 않음" << endl; // 출력
		fprintf(fr, "책을 빌리지 않음\n");
		fclose(fr); // file close
	}
	//fclose(fr); // file close

}

void return_b() { // function declaration
	fr = fopen("manage.txt", "a+"); // file open, 추가 모드로 파일을 연다. 파일이 없으면 새로운 파일을 만들고, 똑같은 이름의 기존의 파일이 있으면 데이터가 파일의 끝에 추가된다.
	int memid, bookid; // int type variables
	int r; // int type variable r
	int x; // int type variable x
	int y; // int type variable y
	int z; // int type variable z
	cout << "1. 책을 반납함 2. 책을 반납하지 않음" << endl; // 출력
	cin >> r; // 입력
	if (r == 1) { // if문
		cout << "책을 반납함" << endl; // 출력
		cout << "누가 책을 반납하였는가?" << endl; // 출력
		member_show(); // function call
		cout << "Member의 번호를 입력하세요(1~5)" << endl; // 출력
		cin >> memid; // 입력
		cout << "어떤 책을 반납하였는가" << endl; // 출력
		book_show(); // function call
		cout << "Book의 번호를 입력하세요(1~10)" << endl; // 출력
		cin >> bookid; // 입력
		cout << "언제 책을 반납하였는가?" << endl; // 출력
		cout << "년도를 입력하세요 : " << endl; // 출력
		cin >> x; // 입력
		cout << "월을 입력하세요 : " << endl; // 출력
		cin >> y; // 입력
		cout << "날짜를 입력하세요 : " << endl; // 출력
		cin >> z; // 입력
		cout << "year: " << x << "month: " << y << "date: " << z << endl; // 출력
		fprintf(fr, "책을 반납함\n"); // file output
		fprintf(fr, "책 빌린 사람 이름: %s 책 빌린 사람 ID: %d\n", members[memid].name, members[memid].id); // file output-member의 name과 id
		fprintf(fr, "빌린 책 이름: %s 빌린 책 ID: %d\n", books[bookid].name, books[bookid].id); // file output-book의 name과 id
		fprintf(fr, "year: %d     month: %d     date: %d\n", x, y, z); // file output-x,y,z
	}
	else if (r == 2) {
		cout << "반납하지 않음" << endl; // 출력
		fprintf(fr, "책을 반납하지 않음\n");
	}
	fclose(fr); // file close
}

int main(void) { // main 함수
	fr = fopen("manage.txt", "w"); // file open, 쓰기 모드로 파일을 생성한다. 파일이 존재하지 않으면 파일이 생성되고, 파일이 이미 존재하면 기존의 내용이 지워진다.
	while (1) { // 무한루프
		cout << "MENU" << endl; // 출력
		cout << "1. quit 2. book show 3. book change 4. book remove 5. book insert " << endl; // 출력
		cout << "6. member show 7. member change 8. member remove 9. member insert " << endl; // 출력
		cout << "10. borrow 11.return " << endl; // 출력
		int k; // int type variable k
		cout << "원하시는 메뉴를 선택하세요" << endl; // 출력
		cin >> k; // 입력
		switch (k) { // switch문
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