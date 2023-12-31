#include "pch.h"
#include "mem.h"

DWORD PID;

using namespace std;

// 读int类型
//int readInt(__int64 address)
//{
//	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
//	if (handle == NULL)
//	{
//		return -1;
//	}
//
//	int value;
//	if (ReadProcessMemory(handle, (void*)address, &value, 4, NULL))
//	{
//		return value;
//	}
//
//	CloseHandle(handle);
//	return -1;
//}

int readInt(HANDLE handle, __int64 address)
{
	int value;
	if (ReadProcessMemory(handle, (void*)address, &value, 4, NULL))
	{
		return value;
	}
	return -1;
}

// 写入int数据
bool writeInt(__int64 address, __int64 value)
{
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (handle == NULL)
	{
		return false;
	}

	if (WriteProcessMemory(handle, (void*)address, &value, 4, NULL)) {
		CloseHandle(handle);
		return true;
	}
	return false;
}

// 读取long类型
//__int64 readLong(__int64 address)
//{
//	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
//	if (handle == NULL)
//	{
//		return -1;
//	}
//
//	__int64 value;
//	if (ReadProcessMemory(handle, (void*)address, &value, 8, NULL))
//	{
//		return value;
//	}
//
//	CloseHandle(handle);
//	return -1;
//}

__int64 readLong(HANDLE handle, __int64 address)
{
	__int64 value;
	if (ReadProcessMemory(handle, (void*)address, &value, 8, NULL))
	{
		return value;
	}
	return -1;
}

// 写入long数据
bool writeLong(__int64 address, __int64 value)
{
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (handle == NULL)
	{
		return false;
	}

	bool res = WriteProcessMemory(handle, (void*)address, &value, 8, NULL);
	CloseHandle(handle);
	return res;
}

// 读取浮点数
//float readFloat(__int64 address)
//{
//	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
//	if (handle == NULL)
//	{
//		return -1;
//	}
//
//	float value;
//	if (ReadProcessMemory(handle, (void*)address, &value, 4, NULL))
//	{
//		return value;
//	}
//	CloseHandle(handle);
//	return -1;
//}

float readFloat(HANDLE handle, __int64 address)
{
	float value;
	if (ReadProcessMemory(handle, (void*)address, &value, 4, NULL))
	{
		return value;
	}
	return -1;
}

double readDouble(HANDLE handle, __int64 address)
{
	double value;
	if (ReadProcessMemory(handle, (void*)address, &value, 8, NULL))
	{
		return value;
	}
	return -1;
}

// 写入浮点数据
bool writeFloat(__int64 address, float value)
{
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (handle == NULL)
	{
		return false;
	}
	bool res = WriteProcessMemory(handle, (void*)address, &value, 4, NULL);
	CloseHandle(handle);
	return res;
}

// 读取字节数组
vector<byte> readByteArray(__int64 address, int length)
{
	vector<byte> result;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (handle == NULL)
	{
		return result;
	}

	byte* tempResult;
	tempResult = new byte[length];
	memset(tempResult, 0, length);
	ReadProcessMemory(handle, (LPCVOID)address, tempResult, length, NULL);
	result.resize(length);
	for (int i = 0; i < length; i++)
	{
		result[i] = tempResult[i];
	}

	CloseHandle(handle);
	return result;
}

CString readCString(HANDLE handle,__int64 address,int length) 
{
	wchar_t* tempResult;
	tempResult = new wchar_t[length];
	memset(tempResult, 0, length);
	ReadProcessMemory(handle, (LPCVOID)address, tempResult, length, NULL);
	CString newstr(tempResult);
	return newstr;
}

// 写入字节数组
bool writeByteArray(__int64 address, vector<byte> Data)
{
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (handle == NULL)
	{
		return false;
	}

	int length;
	length = (int)Data.size();
	byte* val = new byte[length];
	for (int i = 0; i < length; i++)
	{
		val[i] = Data[i];
	}
	bool res = WriteProcessMemory(handle, (LPVOID)address, (LPCVOID)val, length, NULL);
	CloseHandle(handle);
	return res;
}

// wstring转字节数组
vector<byte> wstringToBytes(wstring w_string)
{
	vector<byte> data;
	// 获取宽字符串指针
	const wchar_t* ptr1 = w_string.c_str();
	// 转为字符指针
	byte* pChar = (byte*)ptr1;
	// 获取字符长度（不包含\0）;
	size_t leng = w_string.size() * 2;
	// 字符放入到容器
	for (size_t i = 0; i < leng; i++) {
		data.push_back((byte) * (pChar + i));
	}

	data.push_back(0);
	data.push_back(0);
	return data;
}

// 字节数组转wstring
wstring bytesToWstring(vector<byte> data)
{
	// 声明宽字符串
	wstring wstr;
	// 获取字符长度（不包含\0）;
	size_t length = data.size() - 2;
	// 重新设置字符串大小
	wstr.resize(length / 2, 0);
	// 获取字符串指针
	byte* pByte = (byte*)wstr.data();
	// 填充字符串
	for (size_t i = 0; i < length; i++)
	{
		*pByte = data[i];
		pByte++;
	}

	return wstr;
}

// 创建字节数组
vector<byte> makeByteArray(vector<byte> data)
{
	return data;
}

// 创建指定长度的字节数组
vector<byte> makeEmptyByteArray(int length)
{
	vector<byte> data;
	for (int i = 0; i < length; i++)
	{
		data.push_back(NULL);
	}

	return data;
}

// int转字节数组
vector<byte> intToBytes(int length) {
	__int64  adr = (__int64)&length;
	vector<byte>c;
	for (size_t i = 0; i < 4; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

// long转字节数组
vector<byte> longToBytes(__int64 length) {
	__int64  adr = (__int64)&length;
	vector<byte>c;
	for (size_t i = 0; i < 8; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

// 运算符重载
vector<byte> operator+(vector<byte> a, vector<byte> b)
{
	for (int i = 0; i < b.size(); i++)
	{
		a.push_back(b[i]);
	}

	b.clear();

	return a;
}