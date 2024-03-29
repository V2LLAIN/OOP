#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;
int i;

vector<string> v;
vector<string>::iterator iter;
int LINE = 1; //현재 페이지 시작 line
int vec_size = v.size();

class Strategy_File {   // Strategy Pattern을 위한 순수가상함수 클래스
public:
    virtual bool do_action(string s) = 0;
};

class NextPage : public Strategy_File {
private:
    void nextPage();
public:
    bool do_action(string input_s) {
        if (input_s.size() != 1) {
            cout << "잘못된 입력입니다. " << endl;
            //break;
            return false;
        }
        if (LINE + 19 == vec_size) {
            cout << "This is final page!" << endl;
            //break;
            return false;
        }
        nextPage();
        return true;
    }
};
void NextPage::nextPage() {
    LINE += 20;
    if (vec_size < LINE + 20) {
        int temp = vec_size - 19;
        LINE = (temp <= 1 ? 0 : temp);
    }
}
class PrevPage : public Strategy_File {
private:
    void prevPage();
public:
    bool do_action(string input_s) {
        if (input_s.size() != 1) {
            cout << "잘못된 입력입니다. " << endl;
            return false;
        }
        if (LINE <= 1) {
            cout << "This is first page!" << endl;
            return false;
        }
        prevPage();
        return true;
    }
};
void PrevPage::prevPage() {
    LINE -= 20;
    if (LINE <= 0) {
        LINE = 1;
    }
}
class Insert : public Strategy_File {
private:
    bool insert(int l, int w, string s);
public:
    bool do_action(string input_s) {
        int index = 0;
        bool flag = true;
        int array[2] = { -1, -1 };
        string word;
        if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
            //명령어 다음 입력값과 마지막 입력값은 괄호여야 하기에.
            cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
            return false;
        }
        //괄호 안에 공백을 입력하면 입력오류가 발생
        for (int i = 2; i < input_s.length() - 1; i++) {
            if (input_s[i] == ' ') {
                cout << "괄호안에 공백을 입력하셨습니다. 다시 입력해주세요" << endl;
                flag = false;
                break;
            }
        }
        if (flag == false) { return false; }
        for (int i = 2, temp = 0; i < input_s.length() - 1; i++) {
            if (input_s[i] == ',') {
                array[index] = temp;
                index++;
                temp = 0;
                continue;
            }
            else if (index == 2) {
                word = word + input_s[i];
                continue;
            }
            else {
                if ('0' > input_s[i] || '9' < input_s[i]) {
                    // 숫자가 아닌 값을 숫자부분에 입력
                    cout << " 숫자가 아닌것을 입력하였습니다. 다시 입력 해주세요" << endl;
                    flag = false;
                    break;
                }
                temp = temp * 10 + (input_s[i] - '0'); //int로 변환하여 더한다.
                //일의자리수가 아닐 경우
            }
        }
        if (flag == false) {
            //숫자가 아닌 부분을 입력, 출력은 위에서 진행.
            return false;
        }
        if (array[0] < 0 || array[1] < 0) {
            //숫자가 입력되지 않은것
            cout << "추가할 위치 또는 단어 를 입력하지 않았습니다. 다시 입력해 주세요." << endl;
            return false;
        }
        if (index != 2) {
            //쉼표 두개가 입력이 되지 않은것
            cout << "형식에 맞지 않게 입력하셨습니다. 다시 입력해 주세요." << endl;
            return false;
        }
        if (word.size() == 0) {
            cout << "추가할 단어를 입력하지 않았습니다. 다시 입력해 주세요." << endl;
            return false;
        }
        if (word.size() >= 75) {
            //75바이트 이상 출력 불가능, 재입력 요구
            cout << "75byte 이상 출력이 불가능 합니다. 다시 입력 해주세요" << endl;
            return false;
        }
        if (array[0] < LINE || array[0] >= LINE + 20) {
            cout << "현재 페이지에 존재하지 않는 line입니다. 다시입력해 주세요." << endl;
            return false;
        }
        if (!insert(array[0], array[1], word)) { //원하는 단어가 존재하지 않은 경우 false
            return false;
        }
        return true;
    }
};
bool Insert::insert(int line_position, int idx_position, string insert_word) {
    int temp = 0;
    int line = 1;
    int count = 1;
    string str;
    string stringBuffer;
    istringstream ss(v[line_position - 1]);  // 줄라인 전체 vector
    int i = 1;

    for (; getline(ss, stringBuffer, ' '); i++) {
        if (i == idx_position) {
            str += stringBuffer + " " + insert_word + " ";
        }
        else {
            str += stringBuffer + " ";
        }
    }
    if (i <= idx_position) { //현재 라인에 원하는 단어가 존재하지 않는 경우
        cout << line_position << "번째 라인에는 " << idx_position << "번째 단어가 존재하지 않습니다. 다시 입력해주세요." << endl;
        return false;
    }
    v[line_position - 1] = str;
    return true;

}

