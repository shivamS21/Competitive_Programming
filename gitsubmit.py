import glob
import os.path
import subprocess
import time
folder_path = r'C:\Users\2019u\Desktop\cpp_projects'
file_type = r'\*cpp'
files = glob.glob(folder_path + file_type)
max_file = max(files, key=os.path.getctime)

print(max_file)
command = ["g++", "-std=c++17", max_file]
content = subprocess.check_output(' '.join(command), shell=True).decode('utf-8').split('\n')
time.sleep(3)
if content == ['']:
    #execute executable = '.\a.exe'
    content = subprocess.check_output("./a.exe", shell=True).decode('utf-8').split('\n')
    print(content)
    # file_type = r'\*exe'
    # files = glob.glob(folder_path + file_type)
    # max_file = max(files, key=os.path.getctime)
    # print(max_file)
    # content = subprocess.check_output(max_file, shell=True).decode('utf-8').split('\n')
    # print(content)
else:
    print("shivam")