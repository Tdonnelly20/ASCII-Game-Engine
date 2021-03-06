#ifndef __STAR_H__
#define __STAR_H__
#include "Star.h"
#include <stdlib.h>
#include "DisplayManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "Event.h"
#include "EventOut.h"
#include "EventStep.h"
namespace df {
	Star::Star() {
		setType("Star");
		setSprite("star");
		setSolidness(df::SPECTRAL);
		setVelocity(Vector(0, 0));
		setAltitude(0);	//Puts stars in the background 
		setPosition(df::Vector(50, 5));
	}

	//Handles event
	int Star::eventHandler(const df::Event* p_e) {
		if (p_e->getType() == df::STEP_EVENT) {
			/*if (((EventStep*)p_e)->getStepCount() % 450 == 0) {
				setPosition(df::Vector(25, 5));
			}
			if (((EventStep*)p_e)->getStepCount() % 750 == 0) {
				setPosition(df::Vector(35, 8));
			}
			if (((EventStep*)p_e)->getStepCount() % 800 == 0) {
				setAltitude(1);
			}*/

		}
		if (p_e->getType() == df::OUT_EVENT) {
			LM.writeLog(3, "EventOut");
			return 1;
		}

		return 0;
	}

	//Draws the stars
	int Star::draw() {
		return DM.drawCh(getPosition(), STAR_CHAR, df::GREEN);
	}
	
}
#endif
