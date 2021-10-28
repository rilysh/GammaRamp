# GammaRamp
Programmatically set Windows Desktop Gamma Ramp, using `SetDeviceGammaRamp` (GDI32) WinAPI. Please keep in mind, this WinAPI have major limitation on such behaviours, for only example purpose.

# Limitations and Conclusion
`SetDeviceGammaRamp` may not work on old graphics card / some of new graphics card. If this happens try using an old computer (if it brokes on Win10 or 11, try using XP to 7). Graphics limited to `65535` array. For more information refer to see msdocs. [Documentation](https://docs.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-setdevicegammaramp), for a bit more explanation you may see pInvoke site. [pInvoke-Example](https://www.pinvoke.net/default.aspx/gdi32.setdevicegammaramp)