class Delete : public Strategy_File {
private:
    bool delete_byte(int l, int w, int db);
public:
    bool do_action(string input_s)
    {
        int index = 0;
        bool flag = true;
        int array[3] = { -1, -1, -1 };

        if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
            //명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
            cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
            return false;
        }
        //괄호 안에 공백을 입력하면 입력오류
        for (int i = 2; i < input_s.length() - 1; i++) {
            if (input_s[i] == ' ')
            {
                cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
                flag = false;
                return false;
            }
        }
        if (flag == false) {
            return false;
        }

        for (int i = 2, temp = 0; i < input_s.length() && index < 2; i++) {
            if (input_s[i] == ',') {
                if (index >= 2) { //쉼표가 세번이상 입력된것
                    cout << "쉼표가 세번이상 입력되었습니다. 다시 입력해주세요." << endl;
                    flag = false;
                    break;
                }
                array[0] = temp;
                array[1] = array[0];
                temp = array[1];
                index++;
                temp = 0;

            }


            else if (input_s[i] == ')') {
                array[2] = temp;
                index++;
            }
            else {
                if ('0' > input_s[i] || '9' < input_s[i]) {
                    //숫자부분에 숫자가 아닌 부분을 입력
                    cout << " 숫자가 아닌것을 입력하였습니다. 다시 입력 해주세요" << endl;
                    flag = false;
                    return false;
                }
                temp = temp * 10 + (input_s[i] - '0'); //int로 변환하여 더한다.
            }
        }

        if (flag == false)
            return false;
        if (index != 2) {
            cout << "형식에 맞지 않게 입력하셨습니다. 다시 입력해 주세요." << endl;
            return false;
        }
        if (array[0] < LINE || array[0] >= LINE + 20) {
            //현재 출력창에 존재하지 않음
            cout << "삭제하려는 라인이 현재 창에 존재하지 않습니다. " << endl;
            return false;
        }
        if (!delete_byte(array[0], array[1], array[2])) { //원하는 단어가 존재하지 않을 경우
            return false;
        }
        return true;
    }
};

