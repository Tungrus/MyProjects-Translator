
#include <iostream>
#include <Windows.h>
#include <functional>

using namespace std;
using namespace std::placeholders;

class A;

LRESULT CALLBACK WindowProc(
	A *a,
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	);

class A
{
public:
	A() {
		auto func = std::bind(WindowProc, this, _1, _2, _3, _4);

		WNDCLASSEX c;
		c.lpfnWndProc = (WNDPROC)&func;
	}

	void f() {}

};


LRESULT CALLBACK WindowProc(
	A *a,
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	a->f();
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	A *a = new A();

	return 0;
}