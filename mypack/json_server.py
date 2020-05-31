import socket
import json5,os
import hashlib
file_name="1234.zip"
# file_name="config.json"
address = ('127.0.0.1', 8899)

conn = socket.socket()
conn.connect(address)

file_size = os.path.getsize(file_name)
conn.send(file_name.encode())

conn.send("\0\0\0\0".encode())
conn.send(str(file_size).encode())
msg=conn.recv(1024)

m=hashlib.md5()
send_size=0
f=open(file_name,"rb")
# f.close()
while send_size < file_size:
    send_len=0
    send_data=None
    # send_len = conn.send("\n".encode())  # 多次接收内容，接收大数据   
    try:
        send_data=f.read(1024)
        # print(send_data)   
        send_len = conn.send(send_data)  # 多次接收内容，接收大数据   
        print("发送成功一次，字节数"+str(send_len))
    except Exception as err:
        pass
    if send_len>0:
        m.update(send_data)
    send_size+=send_len
    # f.seek(send_size)
    # conn.recv(100)
    
md5sum=m.hexdigest()
conn.recv(1024)
conn.send(md5sum.encode())
print(md5sum)
f.close()
answer=conn.recv(1024).decode()
print(answer)
conn.close()
print(file_size)
