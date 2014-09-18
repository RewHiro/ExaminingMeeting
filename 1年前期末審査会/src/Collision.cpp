#include "Collision.h"

namespace Collision{

	//Å@â~ÇÃìñÇΩÇËîªíË
	bool isCollision(Vec2f &obja, Vec2f &objb, Vec2f &ra, Vec2f &rb){
		float vecx = (objb.x() - obja.x());
		float vecy = (objb.y() - obja.y());
		float r = (ra.x() + rb.x());
		if (vecx*vecx + vecy*vecy < r*r){
			return true;
		}
		else{
			return false;
		}
	}
}