#pragma once
#include "../GameObject.h"
#include "Transform2D.h"
#include "../../Common/Vector2.h"
#include "../../GameObject/2D/Collider/Collider_Info.h"
#include "../../GameObject/2D/Collider/AbstractCollider.h"
#include "../../GameObject/2D/Collider/CircleCollider.h"
#include "../../GameObject/2D/Collider/RectCollider.h"

class AbstractCollider;
class GameObject2D : public GameObject {
public:
	GameObject2D(void) = default;
	virtual ~GameObject2D(void) override = default;

	/// @brief 子オブジェクトを追加する
	/// @param child 子オブジェクト
	void AddChild(std::shared_ptr<GameObject> child) override;

	/// @brief 2DのゲームオブジェクトのTransformの参照を返す 
	/// @note 外部から中身を弄ることがあるのであえてconstを外してます
	/// @return 2DのTransform
	[[nodiscard]] Transform2D& GetTransform(void);
	
	/// @brief Transformに渡すデータをセットする
	/// @param localPos ローカル座標
	/// @param localRot ローカル角度(名前変かも)
	/// @param localScl ローカルスケール値(名前変かも)
	void SetTransformData( 
		const Vector2<float>& localPos, 
		float localRot, 
		float localScl
	);

	/// @brief コライダーを生成する
	/// @tparam T 生成するコライダーのクラス
	/// @tparam ...Args コライダーに与える引数
	/// @param centerPos 中心座標
	/// @param ...args コライダーに与える引数
	template <typename T, typename ...Args>
	void CreateCollider(const Vector2<float>& centerPos, Args&& ...args);

	std::weak_ptr<AbstractCollider> GetCollider(void) const;
protected:
	// ゲームオブジェクトの基礎データ
	Transform2D transform_;

	// コライダー
	std::shared_ptr<AbstractCollider> collider_;

	void Init_GameObject(void) override;
	void Update_GameObject(void) override;
	void Release_GameObject(void) override;

	// 派生クラスで定義 
	virtual void Init_GameObject2D(void) = 0;
	virtual void Update_GameObject2D(void) = 0;
	virtual void Release_GameObject2D(void) = 0;

	/// @brief 親オブジェクトをセット
	/// @param parent 親オブジェクト
	void SetParent(std::weak_ptr<GameObject> parent) override;
private:
	/// @brief 親オブジェクトを考慮して現在のTransform(2D)のcurrentの値を計算する
	void CalculateTransform2D(void);

};

template<typename T, typename ...Args>
inline void GameObject2D::CreateCollider(const Vector2<float>& centerPos, Args && ...args) {
	collider_ = std::make_shared<T>(centerPos, std::forward<Args>(args)...);
}