bool Delete::delete_byte(int line_position, int idx_position, int del_byte) {
    string str;
    string stringBuffer;
    istringstream ss(v[line_position - 1]); // istringstream은 문자열 포맷을 parsing, 원하는 문자를 기준으로 자를 수 있음
    int i = 1;

    for (; getline(ss, stringBuffer); i++) {  //getline(istream& is, string str, char delim);
        string str;
        string stringBuffer;
        istringstream ss(v[line_position - 1]);
        int i = 1;
        for (; getline(ss, stringBuffer, ' '); i++) {
            //int t = stringBuffer.size();
            if (i == idx_position)
                continue;
            else
                str += stringBuffer + " ";
        }
        if (i <= idx_position) { //현재 라인에 원하는 단어가 존재하지 않는 경우
            cout << line_position << "번째 라인에는 " << idx_position << "번째 단어가 존재하지 않습니다. 다시 입력해주세요." << endl;
            return false;
        }
        v[line_position - 1] = str;
        return true;

    }
}
    class Change : public Strategy_File {
    private:
        bool change(string a, string b);
    public:
        bool do_action(string input_s) {
            bool flag = true;
            string change_str[2];
            string str_temp;
            if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
                //명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
                cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
                return false;
            }
            //괄호 안에 공백을 입력하면 입력오류
            for (int i = 2; i < input_s.length() - 1; i++) {
                if (input_s[i] == ' ') {
                    cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
                    flag = false;
                    return false;
                }
            }
            if (flag == false) { return false; }
            for (int i = 2; i < input_s.length(); i++) {
                if (input_s[i] == ',') {
                    change_str[0] = str_temp;
                    str_temp = "";
                }
                else if (input_s[i] == ')') {
                    change_str[1] = str_temp;
                }
                else
                    str_temp += input_s[i];

            }
            if (change_str[0].size() == 0 || change_str[1].size() == 0) { //하나도 인자가 입력이 제대로 되지 않았으면 ""일것이다.
                cout << "형식에 맞는 입력값이 아닙니다. 다시 입력해 주세요." << endl;
                return false;
            }
            if (!change(change_str[0], change_str[1])) {
                return false;
            }
            return true;
        }
    };

    bool Change::change(string prev_str, string modify_str)  {
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            string str;
            string stringBuffer;
            istringstream ss(v[i]);
            while (getline(ss, stringBuffer, ' ')) {
                if (stringBuffer == prev_str) {
                    str += modify_str + " ";
                    count++;
                    continue;
                }
                else
                    str += stringBuffer + " ";
            }
            v[i] = str;
        }
        if (count == 0) {
            //바꾸려고 하였던 문자가 존재하지 않은것
            cout << "변경할 문자가 존재하지 않습니다. 다시입력해주세요." << endl;
            return false;
        }
        return true;
    }

    class Search : public Strategy_File {
    private:
        bool search(string s);
    public:
        bool do_action(string input_s) {
            bool flag = true;
            string str_temp;
            if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
                //명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
                cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
                return false;
            }
            //괄호 안에 공백을 입력하면 입력오류
            for (int i = 2; i < input_s.length() - 1; i++) {
                if (input_s[i] == ' ') {
                    cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
                    flag = false;
                    return false;
                }
            }
            if (flag == false)
                return false;
            str_temp = input_s.substr(2, input_s.length() - 3);
            if (!search(str_temp + " ")) {
                cout << "찾는 문자가 존재하지 않습니다. 다시입력해주세요" << endl;
                return false;
            }
            //찾는 문자가 존재하면
            return true;
        }
    };

    bool Search::search(string search_word) {
        string str;
        for (int i = 0; i < v.size(); i++) {
            //반환값이 string::npos이면 찾는 문자가 없는것이다.
            str = v[i];
            if (str.find(search_word) != string::npos) {
                //문자를 찾은것
                LINE = i + 1;
                return true;
            }
        }
        return false;
    }

    class SaveEnd : public Strategy_File {
    private:
        void saveFile();
    public:
        bool do_action(string input_s) {
            saveFile();
            cout << "변경내용을 파일에 저장하였습니다. 프로그램을 종료합니다." << endl;
            return false;
        }
    };
    void SaveEnd::saveFile() {
        ofstream out("test.txt");
        for (int i = 0; i < v.size(); i++)
            out << v[i];
        out.close();
    }

    int error_flag = false;
    class FileContext {
    public:
        FileContext(Strategy_File* sf) {
            StrategyFile = sf;
            setVector();
            initPage();
        }
        void setVector() {
            ifstream in("test.txt");
            string s, str;
            int size = 0;
            int temp = 0;
            while (!in.eof()) {
                in >> s;
                size = (int)s.size();
                if (size + temp <= 75) {
                    str += s + " ";
                    temp += size + 1;
                }
                else {
                    v.push_back(str);
                    str = s + " ";
                    temp = size + 1;
                }
            }
            if (in.eof()) {
                v.push_back(str);
            }
            in.close();

            vec_size = v.size();
        }
        void initPage();
        void modifyVector();
        void thisPage();
        bool action() {
            string input;
            if (print_flag) {
                cout << "----------------------------------------------------------------------------------" << endl;
                cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료" << endl;
            }
            print_flag = true;
            getline(cin, input); //한줄 입력받기

            this->setStratage(input); //action 변경
            if (error_flag) {   //잘못된 명령어일경우 리턴
                error_flag = false;
                return false;
            }
            bool result = StrategyFile->do_action(input);
            if ((char)input[0] == 't') {
                return result;
            }
            if (result) {
                modifyVector();
                thisPage();
            }
            return true;
        }
        void setStratage(string input) {
            char keyword = (char)input[0];
            switch (keyword) {
                case 'n':
                    StrategyFile = new NextPage;
                    break;
                case 'p':
                    StrategyFile = new PrevPage;
                    break;
                case 'i':
                    StrategyFile = new Insert;
                    break;
                case 'd':
                    StrategyFile = new Delete;
                    break;
                case 'c':
                    StrategyFile = new Change;
                    break;
                case 's':
                    StrategyFile = new Search;
                    break;
                case 't':
                    StrategyFile = new SaveEnd;
                    break;

                default:
                    if (input == "") {
                        print_flag = false;
                        break;
                    }
                    error_flag = true;
                    cout << "명령어를 잘못 입력하셨습니다. 다시 입력해주세요." << endl;
                    return;
            }
        }
    protected:
        Strategy_File* StrategyFile;
        bool print_flag = true;
    };

    void FileContext::modifyVector() {
        string s, str;
        //한 문자열로 합쳐준다.
        for (int i = 0; i < v.size(); i++)
            s += v[i];
        v.clear();
        int size = 0;
        int temp = 0;
        int i = 0;
        string stringBuffer;
        istringstream ss(s);
        while (getline(ss, stringBuffer, ' ')) {
            size = (int)stringBuffer.size();
            if (size + temp <= 75) {
                str += stringBuffer + " ";
                temp += size + 1;
            }
            else {
                v.push_back(str);
                str = stringBuffer + " ";
                temp = size + 1;
            }
        }
        v.push_back(str);
        vec_size = v.size();
    }
    void FileContext::initPage() {
        LINE = 1;
        thisPage();
    }
    void FileContext::thisPage() {
        for (i = LINE; i < LINE + 20 && v.size(); i++)
            cout << i << " | " << v[i - 1] << endl;
    }

    int main() {
        FileContext* f1 = new FileContext(new NextPage);
        while (f1->action());
    }
