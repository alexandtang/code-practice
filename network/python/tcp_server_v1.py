import socket
import threading,time

def tcplink(sock, addr):
    print('Accepted new connection from {0} {0}...'.format(addr))
    sock.send(b'Welcome!\r\n')
    while True:
        data = sock.recv(1024)
        if not data or data.decode('utf-8')== 'exit':
            break
        print('Receving data: {0}'.format(data.decode('utf-8')))
        sock.send('Hello {0}!'.format(data.decode('utf-8')).encode('utf-8'))
    sock.close()
    print('Connection from {0}: {0} closed.'.format(addr))

s = socket.socket()
s.bind(('127.0.0.1',8888))
s.listen(5)
print('Waiting for new connection......')
while True:
    sock, addr = s.accept()
    t = threading.Thread(target=tcplink, args=(sock, addr))
    t.start()

