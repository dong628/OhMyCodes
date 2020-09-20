from Crypto.Cipher import AES
from Crypto.Util.number import long_to_bytes
from random import getrandbits
from binascii import hexlify, unhexlify
import os

key = long_to_bytes(getrandbits(128))
iv = long_to_bytes(getrandbits(128))

XOR = lambda s1, s2: bytes([x1 ^ x2 for x1, x2 in zip(s1, s2)])


def pad(plain):
    padlen = 16 - len(plain) % 16
    return plain + bytes([padlen] * padlen)


def unpad(cipher):
    padlen = cipher[-1]
    for i in range(1, padlen):
        if cipher[-i] != padlen:
            print('padding check fail')
            return 0
    return cipher[:-padlen]


def my_cbc_enc(plain):
    plain = pad(plain)
    plainblocks = [plain[i * 16:i * 16 + 16] for i in range(len(plain) // 16)]
    cipherblocks = []
    tmpiv = iv
    aes = AES.new(key, AES.MODE_ECB)
    for i in range(len(plainblocks)):
        cipherblocks.append(XOR(tmpiv, aes.encrypt(plainblocks[i])))
        tmpiv = cipherblocks[-1]
    return b''.join(cipherblocks)


def my_cbc_dec(cipher):
    assert len(cipher) % 16 == 0
    aes = AES.new(key, AES.MODE_ECB)
    cipherblocks = [iv] + [cipher[i * 16:i * 16 + 16]
                           for i in range(len(cipher) // 16)]
    plainblocks = []
    for i in range(1, len(cipherblocks)):
        tempcipher = XOR(cipherblocks[i], cipherblocks[i - 1])
        plainblocks.append(aes.decrypt(tempcipher))
    plain = b''.join(plainblocks)
    print(plain)
    return unpad(plain)


def signup(usercount):
    print("user name:")
    name = input().encode()
    cookie = 'username=' + \
        hexlify(name).decode() + \
        ';is_admin=0;user_id=mss2020_{};'.format(usercount)
    print(hexlify(my_cbc_enc(cookie.encode())))
    usercount += 1


def check():
    print("user name:")
    name = input().encode()
    print('cookie:(in hex)')
    cookie = input().encode()
    cookie = my_cbc_dec(unhexlify(cookie))
    print(cookie)
    if cookie == 0:
        return
    cookielist = cookie.split(b';')
    print(cookielist)
    username = cookielist[0].split(b'=')[1]
    admin = cookielist[1].split(b'=')[1]
    if name != unhexlify(username):
        print('name error')
    else:
        if int(admin) == 1:
            print(os.getenv('FLAG'))
        else:
            print('login success')


if __name__ == "__main__":
    usercount = 0
    while 1:
        print('what do you want to do?')
        print('1.signup')
        print('2.login')
        print('3.exit')
        choice = input()
        if choice == '1':
            signup(usercount)
        elif choice == '2':
            check()
        else:
            exit(0)
