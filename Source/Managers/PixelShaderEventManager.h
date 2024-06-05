#pragma once
#include <utility>
#include <unordered_map>
#include <functional>
#include "../Common/StaticSingleton.h"

class PixelShader;
/// @brief ピクセルシェーダーを使う際に使用する定数バッファを管理するイベントを管理するクラス
class PixelShaderEventManager : public StaticSingleton<PixelShaderEventManager> {
public:

	~PixelShaderEventManager(void) = default;
	THIS_CLASS_IS_STATIC_SINGLETON(PixelShaderEventManager);

	void Init(void);
	void Update(void);

	/// @brief 指定されたイベントを使用できるように渡されたピクセルシェーダーの定数バッファを初期化する
	/// @param eventID イベントID
	/// @param pixelShader ピクセルシェーダー
	void InitPixelShader(int eventID, std::weak_ptr<PixelShader> pixelShader);

	/// @brief 指定された定数バッファを初期化する
	/// @param eventID イベントID
	void InitEvent(int eventID);

	/// @brief 指定された定数バッファの更新処理を始める
	/// @param eventID イベントID
	void StartUpdateEvent(int eventID);

	/// @brief 指定された定数バッファの更新処理を止める
	/// @param eventID イベントID
	void StopUpdateEvent(int eventID);

	/// @brief 定数バッファを登録
	/// @param eventId イベントID 
	/// @param constantBuffer 定数バッファ
	void RegisterConstantBuffer(int eventID, int constantBuffer);
private:
	/// @brief イベントの構造体
	/// @param initFunction 初期化処理を行う関数オブジェクト
	/// @param updateFunction 更新処理を行う関数オブジェクト
	/// @param isActive 更新処理を行うか
	/// @param size このイベントを実行するのに必要な定数バッファのサイズ
	struct EVENT_DATA {
		EVENT_DATA(void) : initFunction(nullptr), updateFunction(nullptr), isActive(false), size(0) {};
		~EVENT_DATA(void) = default;
		std::function<void(void)> initFunction;
		std::function<void(void)> updateFunction;
		bool isActive;
		size_t size;
	};

	// 各定数バッファのイベントを管理
	std::unordered_map<int,EVENT_DATA> eventList_;

	// 定数バッファを管理(キー:イベントID, 値:定数バッファ)
	std::unordered_map<int, int> constantBufferList_;

	PixelShaderEventManager(void) = default;
	
	/// @brief 各定数バッファのイベントを登録する
	void RegisterEvent(void);
};