from datetime import datetime
import pytz
import os
def get_time():
    global file_name
    utc_plus_8 = datetime.now(pytz.timezone('Asia/Shanghai'))
    file_name = utc_plus_8.strftime("%Y-%m-%d_%H-%M-%S")
def get_dir_path():
    global temp_path
    temp_path = os.getenv("TEMP")
def create_test_file():
    with open(temp_path+"\\"+file_name+".py", "w", encoding="utf-8") as test_file:
        test_file.write("")
    os.startfile(temp_path+"\\"+file_name+".py")
if __name__ == "__main__":
    os.system("cls")
    get_time()
    get_dir_path()
    create_test_file()