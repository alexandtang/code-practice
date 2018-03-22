import socket
import time

s = socket.socket()
address = '127.0.0.1'
port = 8888  

try:
    s.connect((address, port))   
    # Get welcome message first
    print('Sending {}\r\n\r\n'.format(i))
    print('Receving data: \r\n-----------')
    print(s.recv(1024).decode('utf-8'))
    print('-----------\r\n\r\n')
    
    for i in ['Alex','Bob','Cat']:
        s.send(bytes(i.encode('utf-8')))
        time.sleep(1)
        print('Sending {}\r\n\r\n'.format(i))
        print('Receving data: \r\n-----------')
        print(s.recv(1024).decode('utf-8'))
        print('-----------\r\n\r\n')

    s.send(b'exit')
except Exception as e: 
    print("Error from %s:%d. Exception is %s" % (address, port, e))
finally:
    s.close()
