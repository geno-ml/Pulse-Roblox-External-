#define IMGUI_DEFINE_MATH_OPERATORS


#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_freetype.h"
#include "imgui/custom_functions.h"
#include "imgui/fonts.h"
#include "imgui/images.h"
#include "imgui/skins.h"
#include "imgui/esp_preview.h"
#include <urlmon.h>
#include <d3d11.h>
#include <string>
#include <sstream>
#include <tchar.h>
#include <d3dx11.h>
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "urlmon.lib")

#include "overlay.hpp"

#include <d3d11.h>
#include <tchar.h>

#include <D3DX11tex.h>
#pragma comment(lib, "D3DX11.lib")


#include <dwmapi.h>
#include "../../ImGui/sounds.h"
#include "../../features/visuals/esp.hpp"
#include "../../features/globals/globals.hpp"
#include <../features/player/playerClass.h>

#include <vector>


#include "ckeybind/keybind.hpp"
#include "../skcrypt/skStr.hpp"
#include "../xorstr/xorstr.hpp"

#include "../configs/configs.hpp"
#include "../json/json.hpp"
#include <thread>

#include <filesystem>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <cmath>

#include <d3d11.h>
#include <tchar.h>



#include <string>



const char* GetWorldTime() {
	time_t now = time(0);
	tm* localTime = localtime(&now);
	static char world_time[10];
	strftime(world_time, sizeof(world_time), "%I:%M%p", localTime);
	return world_time;
}

std::vector<ID3D11ShaderResourceView*> default_skins_texture(default_skins.size());
std::vector<ID3D11ShaderResourceView*> cz75_skins_texture(cz75_skins.size());
std::vector<ID3D11ShaderResourceView*> ak47_skins_texture(ak47_skins.size());
std::vector<ID3D11ShaderResourceView*> awp_skins_texture(awp_skins.size());

std::vector<std::vector<ID3D11ShaderResourceView*>> all_skins_textures;

ID3D11ShaderResourceView* load_image(ID3D11Device* pDevice, const char* url)
{
	std::string cached_file_path;

	char cache_file[MAX_PATH] = { 0 };
	HRESULT hr = URLDownloadToCacheFileA(nullptr, url, cache_file, MAX_PATH, 0, nullptr);
	if (SUCCEEDED(hr)) {
		cached_file_path = cache_file;
	}

	D3DX11_IMAGE_LOAD_INFO info; ID3DX11ThreadPump* pump{ nullptr };

	ID3D11ShaderResourceView* texture = nullptr;
	D3DX11CreateShaderResourceViewFromFileA(pDevice, cached_file_path.c_str(), &info, pump, &texture, 0);
	return texture;
}


#ifndef _MIN_MUL
#define _MIN_MUL 0.00
#define _MAX_MUL 0.50
#endif

#ifndef _MIN_DIV
#define _MIN_DIV 0.00
#define _MAX_DIV 10.00
#endif


#include <D3DX11tex.h>
#pragma comment(lib, "D3DX11.lib")

static int notify_select = 0;
const char* notify_items[2]{ "Circle", "Line" };


float calc_dist_3d_x(pulse::roblox::vector3_t first, pulse::roblox::vector3_t sec)
{
	return sqrt((first.x - sec.x) * (first.x - sec.x) + (first.y - sec.y) * (first.y - sec.y) + (first.z - sec.z) * (first.z - sec.z));
}

pulse::roblox::vector3_t vector_sub_x(pulse::roblox::vector3_t one, pulse::roblox::vector3_t two)
{
	return { one.x - two.x, one.y - two.y, one.z - two.z };
}

float vector3_mag_x(pulse::roblox::vector3_t vector)
{
	return sqrtf((vector.x * vector.y) + (vector.y * vector.y) + (vector.z * vector.z));
}


namespace vector_ops_x {
	float distance(const pulse::roblox::vector3_t& a, const pulse::roblox::vector3_t& b) {
		return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
	}

	pulse::roblox::vector3_t subtract(const pulse::roblox::vector3_t& a, const pulse::roblox::vector3_t& b) {
		return { a.x - b.x, a.y - b.y, a.z - b.z };
	}

	float magnitude(const pulse::roblox::vector3_t& v) {
		return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	}
}







using namespace ImGui;

DWORD picker_flags = ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview;

#include "../../game/overlay/imgui/imgui.h"
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <set>
#include <deque>
#include <chrono>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "D3DCompiler.lib")





pulse::roblox::instance_t FindPlayerByName(const std::string& name) {

	auto players = globals::players;

	for (auto& player : players.children()) {
		if (player.name() == name) {
			return player;
		}
	}
	return pulse::roblox::instance_t();
}

struct Notification {
	int id;
	std::string message;
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point endTime;
};






#include "iostream"



ID3D11Device* pulse::utils::overlay::d3d11_device = nullptr;

ID3D11DeviceContext* pulse::utils::overlay::d3d11_device_context = nullptr;

IDXGISwapChain* pulse::utils::overlay::dxgi_swap_chain = nullptr;

ID3D11RenderTargetView* pulse::utils::overlay::d3d11_render_target_view = nullptr;

static const char* combo_items_4[4] = { ("Head"), ("Upper Torso"), ("Humanoid"), ("LowerTorso") };
static const char* macro_items[2] = { ("First Person"), ("I & O Keys") };
static const char* box_items_3[5] = { ("2D Box 1"), ("3D Box"), ("3D Corner Box"), ("2D Box 2"), ("2D Box 3") };
static const char* shake_items[2] = { ("Axis Movement"), ("Scaling") };
static const char* aimbot_items[3] = { ("Mouse"), ("Camera"), ("Silent Aim") };

static const char* pred_items[2] = { ("Division"), ("Multiplication") };
static const char* fovitems[3] = { ("Fov 1"), ("Fov 2"), ("Fov 3") };
static const char* head_dotx[2] = { ("Circle"), ("Filled") };
static const char* thread_type[2] = { ("Milliseconds"), ("Microseconds") };
static const char* smooth_typessex[5] = { ("Linear"), ("Bounce"), ("Elastic"), ("Quadratic"), ("Decay") };

static const char* prediction_methods[2] = { ("Axis Movement"), ("Scaling") };

static const char* hit_sounds[4] = { ("Neverlose"), ("Skeet"), ("Fuck"), ("Senpai") };


std::string getCurrentTime() {
	auto now = std::chrono::system_clock::now();
	auto now_time_t = std::chrono::system_clock::to_time_t(now);
	auto now_tm = std::localtime(&now_time_t);

	std::stringstream ss;
	ss << std::put_time(now_tm, "%H:%M:%S");
	return ss.str();
}

std::vector<std::string> fetchPlayerNames() {
	std::vector<std::string> playerNames;

	auto players = globals::players;

	for (auto& player : playerList) {
		if (!player.playerInstance.self) continue;

		auto playerName = player.playerInstance.name();
		playerNames.push_back(playerName);
	}




	return playerNames;
}

