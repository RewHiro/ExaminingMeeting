#include "Load.h"

const Texture *CLoad::title_graph;
const Texture *CLoad::enter_graph;
const Texture *CLoad::title_bg;
const Media *CLoad::title_bgm;
const Media *CLoad::title_se;
const Media *CLoad::fireworks_se[1];
const Media *CLoad::stage_bgm[1];

CLoad::CLoad(){
	title_graph = new Texture("res/graph/fireflower.png");
	enter_graph = new Texture("res/graph/pressenterkey.png");
	title_bg = new Texture("res/graph/title_bg.png");
	title_bgm = new Media("res/sound/title_bgm.wav");
	title_se = new Media("res/sound/start_se.wav");
	fireworks_se[0] = new Media("res/sound/fireworks_se.wav");
	stage_bgm[0] = new Media("res/sound/stage_bgm.wav");
}

CLoad::~CLoad(){
	delete title_graph;
	delete enter_graph;
	delete title_bg;
	delete title_bgm;
	delete title_se;
	delete fireworks_se[0];
	delete stage_bgm[0];
}
