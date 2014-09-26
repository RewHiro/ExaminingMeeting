#include "lib/appEnv.hpp"
#include "scene/SceneManager.h"
#include "Load.h"
#include "lib\random.hpp"
#include <memory>
#include <random>
#include <ctime>

int main() {

	// アプリウインドウの準備
	AppEnv app_env(CScene::WIDTH, CScene::HEIGHT,
		false, true);

	std::unique_ptr<CSceneManager>scene_mgr(CSceneManager::GetInstance());

  //　リソースの読み込み
  CLoad load;

  //　ランダムの生成
  Random random;
  random.setSeed(u_int(time(nullptr)));

  while (app_env.isOpen() && !app_env.isPushKey(GLFW_KEY_ESCAPE)) {
    
	scene_mgr->Update(app_env,random);
	scene_mgr->Draw(app_env);
  }
}