bool Keybind(CKeybind* keybind, const ImVec2& size_arg = ImVec2(0, 0), bool clicked = false, ImGuiButtonFlags flags = 0)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(keybind->get_name().c_str());
	const ImVec2 label_size = ImGui::CalcTextSize(keybind->get_name().c_str(), NULL, true);

	ImVec2 pos = window->DC.CursorPos;
	if ((flags & ImGuiButtonFlags_AlignTextBaseLine) &&
		style.FramePadding.y <
		window->DC.CurrLineTextBaseOffset)
		pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
	ImVec2 size = ImGui::CalcItemSize(
		size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, pos + size);
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	if (g.CurrentItemFlags & ImGuiItemFlags_ButtonRepeat)
		flags |= ImGuiButtonFlags_Repeat;
	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, flags);

	bool value_changed = false;
	int key = keybind->key;

	auto io = ImGui::GetIO();

	std::string name = keybind->get_key_name();

	if (keybind->waiting_for_input)
		name = "waiting";

	if (ImGui::GetIO().MouseClicked[0] && hovered)
	{
		if (g.ActiveId == id)
		{
			keybind->waiting_for_input = true;
		}
	}
	else if (ImGui::GetIO().MouseClicked[1] && hovered)
	{
		ImGui::OpenPopup(keybind->get_name().c_str());
	}
	else if (ImGui::GetIO().MouseClicked[0] && !hovered)
	{
		if (g.ActiveId == id)
			ImGui::ClearActiveID();
	}

	if (keybind->waiting_for_input)
	{
		if (ImGui::GetIO().MouseClicked[0] && !hovered)
		{
			keybind->key = VK_LBUTTON;

			ImGui::ClearActiveID();
			keybind->waiting_for_input = false;
		}
		else
		{
			if (keybind->set_key())
			{
				ImGui::ClearActiveID();
				keybind->waiting_for_input = false;
			}
		}
	}


	ImVec4 textcolor = ImLerp(ImVec4(201 / 255.f, 204 / 255.f, 210 / 255.f, 1.f), ImVec4(1.0f, 1.0f, 1.0f, 1.f), 1.f);


	window->DrawList->AddRectFilled(bb.Min, bb.Max, ImColor(33 / 255.0f, 33 / 255.0f, 33 / 255.0f, 0.5f), 2.f);







	ImVec2 text_pos = bb.Min + ImVec2(
		size_arg.x / 2 - ImGui::CalcTextSize(name.c_str()).x / 2,
		size_arg.y / 2 - ImGui::CalcTextSize(name.c_str()).y / 2);

	window->DrawList->AddText(text_pos, ImGui::GetColorU32(textcolor), name.c_str());

	if (ImGui::BeginPopup(keybind->get_name().c_str(), 0))
	{
		ImGui::BeginGroup();
		if (ImGui::Selectable("Hold", keybind->type == CKeybind::HOLD))
			keybind->type = CKeybind::HOLD;
		if (ImGui::Selectable("Toggle", keybind->type == CKeybind::TOGGLE))
			keybind->type = CKeybind::TOGGLE;
		ImGui::EndGroup();
		ImGui::EndPopup();
	}


	return pressed;
}


bool pulse::utils::overlay::fullsc(HWND windowHandle)
{
	MONITORINFO monitorInfo = { sizeof(MONITORINFO) };
	if (GetMonitorInfo(MonitorFromWindow(windowHandle, MONITOR_DEFAULTTOPRIMARY), &monitorInfo))
	{
		RECT windowRect;
		if (GetWindowRect(windowHandle, &windowRect))
		{
			return windowRect.left == monitorInfo.rcMonitor.left
				&& windowRect.right == monitorInfo.rcMonitor.right
				&& windowRect.top == monitorInfo.rcMonitor.top
				&& windowRect.bottom == monitorInfo.rcMonitor.bottom;
		}
	}
}

std::string GetConfigFolderPath()
{
	std::string configFolderPath = pulse::utils::appdata_path() + "\\pulse\\configs";

	if (!std::filesystem::exists(configFolderPath))
	{
		std::filesystem::create_directory(configFolderPath);
	}

	return configFolderPath;
}

bool isValid(const std::string& str) {
	bool startsWithNumber = std::isdigit(str[0]);
	bool containsSymbol = false;

	for (char ch : str) {
		if (!std::isalnum(ch) && ch != '_') {
			containsSymbol = true;
			break;
		}
	}

	return startsWithNumber || containsSymbol;
}

void DrawInstance(pulse::roblox::instance_t& instance)
{
	auto children = instance.children();
	bool hasChildren = !children.empty();
	bool isLeaf = !hasChildren;

	// Display label with arrow to indicate expansion state if it has children
	bool isExpanded = !isLeaf && ImGui::TreeNodeEx(instance.name().c_str(), ImGuiTreeNodeFlags_SpanFullWidth);

	if (isExpanded) {
		// If label is expanded, recursively draw its children
		for (auto& child : children) {
			DrawInstance(child);
		}
		ImGui::TreePop();
	}
	else if (isLeaf) {
		// If no children, just display the label without arrow
		ImGui::Bullet();
		ImGui::Text("%s", instance.name().c_str());
	}
}

void OpenGameExplorer()
{
	auto datamodelObject = globals::datamodel;
	if (datamodelObject.self) {
		ImGui::BeginChild("Game Explorer", ImVec2(300, 600), true, ImGuiWindowFlags_AlwaysVerticalScrollbar);

		DrawInstance(const_cast<pulse::roblox::instance_t&>(datamodelObject));

		ImGui::EndChild();
	}
 }


void DisplayInstanceTree(pulse::roblox::instance_t instance, std::string parentPath = "NULL")
{
	std::string instancePath;
	std::string istanceName = instance.name();

	if (parentPath == "NULL") {
		instancePath = "game:GetService(\"";
	}
	else {
		instancePath = (parentPath == "game:GetService(\"") ? parentPath + istanceName + "\")" : (!isValid(istanceName)) ? parentPath + "[\"" + istanceName + "\"]" : parentPath + "." + instance.name();
	}

	for (auto& child : instance.children())
	{
		std::string childName = child.name();
		std::string childPath = instancePath + "[\"" + childName + "\"]";

		ImGui::PushID(childPath.c_str());
		bool isNodeOpen = ImGui::TreeNodeEx(childName.c_str(), ImGuiTreeNodeFlags_OpenOnArrow);

		if (ImGui::IsItemHovered() && ImGui::IsMouseReleased(1))
		{
			ImGui::OpenPopup("Context Menu");
		}

		if (ImGui::BeginPopup("Context Menu"))
		{
			if (ImGui::MenuItem("Copy Path"))
			{
				ImGui::SetClipboardText(childPath.c_str());
			}
			ImGui::EndPopup();
		}

		if (isNodeOpen)
		{
			DisplayInstanceTree(child, instancePath);
			ImGui::TreePop();
		}

		ImGui::PopID();
	}
}

static char text[999] = "";
char configname[100];

bool pulse::utils::overlay::init = false;

bool if_first = false;

bool ButtonCenteredOnLine(const char* label, float alignment = 0.5f)
{
	ImGuiStyle& style = ImGui::GetStyle();

	float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
	float avail = ImGui::GetContentRegionAvail().x;

	float off = (avail - size) * alignment;
	if (off > 0.0f)
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

	return ImGui::Button(label);
}

std::map<std::string, float> previousHealths;

void CheckHealthAndNotify() {
	if (!globals::friendlynotifier) {
		return;
	}

	printf("Friendly notifier status: %s\n", globals::friendlynotifier ? "Enabled" : "Disabled");

	for (const auto& playerName : globals::aimwhitelistedPlayers) {
		auto playerInstance = FindPlayerByName(playerName);
		printf("Retrieving player: %s - Found: %s\n", playerName.c_str(), playerInstance.self ? "Yes" : "No");

		if (playerInstance.self) {
			auto humanoid = playerInstance.find_first_child("Humanoid");
			printf("Retrieving humanoid for player: %s - Found: %s\n", playerName.c_str(), humanoid.self ? "Yes" : "No");

			if (humanoid.self) {
				float currentHealth = humanoid.get_health();
				printf("Direct Health for %s: %f\n", playerName.c_str(), currentHealth);

				if (previousHealths.find(playerName) != previousHealths.end()) {
					float previousHealth = previousHealths[playerName];
					printf("Previous Health for %s: %f\n", playerName.c_str(), previousHealth);

					if (currentHealth < previousHealth) {
						float damageTaken = previousHealth - currentHealth;
						char notificationMessage[256];
						snprintf(notificationMessage, sizeof(notificationMessage), "%s took %.0f damage.", playerName.c_str(), damageTaken);
						printf("Sending notification: %s\n", notificationMessage);
					}
				}
				else {
					printf("No previous health record found for player: %s\n", playerName.c_str());
				}
				previousHealths[playerName] = currentHealth;
			}
		}
	}
}



