#include <windows.h>

int main()
{
	typedef BOOL (WINAPI *TypeSetDeviceGamma)(HDC hdc, LPVOID lpRamp);
	TypeSetDeviceGamma SetGamaRamp;

	HMODULE gdi32 = LoadLibrary("gdi32.dll");
	if (gdi32 == NULL) return 1;
	SetGamaRamp = (TypeSetDeviceGamma)GetProcAddress(gdi32, "SetDeviceGammaRamp");
	if (SetGamaRamp == NULL) return 1;
    WORD GammaArray[3][256];
	WORD GamaRate = 120;

	for (int i = 0; i < 256; i++)
	{
		int arr = i * (GamaRate + 128); // GamaRate 128 = Normal 
		if (arr > 65535) arr = 65535;
		
		GammaArray[0][i] = 
		GammaArray[1][i] = 
		GammaArray[2][i] = (WORD)arr;
    }
    HDC hdc = GetDC(GetDesktopWindow());
    SetGamaRamp(hdc, GammaArray);
	ReleaseDC(NULL, hdc);
    return 0;
}
