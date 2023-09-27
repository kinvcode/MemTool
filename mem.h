#pragma once
#include <vector>
#include "string"
#include <windows.h>

using namespace std;

//int readInt(__int64 address);

int readInt(HANDLE handle, __int64 address);

bool writeInt(__int64 address, __int64 value);

__int64 readLong(HANDLE handle, __int64 address);

bool writeLong(__int64 address, __int64 value);

//float readFloat(__int64 address);
float readFloat(HANDLE handle, __int64 address);

double readDouble(HANDLE handle, __int64 address);

bool writeFloat(__int64 address, float value);

vector<byte> readByteArray(__int64 address, int length);

CString readCString(HANDLE handle, __int64 address, int length);

bool writeByteArray(__int64 address, vector<byte> Data);

vector<byte> wstringToBytes(wstring w_string);

wstring bytesToWstring(vector<byte> data);

vector<byte> makeByteArray(vector<byte> data);

vector<byte> makeEmptyByteArray(int length);

vector<byte> intToBytes(int length);

vector<byte> longToBytes(__int64 length);

vector<byte> operator+(vector<byte> a, vector<byte> b);