static HWND Background() {
	Sleep(50);
	return GetForegroundWindow();
}


bool pulse::utils::overlay::render()
{
	//name.clear(); ownerid.clear(); secret.clear(); version.clear(); url.clear();

	/*if (if_first)
	{
		KeyAuthApp.init();
		if_first = false;
	}*\

	nlohmann::json json;

	/*if (globals::show_auth)
	{
		std::string filePath = appdata_path() + XorStr("\\pulse\\license.json");
		if (std::filesystem::exists(filePath))
		{
			std::ifstream file(filePath);
			if (file.is_open())
			{
				file >> json;
				file.close();

				std::string stored_license = json["license"];
				KeyAuthApp.license(stored_license);

				if (KeyAuthApp.data.success)
				{
					globals::show_auth = false;
				}
				else
				{
					exit(0);
				}
			}
		}
		*/
	ImGui_ImplWin32_EnableDpiAwareness();

	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = GetModuleHandle(nullptr);
	wc.lpfnWndProc = window_proc;
	wc.lpszClassName = TEXT("Pulse");
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClassEx(&wc);
	const HWND hw = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE, wc.lpszClassName, TEXT("Pulse"),
		WS_POPUP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, wc.hInstance, nullptr);

	SetLayeredWindowAttributes(hw, 0, 255, LWA_ALPHA);
	const MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(hw, &margin);

	if (!create_device_d3d(hw))
	{
		cleanup_device_d3d();
		UnregisterClass(wc.lpszClassName, wc.hInstance);
		return false;
	}

	ShowWindow(hw, SW_SHOW);
	UpdateWindow(hw);

	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui::GetIO().IniFilename = nullptr;

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4 originalButtonColor = style.Colors[ImGuiCol_Button];

	ImGuiIO& io = ImGui::GetIO();



	ImFontConfig cfg;
	cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_Bitmap;
	set->selection_font = io.Fonts->AddFontFromMemoryTTF(inter_semibold_hex, sizeof inter_semibold_hex, 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->child_label_font = io.Fonts->AddFontFromMemoryTTF(inter_semibold_hex, sizeof inter_semibold_hex, 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->widgets_font = io.Fonts->AddFontFromMemoryTTF(inter_semibold_hex, sizeof inter_semibold_hex, 12.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->value_font = io.Fonts->AddFontFromMemoryTTF(inter_semibold_hex, sizeof inter_semibold_hex, 10.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->dropdown_font = io.Fonts->AddFontFromMemoryTTF(icons_hex, sizeof icons_hex, 5.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->pippette_font = io.Fonts->AddFontFromMemoryTTF(icons_hex, sizeof icons_hex, 12.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->notify_font = io.Fonts->AddFontFromMemoryTTF(icons_hex, sizeof icons_hex, 11.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->window_icons_font = io.Fonts->AddFontFromMemoryTTF(icons_hex, sizeof icons_hex, 15.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->skin_icons_font = io.Fonts->AddFontFromMemoryTTF(icons2_hex, sizeof icons2_hex, 12.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->close_icon_font = io.Fonts->AddFontFromMemoryTTF(icons2_hex, sizeof icons2_hex, 7.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	set->cfg_icon_font = io.Fonts->AddFontFromMemoryTTF(icons2_hex, sizeof icons2_hex, 10.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());


	for (int i = 0; i < default_skins.size(); i++)
		default_skins_texture.at(i) = load_image(d3d11_device, default_skins.at(i).url.c_str());
	for (int i = 0; i < cz75_skins.size(); i++)
		cz75_skins_texture.at(i) = load_image(d3d11_device, cz75_skins.at(i).url.c_str());
	for (int i = 0; i < ak47_skins.size(); i++)
		ak47_skins_texture.at(i) = load_image(d3d11_device, ak47_skins.at(i).url.c_str());
	for (int i = 0; i < awp_skins.size(); i++)
		awp_skins_texture.at(i) = load_image(d3d11_device, awp_skins.at(i).url.c_str());

	all_skins_textures.push_back(cz75_skins_texture);
	all_skins_textures.push_back(ak47_skins_texture);
	all_skins_textures.push_back(awp_skins_texture);

	D3DX11_IMAGE_LOAD_INFO info; ID3DX11ThreadPump* pump{ nullptr };


	for (int i = 0; i < IM_ARRAYSIZE(selection_binaries); i++)
		if (set->selection_texture_dx11[i] == nullptr)
			D3DX11CreateShaderResourceViewFromMemory(d3d11_device, selection_binaries[i], sizeof(selection_binaries[i]), &info, pump, &set->selection_texture_dx11[i], 0);


	ImGui_ImplWin32_Init(hw);
	ImGui_ImplDX11_Init(d3d11_device, d3d11_device_context);

	const ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	init = true;




	bool draws = false;
	bool done = false;
	bool donesp = false;

	HWND roblox = globals::window_handle;
	HWND GetBackground;







	while (!done)
	{


		MSG msg;
		while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done) break;

		move_window(hw);

		if (GetAsyncKeyState(VK_F2) & 1)
			draws = !draws;

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{


			GetBackground = GetForegroundWindow();


			if (GetBackground == roblox || GetBackground == hw)
			{

				ImGui::Begin("overlay", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoBackground);
				{
					pulse::roblox::hook_esp();
					draw->setup_notify();
					draw->watermark(globals::LocalPlayer.name(), "144", std::to_string(globals::LocalPlayer.get_ping()).c_str());
				}


				if (draws)
				{
					ImGui::SetNextWindowSize(set->window_size);
					gui->begin("Menu", nullptr, ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);
					{
						const ImVec2 pos = ImGui::GetWindowPos();
						const ImVec2 size = ImGui::GetWindowSize();
						ImDrawList* drawlist = ImGui::GetWindowDrawList();
						ImGuiStyle* style = &ImGui::GetStyle();

						{
							style->WindowPadding = set->window_padding;
							style->ItemSpacing = set->window_item_spacing;
							style->WindowBorderSize = set->window_border_size;
							style->WindowShadowSize = set->window_shadow_size;
							style->WindowRounding = set->window_rounding;
							style->ScrollbarSize = set->scrollbar_size;
						}

						{
							drawlist->AddRectFilled(pos, pos + size, draw->get_clr(clr->window_background), style->WindowRounding);
							drawlist->AddLine(pos + ImVec2(0, set->separator_padding), pos + ImVec2(size.x, set->separator_padding), draw->get_clr(clr->window_separator));
							drawlist->AddLine(pos + ImVec2(0, size.y - set->separator_padding - 1), pos + size - ImVec2(0, set->separator_padding + 1), draw->get_clr(clr->window_separator));
						}

						static float tab_alpha = 0.f;
						static int active_tab = 0;

						tab_alpha = ImClamp(tab_alpha + (gui->fixed_speed(6.f) * (set->selection_count == active_tab ? 1.f : -1.f)), 0.f, 1.f);

						if (tab_alpha == 0.f)
							active_tab = set->selection_count;

						{
							gui->set_cursor_pos(ImVec2(set->child_padding.x, size.y - set->separator_padding));
							gui->begin_group();
							{
								for (int i = 0; i < IM_ARRAYSIZE(set->selection_labels); i++)
								{
									gui->selection(set->selection_labels[i], set->selection_texture_dx11[i], i, set->selection_count);
									gui->sameline();
								}
							}
							gui->end_group();
						}

						gui->push_style_var(ImGuiStyleVar_Alpha, tab_alpha);
						{
							for (int i = 0; i < IM_ARRAYSIZE(set->selection_labels); i++)
							{
								if (active_tab == i)
								{
									gui->begin_section_group(set->sections[i].labels.size());
									{
										for (int j = 0; j < set->sections[i].labels.size(); j++)
										{
											gui->section(set->sections[i].labels[j], j, set->sections[i].count);
											gui->sameline();
										}
									}
									gui->end_section_group();
								}
							}
						}

						{
							gui->set_cursor_pos(ImVec2(set->child_padding.x, set->separator_padding + 1));
							gui->begin_content();
							{
								if (tab_alpha == 0.f)
									ImGui::SetScrollY(0.f);

								if (active_tab == 0)
								{
									gui->begin_group();
									{
										gui->begin_child("Aimbot");
										{
											//const char* weapons[5] = { "Pistols", "Heavy Pistols", "Rifles", "Shotguns", "Machineguns" };
											//static int weapons_count = 0;
											//gui->dropdown("Select", &weapons_count, weapons, IM_ARRAYSIZE(weapons));

											//static bool enable_config = true;
											gui->checkbox("Enable Aimbot", &globals::aimbot);
											Keybind(&globals::aimbotkey, ImVec2(60, 20));
										}
										gui->end_child();

										gui->begin_child("General");
										{

											gui->dropdown("Aim Type", &globals::aimtype, aimbot_items, IM_ARRAYSIZE(aimbot_items));
											gui->dropdown("Hitbox", &globals::aimpart, combo_items_4, IM_ARRAYSIZE(combo_items_4));

											//static bool enabled = true;
											//gui->checkbox("Enabled", &enabled);

											//static bool silent_aim = true;
											//gui->checkbox("Silent Aim", &silent_aim);

											//static bool peek_assist = false;
											//gui->checkbox("Peek Assist", &peek_assist);
											if (gui->begin_settings())
											{

												//static float color[4] = { 1.f, 1.f, 1.f, 1.f };
												//gui->color_edit("Color", color, ImGuiColorEditFlags_AlphaBar);

												//static int radius = 25;
												//gui->slider_int("Radius", &radius, 0, 50);

												//static bool auto_return = true;
												//gui->checkbox("Auto Return", &auto_return);

												//gui->end_settings();
											}

											gui->checkbox("Enable Prediction", &globals::prediction);
											gui->checkbox("Enable Smoothness", &globals::smoothness);
											gui->checkbox("Activate Shake Compensation", &globals::shake);

											if (globals::shake) {
												gui->dropdown("Select Type", &globals::shaketype, shake_items, IM_ARRAYSIZE(shake_items));
											}

											gui->checkbox("Enable Aimbot Range", &globals::aimbot_range_enable);
											gui->checkbox("Enable Auto Resolver", &globals::autoresolve);
											gui->checkbox("Disable Outside Field of View", &globals::disable_outside_fov);

											static keybind_state hide_shots_state{ 0, 0, 0 };
											static bool hide_shots = false;
											static bool hide_shots_bind = false;
											//gui->checkbox("Hide Shots", &hide_shots);
											if (gui->begin_settings())
											{
												gui->keybind("Keybind", &hide_shots_state, &hide_shots_bind);

												gui->end_settings();
											}

											static keybind_state double_tap_state{ 0, 0, 0 };
											static bool double_tap = true;
											static bool double_tap_bind = false;
											//gui->checkbox("Double Tap", &double_tap);
											if (gui->begin_settings())
											{
												//gui->keybind("Keybind", &double_tap_state, &double_tap_bind);

												gui->end_settings();
											}

											//static int fov_range = 134;
											//gui->slider_int("FOV Range", &fov_range, 0, 180);

											//static int max_misses = 3;
											//gui->slider_int("Max Misses", &max_misses, 0, 5);
										}
										gui->end_child();
									}
									gui->end_group();

									gui->sameline();

									gui->begin_group();
									{
										gui->begin_child("Configuration");
										{
											static keybind_state hitboxes_state{ 0, 0, 0 };
											const char* hitboxes[7] = { "Head", "Neck", "Stomach", "Body", "Arms", "Legs", "Feets" };
											static bool hitboxes_count[7] = { true, false, true, false, true, false, true };
											static bool hitboxes_count_bind[7] = { false, false, false, false, false, false, false };
											//gui->multi_dropdown("Hitboxes", hitboxes_count, hitboxes, IM_ARRAYSIZE(hitboxes));

											static int key1 = 0;
											double _pred_min = globals::prediction_method == 0 ? _MIN_DIV : _MIN_MUL;
											double _pred_max = globals::prediction_method == 0 ? _MAX_DIV : _MAX_MUL;

											if (globals::prediction_method == 0) {
												if (globals::main_prediction < _MIN_DIV)
													globals::main_prediction = globals::main_close_prediction = globals::main_mid_prediction = globals::main_far_prediction = _MIN_DIV;

												if (globals::prediction_x < _MIN_DIV)
													globals::prediction_x = globals::close_prediction_x = globals::mid_prediction_x = globals::far_prediction_x = _MIN_DIV;

												if (globals::prediction_y < _MIN_DIV)
													globals::prediction_y = globals::close_prediction_y = globals::mid_prediction_y = globals::far_prediction_y = _MIN_DIV;
											}
											else {
												if (globals::main_prediction > _MAX_MUL)
													globals::main_prediction = globals::main_close_prediction = globals::main_mid_prediction = globals::main_far_prediction = _MAX_MUL;

												if (globals::prediction_x > _MAX_MUL)
													globals::prediction_x = globals::close_prediction_x = globals::mid_prediction_x = globals::far_prediction_x = _MAX_MUL;

												if (globals::prediction_y > _MAX_MUL)
													globals::prediction_y = globals::close_prediction_y = globals::mid_prediction_y = globals::far_prediction_y = _MAX_MUL;
											}

											gui->slider_float("Mouse Sensitivity", &globals::sensitivity, 0.1, 5.0, "%.1f");

											if (globals::smoothness_x) {

											gui->slider_float("Smoothness (X-Axis)", &globals::smoothness_x, 1.0, 30.0, "%.1f");
											gui->slider_float("Smoothness (Y-Axis)", &globals::smoothness_y, 1.0, 30.0, "%.1f");

											}

											if (globals::prediction) {

											gui->checkbox("Enable Separate Prediction", &globals::separate_predictions);
											gui->dropdown("Select Prediction Method", &globals::prediction_method, pred_items, IM_ARRAYSIZE(pred_items));

											}

											if (globals::prediction) {
											if (globals::separate_predictions) {
												gui->slider_float("Overall X Prediction Offset", &globals::prediction_x, _pred_min, _pred_max, "%.0005f");
												gui->slider_float("Overall Y Prediction Offset", &globals::prediction_y, _pred_min, _pred_max, "%.0005f");
											}
											else {
												gui->slider_float("Overall Prediction Adjustment", &globals::main_prediction, _pred_min, _pred_max, "%.0005f");
											}
											}

											if (globals::aimbot_range_enable) {
												gui->slider_int("Aimbot Range Limit", &globals::aimbot_range, 1, 100, "%d%%");
											}

											if (globals::autoresolve) {
												gui->slider_float("Velocity Threshold", &globals::velocity_threshold, 1, 100, "%.1f");
											}

											if (globals::shake) {

											if (globals::shaketype == 0) {

												gui->slider_float("Shake X", &globals::shake_x, 0.1, 10.0, "%.1f");
												gui->slider_float("Shake Y", &globals::shake_y, 0.1, 10.0, "%.1f");
											}
											else if (globals::shaketype == 1) {

												gui->slider_float("Shake value", &globals::shake_value, 0.1, 10.0, "%.1f");
											}
											}

											if (gui->begin_settings())
											{



												gui->end_settings();
											}
										}
										gui->end_child();

										if (globals::prediction) {

										gui->begin_child("Prediction");
										{

											static int key1 = 0;
											double _pred_min = globals::prediction_method == 0 ? _MIN_DIV : _MIN_MUL;
											double _pred_max = globals::prediction_method == 0 ? _MAX_DIV : _MAX_MUL;

											if (globals::prediction_method == 0) {
												if (globals::main_prediction < _MIN_DIV)
													globals::main_prediction = globals::main_close_prediction = globals::main_mid_prediction = globals::main_far_prediction = _MIN_DIV;

												if (globals::prediction_x < _MIN_DIV)
													globals::prediction_x = globals::close_prediction_x = globals::mid_prediction_x = globals::far_prediction_x = _MIN_DIV;

												if (globals::prediction_y < _MIN_DIV)
													globals::prediction_y = globals::close_prediction_y = globals::mid_prediction_y = globals::far_prediction_y = _MIN_DIV;
											}
											else {
												if (globals::main_prediction > _MAX_MUL)
													globals::main_prediction = globals::main_close_prediction = globals::main_mid_prediction = globals::main_far_prediction = _MAX_MUL;

												if (globals::prediction_x > _MAX_MUL)
													globals::prediction_x = globals::close_prediction_x = globals::mid_prediction_x = globals::far_prediction_x = _MAX_MUL;

												if (globals::prediction_y > _MAX_MUL)
													globals::prediction_y = globals::close_prediction_y = globals::mid_prediction_y = globals::far_prediction_y = _MAX_MUL;
											}

											if (globals::prediction) {
												gui->checkbox("Enable Distance-Based Prediction", &globals::distpred);

												if (globals::distpred) {
													gui->checkbox("Use Custom Prediction Settings", &globals::separate_predictions);
													gui->dropdown("Choose Prediction Algorithm", &globals::prediction_method, pred_items, IM_ARRAYSIZE(pred_items));
												}

												if (globals::distpred) {
													gui->slider_float("Distance for Close Range", &globals::CloseDistance, 1.00f, 100.00f, "%.1f");

													if (globals::separate_predictions) {
														gui->slider_float("Close Range X Offset", &globals::close_prediction_x, _pred_min, _pred_max, "%.0005f");
														gui->slider_float("Close Range Y Offset", &globals::close_prediction_y, _pred_min, _pred_max, "%.0005f");
													}
													else {
														gui->slider_float("Close Range Prediction Adjustment", &globals::main_close_prediction, _pred_min, _pred_max, "%.0005f");
													}

													gui->slider_float("Distance for Mid Range", &globals::MidDistance, 1.00f, 100.00f, "%.1f");

													if (globals::separate_predictions) {
														gui->slider_float("Mid Range X Offset", &globals::mid_prediction_x, _pred_min, _pred_max, "%.0005f");
														gui->slider_float("Mid Range Y Offset", &globals::mid_prediction_y, _pred_min, _pred_max, "%.0005f");
													}
													else {
														gui->slider_float("Mid Range Prediction Adjustment", &globals::main_mid_prediction, _pred_min, _pred_max, "%.0005f");
													}

													if (globals::separate_predictions) {
														gui->slider_float("Far Range X Offset", &globals::far_prediction_x, _pred_min, _pred_max, "%.0005f");
														gui->slider_float("Far Range Y Offset", &globals::far_prediction_y, _pred_min, _pred_max, "%.0005f");
													}
													else {
														gui->slider_float("Far Range Prediction Adjustment", &globals::main_far_prediction, _pred_min, _pred_max, "%.0005f");
													}
												}
											}
											}
										}
										gui->end_child();
									}
									gui->end_group();
								}
								else if (active_tab == 1)
								{
									static bool flags = false;
									static bool bars = false;
									const char* box_type[2] = { "Default", "Corner" };
									static int box_c = 0;

									gui->begin_group();
									{
										gui->begin_child("General");
										{
											static bool enabled = false;
											gui->checkbox("Enabled", &globals::esp);

											/*gui->checkbox("Flags", &flags);
											if (gui->begin_settings())
											{
												static float defusing_color[4] = { esp_preview::text_colors[1].Value.x, esp_preview::text_colors[1].Value.y, esp_preview::text_colors[1].Value.z, 1.f };
												gui->color_edit("Defusing Color", defusing_color, ImGuiColorEditFlags_AlphaBar);
												esp_preview::text_colors[1].Value.x = defusing_color[0];
												esp_preview::text_colors[1].Value.y = defusing_color[1];
												esp_preview::text_colors[1].Value.z = defusing_color[2];

												static float scoped_color[4] = { esp_preview::text_colors[3].Value.x, esp_preview::text_colors[3].Value.y, esp_preview::text_colors[3].Value.z, 1.f };
												gui->color_edit("Scoped Color", scoped_color, ImGuiColorEditFlags_AlphaBar);
												esp_preview::text_colors[3].Value.x = scoped_color[0];
												esp_preview::text_colors[3].Value.y = scoped_color[1];
												esp_preview::text_colors[3].Value.z = scoped_color[2];

												static float flashed_color[4] = { esp_preview::text_colors[8].Value.x, esp_preview::text_colors[8].Value.y, esp_preview::text_colors[8].Value.z, 1.f };
												gui->color_edit("Flashed Color", flashed_color, ImGuiColorEditFlags_AlphaBar);
												esp_preview::text_colors[8].Value.x = flashed_color[0];
												esp_preview::text_colors[8].Value.y = flashed_color[1];
												esp_preview::text_colors[8].Value.z = flashed_color[2];

												static float lc_color[4] = { esp_preview::text_colors[11].Value.x, esp_preview::text_colors[11].Value.y, esp_preview::text_colors[11].Value.z, 1.f };
												gui->color_edit("LC Color", lc_color, ImGuiColorEditFlags_AlphaBar);
												esp_preview::text_colors[11].Value.x = lc_color[0];
												esp_preview::text_colors[11].Value.y = lc_color[1];
												esp_preview::text_colors[11].Value.z = lc_color[2];

												gui->end_settings();
											}*/

											//gui->checkbox("Bars", &bars);

											//gui->dropdown("Box Type", &box_c, box_type, IM_ARRAYSIZE(box_type));

											if (globals::esp) {

											gui->checkbox("Draw Bounding Box", &globals::box);

											if (globals::box) {
												gui->dropdown("Box Style", &globals::boxtype, box_items_3, IM_ARRAYSIZE(box_items_3));
											}

											gui->checkbox("Draw Health Bar", &globals::healthbar);

											gui->checkbox("Draw Distance Indicators", &globals::distanceeeeee);

											//gui->checkbox("Draw Tracers", &globals::tracersssssss);


											gui->checkbox("Mark Target Status", &globals::targetmark);

											//gui->checkbox("Display Watermark", &globals::moneyesp);

											gui->checkbox("Enable Radar", &globals::radar);

											}

											gui->checkbox("Show Field of View (FOV)", &globals::fov_on);

											if (globals::fov_on)
												gui->dropdown("FOV Type", &globals::fovtype, fovitems, IM_ARRAYSIZE(fovitems));

											gui->slider_int("Field of View (FOV)", &globals::fov, 1, 1000);


										}
										gui->end_child();

										gui->begin_child("Additions");
										{
											static bool glow = false;
											gui->checkbox("Glow", &glow);
											if (gui->begin_settings())
											{
												static float visible_color[4] = { 1.f, 1.f, 1.f, 1.f };
												gui->color_edit("Visible Color", visible_color, ImGuiColorEditFlags_AlphaBar);

												static float invisible_color[4] = { 1.f, 1.f, 1.f, 1.f };
												gui->color_edit("Invisible Color", invisible_color, ImGuiColorEditFlags_AlphaBar);

												static float thickness = 1.f;
												gui->slider_float("Thickness", &thickness, 0, 10);

												gui->end_settings();
											}

											static bool visible = false;
											gui->checkbox("Visible", &visible);

											const char* glow_materials[3] = { "Flat", "Material", "Solid" };
											static int glow_visible_materials = 0;
											gui->dropdown("Visible Material", &glow_visible_materials, glow_materials, IM_ARRAYSIZE(glow_materials));

											static bool invisible = false;
											gui->checkbox("Invisible", &invisible);

											static int glow_invisible_materials = 0;
											gui->dropdown("Invisible Material", &glow_invisible_materials, glow_materials, IM_ARRAYSIZE(glow_materials));

										}
										gui->end_child();
									}
									gui->end_group();

									ImGui::PushFont(set->widgets_font);

									esp_preview::box.pos = ImVec2{ 555 - esp_preview::box.size.x / 2, 210 - esp_preview::box.size.y / 2 };

									esp_preview::area_rect[area_top] = ImRect{ esp_preview::box.pos - ImVec2{ 0, 50 }, esp_preview::box.pos + ImVec2{ esp_preview::box.size.x, 0 } };
									esp_preview::area_rect[area_right] = ImRect{ esp_preview::box.pos + ImVec2{ esp_preview::box.size.x, 0 }, esp_preview::box.pos + esp_preview::box.size + ImVec2{ 50, 0 } };
									esp_preview::area_rect[area_bottom] = ImRect{ esp_preview::box.pos + ImVec2{ 0, esp_preview::box.size.y }, esp_preview::box.pos + esp_preview::box.size + ImVec2{ 0, 50 } };
									esp_preview::area_rect[area_left] = ImRect{ esp_preview::box.pos - ImVec2{ 50, 0 }, esp_preview::box.pos + ImVec2{ 0, esp_preview::box.size.y } };

									esp_preview::draw_box(box_c == 1);

									esp_preview::hovered_area = area_none;

									for (int i = 0; i < IM_ARRAYSIZE(esp_preview::area_rect); ++i) {
										esp_preview::area_hovered[i] = ImGui::IsMouseHoveringRect(ImGui::GetWindowPos() + esp_preview::area_rect[i].Min, ImGui::GetWindowPos() + esp_preview::area_rect[i].Max);
										if (esp_preview::area_hovered[i]) esp_preview::hovered_area = (area_)i;
									}

									if (bars)
										std::fill(std::begin(esp_preview::bars_buffer), std::end(esp_preview::bars_buffer), 0);

									if (flags)
										std::fill(std::begin(esp_preview::texts_buffer), std::end(esp_preview::texts_buffer), 0);

									ImGui::SetCursorPos(esp_preview::area_rect[area_drop].Min + ImVec2{ 20, 25 });
									ImGui::BeginGroup();
									{
										if (bars)
											for (int i = 0; i < esp_preview::bars.size(); i++) esp_preview::draw_bar(esp_preview::bars[i]);

										if (flags)
											for (int i = 0; i < esp_preview::texts.size(); i++) esp_preview::draw_text(esp_preview::texts[i], i);
									}
									ImGui::EndGroup();

									ImGui::PopFont();

								}
								else if (active_tab == 2)
								{
									int elements_in_first_row = 4;

									if (set->skin_stage == 0)
									{
										if (gui->add_skin_button())
											set->skin_stage = 1;

										gui->sameline();

										for (int i = 0; i < set->added_skins.size(); i++)
										{
											gui->added_skin_button(set->added_skins.at(i).name, set->added_skins.at(i).icon_dx11, set->added_skins.at(i).rarity, i);

											if (i < elements_in_first_row - 1)
												gui->sameline();
											else if (i >= elements_in_first_row && (i - elements_in_first_row + 1) % 5 != 0)
												gui->sameline();
										}

									}
									else if (set->skin_stage == 1)
									{
										if (gui->back_skin_button())
											set->skin_stage = 0;

										gui->sameline();

										for (int i = 0; i < default_skins.size(); i++)
										{
											if (gui->default_skin_button(default_skins.at(i).name, default_skins_texture[i]))
											{
												set->selected_weapon = i;
												set->skin_stage = 2;
											}

											if (i < elements_in_first_row - 1)
												gui->sameline();
											else if (i >= elements_in_first_row && (i - elements_in_first_row + 1) % 5 != 0)
												gui->sameline();
										}
									}
									else if (set->skin_stage == 2)
									{
										if (gui->back_skin_button())
											set->skin_stage = 1;

										gui->sameline();

										if (set->selected_weapon < all_skins_textures.size())
										{
											for (int i = 0; i < all_skins.at(set->selected_weapon).size(); i++)
											{
												if (gui->weapon_skin_button(all_skins.at(set->selected_weapon).at(i).name, all_skins_textures.at(set->selected_weapon).at(i), all_skins.at(set->selected_weapon).at(i).rarity))
												{
													set->added_skins.insert(set->added_skins.begin(), { all_skins.at(set->selected_weapon).at(i).name, 0, all_skins_textures.at(set->selected_weapon).at(i), all_skins.at(set->selected_weapon).at(i).rarity });
													set->skin_stage = 0;
												}

												if (i < elements_in_first_row - 1)
													gui->sameline();
												else if (i >= elements_in_first_row && (i - elements_in_first_row + 1) % 5 != 0)
													gui->sameline();
											}
										}
									}
								}
								else if (active_tab == 3)
								{
									gui->begin_group();
									{
										gui->begin_child("Text Settings");

										gui->checkbox("Streamproof Mode", &globals::streamproof);

										gui->checkbox("Enable Knock Check", &globals::knock_check);

										gui->checkbox("Enable Team Check", &globals::team_check);

										//gui->checkbox("Hit Notification", &globals::hitnotification);

										//gui->checkbox("Memory Snapshot", &globals::playerlist2);

										gui->checkbox("Enable Orbit Player", &globals::tpkil_enable);
										gui->slider_float("Orbit Speed (Set to 0.1 for Reduced Crashes)", &globals::orbit_speed, 0.1f, 3, "%.01f");
										gui->slider_float("Orbit Radius", &globals::orbit_height, 0.5f, 50, "%.01f");
										Keybind(&globals::tpkey, ImVec2(60, 20));

										gui->end_child();
									}
									gui->end_group();

									gui->sameline();

									gui->begin_group();
									{
										gui->begin_child("Info");
										{

											if (gui->button("Join Discord"))
											{
												system("start https://discord.gg/WetbNYk5gE");
											}

											{
												static char coder[128] = "atklv, hook_aimbot";
												gui->text_field("Developer", coder, sizeof(coder));
											}


											/*std::vector<std::string> allPlayerNames = fetchPlayerNames();

											std::vector<std::string> playerNames;
											for (const auto& name : allPlayerNames) {
												if (globals::whitelistedPlayers.find(name) == globals::whitelistedPlayers.end()) {
													playerNames.push_back(name);
												}
											}

											static std::string current_selected_player;

											for (const auto& playerName : playerNames) {
												if (ImGui::Selectable(playerName.c_str(), current_selected_player == playerName)) {
													current_selected_player = playerName;
												}
											}

											static bool buss = false;
											if (!current_selected_player.empty() && gui->checkbox("Teleport", &buss)) {
												char notificationMessage[100];

												pulse::roblox::vector3_t posyes = globals::players.find_first_child(current_selected_player).get_model_instance().find_first_child("HumanoidRootPart").get_part_pos();



												globals::players.get_local_player().get_model_instance().find_first_child("HumanoidRootPart").set_part_pos(posyes);





												_snprintf_s(notificationMessage, sizeof(notificationMessage), "Successfully Teleported to  Player: %s", current_selected_player.c_str());
												draw->add_notify("Successfully Teleported To Player!", "Well, what you did was successful!", success);
												buss = false;
												current_selected_player.clear();
											}



											static bool buss4 = false;
											if (!current_selected_player.empty() && gui->checkbox("Spectate", &buss4)) {
												char notificationMessage[100];

												//	pulse::roblox::vector3_t posyes = globals::players.find_first_child(current_selected_player).get_model_instance().find_first_child("HumanoidRootPart").get_part_pos();



												globals::players.Spectate(current_selected_player);





												_snprintf_s(notificationMessage, sizeof(notificationMessage), "Successfully Spectated to  Player: %s", current_selected_player.c_str());
												draw->add_notify("Successfully Spectated Player!", "Well, what you did was successful!", success);
												buss4 = false;
												current_selected_player.clear();
											}

											static bool buss5 = false;
											if (!current_selected_player.empty() && gui->checkbox("UnSpectate", &buss4)) {
												char notificationMessage[100];

												//	pulse::roblox::vector3_t posyes = globals::players.find_first_child(current_selected_player).get_model_instance().find_first_child("HumanoidRootPart").get_part_pos();



												globals::players.UnSpectate();





												_snprintf_s(notificationMessage, sizeof(notificationMessage), "Successfully UnSpectated to  Player: %s", current_selected_player.c_str());
												draw->add_notify("Successfully UnSpectated Player!", "Well, what you did was successful!", success);
												buss4 = false;
												current_selected_player.clear();
											}

											//if (gui->button("Succes"))
											//	draw->add_notify("Successful execution!", "Well, what you did was successful!", success);

											//if (gui->button("Error"))
												//draw->add_notify("There was an error!", "Try again a little later please....", error);

											//if (gui->button("Hint"))
												//draw->add_notify("Notification!", "Something cool? I think so!", hint);*/
										}
										gui->end_child();
									}
									gui->end_group();
								}
								else if (active_tab == 4)
								{
									static char config_name[128];
									gui->config_input("Create a new Configuration (not coded yet)", config_name, sizeof config_name);

									gui->sameline();

									for (int i = 0; i < set->added_configs.size(); i++)
									{
										//gui->config_selectable(set->added_configs.at(i).name, "Username", "05.17.2024", i, set->selected_config);
										gui->config_selectable(set->added_configs.at(i).name, globals::LocalPlayer.name(), "05.17.2024", i, set->selected_config);

										if (i < 0)
											gui->sameline();
										else if (i >= 1 && i % 2 != 0)
											gui->sameline();
									}

								}
							}
							gui->end_content();
						}
						gui->pop_style_var();
					}
					gui->end();
				}





				ImGuiIO& io = ImGui::GetIO();
				float fps = io.Framerate;
				char fpsCounter[32];
				sprintf(fpsCounter, "%.1f ", fps);
				//	const char* info_set[3] = { text, fpsCounter, role };


				std::string world_time = getCurrentTime();
				//	const float world_time_size = ImGui::CalcTextSize(world_time.c_str()).x;










				static bool notificationSent = false;

				if (globals::threadcrash == true && !notificationSent) {
					notificationSent = true;
				}
				else if (globals::threadcrash == false) {
					notificationSent = false;
				}

				static float previousHealth = -1.0f;


				static float animationTime = 0.0f;
				static bool isAnimating = true;

				if (globals::targetmark && globals::saved_player.self != 0) {
					auto draw = ImGui::GetBackgroundDrawList();
					float animationDuration = 0.5f;
					float transparency = globals::transparent ? 128 : 255;
					float baseX = (ImGui::GetIO().DisplaySize.x - 300) / 2;
					float baseY = 50.0f;
					float bounceAmplitude = 10.0f;
					float bounceFrequency = 0.5f; // Slower bounce frequency

					if (globals::lowerbottom) {
						baseX = (ImGui::GetIO().DisplaySize.x - 300) / 2;
						baseY = ImGui::GetIO().DisplaySize.y - 100;
					}

					// Calculate animation offset
					float bounceOffset = bounceAmplitude * sinf(ImGui::GetTime() * bounceFrequency * 2 * 3.14159f);
					float x = baseX;
					float y = baseY + bounceOffset;

					transparency *= isAnimating ? (animationTime / animationDuration) : ((animationDuration - fmin(animationTime, animationDuration)) / animationDuration);

					float initialWidth = 300.0f;
					float additionalWidth = 0.0f;
					float watermarkHeight = 80.0f;
					std::string displayText = "";

					auto character = globals::saved_player.get_model_instance();
					auto humanoid = character.find_first_child("Humanoid");
					auto humanoidrootpart = character.find_first_child("HumanoidRootPart");
					auto hrp_pos = humanoidrootpart.get_part_pos();

					if (humanoid.self) {
						auto targetName = globals::saved_player.name();
						float health = humanoid.get_health();
						float currentHealth = humanoid.get_health();
						pulse::roblox::instance_t armor_path = character.find_first_child("BodyEffects").find_first_child("Armor");
						float armor = armor_path.get_armor();
						int healthPercentage = static_cast<int>(health);
						int armorPercentage = static_cast<int>(armor);

						if (previousHealth >= 0.0f && currentHealth < previousHealth && currentHealth > 0) {
							float damageDealt = previousHealth - currentHealth;
							std::string hitNotification = "Hit on " + targetName + ": " + std::to_string(static_cast<int>(damageDealt)) + " HP.";

						}

						previousHealth = currentHealth;

						displayText = "target: " + targetName + "\nhealth: " + std::to_string(healthPercentage) + " HP\narmor: " + std::to_string(armorPercentage);
						additionalWidth = 0.0f;
					}
					else {
						isAnimating = true;
						previousHealth = -1.0f;
					}

					ImVec2 watermarkPos(x, y);
					ImVec2 watermarkSize(initialWidth + additionalWidth, watermarkHeight);
					ImU32 backgroundColor = IM_COL32(15, 15, 20, static_cast<int>(transparency));
					ImU32 borderColor = IM_COL32(0, 150, 255, static_cast<int>(transparency));
					ImU32 innerColor = IM_COL32(25, 25, 35, static_cast<int>(transparency));
					ImU32 textColor = IM_COL32(0, 255, 200, 255);
					ImU32 glowColor = IM_COL32(0, 255, 150, 128);

					draw->AddRectFilled(watermarkPos, ImVec2(watermarkPos.x + watermarkSize.x, watermarkPos.y + watermarkSize.y), backgroundColor, 15.0f);
					draw->AddRect(watermarkPos, ImVec2(watermarkPos.x + watermarkSize.x, watermarkPos.y + watermarkSize.y), borderColor, 2.0f, ImDrawFlags_RoundCornersAll);
					draw->AddRectFilled(ImVec2(watermarkPos.x + 4, watermarkPos.y + 4), ImVec2(watermarkPos.x + watermarkSize.x - 4, watermarkPos.y + watermarkSize.y - 4), innerColor, 15.0f);
					draw->AddText(ImGui::GetFont(), 14.0f, ImVec2(watermarkPos.x + 20, watermarkPos.y + 20), textColor, displayText.c_str());

					draw->AddRect(ImVec2(watermarkPos.x - 5, watermarkPos.y - 5), ImVec2(watermarkPos.x + watermarkSize.x + 5, watermarkPos.y + watermarkSize.y + 5), glowColor, 20.0f, ImDrawFlags_RoundCornersAll);

					if (isAnimating) {
						animationTime += ImGui::GetIO().DeltaTime;
						if (animationTime >= animationDuration) {
							animationTime = 0.0f;
							isAnimating = false;
						}
					}
				}
				else {
					animationTime = 0.0f;
					previousHealth = -1.0f;
					isAnimating = true;
				}

				/*if (globals::playerlist2) {
					static ImVec2 windowSize(323, 639);

					ImVec2 screenSize = ImGui::GetIO().DisplaySize;

					ImVec2 windowPos(screenSize.x - windowSize.x - 10, 10);

					ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);
					ImGui::SetNextWindowPos(windowPos, ImGuiCond_Once); 
					ImGui::Begin("Explorer", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove);

					OpenGameExplorer();

					ImGui::End();
				}*/


				static float previousHealthx = -1.0f;

				//PopFont();

					//PushFont(font::monospace);

				if (globals::hitnotification && globals::saved_player.self != 0) {


					//PopFont();

					//PushFont(font::monospace);

					auto character = globals::saved_player.get_model_instance();
					auto humanoid = character.find_first_child("Humanoid");

					auto hrp_pos = humanoid.get_part_pos();


					if (humanoid.self) {
						auto targetName = globals::saved_player.name();
						float health = humanoid.get_health();
						float currentHealth = humanoid.get_health();

						int healthPercentage = static_cast<int>(health);


						if (previousHealthx >= 0.0f && currentHealth < previousHealthx && currentHealth > 0) {

							float damageDealt = previousHealthx - currentHealth;
							std::string hitNotification = "Hit detected on " + targetName + "! Damage: " + std::to_string(static_cast<int>(damageDealt)) + " HP.";
							//	notificationSystem.AddNotification(hitNotification, 1000);
							if (globals::hitsound) {

								if (globals::hitsound_type == 0) {

									PlaySoundA(reinterpret_cast<char*>(neverlose_sound), NULL, SND_ASYNC | SND_MEMORY);

								}
								else if (globals::hitsound_type == 1) {
									PlaySoundA(reinterpret_cast<char*>(skeet_sound), NULL, SND_ASYNC | SND_MEMORY);

								}
								else if (globals::hitsound_type == 2) {
									PlaySoundA(reinterpret_cast<char*>(Fuck), NULL, SND_ASYNC | SND_MEMORY);

								}
								else if (globals::hitsound_type == 3) {
									PlaySoundA(reinterpret_cast<char*>(Senpai), NULL, SND_ASYNC | SND_MEMORY);

								}

							}

						}

						previousHealthx = currentHealth;



					}
					else {
						previousHealthx = -1.0f;

					}
				}







				//		CheckHealthAndNotify();






				if (globals::streamproof)
				{
					SetWindowDisplayAffinity(hw, WDA_EXCLUDEFROMCAPTURE);
				}
				else
				{
					SetWindowDisplayAffinity(hw, WDA_NONE);
				}

				//if (globals::show_auth)
				if (draws)
				{
					SetWindowLong(hw, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW);
				}
				else
				{
					SetWindowLong(hw, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED | WS_EX_TOOLWINDOW);
				}

				ImGui::EndFrame();
				ImGui::Render();

				const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
				d3d11_device_context->OMSetRenderTargets(1, &d3d11_render_target_view, nullptr);
				d3d11_device_context->ClearRenderTargetView(d3d11_render_target_view, clear_color_with_alpha);
				ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

				if (globals::vsync)
				{
					dxgi_swap_chain->Present(1, 0);
				}
				else
				{
					dxgi_swap_chain->Present(0, 0);

				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3));

	}
	init = false;




	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	cleanup_device_d3d();
	DestroyWindow(hw);
	UnregisterClass(wc.lpszClassName, wc.hInstance);
}

void pulse::utils::overlay::move_window(HWND hw)
{
	HWND target = globals::window_handle;
	HWND foregroundWindow = GetForegroundWindow();

	if (target != foregroundWindow && hw != foregroundWindow)
	{
		MoveWindow(hw, 0, 0, 0, 0, true);
	}
	else
	{
		RECT rect;
		GetWindowRect(target, &rect);

		int rsize_x = rect.right - rect.left;
		int rsize_y = rect.bottom - rect.top;

		if (fullsc(target))
		{
			rsize_x += 16;
			rsize_y -= 24;
		}
		else
		{
			rsize_y -= 63;
			rect.left += 8;
			rect.top += 31;
		}

		MoveWindow(hw, rect.left, rect.top, rsize_x, rsize_y, TRUE);
	}
}


bool pulse::utils::overlay::create_device_d3d(HWND hw)
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 75;
	sd.BufferDesc.RefreshRate.Denominator = 1;

	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hw;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	const UINT create_device_flags = 0;
	D3D_FEATURE_LEVEL d3d_feature_level;
	const D3D_FEATURE_LEVEL feature_level_arr[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, create_device_flags, feature_level_arr, 2, D3D11_SDK_VERSION, &sd, &dxgi_swap_chain, &d3d11_device, &d3d_feature_level, &d3d11_device_context);

	if (res == DXGI_ERROR_UNSUPPORTED)
		res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, create_device_flags, feature_level_arr, 2, D3D11_SDK_VERSION, &sd, &dxgi_swap_chain, &d3d11_device, &d3d_feature_level, &d3d11_device_context);
	if (res != S_OK)
		return false;

	create_render_target();
	return true;
}

void pulse::utils::overlay::cleanup_device_d3d()
{
	cleanup_render_target();

	if (dxgi_swap_chain)
	{
		dxgi_swap_chain->Release();
		dxgi_swap_chain = nullptr;
	}

	if (d3d11_device_context)
	{
		d3d11_device_context->Release();
		d3d11_device_context = nullptr;
	}

	if (d3d11_device)
	{
		d3d11_device->Release();
		d3d11_device = nullptr;
	}
}

void pulse::utils::overlay::create_render_target()
{
	ID3D11Texture2D* d3d11_back_buffer;
	dxgi_swap_chain->GetBuffer(0, IID_PPV_ARGS(&d3d11_back_buffer));
	if (d3d11_back_buffer != nullptr)
	{
		d3d11_device->CreateRenderTargetView(d3d11_back_buffer, nullptr, &d3d11_render_target_view);
		d3d11_back_buffer->Release();
	}
}

void pulse::utils::overlay::cleanup_render_target()
{
	if (d3d11_render_target_view)
	{
		d3d11_render_target_view->Release();
		d3d11_render_target_view = nullptr;
	}
}

LRESULT __stdcall pulse::utils::overlay::window_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (d3d11_device != nullptr && wParam != SIZE_MINIMIZED)
		{
			cleanup_render_target();
			dxgi_swap_chain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			create_render_target();
		}
		return 0;

	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
