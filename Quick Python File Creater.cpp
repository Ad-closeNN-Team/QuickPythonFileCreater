#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#ifdef _WIN32
#include <Windows.h>
#endif

std::string file_name;
std::string temp_path;

void get_time() {
    // 获取当前时间并格式化为文件名
    time_t t = time(0);
    struct tm* now = localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(now, "%Y-%m-%d_%H-%M-%S");
    file_name = oss.str();
}

void get_dir_path() {
    // 获取临时文件夹路径
    char* temp = std::getenv("TEMP");
    if (temp != nullptr) {
        temp_path = temp;
    }
}

void create_test_file() {
    // 创建文件并写入内容
    std::ofstream test_file(temp_path + "\\" + file_name + ".py");
    if (test_file.is_open()) {
        test_file << "";
        test_file.close();
    }
    
    // 打开文件
    std::string file_path = temp_path + "\\" + file_name + ".py";
    #ifdef _WIN32
    system((file_path).c_str());
    #endif
}

int main() {
    // 清屏
    system("cls");

    // 调用函数
    get_time();
    get_dir_path();
    create_test_file();

    return 0;
}
