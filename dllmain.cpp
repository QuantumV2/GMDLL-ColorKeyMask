#include "pch.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

BOOL SetTransparent(HWND hwnd, COLORREF colorKey) {
    LONG_PTR exStyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
    SetWindowLongPtr(hwnd, GWL_EXSTYLE, exStyle | WS_EX_LAYERED);
    return SetLayeredWindowAttributes(hwnd, colorKey, 0, LWA_COLORKEY);
}

extern "C" __declspec(dllexport) double MakeColorTransparent(const char* hwndString, double r, double g, double b) {
    HWND hwnd = reinterpret_cast<HWND>(std::stoull(hwndString, nullptr, 16)); 
    if (!IsWindow(hwnd)) {
        MessageBoxA(NULL, "Invalid HWND", "Error", MB_ICONERROR);
        return 0.0;
    }
    COLORREF colorKey = RGB((int)r, (int)g, (int)b);
    return (double)SetTransparent(hwnd, colorKey);
}

//TODO: Fix these functions

/*BOOL WRAPPER_RemoveTransparency(HWND hwnd) {
    LONG_PTR exStyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
    SetWindowLongPtr(hwnd, GWL_EXSTYLE, exStyle & ~WS_EX_LAYERED);
    RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME | RDW_ALLCHILDREN);
    return FALSE;
}

extern "C" __declspec(dllexport) double RemoveTransparency(const char* hwndString) {
    HWND hwnd = reinterpret_cast<HWND>(std::stoull(hwndString, nullptr, 16));
    WRAPPER_RemoveTransparency(hwnd);
    return 0.0;
}*/