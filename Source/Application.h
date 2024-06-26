#pragma once
#include <string>
#include <memory>
#include "Common/StaticSingleton.h"

class Application : public StaticSingleton<Application> {
public:
	// ウィンドウのサイズ
	static constexpr int WINDOW_SIZE_WIDTH = 1024;
	static constexpr int WINDOW_SIZE_HEIGHT = 768;

	// 1秒あたりのフレーム数
	static constexpr int FRAME_TIME = 60;
	
	// 1秒あたりのフレーム数
	static constexpr float DELTA_TIME = 1.0f / static_cast<float>(FRAME_TIME);

	~Application(void) noexcept = default;
	THIS_CLASS_IS_STATIC_SINGLETON(Application);

	/// @brief 初期化処理
	/// @return 初期化が成功したか
	bool Init(void);

	/// @brief アプリケーションの実行 
	void Run(void);

	/// @brief 解放処理
	void Release(void);

	/// @brief シャットダウンする 
	void Shutdown(void);
private:
	// ゲームをシャットダウンするか
	bool isShutdown_;

	Application(void) = default;

	/// @brief ウィンドウに関する初期化処理
	/// @param name ウィンドウのタイトル
	/// @param screenWidth ウィンドウの横幅
	/// @param screenHeight ウィンドウの縦幅
	/// @param bitColor 色モード
	void Window_Init(std::string name, int screenWidth, int screenHeight, int bitColor);
};