#pragma once
#include <d3d9.h>

namespace gui
{
	//constant window size
	constexpr int WIDTH = 500;
	constexpr int HEIGHT = 300;

	inline bool exit = true;

	//winapi window vars
	inline HWND window = nullptr;
	inline WNDCLASSEXA windowClass = { };

	//points for window movement 
	inline POINTS position = { };

	inline PDIRECT3D9 d3d = nullptr;
	inline LPD3DVERTEXELEMENT9 device = nullptr;
	inline D3DPRESENT_PARAMETERS presentParameter = { };

	// handle windows creation and deleiton
	void CreateHWindow(
		const char* windowName,
		const char* className) noexcept;
	void DestroyHWidnow() noexcept;

	//handle devices creation and deletion
	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	// handle the Im GUi creation and destruction
	void CreateImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;
	void Render() noexcept;

	}
}